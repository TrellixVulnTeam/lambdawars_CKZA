//===== Copyright � 1996-2005, Valve Corporation, All rights reserved. ======//
//
// Purpose: 
//
// $NoKeywords: $
//===========================================================================//

#include "cbase.h"
#include "ServerNetworkProperty.h"
#include "tier0/dbg.h"
#include "gameinterface.h"

#include "hl2wars_player.h"
#include "collisionutils.h"

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

extern CTimedEventMgr g_NetworkPropertyEventMgr;

#define USE_NEW_ISINPVS

static ConVar wars_use_newpvs_code( "wars_use_newpvs_code", "1", FCVAR_CHEAT );

//-----------------------------------------------------------------------------
// Save/load
//-----------------------------------------------------------------------------
BEGIN_DATADESC_NO_BASE( CServerNetworkProperty )
//	DEFINE_FIELD( m_pOuter, FIELD_CLASSPTR ),
//	DEFINE_FIELD( m_pPev, FIELD_CLASSPTR ),
//	DEFINE_FIELD( m_PVSInfo, PVSInfo_t ),
//	DEFINE_FIELD( m_pServerClass, FIELD_CLASSPTR ),
	DEFINE_GLOBAL_FIELD( m_hParent, FIELD_EHANDLE ),
//	DEFINE_FIELD( m_TimerEvent, CEventRegister ),
//	DEFINE_FIELD( m_bPendingStateChange, FIELD_BOOLEAN ),
END_DATADESC()


//-----------------------------------------------------------------------------
// Constructor, destructor
//-----------------------------------------------------------------------------
CServerNetworkProperty::CServerNetworkProperty()
{
	Init( NULL );
	m_bDestroyed = false;
}


CServerNetworkProperty::~CServerNetworkProperty()
{
// =======================================
// PySource Additions
// =======================================
#ifdef ENABLE_PYTHON
	if( !m_bDestroyed )
	{
		DestroyNetworkProperty();
	}
#else
	/* Free our transmit proxy.
	if ( m_pTransmitProxy )
	{
		m_pTransmitProxy->Release();
	}*/

	engine->CleanUpEntityClusterList( &m_PVSInfo );

	// remove the attached edict if it exists
	DetachEdict();
#endif // ENABLE_PYTHON
// =======================================
// END PySource Additions
// =======================================
}

// =======================================
// PySource Additions
// =======================================
#ifdef ENABLE_PYTHON
void CServerNetworkProperty::DestroyNetworkProperty()
{
	/* Free our transmit proxy.
	if ( m_pTransmitProxy )
	{
		m_pTransmitProxy->Release();
	}*/

	engine->CleanUpEntityClusterList( &m_PVSInfo );

	// remove the attached edict if it exists
	DetachEdict();

	m_bDestroyed = true;
}
#endif // ENABLE_PYTHON
// =======================================
// END PySource Additions
// =======================================

//-----------------------------------------------------------------------------
// Initialization
//-----------------------------------------------------------------------------
void CServerNetworkProperty::Init( CBaseEntity *pEntity )
{
	m_pPev = NULL;
	m_pOuter = pEntity;
	m_pServerClass = NULL;
//	m_pTransmitProxy = NULL;
	m_bPendingStateChange = false;
	m_PVSInfo.m_nClusterCount = 0;
	m_TimerEvent.Init( &g_NetworkPropertyEventMgr, this );
}


//-----------------------------------------------------------------------------
// Connects, disconnects edicts
//-----------------------------------------------------------------------------
void CServerNetworkProperty::AttachEdict( edict_t *pRequiredEdict )
{
	Assert ( !m_pPev );

	// see if there is an edict allocated for it, otherwise get one from the engine
	if ( !pRequiredEdict )
	{
		pRequiredEdict = engine->CreateEdict();
	}

	m_pPev = pRequiredEdict;
	m_pPev->SetEdict( GetBaseEntity(), true );
}

void CServerNetworkProperty::DetachEdict()
{
	if ( m_pPev )
	{
		m_pPev->SetEdict( NULL, false );
		engine->RemoveEdict( m_pPev );
		m_pPev = NULL;
	}
}


//-----------------------------------------------------------------------------
// Entity handles
//-----------------------------------------------------------------------------
IHandleEntity *CServerNetworkProperty::GetEntityHandle( )
{
	return m_pOuter;
}

void CServerNetworkProperty::Release()
{
	delete m_pOuter;
}


