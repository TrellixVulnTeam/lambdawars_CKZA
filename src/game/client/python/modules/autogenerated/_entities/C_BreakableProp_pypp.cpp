// This file has been generated by Py++.

#include "cbase.h"
// This file has been generated by Py++.

#include "cbase.h"
#include "npcevent.h"
#include "srcpy_entities.h"
#include "bone_setup.h"
#include "baseprojectile.h"
#include "basegrenade_shared.h"
#include "takedamageinfo.h"
#include "c_ai_basenpc.h"
#include "c_basetoggle.h"
#include "c_triggers.h"
#include "soundinfo.h"
#include "saverestore.h"
#include "saverestoretypes.h"
#include "vcollide_parse.h"
#include "iclientvehicle.h"
#include "steam/steamclientpublic.h"
#include "view_shared.h"
#include "c_playerresource.h"
#include "c_breakableprop.h"
#include "nav_area.h"
#include "Sprite.h"
#include "SpriteTrail.h"
#include "c_smoke_trail.h"
#include "beam_shared.h"
#include "c_hl2wars_player.h"
#include "unit_base_shared.h"
#include "wars_func_unit.h"
#include "hl2wars_player_shared.h"
#include "wars_mapboundary.h"
#include "srcpy_util.h"
#include "c_wars_weapon.h"
#include "wars_flora.h"
#include "unit_baseanimstate.h"
#include "srcpy.h"
#include "tier0/memdbgon.h"
#include "C_BreakableProp_pypp.hpp"

namespace bp = boost::python;

struct C_BreakableProp_wrapper : C_BreakableProp, bp::wrapper< C_BreakableProp > {

    C_BreakableProp_wrapper( )
    : C_BreakableProp( )
      , bp::wrapper< C_BreakableProp >(){
        // null constructor
    
    }

    virtual void OnDataChanged( ::DataUpdateType_t type ) {
        PY_OVERRIDE_CHECK( C_BreakableProp, OnDataChanged )
        PY_OVERRIDE_LOG( _entities, C_BreakableProp, OnDataChanged )
        bp::override func_OnDataChanged = this->get_override( "OnDataChanged" );
        if( func_OnDataChanged.ptr() != Py_None )
            try {
                func_OnDataChanged( type );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BreakableProp::OnDataChanged( type );
            }
        else
            this->C_BreakableProp::OnDataChanged( type );
    }
    
    void default_OnDataChanged( ::DataUpdateType_t type ) {
        C_BreakableProp::OnDataChanged( type );
    }

