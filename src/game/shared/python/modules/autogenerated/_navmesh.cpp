// This file has been generated by Py++.

#include "cbase.h"
#ifdef CLIENT_DLL
#include "cbase.h"

#include "srcpy_navmesh.h"

#include "unit_base_shared.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_navmesh){
    bp::docstring_options doc_options( true, true, false );

    { //::CreateHidingSpot
    
        typedef int ( *CreateHidingSpot_function_type )( ::Vector const &,bool,bool );
        
        bp::def( 
            "CreateHidingSpot"
            , CreateHidingSpot_function_type( &::CreateHidingSpot )
            , ( bp::arg("pos"), bp::arg("notsaved")=(bool)(false), bp::arg("checkground")=(bool)(true) ) );
    
    }

    { //::CreateNavArea
    
        typedef int ( *CreateNavArea_function_type )( ::Vector const &,::Vector const & );
        
        bp::def( 
            "CreateNavArea"
            , CreateNavArea_function_type( &::CreateNavArea )
            , ( bp::arg("corner"), bp::arg("otherCorner") ) );
    
    }

    { //::CreateNavAreaByCorners
    
        typedef int ( *CreateNavAreaByCorners_function_type )( ::Vector const &,::Vector const &,::Vector const &,::Vector const & );
        
        bp::def( 
            "CreateNavAreaByCorners"
            , CreateNavAreaByCorners_function_type( &::CreateNavAreaByCorners )
            , ( bp::arg("nwcorner"), bp::arg("necorner"), bp::arg("secorner"), bp::arg("swcorner") ) );
    
    }

    { //::DestroyAllNavAreas
    
        typedef void ( *DestroyAllNavAreas_function_type )(  );
        
        bp::def( 
            "DestroyAllNavAreas"
            , DestroyAllNavAreas_function_type( &::DestroyAllNavAreas ) );
    
    }

    { //::DestroyHidingSpot
    
        typedef bool ( *DestroyHidingSpot_function_type )( ::Vector const &,float,int,unsigned int );
        
        bp::def( 
            "DestroyHidingSpot"
            , DestroyHidingSpot_function_type( &::DestroyHidingSpot )
            , ( bp::arg("pos"), bp::arg("tolerance"), bp::arg("num")=(int)(1), bp::arg("excludeFlags")=(unsigned int)(0) ) );
    
    }

    { //::DestroyHidingSpotByID
    
        typedef bool ( *DestroyHidingSpotByID_function_type )( ::Vector const &,unsigned int );
        
        bp::def( 
            "DestroyHidingSpotByID"
            , DestroyHidingSpotByID_function_type( &::DestroyHidingSpotByID )
            , ( bp::arg("pos"), bp::arg("hidespotid") ) );
    
    }

    { //::DestroyNavArea
    
        typedef void ( *DestroyNavArea_function_type )( unsigned int );
        
        bp::def( 
            "DestroyNavArea"
            , DestroyNavArea_function_type( &::DestroyNavArea )
            , ( bp::arg("id") ) );
    
    }

    { //::GetActiveNavMesh
    
        typedef int ( *GetActiveNavMesh_function_type )(  );
        
        bp::def( 
            "GetActiveNavMesh"
            , GetActiveNavMesh_function_type( &::GetActiveNavMesh ) );
    
    }

    { //::GetEditingCursor
    
        typedef ::Vector ( *GetEditingCursor_function_type )(  );
        
        bp::def( 
            "GetEditingCursor"
            , GetEditingCursor_function_type( &::GetEditingCursor ) );
    
    }

    { //::GetHidingSpotsInRadius
    
        typedef ::boost::python::list ( *GetHidingSpotsInRadius_function_type )( ::Vector const &,float,::C_UnitBase *,bool,::Vector const * );
        
        bp::def( 
            "GetHidingSpotsInRadius"
            , GetHidingSpotsInRadius_function_type( &::GetHidingSpotsInRadius )
            , ( bp::arg("pos"), bp::arg("radius"), bp::arg("unit")=bp::object(), bp::arg("sort")=(bool)(true), bp::arg("sortpos")=bp::object() ) );
    
    }

    { //::GetNavAreaAt
    
        typedef int ( *GetNavAreaAt_function_type )( ::Vector const &,float );
        
        bp::def( 
            "GetNavAreaAt"
            , GetNavAreaAt_function_type( &::GetNavAreaAt )
            , ( bp::arg("pos"), bp::arg("beneathlimit")=1.2e+2f ) );
    
    }

    { //::GetNavAreasAtBB
    
        typedef ::boost::python::list ( *GetNavAreasAtBB_function_type )( ::Vector const &,::Vector const & );
        
        bp::def( 
            "GetNavAreasAtBB"
            , GetNavAreasAtBB_function_type( &::GetNavAreasAtBB )
            , ( bp::arg("mins"), bp::arg("maxs") ) );
    
    }

    { //::IsAreaBlocked
    
        typedef bool ( *IsAreaBlocked_function_type )( int );
        
        bp::def( 
            "IsAreaBlocked"
            , IsAreaBlocked_function_type( &::IsAreaBlocked )
            , ( bp::arg("areaid") ) );
    
    }

    { //::IsBBCoveredByNavAreas
    
        typedef bool ( *IsBBCoveredByNavAreas_function_type )( ::Vector const &,::Vector const &,float,bool,float );
        
        bp::def( 
            "IsBBCoveredByNavAreas"
            , IsBBCoveredByNavAreas_function_type( &::IsBBCoveredByNavAreas )
            , ( bp::arg("mins"), bp::arg("maxs"), bp::arg("tolerance")=1.00000001490116119384765625e-1f, bp::arg("requireisflat")=(bool)(true), bp::arg("flattol")=6.99999988079071044921875e-1f ) );
    
    }

    { //::NavMeshAvailable
    
        typedef bool ( *NavMeshAvailable_function_type )(  );
        
        bp::def( 
            "NavMeshAvailable"
            , NavMeshAvailable_function_type( &::NavMeshAvailable ) );
    
    }

    { //::NavMeshGetPathDistance
    
        typedef float ( *NavMeshGetPathDistance_function_type )( ::Vector &,::Vector &,bool,float,bool,::C_UnitBase * );
        
        bp::def( 
            "NavMeshGetPathDistance"
            , NavMeshGetPathDistance_function_type( &::NavMeshGetPathDistance )
            , ( bp::arg("start"), bp::arg("goal"), bp::arg("anyz")=(bool)(false), bp::arg("maxdist")=1.0e+4f, bp::arg("notolerance")=(bool)(false), bp::arg("unit")=bp::object() ) );
    
    }

    { //::NavMeshGetPositionNearestNavArea
    
        typedef ::Vector ( *NavMeshGetPositionNearestNavArea_function_type )( ::Vector const &,float,bool );
        
        bp::def( 
            "NavMeshGetPositionNearestNavArea"
            , NavMeshGetPositionNearestNavArea_function_type( &::NavMeshGetPositionNearestNavArea )
            , ( bp::arg("pos"), bp::arg("beneathlimit")=1.2e+2f, bp::arg("checkblocked")=(bool)(true) ) );
    
    }

    { //::NavMeshTestHasArea
    
        typedef bool ( *NavMeshTestHasArea_function_type )( ::Vector &,float );
        
        bp::def( 
            "NavMeshTestHasArea"
            , NavMeshTestHasArea_function_type( &::NavMeshTestHasArea )
            , ( bp::arg("pos"), bp::arg("beneathLimt")=1.2e+2f ) );
    
    }

    { //::RandomNavAreaPosition
    
        typedef ::Vector ( *RandomNavAreaPosition_function_type )( float,int );
        
        bp::def( 
            "RandomNavAreaPosition"
            , RandomNavAreaPosition_function_type( &::RandomNavAreaPosition )
            , ( bp::arg("minimumarea")=0, bp::arg("maxtries")=(int)(-0x000000001) ) );
    
    }

    { //::RandomNavAreaPositionWithin
    
        typedef ::Vector ( *RandomNavAreaPositionWithin_function_type )( ::Vector const &,::Vector const &,float,int );
        
        bp::def( 
            "RandomNavAreaPositionWithin"
            , RandomNavAreaPositionWithin_function_type( &::RandomNavAreaPositionWithin )
            , ( bp::arg("mins"), bp::arg("maxs"), bp::arg("minimumarea")=0, bp::arg("maxtries")=(int)(-0x000000001) ) );
    
    }

    { //::SetAreasBlocked
    
        typedef void ( *SetAreasBlocked_function_type )( ::boost::python::list,bool,::C_BaseEntity * );
        
        bp::def( 
            "SetAreasBlocked"
            , SetAreasBlocked_function_type( &::SetAreasBlocked )
            , ( bp::arg("areas"), bp::arg("blocked"), bp::arg("pOwner")=bp::object() ) );
    
    }

    { //::SplitAreasAtBB
    
        typedef void ( *SplitAreasAtBB_function_type )( ::Vector const &,::Vector const & );
        
        bp::def( 
            "SplitAreasAtBB"
            , SplitAreasAtBB_function_type( &::SplitAreasAtBB )
            , ( bp::arg("mins"), bp::arg("maxs") ) );
    
    }

    { //::TryMergeSurrounding
    
        typedef bool ( *TryMergeSurrounding_function_type )( int,float );
        
        bp::def( 
            "TryMergeSurrounding"
            , TryMergeSurrounding_function_type( &::TryMergeSurrounding )
            , ( bp::arg("id"), bp::arg("tolerance")=1.1920928955078125e-7f ) );
    
    }
}
#else
#include "cbase.h"

