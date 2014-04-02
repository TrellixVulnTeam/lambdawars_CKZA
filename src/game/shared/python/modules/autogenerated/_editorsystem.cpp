// This file has been generated by Py++.

#include "cbase.h"
#ifdef CLIENT_DLL
#include "cbase.h"

#include "editor/editorsystem.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

struct CEditorSystem_wrapper : CEditorSystem, bp::wrapper< CEditorSystem > {

    virtual bool Init(  ) {
        PY_OVERRIDE_CHECK( CEditorSystem, Init )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, Init )
        bp::override func_Init = this->get_override( "Init" );
        if( func_Init.ptr() != Py_None )
            try {
                return func_Init(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->CEditorSystem::Init(  );
            }
        else
            return this->CEditorSystem::Init(  );
    }
    
    bool default_Init(  ) {
        return CEditorSystem::Init( );
    }

    virtual void LevelShutdownPreEntity(  ) {
        PY_OVERRIDE_CHECK( CEditorSystem, LevelShutdownPreEntity )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, LevelShutdownPreEntity )
        bp::override func_LevelShutdownPreEntity = this->get_override( "LevelShutdownPreEntity" );
        if( func_LevelShutdownPreEntity.ptr() != Py_None )
            try {
                func_LevelShutdownPreEntity(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->CEditorSystem::LevelShutdownPreEntity(  );
            }
        else
            this->CEditorSystem::LevelShutdownPreEntity(  );
    }
    
    void default_LevelShutdownPreEntity(  ) {
        CEditorSystem::LevelShutdownPreEntity( );
    }

    virtual void Shutdown(  ) {
        PY_OVERRIDE_CHECK( CEditorSystem, Shutdown )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, Shutdown )
        bp::override func_Shutdown = this->get_override( "Shutdown" );
        if( func_Shutdown.ptr() != Py_None )
            try {
                func_Shutdown(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->CEditorSystem::Shutdown(  );
            }
        else
            this->CEditorSystem::Shutdown(  );
    }
    
    void default_Shutdown(  ) {
        CEditorSystem::Shutdown( );
    }

};

BOOST_PYTHON_MODULE(_editorsystem){
    bp::docstring_options doc_options( true, true, false );

    bp::class_< CEditorSystem_wrapper, boost::noncopyable >( "CEditorSystem", bp::no_init )    
        .def( 
            "ClearLoadedMap"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::ClearLoadedMap ) )    
        .def( 
            "ClearSelection"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::ClearSelection ) )    
        .def( 
            "DoSelect"
            , (void ( ::CEditorSystem::* )( ::C_HL2WarsPlayer * ) )( &::CEditorSystem::DoSelect )
            , ( bp::arg("pPlayer") ) )    
        .def( 
            "GetCurrentVmfPath"
            , (char const * ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::GetCurrentVmfPath ) )    
        .def( 
            "Init"
            , (bool ( ::CEditorSystem::* )(  ) )(&::CEditorSystem::Init)
            , (bool ( CEditorSystem_wrapper::* )(  ) )(&CEditorSystem_wrapper::default_Init) )    
        .def( 
            "IsMapLoaded"
            , (bool ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::IsMapLoaded ) )    
        .def( 
            "LevelShutdownPreEntity"
            , (void ( ::CEditorSystem::* )(  ) )(&::CEditorSystem::LevelShutdownPreEntity)
            , (void ( CEditorSystem_wrapper::* )(  ) )(&CEditorSystem_wrapper::default_LevelShutdownPreEntity) )    
        .def( 
            "LoadCurrentVmf"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::LoadCurrentVmf ) )    
        .def( 
            "RemoveFloraInRadius"
            , (void ( ::CEditorSystem::* )( ::Vector const &,float ) )( &::CEditorSystem::RemoveFloraInRadius )
            , ( bp::arg("vPosition"), bp::arg("fRadius") ) )    
        .def( 
            "Shutdown"
            , (void ( ::CEditorSystem::* )(  ) )(&::CEditorSystem::Shutdown)
            , (void ( CEditorSystem_wrapper::* )(  ) )(&CEditorSystem_wrapper::default_Shutdown) );

    { //::EditorSystem
    
        typedef ::CEditorSystem * ( *EditorSystem_function_type )(  );
        
        bp::def( 
            "EditorSystem"
            , EditorSystem_function_type( &::EditorSystem )
            , bp::return_value_policy< bp::reference_existing_object >() );
    
    }
}
#else
#include "cbase.h"

#include "editor/editorsystem.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

struct CEditorSystem_wrapper : CEditorSystem, bp::wrapper< CEditorSystem > {

    virtual bool Init(  ) {
        PY_OVERRIDE_CHECK( CEditorSystem, Init )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, Init )
        bp::override func_Init = this->get_override( "Init" );
        if( func_Init.ptr() != Py_None )
            try {
                return func_Init(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->CEditorSystem::Init(  );
            }
        else
            return this->CEditorSystem::Init(  );
    }
    
    bool default_Init(  ) {
        return CEditorSystem::Init( );
    }