    virtual void Activate(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, Activate )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, Activate )
        bp::override func_Activate = this->get_override( "Activate" );
        if( func_Activate.ptr() != Py_None )
            try {
                func_Activate(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::Activate(  );
            }
        else
            this->C_BaseEntity::Activate(  );
    }
    
    void default_Activate(  ) {
        C_BaseEntity::Activate( );
    }

    void AddToEntityList( ::entity_list_ids_t listId ){
        C_BaseEntity::AddToEntityList( listId );
    }

    virtual void ClientThink(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, ClientThink )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, ClientThink )
        bp::override func_ClientThink = this->get_override( "ClientThink" );
        if( func_ClientThink.ptr() != Py_None )
            try {
                func_ClientThink(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::ClientThink(  );
            }
        else
            this->C_BaseEntity::ClientThink(  );
    }
    
    void default_ClientThink(  ) {
        C_BaseEntity::ClientThink( );
    }

    virtual void ComputeWorldSpaceSurroundingBox( ::Vector * pVecWorldMins, ::Vector * pVecWorldMaxs ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, ComputeWorldSpaceSurroundingBox )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, ComputeWorldSpaceSurroundingBox )
        bp::override func_ComputeWorldSpaceSurroundingBox = this->get_override( "ComputeWorldSpaceSurroundingBox" );
        if( func_ComputeWorldSpaceSurroundingBox.ptr() != Py_None )
            try {
                func_ComputeWorldSpaceSurroundingBox( boost::python::ptr(pVecWorldMins), boost::python::ptr(pVecWorldMaxs) );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::ComputeWorldSpaceSurroundingBox( pVecWorldMins, pVecWorldMaxs );
            }
        else
            this->C_BaseEntity::ComputeWorldSpaceSurroundingBox( pVecWorldMins, pVecWorldMaxs );
    }
    
    void default_ComputeWorldSpaceSurroundingBox( ::Vector * pVecWorldMins, ::Vector * pVecWorldMaxs ) {
        C_BaseEntity::ComputeWorldSpaceSurroundingBox( pVecWorldMins, pVecWorldMaxs );
    }

    virtual bool CreateVPhysics(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, CreateVPhysics )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, CreateVPhysics )
        bp::override func_CreateVPhysics = this->get_override( "CreateVPhysics" );
        if( func_CreateVPhysics.ptr() != Py_None )
            try {
                return func_CreateVPhysics(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::CreateVPhysics(  );
            }
        else
            return this->C_BaseEntity::CreateVPhysics(  );
    }
    
    bool default_CreateVPhysics(  ) {
        return C_BaseEntity::CreateVPhysics( );
    }

    virtual void DoImpactEffect( ::trace_t & tr, int nDamageType ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, DoImpactEffect )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, DoImpactEffect )
        bp::override func_DoImpactEffect = this->get_override( "DoImpactEffect" );
        if( func_DoImpactEffect.ptr() != Py_None )
            try {
                func_DoImpactEffect( boost::ref(tr), nDamageType );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::DoImpactEffect( tr, nDamageType );
            }
        else
            this->C_BaseEntity::DoImpactEffect( tr, nDamageType );
    }
    
    void default_DoImpactEffect( ::trace_t & tr, int nDamageType ) {
        C_BaseEntity::DoImpactEffect( tr, nDamageType );
    }

    virtual void EndTouch( ::C_BaseEntity * pOther ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, EndTouch )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, EndTouch )
        bp::override func_EndTouch = this->get_override( "EndTouch" );
        if( func_EndTouch.ptr() != Py_None )
            try {
                func_EndTouch( pOther ? pOther->GetPyHandle() : boost::python::object() );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::EndTouch( pOther );
            }
        else
            this->C_BaseEntity::EndTouch( pOther );
    }
    
    void default_EndTouch( ::C_BaseEntity * pOther ) {
        C_BaseEntity::EndTouch( pOther );
    }

    virtual ::CollideType_t GetCollideType(  ) {
        PY_OVERRIDE_CHECK( C_BaseAnimating, GetCollideType )
        PY_OVERRIDE_LOG( _entities, C_BaseAnimating, GetCollideType )
        bp::override func_GetCollideType = this->get_override( "GetCollideType" );
        if( func_GetCollideType.ptr() != Py_None )
            try {
                return func_GetCollideType(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseAnimating::GetCollideType(  );
            }
        else
            return this->C_BaseAnimating::GetCollideType(  );
    }
    
    ::CollideType_t default_GetCollideType(  ) {
        return C_BaseAnimating::GetCollideType( );
    }

    virtual ::IMouse * GetIMouse(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, GetIMouse )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, GetIMouse )
        bp::override func_GetIMouse = this->get_override( "GetIMouse" );
        if( func_GetIMouse.ptr() != Py_None )
            try {
                return func_GetIMouse(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::GetIMouse(  );
            }
        else
            return this->C_BaseEntity::GetIMouse(  );
    }
    
    ::IMouse * default_GetIMouse(  ) {
        return C_BaseEntity::GetIMouse( );
    }

    virtual char const * GetTracerType(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, GetTracerType )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, GetTracerType )
        bp::override func_GetTracerType = this->get_override( "GetTracerType" );
        if( func_GetTracerType.ptr() != Py_None )
            try {
                return func_GetTracerType(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::GetTracerType(  );
            }
        else
            return this->C_BaseEntity::GetTracerType(  );
    }
    
    char const * default_GetTracerType(  ) {
        return C_BaseEntity::GetTracerType( );
    }

    virtual bool KeyValue( char const * szKeyName, char const * szValue ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, KeyValue )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, KeyValue )
        bp::override func_KeyValue = this->get_override( "KeyValue" );
        if( func_KeyValue.ptr() != Py_None )
            try {
                return func_KeyValue( szKeyName, szValue );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::KeyValue( szKeyName, szValue );
            }
        else
            return this->C_BaseEntity::KeyValue( szKeyName, szValue );
    }
    
    bool default_KeyValue( char const * szKeyName, char const * szValue ) {
        return C_BaseEntity::KeyValue( szKeyName, szValue );
    }

    virtual bool KeyValue( char const * szKeyName, float flValue ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, KeyValue )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, KeyValue )
        bp::override func_KeyValue = this->get_override( "KeyValue" );
        if( func_KeyValue.ptr() != Py_None )
            try {
                return func_KeyValue( szKeyName, flValue );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::KeyValue( szKeyName, flValue );
            }
        else
            return this->C_BaseEntity::KeyValue( szKeyName, flValue );
    }
    
    bool default_KeyValue( char const * szKeyName, float flValue ) {
        return C_BaseEntity::KeyValue( szKeyName, flValue );
    }

    virtual bool KeyValue( char const * szKeyName, int nValue ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, KeyValue )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, KeyValue )
        bp::override func_KeyValue = this->get_override( "KeyValue" );
        if( func_KeyValue.ptr() != Py_None )
            try {
                return func_KeyValue( szKeyName, nValue );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::KeyValue( szKeyName, nValue );
            }
        else
            return this->C_BaseEntity::KeyValue( szKeyName, nValue );
    }
    
    bool default_KeyValue( char const * szKeyName, int nValue ) {
        return C_BaseEntity::KeyValue( szKeyName, nValue );
    }

    virtual bool KeyValue( char const * szKeyName, ::Vector const & vecValue ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, KeyValue )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, KeyValue )
        bp::override func_KeyValue = this->get_override( "KeyValue" );
        if( func_KeyValue.ptr() != Py_None )
            try {
                return func_KeyValue( szKeyName, boost::ref(vecValue) );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::KeyValue( szKeyName, vecValue );
            }
        else
            return this->C_BaseEntity::KeyValue( szKeyName, vecValue );
    }
    
    bool default_KeyValue( char const * szKeyName, ::Vector const & vecValue ) {
        return C_BaseEntity::KeyValue( szKeyName, vecValue );
    }

    virtual void MakeTracer( ::Vector const & vecTracerSrc, ::trace_t const & tr, int iTracerType ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, MakeTracer )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, MakeTracer )
        bp::override func_MakeTracer = this->get_override( "MakeTracer" );
        if( func_MakeTracer.ptr() != Py_None )
            try {
                func_MakeTracer( boost::ref(vecTracerSrc), boost::ref(tr), iTracerType );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::MakeTracer( vecTracerSrc, tr, iTracerType );
            }
        else
            this->C_BaseEntity::MakeTracer( vecTracerSrc, tr, iTracerType );
    }
    
    void default_MakeTracer( ::Vector const & vecTracerSrc, ::trace_t const & tr, int iTracerType ) {
        C_BaseEntity::MakeTracer( vecTracerSrc, tr, iTracerType );
    }

    virtual void NotifyShouldTransmit( ::ShouldTransmitState_t state ) {
        PY_OVERRIDE_CHECK( C_BaseAnimating, NotifyShouldTransmit )
        PY_OVERRIDE_LOG( _entities, C_BaseAnimating, NotifyShouldTransmit )
        bp::override func_NotifyShouldTransmit = this->get_override( "NotifyShouldTransmit" );
        if( func_NotifyShouldTransmit.ptr() != Py_None )
            try {
                func_NotifyShouldTransmit( state );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseAnimating::NotifyShouldTransmit( state );
            }
        else
            this->C_BaseAnimating::NotifyShouldTransmit( state );
    }
    
    void default_NotifyShouldTransmit( ::ShouldTransmitState_t state ) {
        C_BaseAnimating::NotifyShouldTransmit( state );
    }

    virtual void OnChangeOwnerNumber( int old_owner_number ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, OnChangeOwnerNumber )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, OnChangeOwnerNumber )
        bp::override func_OnChangeOwnerNumber = this->get_override( "OnChangeOwnerNumber" );
        if( func_OnChangeOwnerNumber.ptr() != Py_None )
            try {
                func_OnChangeOwnerNumber( old_owner_number );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::OnChangeOwnerNumber( old_owner_number );
            }
        else
            this->C_BaseEntity::OnChangeOwnerNumber( old_owner_number );
    }
    
    void default_OnChangeOwnerNumber( int old_owner_number ) {
        C_BaseEntity::OnChangeOwnerNumber( old_owner_number );
    }

    virtual void OnRestore(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, OnRestore )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, OnRestore )
        bp::override func_OnRestore = this->get_override( "OnRestore" );
        if( func_OnRestore.ptr() != Py_None )
            try {
                func_OnRestore(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::OnRestore(  );
            }
        else
            this->C_BaseEntity::OnRestore(  );
    }
    
    void default_OnRestore(  ) {
        C_BaseEntity::OnRestore( );
    }

    virtual void Precache(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, Precache )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, Precache )
        bp::override func_Precache = this->get_override( "Precache" );
        if( func_Precache.ptr() != Py_None )
            try {
                func_Precache(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::Precache(  );
            }
        else
            this->C_BaseEntity::Precache(  );
    }
    
    void default_Precache(  ) {
        C_BaseEntity::Precache( );
    }

    virtual void PyOnNewModel(  ) {
        PY_OVERRIDE_CHECK( C_BaseAnimating, PyOnNewModel )
        PY_OVERRIDE_LOG( _entities, C_BaseAnimating, PyOnNewModel )
        bp::override func_OnNewModel = this->get_override( "OnNewModel" );
        if( func_OnNewModel.ptr() != Py_None )
            try {
                func_OnNewModel(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseAnimating::PyOnNewModel(  );
            }
        else
            this->C_BaseAnimating::PyOnNewModel(  );
    }
    
    void default_OnNewModel(  ) {
        C_BaseAnimating::PyOnNewModel( );
    }

    virtual void PyPostOnNewModel(  ) {
        PY_OVERRIDE_CHECK( C_BaseAnimating, PyPostOnNewModel )
        PY_OVERRIDE_LOG( _entities, C_BaseAnimating, PyPostOnNewModel )
        bp::override func_PostOnNewModel = this->get_override( "PostOnNewModel" );
        if( func_PostOnNewModel.ptr() != Py_None )
            try {
                func_PostOnNewModel(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseAnimating::PyPostOnNewModel(  );
            }
        else
            this->C_BaseAnimating::PyPostOnNewModel(  );
    }
    
    void default_PostOnNewModel(  ) {
        C_BaseAnimating::PyPostOnNewModel( );
    }

    virtual void PyReceiveMessage( ::boost::python::list msg ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, PyReceiveMessage )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, PyReceiveMessage )
        bp::override func_ReceiveMessage = this->get_override( "ReceiveMessage" );
        if( func_ReceiveMessage.ptr() != Py_None )
            try {
                func_ReceiveMessage( msg );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::PyReceiveMessage( msg );
            }
        else
            this->C_BaseEntity::PyReceiveMessage( msg );
    }
    
    void default_ReceiveMessage( ::boost::python::list msg ) {
        C_BaseEntity::PyReceiveMessage( msg );
    }

    void RemoveFromEntityList( ::entity_list_ids_t listId ){
        C_BaseEntity::RemoveFromEntityList( listId );
    }

    virtual int Restore( ::IRestore & restore ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, Restore )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, Restore )
        bp::override func_Restore = this->get_override( "Restore" );
        if( func_Restore.ptr() != Py_None )
            try {
                return func_Restore( boost::ref(restore) );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::Restore( restore );
            }
        else
            return this->C_BaseEntity::Restore( restore );
    }
    
    int default_Restore( ::IRestore & restore ) {
        return C_BaseEntity::Restore( restore );
    }

    virtual bool ShouldDraw(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, ShouldDraw )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, ShouldDraw )
        bp::override func_ShouldDraw = this->get_override( "ShouldDraw" );
        if( func_ShouldDraw.ptr() != Py_None )
            try {
                return func_ShouldDraw(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseEntity::ShouldDraw(  );
            }
        else
            return this->C_BaseEntity::ShouldDraw(  );
    }
    
    bool default_ShouldDraw(  ) {
        return C_BaseEntity::ShouldDraw( );
    }

    virtual bool Simulate(  ) {
        PY_OVERRIDE_CHECK( C_BaseAnimating, Simulate )
        PY_OVERRIDE_LOG( _entities, C_BaseAnimating, Simulate )
        bp::override func_Simulate = this->get_override( "Simulate" );
        if( func_Simulate.ptr() != Py_None )
            try {
                return func_Simulate(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->C_BaseAnimating::Simulate(  );
            }
        else
            return this->C_BaseAnimating::Simulate(  );
    }
    
    bool default_Simulate(  ) {
        return C_BaseAnimating::Simulate( );
    }

    virtual void Spawn(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, Spawn )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, Spawn )
        bp::override func_Spawn = this->get_override( "Spawn" );
        if( func_Spawn.ptr() != Py_None )
            try {
                func_Spawn(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::Spawn(  );
            }
        else
            this->C_BaseEntity::Spawn(  );
    }
    
    void default_Spawn(  ) {
        C_BaseEntity::Spawn( );
    }

    virtual void StartTouch( ::C_BaseEntity * pOther ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, StartTouch )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, StartTouch )
        bp::override func_StartTouch = this->get_override( "StartTouch" );
        if( func_StartTouch.ptr() != Py_None )
            try {
                func_StartTouch( pOther ? pOther->GetPyHandle() : boost::python::object() );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::StartTouch( pOther );
            }
        else
            this->C_BaseEntity::StartTouch( pOther );
    }
    
    void default_StartTouch( ::C_BaseEntity * pOther ) {
        C_BaseEntity::StartTouch( pOther );
    }

    virtual void UpdateOnRemove(  ) {
        PY_OVERRIDE_CHECK( C_BaseEntity, UpdateOnRemove )
        PY_OVERRIDE_LOG( _entities, C_BaseEntity, UpdateOnRemove )
        bp::override func_UpdateOnRemove = this->get_override( "UpdateOnRemove" );
        if( func_UpdateOnRemove.ptr() != Py_None )
            try {
                func_UpdateOnRemove(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->C_BaseEntity::UpdateOnRemove(  );
            }
        else
            this->C_BaseEntity::UpdateOnRemove(  );
    }
    
    void default_UpdateOnRemove(  ) {
        C_BaseEntity::UpdateOnRemove( );
    }

    virtual PyObject *GetPySelf() const { return bp::detail::wrapper_base_::get_owner(*this); }

    virtual ClientClass* GetClientClass() {
#if defined(_WIN32)
        if( GetCurrentThreadId() != g_hPythonThreadID )
            return C_BreakableProp::GetClientClass();
#endif // _WIN32
        if( PyObject_HasAttrString(GetPyInstance().ptr(), "pyClientClass") )
        {
            try
            {
                ClientClass *pClientClass = boost::python::extract<ClientClass *>( GetPyInstance().attr("pyClientClass") );
                if( pClientClass )
                    return pClientClass;
            }
            catch( bp::error_already_set & ) 
            {
                PyErr_Print();
            }
        }
        return C_BreakableProp::GetClientClass();
    }

    static int m_lifeState_Get( C_BreakableProp const & inst ) { return inst.m_lifeState; }

    static void m_lifeState_Set( C_BreakableProp & inst, int val ) { inst.m_lifeState = val; }

    static int m_takedamage_Get( C_BreakableProp const & inst ) { return inst.m_takedamage; }

    static void m_takedamage_Set( C_BreakableProp & inst, int val ) { inst.m_takedamage = val; }

    static int m_nSkin_Get( C_BreakableProp const & inst ) { return inst.m_nSkin; }

    static void m_nSkin_Set( C_BreakableProp & inst, int val ) { inst.m_nSkin = val; }

};

