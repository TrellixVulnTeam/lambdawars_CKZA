// This file has been generated by Py++.

#include "cbase.h"
#ifdef CLIENT_DLL
#include "cbase.h"

#include "recast/recast_mgr.h"

#include "recast/recast_mesh.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_recast){
    bp::docstring_options doc_options( true, true, false );

    { //::CRecastMesh
        typedef bp::class_< CRecastMesh > CRecastMesh_exposer_t;
        CRecastMesh_exposer_t CRecastMesh_exposer = CRecastMesh_exposer_t( "CRecastMesh", bp::no_init );
        bp::scope CRecastMesh_scope( CRecastMesh_exposer );
        { //property "agentradius"[fget=::CRecastMesh::GetAgentRadius]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            
            CRecastMesh_exposer.add_property( 
                "agentradius"
                , fget( &::CRecastMesh::GetAgentRadius ) );
        
        }
        { //property "agentheight"[fget=::CRecastMesh::GetAgentHeight]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            
            CRecastMesh_exposer.add_property( 
                "agentheight"
                , fget( &::CRecastMesh::GetAgentHeight ) );
        
        }
        { //property "cellsize"[fget=::CRecastMesh::GetCellSize, fset=::CRecastMesh::SetCellSize]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            typedef void ( ::CRecastMesh::*fset )( float ) ;
            
            CRecastMesh_exposer.add_property( 
                "cellsize"
                , fget( &::CRecastMesh::GetCellSize )
                , fset( &::CRecastMesh::SetCellSize ) );
        
        }
        { //property "cellheight"[fget=::CRecastMesh::GetCellHeight, fset=::CRecastMesh::SetCellHeight]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            typedef void ( ::CRecastMesh::*fset )( float ) ;
            
            CRecastMesh_exposer.add_property( 
                "cellheight"
                , fget( &::CRecastMesh::GetCellHeight )
                , fset( &::CRecastMesh::SetCellHeight ) );
        
        }
        { //property "tilesize"[fget=::CRecastMesh::GetTileSize, fset=::CRecastMesh::SetTileSize]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            typedef void ( ::CRecastMesh::*fset )( float ) ;
            
            CRecastMesh_exposer.add_property( 
                "tilesize"
                , fget( &::CRecastMesh::GetTileSize )
                , fset( &::CRecastMesh::SetTileSize ) );
        
        }
    }

    bp::class_< CRecastMgr, boost::noncopyable >( "CRecastMgr", bp::no_init )    
        .def( 
            "AddEntBoxObstacle"
            , (bool ( ::CRecastMgr::* )( ::C_BaseEntity *,::Vector const &,::Vector const &,float ) )( &::CRecastMgr::AddEntBoxObstacle )
            , ( bp::arg("pEntity"), bp::arg("mins"), bp::arg("maxs"), bp::arg("height") ) )    
        .def( 
            "AddEntRadiusObstacle"
            , (bool ( ::CRecastMgr::* )( ::C_BaseEntity *,float,float ) )( &::CRecastMgr::AddEntRadiusObstacle )
            , ( bp::arg("pEntity"), bp::arg("radius"), bp::arg("height") ) )    
        .def( 
            "FindBestMeshNameForEntity"
            , (char const * ( ::CRecastMgr::* )( ::C_BaseEntity * ) )( &::CRecastMgr::FindBestMeshNameForEntity )
            , ( bp::arg("pEntity") ) )    
        .def( 
            "FindBestMeshNameForRadiusHeight"
            , (char const * ( ::CRecastMgr::* )( float,float ) )( &::CRecastMgr::FindBestMeshNameForRadiusHeight )
            , ( bp::arg("radius"), bp::arg("height") ) )    
        .def( 
            "GetMesh"
            , (::CRecastMesh * ( ::CRecastMgr::* )( int ) )( &::CRecastMgr::GetMesh )
            , ( bp::arg("index") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "GetMesh"
            , (::CRecastMesh * ( ::CRecastMgr::* )( char const * ) )( &::CRecastMgr::GetMesh )
            , ( bp::arg("name") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "Init"
            , (void ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::Init ) )    
        .def( 
            "InitDefaultMeshes"
            , (bool ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::InitDefaultMeshes ) )    
        .def( 
            "InsertMesh"
            , (bool ( ::CRecastMgr::* )( char const *,float,float,float,float ) )( &::CRecastMgr::InsertMesh )
            , ( bp::arg("name"), bp::arg("agentRadius"), bp::arg("agentHeight"), bp::arg("agentMaxClimb"), bp::arg("agentMaxSlope") ) )    
        .def( 
            "IsMeshLoaded"
            , (bool ( ::CRecastMgr::* )( char const * ) )( &::CRecastMgr::IsMeshLoaded )
            , ( bp::arg("name") ) )    
        .def( 
            "RemoveEntObstacles"
            , (bool ( ::CRecastMgr::* )( ::C_BaseEntity * ) )( &::CRecastMgr::RemoveEntObstacles )
            , ( bp::arg("pEntity") ) )    
        .def( 
            "Reset"
            , (void ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::Reset ) )    
        .def( 
            "Update"
            , (void ( ::CRecastMgr::* )( float ) )( &::CRecastMgr::Update )
            , ( bp::arg("dt") ) );

    { //::RecastMgr
    
        typedef ::CRecastMgr & ( *RecastMgr_function_type )(  );
        
        bp::def( 
            "RecastMgr"
            , RecastMgr_function_type( &::RecastMgr )
            , bp::return_value_policy< bp::reference_existing_object >() );
    
    }
}
#else
#include "cbase.h"

#include "recast/recast_mgr.h"

#include "recast/recast_mesh.h"

#include "recast/recast_mapmesh.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_recast){
    bp::docstring_options doc_options( true, true, false );

    bp::class_< CMapMesh, boost::noncopyable >( "CMapMesh", bp::no_init )    
        .def( 
            "AddEntity"
            , (void ( ::CMapMesh::* )( ::CBaseEntity * ) )( &::CMapMesh::AddEntity )
            , ( bp::arg("pEnt") ) );

    { //::CRecastMesh
        typedef bp::class_< CRecastMesh > CRecastMesh_exposer_t;
        CRecastMesh_exposer_t CRecastMesh_exposer = CRecastMesh_exposer_t( "CRecastMesh", bp::no_init );
        bp::scope CRecastMesh_scope( CRecastMesh_exposer );
        { //property "agentradius"[fget=::CRecastMesh::GetAgentRadius]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            
            CRecastMesh_exposer.add_property( 
                "agentradius"
                , fget( &::CRecastMesh::GetAgentRadius ) );
        
        }
        { //property "agentheight"[fget=::CRecastMesh::GetAgentHeight]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            
            CRecastMesh_exposer.add_property( 
                "agentheight"
                , fget( &::CRecastMesh::GetAgentHeight ) );
        
        }
        { //property "cellsize"[fget=::CRecastMesh::GetCellSize, fset=::CRecastMesh::SetCellSize]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            typedef void ( ::CRecastMesh::*fset )( float ) ;
            
            CRecastMesh_exposer.add_property( 
                "cellsize"
                , fget( &::CRecastMesh::GetCellSize )
                , fset( &::CRecastMesh::SetCellSize ) );
        
        }
        { //property "cellheight"[fget=::CRecastMesh::GetCellHeight, fset=::CRecastMesh::SetCellHeight]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            typedef void ( ::CRecastMesh::*fset )( float ) ;
            
            CRecastMesh_exposer.add_property( 
                "cellheight"
                , fget( &::CRecastMesh::GetCellHeight )
                , fset( &::CRecastMesh::SetCellHeight ) );
        
        }
        { //property "tilesize"[fget=::CRecastMesh::GetTileSize, fset=::CRecastMesh::SetTileSize]
        
            typedef float ( ::CRecastMesh::*fget )(  ) ;
            typedef void ( ::CRecastMesh::*fset )( float ) ;
            
            CRecastMesh_exposer.add_property( 
                "tilesize"
                , fget( &::CRecastMesh::GetTileSize )
                , fset( &::CRecastMesh::SetTileSize ) );
        
        }
    }

    bp::class_< CRecastMgr, boost::noncopyable >( "CRecastMgr", bp::no_init )    
        .def( 
            "AddEntBoxObstacle"
            , (bool ( ::CRecastMgr::* )( ::CBaseEntity *,::Vector const &,::Vector const &,float ) )( &::CRecastMgr::AddEntBoxObstacle )
            , ( bp::arg("pEntity"), bp::arg("mins"), bp::arg("maxs"), bp::arg("height") ) )    
        .def( 
            "AddEntRadiusObstacle"
            , (bool ( ::CRecastMgr::* )( ::CBaseEntity *,float,float ) )( &::CRecastMgr::AddEntRadiusObstacle )
            , ( bp::arg("pEntity"), bp::arg("radius"), bp::arg("height") ) )    
        .def( 
            "Build"
            , (bool ( ::CRecastMgr::* )( bool ) )( &::CRecastMgr::Build )
            , ( bp::arg("loadDefaultMeshes")=(bool)(true) ) )    
        .def( 
            "FindBestMeshNameForEntity"
            , (char const * ( ::CRecastMgr::* )( ::CBaseEntity * ) )( &::CRecastMgr::FindBestMeshNameForEntity )
            , ( bp::arg("pEntity") ) )    
        .def( 
            "FindBestMeshNameForRadiusHeight"
            , (char const * ( ::CRecastMgr::* )( float,float ) )( &::CRecastMgr::FindBestMeshNameForRadiusHeight )
            , ( bp::arg("radius"), bp::arg("height") ) )    
        .def( 
            "GetMesh"
            , (::CRecastMesh * ( ::CRecastMgr::* )( int ) )( &::CRecastMgr::GetMesh )
            , ( bp::arg("index") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "GetMesh"
            , (::CRecastMesh * ( ::CRecastMgr::* )( char const * ) )( &::CRecastMgr::GetMesh )
            , ( bp::arg("name") )
            , bp::return_value_policy< bp::reference_existing_object >() )    
        .def( 
            "Init"
            , (void ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::Init ) )    
        .def( 
            "InitDefaultMeshes"
            , (bool ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::InitDefaultMeshes ) )    
        .def( 
            "InsertMesh"
            , (bool ( ::CRecastMgr::* )( char const *,float,float,float,float ) )( &::CRecastMgr::InsertMesh )
            , ( bp::arg("name"), bp::arg("agentRadius"), bp::arg("agentHeight"), bp::arg("agentMaxClimb"), bp::arg("agentMaxSlope") ) )    
        .def( 
            "IsMeshLoaded"
            , (bool ( ::CRecastMgr::* )( char const * ) )( &::CRecastMgr::IsMeshLoaded )
            , ( bp::arg("name") ) )    
        .def( 
            "RebuildPartial"
            , (bool ( ::CRecastMgr::* )( ::Vector const &,::Vector const & ) )( &::CRecastMgr::RebuildPartial )
            , ( bp::arg("vMins"), bp::arg("vMaxs") ) )    
        .def( 
            "RemoveEntObstacles"
            , (bool ( ::CRecastMgr::* )( ::CBaseEntity * ) )( &::CRecastMgr::RemoveEntObstacles )
            , ( bp::arg("pEntity") ) )    
        .def( 
            "Reset"
            , (void ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::Reset ) )    
        .def( 
            "Save"
            , (bool ( ::CRecastMgr::* )(  ) )( &::CRecastMgr::Save ) )    
        .def( 
            "Update"
            , (void ( ::CRecastMgr::* )( float ) )( &::CRecastMgr::Update )
            , ( bp::arg("dt") ) );

    { //::RecastMgr
    
        typedef ::CRecastMgr & ( *RecastMgr_function_type )(  );
        
        bp::def( 
            "RecastMgr"
            , RecastMgr_function_type( &::RecastMgr )
            , bp::return_value_policy< bp::reference_existing_object >() );
    
    }
}
#endif

