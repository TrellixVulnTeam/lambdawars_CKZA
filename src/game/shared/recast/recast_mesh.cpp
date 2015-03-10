//====== Copyright � Sandern Corporation, All rights reserved. ===========//
//
// Purpose: 
//
// Note: Recasts expects "y" to be up, so y and z must be swapped everywhere. 
//
// TODO: 
// - Merge common code FindPath and FindPathDistance
// - Fix case with finding the shortest path to neutral obstacle (might try to go from other side)
// - Move m_polys and various into class?
// - Cache paths computed for unit type in same frame?
//
// $NoKeywords: $
//=============================================================================//
#include "cbase.h"
#include "recast/recast_mesh.h"

#ifndef CLIENT_DLL
#include "recast/recast_mapmesh.h"
#else
#include "recast/recast_imapmesh.h"
#include "recast/recast_recastdebugdraw.h"
#include "recast/recast_debugdrawmesh.h"
#include "recast/recast_detourdebugdraw.h"
#include "wars/iwars_extension.h"
#include "recast_imgr.h"
#endif // CLIENT_DLL

#include "recast/recast_tilecache_helpers.h"

#include "detour/DetourNavMesh.h"
#include "detour/DetourNavMeshBuilder.h"
#include "detour/DetourNavMeshQuery.h"
#include "detour/DetourCommon.h"

#ifndef CLIENT_DLL
#include "unit_navigator.h"
#endif // CLIENT_DLL

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#define MAX_POLYS 256

#ifndef CLIENT_DLL
ConVar recast_findpath_debug( "recast_findpath_debug", "0", FCVAR_CHEAT, "" );
#else
ConVar recast_findpath_debug( "cl_recast_findpath_debug", "0", FCVAR_CHEAT, "" );
#endif // CLIENT_DLL