//-----------------------------------------------------------------------------
// Returns the network parent
//-----------------------------------------------------------------------------
CServerNetworkProperty* CServerNetworkProperty::GetNetworkParent()
{
	CBaseEntity *pParent = m_hParent.Get();
	return pParent ? pParent->NetworkProp() : NULL;
}


//-----------------------------------------------------------------------------
// Marks for deletion
//-----------------------------------------------------------------------------
void CServerNetworkProperty::MarkForDeletion()
{
	m_pOuter->AddEFlags( EFL_KILLME );
}

bool CServerNetworkProperty::IsMarkedForDeletion() const
{
	return ( m_pOuter->GetEFlags() & EFL_KILLME ) != 0;
}

//-----------------------------------------------------------------------------
// PVS information
//-----------------------------------------------------------------------------
void CServerNetworkProperty::RecomputePVSInformation()
{
#ifdef USE_NEW_ISINPVS
	if( gpGlobals->maxClients != 1 && wars_use_newpvs_code.GetBool() )
		return;
#endif // USE_NEW_ISINPVS
	if ( m_pPev && ( ( m_pPev->m_fStateFlags & FL_EDICT_DIRTY_PVS_INFORMATION ) != 0 ) )
	{
		m_pPev->m_fStateFlags &= ~FL_EDICT_DIRTY_PVS_INFORMATION;
		engine->BuildEntityClusterList( edict(), &m_PVSInfo );
	}
}


//-----------------------------------------------------------------------------
// Serverclass
//-----------------------------------------------------------------------------
ServerClass* CServerNetworkProperty::GetServerClass()
{
	if ( !m_pServerClass )
		m_pServerClass = m_pOuter->GetServerClass();
	return m_pServerClass;
}

const char* CServerNetworkProperty::GetClassName() const
{
	return STRING(m_pOuter->m_iClassname);
}


//-----------------------------------------------------------------------------
// Transmit proxies
/*-----------------------------------------------------------------------------
void CServerNetworkProperty::SetTransmitProxy( CBaseTransmitProxy *pProxy )
{
	if ( m_pTransmitProxy )
	{
		m_pTransmitProxy->Release();
	}

	m_pTransmitProxy = pProxy;
	
	if ( m_pTransmitProxy )
	{
		m_pTransmitProxy->AddRef();
	}
}*/

//-----------------------------------------------------------------------------
// PVS rules
//-----------------------------------------------------------------------------
bool CServerNetworkProperty::IsInPVS( const edict_t *pRecipient, const void *pvs, int pvssize )
{
#ifndef USE_NEW_ISINPVS
	RecomputePVSInformation();

	// ignore if not touching a PV leaf
	// negative leaf count is a node number
	// If no pvs, add any entity

	Assert( pvs && ( edict() != pRecipient ) );

	unsigned char *pPVS = ( unsigned char * )pvs;
	
	if ( m_PVSInfo.m_nClusterCount < 0 )   // too many clusters, use headnode
	{
		return ( engine->CheckHeadnodeVisible( m_PVSInfo.m_nHeadNode, pPVS, pvssize ) != 0);
	}
	
	for ( int i = m_PVSInfo.m_nClusterCount; --i >= 0; )
	{
		if (pPVS[m_PVSInfo.m_pClusters[i] >> 3] & (1 << (m_PVSInfo.m_pClusters[i] & 7) ))
			return true;
	}
#else
	Assert( 0 );
	Warning( "CServerNetworkProperty::IsInPVS: unimplemented\n");
#endif // USE_NEW_ISINPVS

	return false;		// not visible
}

static inline bool TestPointInCamera( const Vector &vPoint, const Vector &vCamLimits, const matrix3x4_t &matAngles, const Vector &vPlayerPos )
{
	// Get point direction
	Vector vecToTarget = vPoint - vPlayerPos;
	vecToTarget.NormalizeInPlace();

	// Transform into player space
	VectorITransform( vecToTarget, matAngles, vecToTarget );

	// Test against camera angles of player
	if( vecToTarget.y > -vCamLimits.y && vecToTarget.y < vCamLimits.y &&
		vecToTarget.z > -vCamLimits.z && vecToTarget.z < vCamLimits.z )
	{
		return true;
	}
	return false;
}