    virtual void LevelShutdownPreEntity(  ) {
        PY_OVERRIDE_CHECK( CEditorSystem, LevelShutdownPreEntity )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, LevelShutdownPreEntity )
        bp::override func_LevelShutdownPreEntity = this->get_override( "LevelShutdownPreEntity" );
        if( func_LevelShutdownPreEntity.ptr() != Py_None )
            try {
                func_LevelShutdownPreEntity(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->CEditorSystem::LevelShutdownPreEntity(  );
            }
        else
            this->CEditorSystem::LevelShutdownPreEntity(  );
    }
    
    void default_LevelShutdownPreEntity(  ) {
        CEditorSystem::LevelShutdownPreEntity( );
    }

    virtual void OnEntityDeleted( ::CBaseEntity * pEntity ) {
        PY_OVERRIDE_CHECK( CEditorSystem, OnEntityDeleted )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, OnEntityDeleted )
        bp::override func_OnEntityDeleted = this->get_override( "OnEntityDeleted" );
        if( func_OnEntityDeleted.ptr() != Py_None )
            try {
                func_OnEntityDeleted( pEntity ? pEntity->GetPyHandle() : boost::python::object() );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->CEditorSystem::OnEntityDeleted( pEntity );
            }
        else
            this->CEditorSystem::OnEntityDeleted( pEntity );
    }
    
    void default_OnEntityDeleted( ::CBaseEntity * pEntity ) {
        CEditorSystem::OnEntityDeleted( pEntity );
    }

    virtual void Shutdown(  ) {
        PY_OVERRIDE_CHECK( CEditorSystem, Shutdown )
        PY_OVERRIDE_LOG( _editorsystem, CEditorSystem, Shutdown )
        bp::override func_Shutdown = this->get_override( "Shutdown" );
        if( func_Shutdown.ptr() != Py_None )
            try {
                func_Shutdown(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->CEditorSystem::Shutdown(  );
            }
        else
            this->CEditorSystem::Shutdown(  );
    }
    
    void default_Shutdown(  ) {
        CEditorSystem::Shutdown( );
    }

};

BOOST_PYTHON_MODULE(_editorsystem){
    bp::docstring_options doc_options( true, true, false );

    bp::class_< CEditorSystem_wrapper, boost::noncopyable >( "CEditorSystem", bp::no_init )    
        .def( 
            "ClearLoadedMap"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::ClearLoadedMap ) )    
        .def( 
            "ClearSelection"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::ClearSelection ) )    
        .def( 
            "DoSelect"
            , (void ( ::CEditorSystem::* )( ::CHL2WarsPlayer * ) )( &::CEditorSystem::DoSelect )
            , ( bp::arg("pPlayer") ) )    
        .def( 
            "GetCurrentVmfPath"
            , (char const * ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::GetCurrentVmfPath ) )    
        .def( 
            "Init"
            , (bool ( ::CEditorSystem::* )(  ) )(&::CEditorSystem::Init)
            , (bool ( CEditorSystem_wrapper::* )(  ) )(&CEditorSystem_wrapper::default_Init) )    
        .def( 
            "IsMapLoaded"
            , (bool ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::IsMapLoaded ) )    
        .def( 
            "LevelShutdownPreEntity"
            , (void ( ::CEditorSystem::* )(  ) )(&::CEditorSystem::LevelShutdownPreEntity)
            , (void ( CEditorSystem_wrapper::* )(  ) )(&CEditorSystem_wrapper::default_LevelShutdownPreEntity) )    
        .def( 
            "LoadCurrentVmf"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::LoadCurrentVmf ) )    
        .def( 
            "OnEntityDeleted"
            , (void ( ::CEditorSystem::* )( ::CBaseEntity * ) )(&::CEditorSystem::OnEntityDeleted)
            , (void ( CEditorSystem_wrapper::* )( ::CBaseEntity * ) )(&CEditorSystem_wrapper::default_OnEntityDeleted)
            , ( bp::arg("pEntity") ) )    
        .def( 
            "RemoveFloraInRadius"
            , (void ( ::CEditorSystem::* )( ::Vector const &,float ) )( &::CEditorSystem::RemoveFloraInRadius )
            , ( bp::arg("vPosition"), bp::arg("fRadius") ) )    
        .def( 
            "SaveCurrentVmf"
            , (void ( ::CEditorSystem::* )(  ) )( &::CEditorSystem::SaveCurrentVmf ) )    
        .def( 
            "Shutdown"
            , (void ( ::CEditorSystem::* )(  ) )(&::CEditorSystem::Shutdown)
            , (void ( CEditorSystem_wrapper::* )(  ) )(&CEditorSystem_wrapper::default_Shutdown) );

    { //::EditorSystem
    
        typedef ::CEditorSystem * ( *EditorSystem_function_type )(  );
        
        bp::def( 
            "EditorSystem"
            , EditorSystem_function_type( &::EditorSystem )
            , bp::return_value_policy< bp::reference_existing_object >() );
    
    }
}
#endif