// Defaults
static ConVar recast_maxslope("recast_maxslope", "45.0", FCVAR_REPLICATED);

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
CRecastMesh::CRecastMesh() : 
	m_keepInterResults(true),
	m_triareas(0),
	m_solid(0),
	m_chf(0),
	m_cset(0),
	m_pmesh(0),
	m_dmesh(0),
	m_navMesh(0),
	m_tileCache(0),
	m_cacheBuildTimeMs(0),
	m_cacheCompressedSize(0),
	m_cacheRawSize(0),
	m_cacheLayerCount(0),
	m_cacheBuildMemUsage(0),
	m_navQuery(0),
	m_talloc(0),
	m_tcomp(0),
	m_tmproc(0)
{
	m_Name.Set("default");

	m_regionMinSize = 8;
	m_regionMergeSize = 20;
	m_edgeMaxLen = 12000.0f;
	m_edgeMaxError = 1.3f;
	m_vertsPerPoly = 6.0f;
	m_detailSampleDist = 600.0f;
	m_detailSampleMaxError = 100.0f;
	m_partitionType = SAMPLE_PARTITION_WATERSHED;

	m_maxTiles = 0;
	m_maxPolysPerTile = 0;
	m_tileSize = 48;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
CRecastMesh::~CRecastMesh()
{
	Reset();

	if( m_navQuery )
	{
		dtFreeNavMeshQuery( m_navQuery );
		m_navQuery = 0;
	}

	if( m_talloc )
	{
		delete m_talloc;
		m_talloc = 0;
	}

	if( m_tcomp )
	{
		delete m_tcomp;
		m_tcomp = 0;
	}

	if( m_tmproc )
	{
		delete m_tmproc;
		m_tmproc = 0;
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
bool CRecastMesh::ComputeMeshSettings( const char *name, 
	float &fAgentRadius, float &fAgentHeight, float &fAgentMaxClimb, float &fAgentMaxSlope,
	float &fCellSize, float &fCellHeight )
{
	// Per type
	fAgentMaxSlope = recast_maxslope.GetFloat(); // Default slope for units
	if( V_strncmp( name, "human", V_strlen( name ) ) == 0 )
	{
		// HULL_HUMAN, e.g. Soldier/human
		fAgentHeight = 72.0f;
		fAgentRadius = 18.5f;
		fAgentMaxClimb = 18.0f;
		fCellSize = round( fAgentRadius / 3.0f );
		fCellHeight = round( fCellSize / 2.0f );

	}
	else if( V_strncmp( name, "medium", V_strlen( name ) )== 0 )
	{
		// HULL_MEDIUM & HULL_TALL, e.g. antlion, hunter, dog
		fAgentHeight = 80.0f;
		fAgentRadius = 26.0f;
		fAgentMaxClimb = 18.0f;
		fCellSize = round( fAgentRadius / 3.0f );
		fCellHeight = round( fCellSize / 2.0f );
	}
	else if( V_strncmp( name, "large", V_strlen( name ) )== 0 )
	{
		// HULL_LARGE, e.g. Antlion Guard
		fAgentHeight = 100.0f;
		fAgentRadius = 58.0f; 
		fAgentMaxClimb = 18.0f;
		fCellSize = 10.0f;
		fCellHeight = round( fCellSize / 2.0f );
	}
	else if( V_strncmp( name, "verylarge", V_strlen( name ) )== 0 )
	{
		// HULL_LARGE, e.g. Antlion Guard Boss
		fAgentHeight = 150.0f;
		fAgentRadius = 90.0f; 
		fAgentMaxClimb = 18.0f;
		fCellSize = 12.0f;
		fCellHeight = round( fCellSize / 2.0f );
	}
	else if( V_strncmp( name, "air", V_strlen( name ) )== 0 )
	{
		// HULL_LARGE_CENTERED, e.g. Strider. Should also be good for gunship/helicop.
		fAgentHeight = 450.0f; // Not really that height ever, but don't want to have areas indoor
		fAgentRadius = 42.0f; 
		fAgentMaxClimb =  225.0f;
		fAgentMaxSlope = 70.0f;
		fCellSize = 10.0f;
		fCellHeight = round( fCellSize / 2.0f );
	}
	else
	{
		Warning( "CRecastMesh::ComputeMeshSettings: Unknown mesh %s\n", name );

		fAgentHeight = 72.0f; // => Soldier/human
		fAgentRadius = 18.5f; // => Soldier/human
		fAgentMaxClimb = 18.0f;
		fCellSize = 10.0f;
		fCellHeight = round( fCellSize / 2.0f );

		return false;
	}
	return true;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CRecastMesh::Init( const char *name )
{
	m_Name.Set( name );

	m_navQuery = dtAllocNavMeshQuery();

	m_talloc = new LinearAllocator(32000);
	m_tcomp = new FastLZCompressor;
	m_tmproc = new MeshProcess( name );

	// Shared settings by all
	ComputeMeshSettings( name, m_agentRadius, m_agentHeight, m_agentMaxClimb, m_agentMaxSlope,
		m_cellSize, m_cellHeight );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CRecastMesh::Init( const char *name, float agentRadius, float agentHeight, float agentMaxClimb, float agentMaxSlope )
{
	m_Name.Set( name );

	m_navQuery = dtAllocNavMeshQuery();

	m_talloc = new LinearAllocator(32000);
	m_tcomp = new FastLZCompressor;
	m_tmproc = new MeshProcess( name );

	m_agentHeight = agentHeight;
	m_agentRadius = agentRadius;
	m_agentMaxClimb = agentMaxClimb;
	m_agentMaxSlope = agentMaxSlope;
	m_cellSize = round( m_agentRadius / 3.0f );
	m_cellHeight = round( m_cellSize / 2.0f );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void CRecastMesh::Update( float dt )
{
	if( !IsLoaded() )
	{
		return;
	}

	dtStatus status = m_tileCache->update( dt, m_navMesh );
	if( !dtStatusSucceed( status ) )
	{
		Warning("CRecastMesh::Update failed: \n");
		if( status & DT_OUT_OF_MEMORY )
			Warning("\tOut of memory\n");
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
bool CRecastMesh::Reset()
{
	// Cleanup Nav mesh data
	if( m_triareas )
	{
		delete [] m_triareas;
		m_triareas = 0;
	}

	if( m_solid )
	{
		rcFreeHeightField(m_solid);
		m_solid = 0;
	}

	if( m_chf )
	{
		rcFreeCompactHeightfield(m_chf);
		m_chf = 0;
	}

	if( m_cset )
	{
		rcFreeContourSet(m_cset);
		m_cset = 0;
	}

	if( m_pmesh )
	{
		rcFreePolyMesh(m_pmesh);
		m_pmesh = 0;
	}

	if( m_dmesh )
	{
		rcFreePolyMeshDetail(m_dmesh);
		m_dmesh = 0;
	}

	if( m_navMesh )
	{
		dtFreeNavMesh(m_navMesh);
		m_navMesh = 0;
	}

	if( m_tileCache )
	{
		dtFreeTileCache(m_tileCache);
		m_tileCache = 0;
	}

	return true;
}

#ifdef CLIENT_DLL
ConVar recast_draw_trimeshslope("recast_draw_trimeshslope", "0");
#if 0
ConVar recast_draw_contours("recast_draw_contours", "0");
ConVar recast_draw_polymesh("recast_draw_polymesh", "0");
ConVar recast_draw_polymeshdetail("recast_draw_polymeshdetail", "0");
#endif // 0
ConVar recast_draw_navmesh("recast_draw_navmesh", "0");
ConVar recast_draw_server("recast_draw_server", "1");

//-----------------------------------------------------------------------------
// Purpose: Draws the mesh
//-----------------------------------------------------------------------------
void CRecastMesh::DebugRender()
{
	DebugDrawMesh dd;

	if( recast_draw_trimeshslope.GetBool() )
	{
		const float texScale = 1.0f / (m_cellSize * 10.0f);

		IRecastMgr *pRecastMgr = warsextension->GetRecastMgr();
		if( pRecastMgr )
		{
			IMapMesh *pMapMesh = pRecastMgr->GetMapMesh();
			if( pMapMesh )
			{
				duDebugDrawTriMeshSlope(&dd, pMapMesh->GetVerts(), pMapMesh->GetNumVerts(),
										pMapMesh->GetTris(), pMapMesh->GetNorms(), pMapMesh->GetNumTris(),
										m_agentMaxSlope, texScale);
			}
		}
	}

#if 0
	if( recast_draw_contours.GetBool() && m_cset != NULL )
	{
		duDebugDrawContours(&dd, *m_cset);
	}

	if( recast_draw_polymesh.GetBool() && m_pmesh != NULL )
	{
		duDebugDrawPolyMesh(&dd, *m_pmesh);
	}

	if( recast_draw_polymeshdetail.GetBool() && m_dmesh != NULL )
	{
		duDebugDrawPolyMeshDetail(&dd, *m_dmesh);
	}
#endif // 0

	if( recast_draw_navmesh.GetBool() )
	{
		dtNavMesh *navMesh = NULL;
		dtNavMeshQuery *navQuery = NULL;
		if( recast_draw_server.GetBool() )
		{
			IRecastMgr *pRecastMgr = warsextension->GetRecastMgr();
			navMesh = pRecastMgr->GetNavMesh( m_Name.Get() );
			navQuery = pRecastMgr->GetNavMeshQuery( m_Name.Get() );
		}
		else
		{
			navMesh = m_navMesh;
			navQuery = m_navQuery;
		}

		if( navMesh != NULL && navQuery != NULL )
		{
			char m_navMeshDrawFlags = DU_DRAWNAVMESH_OFFMESHCONS|DU_DRAWNAVMESH_CLOSEDLIST;
			duDebugDrawNavMeshWithClosedList(&dd, *navMesh, *navQuery, m_navMeshDrawFlags);

#if 0 // TODO: add different draw modes
			if (m_drawMode != DRAWMODE_NAVMESH_INVIS)
				duDebugDrawNavMeshWithClosedList(&dd, *m_navMesh, *m_navQuery, m_navMeshDrawFlags);
			if (m_drawMode == DRAWMODE_NAVMESH_BVTREE)
				duDebugDrawNavMeshBVTree(&dd, *m_navMesh);
			if (m_drawMode == DRAWMODE_NAVMESH_NODES)
				duDebugDrawNavMeshNodes(&dd, *m_navQuery);
			duDebugDrawNavMeshPolysWithFlags(&dd, *m_navMesh, SAMPLE_POLYFLAGS_DISABLED, duRGBA(0,0,0,128));
#endif // 0
		}
	}
}
#endif // CLIENT_DLL

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
int CRecastMesh::GetPolyRef( const Vector &vPoint, float fBeneathLimit )
{
	if( !IsLoaded() )
		return 0;

	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	float pos[3];
	pos[0] = vPoint[0];
	pos[1] = vPoint[2];
	pos[2] = vPoint[1];

	// The search distance along each axis. [(x, y, z)]
	float polyPickExt[3];
	polyPickExt[0] = 256.0f;
	polyPickExt[1] = fBeneathLimit;
	polyPickExt[2] = 256.0f;

	dtPolyRef ref;
	dtStatus status = m_navQuery->findNearestPoly(pos, polyPickExt, &m_filter, &ref, 0);
	if( !dtStatusSucceed( status ) )
	{
		return 0;
	}
	return ref;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
bool CRecastMesh::IsValidPolyRef( int polyRef )
{
	if( !IsLoaded() )
		return false;

	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	return m_navQuery->isValidPolyRef( polyRef, &m_filter );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
Vector CRecastMesh::ClosestPointOnMesh( const Vector &vPoint, float fBeneathLimit, float fRadius )
{
	if( !IsLoaded() )
		return vec3_origin;

	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	float pos[3];
	float center[3];
	pos[0] = vPoint[0];
	pos[1] = vPoint[2];
	pos[2] = vPoint[1];

	center[0] = pos[0];
	center[1] = pos[1] - (fBeneathLimit / 2.0f) + 32.0f;
	center[2] = pos[2];

	// The search distance along each axis. [(x, y, z)]
	float polyPickExt[3];
	polyPickExt[0] = fRadius;
	polyPickExt[1] = (fBeneathLimit + 32.0f) / 2.0f;
	polyPickExt[2] = fRadius;

	dtPolyRef closestRef;
	dtStatus status = m_navQuery->findNearestPoly(center, polyPickExt, &m_filter, &closestRef, 0, pos);
	if( !dtStatusSucceed( status ) )
	{
		return vec3_origin;
	}

	float closest[3];
	status = m_navQuery->closestPointOnPoly(closestRef, pos, closest, NULL/*, &posOverPoly*/);
	if( !dtStatusSucceed( status ) )
	{
		return vec3_origin;
	}

	return Vector( closest[0], closest[2], closest[1] );
}

// Returns a random number [0..1)
static float frand()
{
//	return ((float)(rand() & 0xffff)/(float)0xffff);
//	return (float)rand()/(float)RAND_MAX;
	return random->RandomFloat();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
Vector CRecastMesh::RandomPointWithRadius( const Vector &vCenter, float fRadius, const Vector *pStartPoint )
{
	if( !IsLoaded() )
		return vec3_origin;

	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	float pos[3];
	float center[3];
	center[0] = vCenter[0];
	center[1] = vCenter[2];
	center[2] = vCenter[1];

	if( pStartPoint )
	{
		pos[0] = (*pStartPoint)[0];
		pos[1] = (*pStartPoint)[2];
		pos[2] = (*pStartPoint)[1];
	}
	else
	{
		dtVcopy(pos, center);
	}

	// The search distance along each axis. [(x, y, z)]
	float polyPickExt[3];
	polyPickExt[0] = 256.0f;
	polyPickExt[1] = MAX_COORD_FLOAT;
	polyPickExt[2] = 256.0f;

	dtPolyRef closestRef;
	dtStatus status = m_navQuery->findNearestPoly( pos, polyPickExt, &m_filter, &closestRef, 0 );
	if( !dtStatusSucceed( status ) )
	{
		return vec3_origin;
	}

	dtPolyRef eRef;
	float epos[3];
	status = m_navQuery->findRandomPointAroundCircle( closestRef, center, fRadius, &m_filter, frand, &eRef, epos );
	if( !dtStatusSucceed( status ) )
	{
		return vec3_origin;
	}

	return Vector( epos[0], epos[2], epos[1] );
}

#ifndef CLIENT_DLL
//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
UnitBaseWaypoint * CRecastMesh::FindPath( const Vector &vStart, const Vector &vEnd, float fBeneathLimit, CBaseEntity *pTarget )
{
	VPROF_BUDGET( "CRecastMesh::FindPath", "RecastNav" );

	if( !IsLoaded() )
		return NULL;

	UnitBaseWaypoint *pResultPath = NULL;

	dtStatus status;

	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	dtPolyRef m_polys[MAX_POLYS];
	int m_npolys;

	dtPolyRef startRef;
	dtPolyRef endRef;

	float spos[3];
	spos[0] = vStart[0];
	spos[1] = vStart[2];
	spos[2] = vStart[1];

	float epos[3];
	if( pTarget )
	{
		Vector vDir = vStart - vEnd;
		VectorNormalize( vDir );
		Vector vModifiedEnd = vEnd + vDir * pTarget->CollisionProp()->BoundingRadius2D();

		epos[0] = vModifiedEnd[0];
		epos[1] = vModifiedEnd[2];
		epos[2] = vModifiedEnd[1];
	}
	else
	{
		epos[0] = vEnd[0];
		epos[1] = vEnd[2];
		epos[2] = vEnd[1];
	}

	// The search distance along each axis. [(x, y, z)]
	float polyPickExt[3];
	polyPickExt[0] = 256.0f;
	polyPickExt[1] = fBeneathLimit;
	polyPickExt[2] = 256.0f;

	int m_straightPathOptions = 0;
	float m_straightPath[MAX_POLYS*3];
	unsigned char m_straightPathFlags[MAX_POLYS];
	dtPolyRef m_straightPathPolys[MAX_POLYS];
	int m_nstraightPath;

	// Find the start area
	status = m_navQuery->findNearestPoly(spos, polyPickExt, &m_filter, &startRef, 0);
	if( !dtStatusSucceed( status ) )
	{
		return NULL;
	}

	// Find the end area
	status = m_navQuery->findNearestPoly(epos, polyPickExt, &m_filter, &endRef, 0);
	if( !dtStatusSucceed( status ) )
	{
		return NULL;
	}

	if( recast_findpath_debug.GetBool() )
	{
		NDebugOverlay::Box( Vector(spos[0], spos[2], spos[1]), -Vector(8, 8, 8), Vector(8, 8, 8), 0, 255, 0, 255, 5.0f);
		NDebugOverlay::Box( Vector(epos[0], epos[2], epos[1]), -Vector(8, 8, 8), Vector(8, 8, 8), 0, 0, 255, 255, 5.0f);
	}

	status = m_navQuery->findPath(startRef, endRef, spos, epos, &m_filter, m_polys, &m_npolys, MAX_POLYS);
	if( !dtStatusSucceed( status ) )
	{
		return NULL;
	}
	m_nstraightPath = 0;
	if (m_npolys)
	{
		// In case of partial path, make sure the end point is clamped to the last polygon.
		float epos2[3];
		dtVcopy(epos2, epos);
		if (m_polys[m_npolys-1] != endRef)
			m_navQuery->closestPointOnPoly(m_polys[m_npolys-1], epos, epos2, 0);

		if( recast_findpath_debug.GetBool() )
		{
			NDebugOverlay::Box( Vector(epos2[0], epos[2], epos[1] + 16.0f), -Vector(8, 8, 8), Vector(8, 8, 8), 255, 0, 0, 255, 5.0f);
		}
				
		status = m_navQuery->findStraightPath(spos, epos2, m_polys, m_npolys,
										m_straightPath, m_straightPathFlags,
										m_straightPathPolys, &m_nstraightPath, MAX_POLYS, m_straightPathOptions);
		if( !dtStatusSucceed( status ) )
		{
			return NULL;
		}

		pResultPath = new UnitBaseWaypoint( Vector(epos2[0], epos2[2], epos2[1]) );
		for (int i = m_nstraightPath - 1; i >= 0; i--)
		{
			
			const dtOffMeshConnection *pOffmeshCon = m_navMesh->getOffMeshConnectionByRef( m_straightPathPolys[i] );

			Vector pos( m_straightPath[i*3], m_straightPath[i*3+2], m_straightPath[i*3+1] );

			UnitBaseWaypoint *pNewPath = new UnitBaseWaypoint( pos );
			pNewPath->SetNext( pResultPath );
			// For now, offmesh connections are always considered as edges.
			if( pOffmeshCon )
			{
				pResultPath->SpecialGoalStatus = CHS_EDGEDOWNDEST;
				pNewPath->SpecialGoalStatus = CHS_EDGEDOWN;
			}
			pResultPath = pNewPath;
		}
	}

	return pResultPath;
}
#endif // CLIENT_DLL

// TODO: Merge common with FindPath
float CRecastMesh::FindPathDistance( const Vector &vStart, const Vector &vEnd, CBaseEntity *pTarget )
{
	VPROF_BUDGET( "CRecastMesh::FindPathDistance", "RecastNav" );

	if( !IsLoaded() )
		return -1;

	dtStatus status;

	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	dtPolyRef m_polys[MAX_POLYS];
	int m_npolys;

	dtPolyRef startRef;
	dtPolyRef endRef;

	float spos[3];
	spos[0] = vStart[0];
	spos[1] = vStart[2];
	spos[2] = vStart[1];

	float epos[3];
	if( pTarget )
	{
		Vector vDir = vStart - vEnd;
		VectorNormalize( vDir );
		Vector vModifiedEnd = vEnd + vDir * pTarget->CollisionProp()->BoundingRadius2D();

		epos[0] = vModifiedEnd[0];
		epos[1] = vModifiedEnd[2];
		epos[2] = vModifiedEnd[1];
	}
	else
	{
		epos[0] = vEnd[0];
		epos[1] = vEnd[2];
		epos[2] = vEnd[1];
	}

	// The search distance along each axis. [(x, y, z)]
	float polyPickExt[3];
	polyPickExt[0] = 256.0f;
	polyPickExt[1] = 600.0f;
	polyPickExt[2] = 256.0f;

	int m_straightPathOptions = 0;
	float m_straightPath[MAX_POLYS*3];
	unsigned char m_straightPathFlags[MAX_POLYS];
	dtPolyRef m_straightPathPolys[MAX_POLYS];
	int m_nstraightPath;

	status = m_navQuery->findNearestPoly(spos, polyPickExt, &m_filter, &startRef, 0);
	if( !dtStatusSucceed( status ) )
	{
		return -1;
	}
	status = m_navQuery->findNearestPoly(epos, polyPickExt, &m_filter, &endRef, 0);
	if( !dtStatusSucceed( status ) )
	{
		return -1;
	}

	status = m_navQuery->findPath(startRef, endRef, spos, epos, &m_filter, m_polys, &m_npolys, MAX_POLYS);
	if( !dtStatusSucceed( status ) )
	{
		return -1;
	}
	m_nstraightPath = 0;
	if (m_npolys)
	{
		// In case of partial path, make sure the end point is clamped to the last polygon.
		float epos2[3];
		dtVcopy(epos2, epos);
		if (m_polys[m_npolys-1] != endRef)
		{
			return -1;
		}
				
		status = m_navQuery->findStraightPath(spos, epos2, m_polys, m_npolys,
										m_straightPath, m_straightPathFlags,
										m_straightPathPolys, &m_nstraightPath, MAX_POLYS, m_straightPathOptions);
		if( !dtStatusSucceed( status ) )
		{
			return NULL;
		}

		float fPathDistance = 0;
		Vector vPrev = vEnd;
		for (int i = m_nstraightPath - 1; i >= 0; i--)
		{
			Vector pos( m_straightPath[i*3], m_straightPath[i*3+2], m_straightPath[i*3+1] );
			fPathDistance += pos.DistTo(vPrev);
			vPrev = pos;
		}
		return fPathDistance;
	}

	return -1;
}

bool CRecastMesh::TestRoute( const Vector &vStart, const Vector &vEnd )
{
	if( !IsLoaded() )
		return false;

	dtStatus status;
	dtQueryFilter m_filter;
	m_filter.setIncludeFlags(SAMPLE_POLYFLAGS_ALL ^ SAMPLE_POLYFLAGS_DISABLED);
	m_filter.setExcludeFlags(0);

	dtPolyRef startRef;
	dtPolyRef endRef;

	float spos[3];
	spos[0] = vStart[0];
	spos[1] = vStart[2];
	spos[2] = vStart[1];

	float epos[3];
	epos[0] = vEnd[0];
	epos[1] = vEnd[2];
	epos[2] = vEnd[1];

	float polyPickExt[3];
	polyPickExt[0] = 128.0f;
	polyPickExt[1] = 600.0f;
	polyPickExt[2] = 128.0f;

	status = m_navQuery->findNearestPoly(spos, polyPickExt, &m_filter, &startRef, 0);
	if( !dtStatusSucceed( status ) )
	{
		return false;
	}
	status = m_navQuery->findNearestPoly(epos, polyPickExt, &m_filter, &endRef, 0);
	if( !dtStatusSucceed( status ) )
	{
		return false;
	}

	dtRaycastHit rayHit;
	rayHit.maxPath = 0;
	rayHit.pathCost = rayHit.t = 0;
	status = m_navQuery->raycast( startRef, spos, epos, &m_filter, 0, &rayHit );
	if( !dtStatusSucceed( status ) )
	{
		return false;
	}

	return rayHit.t == FLT_MAX;
}

dtObstacleRef CRecastMesh::AddTempObstacle( const Vector &vPos, float radius, float height )
{
	if( !IsLoaded() )
		return 0;
	float pos[3] = {vPos.x, vPos.z, vPos.y};
	//Msg("Adding temp obstacle to %f %f %f with radius %f and height %f\n", pos[0], pos[1], pos[2], radius, height);
	dtObstacleRef result;
	dtStatus status = m_tileCache->addObstacle( pos, radius, height, &result );
	if( !dtStatusSucceed( status ) )
	{
		if( status & DT_BUFFER_TOO_SMALL )
		{
			Warning("CRecastMesh::AddTempObstacle: request buffer too small\n");
		}
		if( status & DT_OUT_OF_MEMORY )
		{
			Warning("CRecastMesh::AddTempObstacle: out of memory\n");
		}
		return 0;
	}
	return result;
}

dtObstacleRef CRecastMesh::AddTempObstacle( const Vector &vPos, const Vector *convexHull, const int numConvexHull, float height )
{
	if( !IsLoaded() )
		return 0;

	float pos[3] = {vPos.x, vPos.z, vPos.y};

	float *verts = (float *)stackalloc( numConvexHull * 3 * sizeof( float ) );
	for( int i = 0; i < numConvexHull; i++ )
	{
		verts[(i*3)+0] = convexHull[i].x;
		verts[(i*3)+1] = convexHull[i].z;
		verts[(i*3)+2] = convexHull[i].y;
	}

	//Msg("Adding temp obstacle to %f %f %f with height %f and %d verts\n", pos[0], pos[1], pos[2], height, numConvexHull);
	dtObstacleRef result;
	dtStatus status = m_tileCache->addObstacle( pos, verts, numConvexHull, height, &result );
	if( !dtStatusSucceed( status ) )
	{
		if( status & DT_BUFFER_TOO_SMALL )
		{
			Warning("CRecastMesh::AddTempObstacle: request buffer too small\n");
		}
		if( status & DT_OUT_OF_MEMORY )
		{
			Warning("CRecastMesh::AddTempObstacle: out of memory\n");
		}
		return 0;
	}
	return result;
}

bool CRecastMesh::RemoveObstacle( const dtObstacleRef ref )
{
	if( !IsLoaded() )
		return false;

	dtStatus status = m_tileCache->removeObstacle( ref );
	if( !dtStatusSucceed( status ) )
	{
		if( status & DT_BUFFER_TOO_SMALL )
		{
			Warning("CRecastMesh::RemoveObstacle: request buffer too small\n");
		}
		if( status & DT_OUT_OF_MEMORY )
		{
			Warning("CRecastMesh::RemoveObstacle: out of memory\n");
		}
		return false;
	}
	return true;
}