//-----------------------------------------------------------------------------
// PVS: this function is called a lot, so it avoids function calls
//-----------------------------------------------------------------------------
bool CServerNetworkProperty::IsInPVS( const CCheckTransmitInfo *pInfo )
{
#ifdef USE_NEW_ISINPVS
	if( gpGlobals->maxClients == 1 || !wars_use_newpvs_code.GetBool() )
#endif // USE_NEW_ISINPVS
	{
		// PVS data must be up to date
		Assert( !m_pPev || ( ( m_pPev->m_fStateFlags & FL_EDICT_DIRTY_PVS_INFORMATION ) == 0 ) );
	
		int i;

		// Early out if the areas are connected
		if ( !m_PVSInfo.m_nAreaNum2 )
		{
			for ( i=0; i< pInfo->m_AreasNetworked; i++ )
			{
				int clientArea = pInfo->m_Areas[i];
				if ( clientArea == m_PVSInfo.m_nAreaNum || engine->CheckAreasConnected( clientArea, m_PVSInfo.m_nAreaNum ) )
					break;
			}
		}
		else
		{
			// doors can legally straddle two areas, so
			// we may need to check another one
			for ( i=0; i< pInfo->m_AreasNetworked; i++ )
			{
				int clientArea = pInfo->m_Areas[i];
				if ( clientArea == m_PVSInfo.m_nAreaNum || clientArea == m_PVSInfo.m_nAreaNum2 )
					break;

				if ( engine->CheckAreasConnected( clientArea, m_PVSInfo.m_nAreaNum ) )
					break;

				if ( engine->CheckAreasConnected( clientArea, m_PVSInfo.m_nAreaNum2 ) )
					break;
			}
		}

		if ( i == pInfo->m_AreasNetworked )
		{
			// areas not connected
			return false;
		}

		// ignore if not touching a PV leaf
		// negative leaf count is a node number
		// If no pvs, add any entity

		Assert( edict() != pInfo->m_pClientEnt );

		unsigned char *pPVS = ( unsigned char * )pInfo->m_PVS;
	
		if ( m_PVSInfo.m_nClusterCount < 0 )   // too many clusters, use headnode
		{
			return (engine->CheckHeadnodeVisible( m_PVSInfo.m_nHeadNode, pPVS, pInfo->m_nPVSSize ) != 0);
		}
	
		for ( i = m_PVSInfo.m_nClusterCount; --i >= 0; )
		{
			int nCluster = m_PVSInfo.m_pClusters[i];
			if ( ((int)(pPVS[nCluster >> 3])) & BitVec_BitInByte( nCluster ) )
				return true;
		}

		return false;		// not visible
	}
#ifdef USE_NEW_ISINPVS
	else
	{
		// Cull transmission based on the camera limits
		// These limits are send in cl_strategic_cam_limits (basically just the fov angles)
		CBaseEntity *pRecipientEntity = CBaseEntity::Instance( pInfo->m_pClientEnt );
		Assert( pRecipientEntity && pRecipientEntity->IsPlayer() );
		if ( !pRecipientEntity )
			return false;
		CHL2WarsPlayer *pRecipientPlayer = static_cast<CHL2WarsPlayer*>( pRecipientEntity );

		// Get player camera position and limits
		Vector vPlayerPos = pRecipientPlayer->Weapon_ShootPosition() + pRecipientPlayer->GetCameraOffset();
		const Vector &vCamLimits = pRecipientPlayer->GetCamLimits();

		// Get player angles
		matrix3x4_t matAngles;
		AngleMatrix( pRecipientPlayer->GetAbsAngles(), matAngles );

		// Now check if the entity is within the camera limits
		const Vector &center = GetOuter()->WorldSpaceCenter();
		if( GetOuter()->IsPointSized() )
		{
			if( TestPointInCamera( center, vCamLimits, matAngles, vPlayerPos ) )
				return true;
		}
		else
		{
			// TODO: Do a better (and fast) check
			const Vector &vOffset1 = GetOuter()->CollisionProp()->OBBMins();
			Vector vOffset2 = GetOuter()->CollisionProp()->OBBMaxs();
			vOffset2.z = vOffset1.z;

			if( TestPointInCamera( center + vOffset1, vCamLimits, matAngles, vPlayerPos ) ||
				TestPointInCamera( center + vOffset2, vCamLimits, matAngles, vPlayerPos ) )
				return true;
		}

		return false;
	}
#endif // 0
}


void CServerNetworkProperty::SetUpdateInterval( float val )
{
	if ( val == 0 )
		m_TimerEvent.StopUpdates();
	else
		m_TimerEvent.SetUpdateInterval( val );
}


void CServerNetworkProperty::FireEvent()
{
	// Our timer went off. If our state has changed in the background, then 
	// trigger a state change in the edict.
	if ( m_bPendingStateChange && m_pPev )
	{
		m_pPev->StateChanged();
		m_bPendingStateChange = false;
	}
}



