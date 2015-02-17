// This file has been generated by Py++.

#include "cbase.h"
#ifdef CLIENT_DLL
#include "cbase.h"

#include "srcpy_tests.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_srctests){
    bp::docstring_options doc_options( true, true, false );

    { //::SrcPyTest_EntityArg
    
        typedef bool ( *SrcPyTest_EntityArg_function_type )( ::C_BaseEntity * );
        
        bp::def( 
            "SrcPyTest_EntityArg"
            , SrcPyTest_EntityArg_function_type( &::SrcPyTest_EntityArg )
            , ( bp::arg("pEntity") ) );
    
    }

    { //::SrcPyTest_ExtractEntityArg
    
        typedef bool ( *SrcPyTest_ExtractEntityArg_function_type )( ::boost::python::api::object );
        
        bp::def( 
            "SrcPyTest_ExtractEntityArg"
            , SrcPyTest_ExtractEntityArg_function_type( &::SrcPyTest_ExtractEntityArg )
            , ( bp::arg("entity") ) );
    
    }
}
#else
#include "cbase.h"

#include "srcpy_tests.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_srctests){
    bp::docstring_options doc_options( true, true, false );

    { //::SrcPyTest_EntityArg
    
        typedef bool ( *SrcPyTest_EntityArg_function_type )( ::CBaseEntity * );
        
        bp::def( 
            "SrcPyTest_EntityArg"
            , SrcPyTest_EntityArg_function_type( &::SrcPyTest_EntityArg )
            , ( bp::arg("pEntity") ) );
    
    }

    { //::SrcPyTest_ExtractEntityArg
    
        typedef bool ( *SrcPyTest_ExtractEntityArg_function_type )( ::boost::python::api::object );
        
        bp::def( 
            "SrcPyTest_ExtractEntityArg"
            , SrcPyTest_ExtractEntityArg_function_type( &::SrcPyTest_ExtractEntityArg )
            , ( bp::arg("entity") ) );
    
    }
}
#endif