#include "srcpy_navmesh.h"

#include "unit_base_shared.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_navmesh){
    bp::docstring_options doc_options( true, true, false );

    { //::CreateHidingSpot
    
        typedef int ( *CreateHidingSpot_function_type )( ::Vector const &,bool,bool );
        
        bp::def( 
            "CreateHidingSpot"
            , CreateHidingSpot_function_type( &::CreateHidingSpot )
            , ( bp::arg("pos"), bp::arg("notsaved")=(bool)(false), bp::arg("checkground")=(bool)(true) ) );
    
    }

    { //::CreateNavArea
    
        typedef int ( *CreateNavArea_function_type )( ::Vector const &,::Vector const & );
        
        bp::def( 
            "CreateNavArea"
            , CreateNavArea_function_type( &::CreateNavArea )
            , ( bp::arg("corner"), bp::arg("otherCorner") ) );
    
    }

    { //::CreateNavAreaByCorners
    
        typedef int ( *CreateNavAreaByCorners_function_type )( ::Vector const &,::Vector const &,::Vector const &,::Vector const & );
        
        bp::def( 
            "CreateNavAreaByCorners"
            , CreateNavAreaByCorners_function_type( &::CreateNavAreaByCorners )
            , ( bp::arg("nwcorner"), bp::arg("necorner"), bp::arg("secorner"), bp::arg("swcorner") ) );
    
    }

    { //::DestroyAllNavAreas
    
        typedef void ( *DestroyAllNavAreas_function_type )(  );
        
        bp::def( 
            "DestroyAllNavAreas"
            , DestroyAllNavAreas_function_type( &::DestroyAllNavAreas ) );
    
    }

    { //::DestroyHidingSpot
    
        typedef bool ( *DestroyHidingSpot_function_type )( ::Vector const &,float,int,unsigned int );
        
        bp::def( 
            "DestroyHidingSpot"
            , DestroyHidingSpot_function_type( &::DestroyHidingSpot )
            , ( bp::arg("pos"), bp::arg("tolerance"), bp::arg("num")=(int)(1), bp::arg("excludeFlags")=(unsigned int)(0) ) );
    
    }

    { //::DestroyHidingSpotByID
    
        typedef bool ( *DestroyHidingSpotByID_function_type )( ::Vector const &,unsigned int );
        
        bp::def( 
            "DestroyHidingSpotByID"
            , DestroyHidingSpotByID_function_type( &::DestroyHidingSpotByID )
            , ( bp::arg("pos"), bp::arg("hidespotid") ) );
    
    }

    { //::DestroyNavArea
    
        typedef void ( *DestroyNavArea_function_type )( unsigned int );
        
        bp::def( 
            "DestroyNavArea"
            , DestroyNavArea_function_type( &::DestroyNavArea )
            , ( bp::arg("id") ) );
    
    }

    { //::GetActiveNavMesh
    
        typedef int ( *GetActiveNavMesh_function_type )(  );
        
        bp::def( 
            "GetActiveNavMesh"
            , GetActiveNavMesh_function_type( &::GetActiveNavMesh ) );
    
    }

    { //::GetEditingCursor
    
        typedef ::Vector ( *GetEditingCursor_function_type )(  );
        
        bp::def( 
            "GetEditingCursor"
            , GetEditingCursor_function_type( &::GetEditingCursor ) );
    
    }

    { //::GetHidingSpotsInRadius
    
        typedef ::boost::python::list ( *GetHidingSpotsInRadius_function_type )( ::Vector const &,float,::CUnitBase *,bool,::Vector const * );
        
        bp::def( 
            "GetHidingSpotsInRadius"
            , GetHidingSpotsInRadius_function_type( &::GetHidingSpotsInRadius )
            , ( bp::arg("pos"), bp::arg("radius"), bp::arg("unit")=bp::object(), bp::arg("sort")=(bool)(true), bp::arg("sortpos")=bp::object() ) );
    
    }

    { //::GetNavAreaAt
    
        typedef int ( *GetNavAreaAt_function_type )( ::Vector const &,float );
        
        bp::def( 
            "GetNavAreaAt"
            , GetNavAreaAt_function_type( &::GetNavAreaAt )
            , ( bp::arg("pos"), bp::arg("beneathlimit")=1.2e+2f ) );
    
    }

    { //::GetNavAreasAtBB
    
        typedef ::boost::python::list ( *GetNavAreasAtBB_function_type )( ::Vector const &,::Vector const & );
        
        bp::def( 
            "GetNavAreasAtBB"
            , GetNavAreasAtBB_function_type( &::GetNavAreasAtBB )
            , ( bp::arg("mins"), bp::arg("maxs") ) );
    
    }

    { //::IsAreaBlocked
    
        typedef bool ( *IsAreaBlocked_function_type )( int );
        
        bp::def( 
            "IsAreaBlocked"
            , IsAreaBlocked_function_type( &::IsAreaBlocked )
            , ( bp::arg("areaid") ) );
    
    }

    { //::IsBBCoveredByNavAreas
    
        typedef bool ( *IsBBCoveredByNavAreas_function_type )( ::Vector const &,::Vector const &,float,bool,float );
        
        bp::def( 
            "IsBBCoveredByNavAreas"
            , IsBBCoveredByNavAreas_function_type( &::IsBBCoveredByNavAreas )
            , ( bp::arg("mins"), bp::arg("maxs"), bp::arg("tolerance")=1.00000001490116119384765625e-1f, bp::arg("requireisflat")=(bool)(true), bp::arg("flattol")=6.99999988079071044921875e-1f ) );
    
    }

    { //::NavMeshAvailable
    
        typedef bool ( *NavMeshAvailable_function_type )(  );
        
        bp::def( 
            "NavMeshAvailable"
            , NavMeshAvailable_function_type( &::NavMeshAvailable ) );
    
    }

    { //::NavMeshGetPathDistance
    
        typedef float ( *NavMeshGetPathDistance_function_type )( ::Vector &,::Vector &,bool,float,bool,::CUnitBase * );
        
        bp::def( 
            "NavMeshGetPathDistance"
            , NavMeshGetPathDistance_function_type( &::NavMeshGetPathDistance )
            , ( bp::arg("start"), bp::arg("goal"), bp::arg("anyz")=(bool)(false), bp::arg("maxdist")=1.0e+4f, bp::arg("notolerance")=(bool)(false), bp::arg("unit")=bp::object() ) );
    
    }

    { //::NavMeshGetPositionNearestNavArea
    
        typedef ::Vector ( *NavMeshGetPositionNearestNavArea_function_type )( ::Vector const &,float,bool );
        
        bp::def( 
            "NavMeshGetPositionNearestNavArea"
            , NavMeshGetPositionNearestNavArea_function_type( &::NavMeshGetPositionNearestNavArea )
            , ( bp::arg("pos"), bp::arg("beneathlimit")=1.2e+2f, bp::arg("checkblocked")=(bool)(true) ) );
    
    }

    { //::NavMeshTestHasArea
    
        typedef bool ( *NavMeshTestHasArea_function_type )( ::Vector &,float );
        
        bp::def( 
            "NavMeshTestHasArea"
            , NavMeshTestHasArea_function_type( &::NavMeshTestHasArea )
            , ( bp::arg("pos"), bp::arg("beneathLimt")=1.2e+2f ) );
    
    }

    { //::RandomNavAreaPosition
    
        typedef ::Vector ( *RandomNavAreaPosition_function_type )( float,int );
        
        bp::def( 
            "RandomNavAreaPosition"
            , RandomNavAreaPosition_function_type( &::RandomNavAreaPosition )
            , ( bp::arg("minimumarea")=0, bp::arg("maxtries")=(int)(-0x000000001) ) );
    
    }

    { //::RandomNavAreaPositionWithin
    
        typedef ::Vector ( *RandomNavAreaPositionWithin_function_type )( ::Vector const &,::Vector const &,float,int );
        
        bp::def( 
            "RandomNavAreaPositionWithin"
            , RandomNavAreaPositionWithin_function_type( &::RandomNavAreaPositionWithin )
            , ( bp::arg("mins"), bp::arg("maxs"), bp::arg("minimumarea")=0, bp::arg("maxtries")=(int)(-0x000000001) ) );
    
    }

    { //::SetAreasBlocked
    
        typedef void ( *SetAreasBlocked_function_type )( ::boost::python::list,bool,::CBaseEntity * );
        
        bp::def( 
            "SetAreasBlocked"
            , SetAreasBlocked_function_type( &::SetAreasBlocked )
            , ( bp::arg("areas"), bp::arg("blocked"), bp::arg("pOwner")=bp::object() ) );
    
    }

    { //::SplitAreasAtBB
    
        typedef void ( *SplitAreasAtBB_function_type )( ::Vector const &,::Vector const & );
        
        bp::def( 
            "SplitAreasAtBB"
            , SplitAreasAtBB_function_type( &::SplitAreasAtBB )
            , ( bp::arg("mins"), bp::arg("maxs") ) );
    
    }

    { //::TryMergeSurrounding
    
        typedef bool ( *TryMergeSurrounding_function_type )( int,float );
        
        bp::def( 
            "TryMergeSurrounding"
            , TryMergeSurrounding_function_type( &::TryMergeSurrounding )
            , ( bp::arg("id"), bp::arg("tolerance")=1.1920928955078125e-7f ) );
    
    }
}
#endif