void register_C_BreakableProp_class(){

    bp::class_< C_BreakableProp_wrapper, bp::bases< C_BaseAnimating >, boost::noncopyable >( "C_BreakableProp", bp::init< >() )    
        .def( 
            "CopyFadeFrom"
            , (void ( ::C_BreakableProp::* )( ::C_BreakableProp * ) )( &::C_BreakableProp::CopyFadeFrom )
            , ( bp::arg("pSource") ) )    
        .def( 
            "GetNetworkedPreferredPlayerCarryAngles"
            , (::QAngle const & ( ::C_BreakableProp::* )(  ) )( &::C_BreakableProp::GetNetworkedPreferredPlayerCarryAngles )
            , bp::return_value_policy< bp::copy_const_reference >() )    
        .def( 
            "HasPreferredCarryAnglesForPlayer"
            , (bool ( ::C_BreakableProp::* )( ::C_BasePlayer * ) )( &::C_BreakableProp::HasPreferredCarryAnglesForPlayer )
            , ( bp::arg("pPlayer") ) )    
        .def( 
            "IsProp"
            , (bool ( ::C_BreakableProp::* )(  ) const)( &::C_BreakableProp::IsProp ) )    
        .def( 
            "OnDataChanged"
            , (void ( ::C_BreakableProp::* )( ::DataUpdateType_t ) )(&::C_BreakableProp::OnDataChanged)
            , (void ( C_BreakableProp_wrapper::* )( ::DataUpdateType_t ) )(&C_BreakableProp_wrapper::default_OnDataChanged)
            , ( bp::arg("type") ) )    
        .def( 
            "PreferredCarryAngles"
            , (::QAngle ( ::C_BreakableProp::* )(  ) )( &::C_BreakableProp::PreferredCarryAngles ) )    
        .def( 
            "Activate"
            , (void ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::Activate)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_Activate) )    
        .def( 
            "AddToEntityList"
            , (void ( C_BreakableProp_wrapper::* )( ::entity_list_ids_t ) )(&C_BreakableProp_wrapper::AddToEntityList)
            , ( bp::arg("listId") ) )    
        .def( 
            "ClientThink"
            , (void ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::ClientThink)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_ClientThink) )    
        .def( 
            "ComputeWorldSpaceSurroundingBox"
            , (void ( ::C_BaseEntity::* )( ::Vector *,::Vector * ) )(&::C_BaseEntity::ComputeWorldSpaceSurroundingBox)
            , (void ( C_BreakableProp_wrapper::* )( ::Vector *,::Vector * ) )(&C_BreakableProp_wrapper::default_ComputeWorldSpaceSurroundingBox)
            , ( bp::arg("pVecWorldMins"), bp::arg("pVecWorldMaxs") ) )    
        .def( 
            "CreateVPhysics"
            , (bool ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::CreateVPhysics)
            , (bool ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_CreateVPhysics) )    
        .def( 
            "DoImpactEffect"
            , (void ( ::C_BaseEntity::* )( ::trace_t &,int ) )(&::C_BaseEntity::DoImpactEffect)
            , (void ( C_BreakableProp_wrapper::* )( ::trace_t &,int ) )(&C_BreakableProp_wrapper::default_DoImpactEffect)
            , ( bp::arg("tr"), bp::arg("nDamageType") ) )    
        .def( 
            "EndTouch"
            , (void ( ::C_BaseEntity::* )( ::C_BaseEntity * ) )(&::C_BaseEntity::EndTouch)
            , (void ( C_BreakableProp_wrapper::* )( ::C_BaseEntity * ) )(&C_BreakableProp_wrapper::default_EndTouch)
            , ( bp::arg("pOther") ) )    
        .def( 
            "GetCollideType"
            , (::CollideType_t ( ::C_BaseAnimating::* )(  ) )(&::C_BaseAnimating::GetCollideType)
            , (::CollideType_t ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_GetCollideType) )    
        .def( 
            "GetIMouse"
            , (::IMouse * ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::GetIMouse)
            , (::IMouse * ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_GetIMouse)
            , bp::return_value_policy< bp::return_by_value >() )    
        .def( 
            "GetTracerType"
            , (char const * ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::GetTracerType)
            , (char const * ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_GetTracerType) )    
        .def( 
            "KeyValue"
            , (bool ( ::C_BaseEntity::* )( char const *,char const * ) )(&::C_BaseEntity::KeyValue)
            , (bool ( C_BreakableProp_wrapper::* )( char const *,char const * ) )(&C_BreakableProp_wrapper::default_KeyValue)
            , ( bp::arg("szKeyName"), bp::arg("szValue") ) )    
        .def( 
            "KeyValue"
            , (bool ( ::C_BaseEntity::* )( char const *,float ) )(&::C_BaseEntity::KeyValue)
            , (bool ( C_BreakableProp_wrapper::* )( char const *,float ) )(&C_BreakableProp_wrapper::default_KeyValue)
            , ( bp::arg("szKeyName"), bp::arg("flValue") ) )    
        .def( 
            "KeyValue"
            , (bool ( ::C_BaseEntity::* )( char const *,int ) )(&::C_BaseEntity::KeyValue)
            , (bool ( C_BreakableProp_wrapper::* )( char const *,int ) )(&C_BreakableProp_wrapper::default_KeyValue)
            , ( bp::arg("szKeyName"), bp::arg("nValue") ) )    
        .def( 
            "KeyValue"
            , (bool ( ::C_BaseEntity::* )( char const *,::Vector const & ) )(&::C_BaseEntity::KeyValue)
            , (bool ( C_BreakableProp_wrapper::* )( char const *,::Vector const & ) )(&C_BreakableProp_wrapper::default_KeyValue)
            , ( bp::arg("szKeyName"), bp::arg("vecValue") ) )    
        .def( 
            "MakeTracer"
            , (void ( ::C_BaseEntity::* )( ::Vector const &,::trace_t const &,int ) )(&::C_BaseEntity::MakeTracer)
            , (void ( C_BreakableProp_wrapper::* )( ::Vector const &,::trace_t const &,int ) )(&C_BreakableProp_wrapper::default_MakeTracer)
            , ( bp::arg("vecTracerSrc"), bp::arg("tr"), bp::arg("iTracerType") ) )    
        .def( 
            "NotifyShouldTransmit"
            , (void ( ::C_BaseAnimating::* )( ::ShouldTransmitState_t ) )(&::C_BaseAnimating::NotifyShouldTransmit)
            , (void ( C_BreakableProp_wrapper::* )( ::ShouldTransmitState_t ) )(&C_BreakableProp_wrapper::default_NotifyShouldTransmit)
            , ( bp::arg("state") ) )    
        .def( 
            "OnChangeOwnerNumber"
            , (void ( ::C_BaseEntity::* )( int ) )(&::C_BaseEntity::OnChangeOwnerNumber)
            , (void ( C_BreakableProp_wrapper::* )( int ) )(&C_BreakableProp_wrapper::default_OnChangeOwnerNumber)
            , ( bp::arg("old_owner_number") ) )    
        .def( 
            "OnRestore"
            , (void ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::OnRestore)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_OnRestore) )    
        .def( 
            "Precache"
            , (void ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::Precache)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_Precache) )    
        .def( 
            "OnNewModel"
            , (void ( ::C_BaseAnimating::* )(  ) )(&::C_BaseAnimating::PyOnNewModel)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_OnNewModel) )    
        .def( 
            "PostOnNewModel"
            , (void ( ::C_BaseAnimating::* )(  ) )(&::C_BaseAnimating::PyPostOnNewModel)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_PostOnNewModel) )    
        .def( 
            "ReceiveMessage"
            , (void ( ::C_BaseEntity::* )( ::boost::python::list ) )(&::C_BaseEntity::PyReceiveMessage)
            , (void ( C_BreakableProp_wrapper::* )( ::boost::python::list ) )(&C_BreakableProp_wrapper::default_ReceiveMessage)
            , ( bp::arg("msg") ) )    
        .def( 
            "RemoveFromEntityList"
            , (void ( C_BreakableProp_wrapper::* )( ::entity_list_ids_t ) )(&C_BreakableProp_wrapper::RemoveFromEntityList)
            , ( bp::arg("listId") ) )    
        .def( 
            "Restore"
            , (int ( ::C_BaseEntity::* )( ::IRestore & ) )(&::C_BaseEntity::Restore)
            , (int ( C_BreakableProp_wrapper::* )( ::IRestore & ) )(&C_BreakableProp_wrapper::default_Restore)
            , ( bp::arg("restore") ) )    
        .def( 
            "ShouldDraw"
            , (bool ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::ShouldDraw)
            , (bool ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_ShouldDraw) )    
        .def( 
            "Simulate"
            , (bool ( ::C_BaseAnimating::* )(  ) )(&::C_BaseAnimating::Simulate)
            , (bool ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_Simulate) )    
        .def( 
            "Spawn"
            , (void ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::Spawn)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_Spawn) )    
        .def( 
            "StartTouch"
            , (void ( ::C_BaseEntity::* )( ::C_BaseEntity * ) )(&::C_BaseEntity::StartTouch)
            , (void ( C_BreakableProp_wrapper::* )( ::C_BaseEntity * ) )(&C_BreakableProp_wrapper::default_StartTouch)
            , ( bp::arg("pOther") ) )    
        .def( 
            "UpdateOnRemove"
            , (void ( ::C_BaseEntity::* )(  ) )(&::C_BaseEntity::UpdateOnRemove)
            , (void ( C_BreakableProp_wrapper::* )(  ) )(&C_BreakableProp_wrapper::default_UpdateOnRemove) )    
        .add_property( "lifestate", &C_BreakableProp_wrapper::m_lifeState_Get, &C_BreakableProp_wrapper::m_lifeState_Set )    
        .add_property( "takedamage", &C_BreakableProp_wrapper::m_takedamage_Get, &C_BreakableProp_wrapper::m_takedamage_Set )    
        .add_property( "skin", &C_BreakableProp_wrapper::m_nSkin_Get, &C_BreakableProp_wrapper::m_nSkin_Set );

}

