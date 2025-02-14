// This file has been generated by Py++.

#include "cbase.h"



#include "cbase.h"

#include "src_cef.h"

#include "src_cef_browser.h"

#include "src_cef_python.h"

#include "include/cef_v8.h"

#include "include/cef_process_message.h"

#include "src_cef_js.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

struct SrcCefBrowser_wrapper : SrcCefBrowser, bp::wrapper< SrcCefBrowser > {

    SrcCefBrowser_wrapper(char const * name, char const * url="", int renderframerate=30, int wide=0, int tall=0, ::SrcCefNavigationType navigationbehavior=::NT_DEFAULT )
    : SrcCefBrowser( name, url, renderframerate, wide, tall, navigationbehavior )
      , bp::wrapper< SrcCefBrowser >(){
        // constructor
    
    }

    SrcCefBrowser_wrapper(::SrcCefBrowser const & vec )
    : SrcCefBrowser( vec )
      , bp::wrapper< SrcCefBrowser >(){
        // copy constructor
    
    }

    virtual void InvalidateLayout(  ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, InvalidateLayout )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, InvalidateLayout )
        bp::override func_InvalidateLayout = this->get_override( "InvalidateLayout" );
        if( func_InvalidateLayout.ptr() != Py_None )
            try {
                func_InvalidateLayout(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::InvalidateLayout(  );
            }
        else
            this->SrcCefBrowser::InvalidateLayout(  );
    }
    
    void default_InvalidateLayout(  ) {
        SrcCefBrowser::InvalidateLayout( );
    }

    virtual int KeyInput( int down, ::ButtonCode_t keynum, char const * pszCurrentBinding ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, KeyInput )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, KeyInput )
        bp::override func_KeyInput = this->get_override( "KeyInput" );
        if( func_KeyInput.ptr() != Py_None )
            try {
                return func_KeyInput( down, keynum, pszCurrentBinding );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                return this->SrcCefBrowser::KeyInput( down, keynum, pszCurrentBinding );
            }
        else
            return this->SrcCefBrowser::KeyInput( down, keynum, pszCurrentBinding );
    }
    
    int default_KeyInput( int down, ::ButtonCode_t keynum, char const * pszCurrentBinding ) {
        return SrcCefBrowser::KeyInput( down, keynum, pszCurrentBinding );
    }

    virtual void OnAfterCreated(  ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, OnAfterCreated )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, OnAfterCreated )
        bp::override func_OnAfterCreated = this->get_override( "OnAfterCreated" );
        if( func_OnAfterCreated.ptr() != Py_None )
            try {
                func_OnAfterCreated(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::OnAfterCreated(  );
            }
        else
            this->SrcCefBrowser::OnAfterCreated(  );
    }
    
    void default_OnAfterCreated(  ) {
        SrcCefBrowser::OnAfterCreated( );
    }

    virtual void OnContextCreated(  ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, OnContextCreated )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, OnContextCreated )
        bp::override func_OnContextCreated = this->get_override( "OnContextCreated" );
        if( func_OnContextCreated.ptr() != Py_None )
            try {
                func_OnContextCreated(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::OnContextCreated(  );
            }
        else
            this->SrcCefBrowser::OnContextCreated(  );
    }
    
    void default_OnContextCreated(  ) {
        SrcCefBrowser::OnContextCreated( );
    }

    virtual void OnDestroy(  ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, OnDestroy )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, OnDestroy )
        bp::override func_OnDestroy = this->get_override( "OnDestroy" );
        if( func_OnDestroy.ptr() != Py_None )
            try {
                func_OnDestroy(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::OnDestroy(  );
            }
        else
            this->SrcCefBrowser::OnDestroy(  );
    }
    
    void default_OnDestroy(  ) {
        SrcCefBrowser::OnDestroy( );
    }

    virtual void OnLoadingStateChange( bool isLoading, bool canGoBack, bool canGoForward ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, OnLoadingStateChange )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, OnLoadingStateChange )
        bp::override func_OnLoadingStateChange = this->get_override( "OnLoadingStateChange" );
        if( func_OnLoadingStateChange.ptr() != Py_None )
            try {
                func_OnLoadingStateChange( isLoading, canGoBack, canGoForward );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::OnLoadingStateChange( isLoading, canGoBack, canGoForward );
            }
        else
            this->SrcCefBrowser::OnLoadingStateChange( isLoading, canGoBack, canGoForward );
    }
    
    void default_OnLoadingStateChange( bool isLoading, bool canGoBack, bool canGoForward ) {
        SrcCefBrowser::OnLoadingStateChange( isLoading, canGoBack, canGoForward );
    }

    virtual void OnThink(  ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, OnThink )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, OnThink )
        bp::override func_OnThink = this->get_override( "OnThink" );
        if( func_OnThink.ptr() != Py_None )
            try {
                func_OnThink(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::OnThink(  );
            }
        else
            this->SrcCefBrowser::OnThink(  );
    }
    
    void default_OnThink(  ) {
        SrcCefBrowser::OnThink( );
    }

    virtual void PerformLayout(  ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, PerformLayout )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, PerformLayout )
        bp::override func_PerformLayout = this->get_override( "PerformLayout" );
        if( func_PerformLayout.ptr() != Py_None )
            try {
                func_PerformLayout(  );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::PerformLayout(  );
            }
        else
            this->SrcCefBrowser::PerformLayout(  );
    }
    
    void default_PerformLayout(  ) {
        SrcCefBrowser::PerformLayout( );
    }

    virtual void PyOnLoadEnd( ::boost::python::api::object frame, int httpStatusCode ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, PyOnLoadEnd )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, PyOnLoadEnd )
        bp::override func_OnLoadEnd = this->get_override( "OnLoadEnd" );
        if( func_OnLoadEnd.ptr() != Py_None )
            try {
                func_OnLoadEnd( frame, httpStatusCode );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::PyOnLoadEnd( frame, httpStatusCode );
            }
        else
            this->SrcCefBrowser::PyOnLoadEnd( frame, httpStatusCode );
    }
    
    void default_OnLoadEnd( ::boost::python::api::object frame, int httpStatusCode ) {
        SrcCefBrowser::PyOnLoadEnd( frame, httpStatusCode );
    }

    virtual void PyOnLoadError( ::boost::python::api::object frame, int errorCode, ::boost::python::api::object errorText, ::boost::python::api::object failedUrl ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, PyOnLoadError )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, PyOnLoadError )
        bp::override func_OnLoadError = this->get_override( "OnLoadError" );
        if( func_OnLoadError.ptr() != Py_None )
            try {
                func_OnLoadError( frame, errorCode, errorText, failedUrl );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::PyOnLoadError( frame, errorCode, errorText, failedUrl );
            }
        else
            this->SrcCefBrowser::PyOnLoadError( frame, errorCode, errorText, failedUrl );
    }
    
    void default_OnLoadError( ::boost::python::api::object frame, int errorCode, ::boost::python::api::object errorText, ::boost::python::api::object failedUrl ) {
        SrcCefBrowser::PyOnLoadError( frame, errorCode, errorText, failedUrl );
    }

    virtual void PyOnLoadStart( ::boost::python::api::object frame ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, PyOnLoadStart )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, PyOnLoadStart )
        bp::override func_OnLoadStart = this->get_override( "OnLoadStart" );
        if( func_OnLoadStart.ptr() != Py_None )
            try {
                func_OnLoadStart( frame );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::PyOnLoadStart( frame );
            }
        else
            this->SrcCefBrowser::PyOnLoadStart( frame );
    }
    
    void default_OnLoadStart( ::boost::python::api::object frame ) {
        SrcCefBrowser::PyOnLoadStart( frame );
    }

    virtual void PyOnMethodCall( ::boost::python::api::object identifier, ::boost::python::api::object methodargs, ::boost::python::api::object callbackid ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, PyOnMethodCall )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, PyOnMethodCall )
        bp::override func_OnMethodCall = this->get_override( "OnMethodCall" );
        if( func_OnMethodCall.ptr() != Py_None )
            try {
                func_OnMethodCall( identifier, methodargs, callbackid );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::PyOnMethodCall( identifier, methodargs, callbackid );
            }
        else
            this->SrcCefBrowser::PyOnMethodCall( identifier, methodargs, callbackid );
    }
    
    void default_OnMethodCall( ::boost::python::api::object identifier, ::boost::python::api::object methodargs, ::boost::python::api::object callbackid ) {
        SrcCefBrowser::PyOnMethodCall( identifier, methodargs, callbackid );
    }

    virtual void WasHidden( bool hidden ) {
        PY_OVERRIDE_CHECK( SrcCefBrowser, WasHidden )
        PY_OVERRIDE_LOG( _cef, SrcCefBrowser, WasHidden )
        bp::override func_WasHidden = this->get_override( "WasHidden" );
        if( func_WasHidden.ptr() != Py_None )
            try {
                func_WasHidden( hidden );
            } catch(bp::error_already_set &) {
                PyErr_Print();
                this->SrcCefBrowser::WasHidden( hidden );
            }
        else
            this->SrcCefBrowser::WasHidden( hidden );
    }
    
    void default_WasHidden( bool hidden ) {
        SrcCefBrowser::WasHidden( hidden );
    }

};

BOOST_PYTHON_MODULE(_cef){
    bp::docstring_options doc_options( true, true, false );

    bp::enum_< SrcCefNavigationType>("SrcCefNavigationType")
        .value("NT_DEFAULT", NT_DEFAULT)
        .value("NT_PREVENTALL", NT_PREVENTALL)
        .value("NT_ONLYFILEPROT", NT_ONLYFILEPROT)
        .export_values()
        ;

    bp::class_< CCefSystem, boost::noncopyable >( "CCefSystem", bp::no_init )    
        .def( bp::init< >() )    
        .def( 
            "SetFocus"
            , (void ( ::CCefSystem::* )( bool ) )( &::CCefSystem::SetFocus )
            , ( bp::arg("focus") ) );

    { //::PyCefFrame
        typedef bp::class_< PyCefFrame > CefFrame_exposer_t;
        CefFrame_exposer_t CefFrame_exposer = CefFrame_exposer_t( "CefFrame", bp::no_init );
        bp::scope CefFrame_scope( CefFrame_exposer );
        CefFrame_exposer.def( bp::init< CefRefPtr< CefFrame > >(( bp::arg("frame") )) );
        bp::implicitly_convertible< CefRefPtr< CefFrame >, PyCefFrame >();
        { //::PyCefFrame::GetURL
        
            typedef char const * ( ::PyCefFrame::*GetURL_function_type )(  ) ;
            
            CefFrame_exposer.def( 
                "GetURL"
                , GetURL_function_type( &::PyCefFrame::GetURL ) );
        
        }
        { //::PyCefFrame::IsMain
        
            typedef bool ( ::PyCefFrame::*IsMain_function_type )(  ) ;
            
            CefFrame_exposer.def( 
                "IsMain"
                , IsMain_function_type( &::PyCefFrame::IsMain ) );
        
        }
        CefFrame_exposer.def( bp::self != bp::self );
        CefFrame_exposer.def( bp::self == bp::self );
    }

    { //::PyJSObject
        typedef bp::class_< PyJSObject > JSObject_exposer_t;
        JSObject_exposer_t JSObject_exposer = JSObject_exposer_t( "JSObject", bp::no_init );
        bp::scope JSObject_scope( JSObject_exposer );
        JSObject_exposer.def( bp::init< CefRefPtr< JSObject > >(( bp::arg("object") )) );
        bp::implicitly_convertible< CefRefPtr< JSObject >, PyJSObject >();
        { //property "identifier"[fget=::PyJSObject::GetIdentifier]
        
            typedef ::boost::python::api::object ( ::PyJSObject::*fget )(  ) ;
            
            JSObject_exposer.add_property( 
                "identifier"
                , fget( &::PyJSObject::GetIdentifier ) );
        
        }
        { //property "name"[fget=::PyJSObject::GetName]
        
            typedef ::boost::python::api::object ( ::PyJSObject::*fget )(  ) ;
            
            JSObject_exposer.add_property( 
                "name"
                , fget( &::PyJSObject::GetName ) );
        
        }
    }

    { //::SrcCefBrowser
        typedef bp::class_< SrcCefBrowser_wrapper, boost::noncopyable > SrcCefBrowser_exposer_t;
        SrcCefBrowser_exposer_t SrcCefBrowser_exposer = SrcCefBrowser_exposer_t( "SrcCefBrowser", bp::init< char const *, bp::optional< char const *, int, int, int, SrcCefNavigationType > >(( bp::arg("name"), bp::arg("url")="", bp::arg("renderframerate")=(int)(30), bp::arg("wide")=(int)(0), bp::arg("tall")=(int)(0), bp::arg("navigationbehavior")=::NT_DEFAULT )) );
        bp::scope SrcCefBrowser_scope( SrcCefBrowser_exposer );
        bp::implicitly_convertible< char const *, SrcCefBrowser >();
        SrcCefBrowser_exposer.def( bp::init< SrcCefBrowser const & >(( bp::arg("vec") )) );
        { //::SrcCefBrowser::CloseDevTools
        
            typedef void ( ::SrcCefBrowser::*CloseDevTools_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "CloseDevTools"
                , CloseDevTools_function_type( &::SrcCefBrowser::CloseDevTools ) );
        
        }
        { //::SrcCefBrowser::Destroy
        
            typedef void ( ::SrcCefBrowser::*Destroy_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "Destroy"
                , Destroy_function_type( &::SrcCefBrowser::Destroy ) );
        
        }
        { //::SrcCefBrowser::ExecuteJavaScript
        
            typedef void ( ::SrcCefBrowser::*ExecuteJavaScript_function_type )( char const *,char const *,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "ExecuteJavaScript"
                , ExecuteJavaScript_function_type( &::SrcCefBrowser::ExecuteJavaScript )
                , ( bp::arg("code"), bp::arg("script_url"), bp::arg("start_line")=(int)(0) ) );
        
        }
        { //::SrcCefBrowser::Focus
        
            typedef void ( ::SrcCefBrowser::*Focus_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "Focus"
                , Focus_function_type( &::SrcCefBrowser::Focus ) );
        
        }
        { //::SrcCefBrowser::GetAlphaAt
        
            typedef int ( ::SrcCefBrowser::*GetAlphaAt_function_type )( int,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetAlphaAt"
                , GetAlphaAt_function_type( &::SrcCefBrowser::GetAlphaAt )
                , ( bp::arg("x"), bp::arg("y") ) );
        
        }
        { //::SrcCefBrowser::GetCursor
        
            typedef ::vgui::HCursor ( ::SrcCefBrowser::*GetCursor_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetCursor"
                , GetCursor_function_type( &::SrcCefBrowser::GetCursor ) );
        
        }
        { //::SrcCefBrowser::GetIgnoreTabKey
        
            typedef bool ( ::SrcCefBrowser::*GetIgnoreTabKey_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetIgnoreTabKey"
                , GetIgnoreTabKey_function_type( &::SrcCefBrowser::GetIgnoreTabKey ) );
        
        }
        { //::SrcCefBrowser::GetName
        
            typedef char const * ( ::SrcCefBrowser::*GetName_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetName"
                , GetName_function_type( &::SrcCefBrowser::GetName ) );
        
        }
        { //::SrcCefBrowser::GetPassMouseTruIfAlphaZero
        
            typedef bool ( ::SrcCefBrowser::*GetPassMouseTruIfAlphaZero_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetPassMouseTruIfAlphaZero"
                , GetPassMouseTruIfAlphaZero_function_type( &::SrcCefBrowser::GetPassMouseTruIfAlphaZero ) );
        
        }
        { //::SrcCefBrowser::GetURL
        
            typedef char const * ( ::SrcCefBrowser::*GetURL_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetURL"
                , GetURL_function_type( &::SrcCefBrowser::GetURL ) );
        
        }
        { //::SrcCefBrowser::GetUseMouseCapture
        
            typedef bool ( ::SrcCefBrowser::*GetUseMouseCapture_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetUseMouseCapture"
                , GetUseMouseCapture_function_type( &::SrcCefBrowser::GetUseMouseCapture ) );
        
        }
        { //::SrcCefBrowser::GetVPanel
        
            typedef ::vgui::VPANEL ( ::SrcCefBrowser::*GetVPanel_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetVPanel"
                , GetVPanel_function_type( &::SrcCefBrowser::GetVPanel ) );
        
        }
        { //::SrcCefBrowser::InvalidateLayout
        
            typedef void ( ::SrcCefBrowser::*InvalidateLayout_function_type )(  ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_InvalidateLayout_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "InvalidateLayout"
                , InvalidateLayout_function_type(&::SrcCefBrowser::InvalidateLayout)
                , default_InvalidateLayout_function_type(&SrcCefBrowser_wrapper::default_InvalidateLayout) );
        
        }
        { //::SrcCefBrowser::IsAlphaZeroAt
        
            typedef bool ( ::SrcCefBrowser::*IsAlphaZeroAt_function_type )( int,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsAlphaZeroAt"
                , IsAlphaZeroAt_function_type( &::SrcCefBrowser::IsAlphaZeroAt )
                , ( bp::arg("x"), bp::arg("y") ) );
        
        }
        { //::SrcCefBrowser::IsFullyVisible
        
            typedef bool ( ::SrcCefBrowser::*IsFullyVisible_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsFullyVisible"
                , IsFullyVisible_function_type( &::SrcCefBrowser::IsFullyVisible ) );
        
        }
        { //::SrcCefBrowser::IsGameInputEnabled
        
            typedef bool ( ::SrcCefBrowser::*IsGameInputEnabled_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsGameInputEnabled"
                , IsGameInputEnabled_function_type( &::SrcCefBrowser::IsGameInputEnabled ) );
        
        }
        { //::SrcCefBrowser::IsKeyBoardInputEnabled
        
            typedef bool ( ::SrcCefBrowser::*IsKeyBoardInputEnabled_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsKeyBoardInputEnabled"
                , IsKeyBoardInputEnabled_function_type( &::SrcCefBrowser::IsKeyBoardInputEnabled ) );
        
        }
        { //::SrcCefBrowser::IsLoading
        
            typedef bool ( ::SrcCefBrowser::*IsLoading_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsLoading"
                , IsLoading_function_type( &::SrcCefBrowser::IsLoading ) );
        
        }
        { //::SrcCefBrowser::IsMouseInputEnabled
        
            typedef bool ( ::SrcCefBrowser::*IsMouseInputEnabled_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsMouseInputEnabled"
                , IsMouseInputEnabled_function_type( &::SrcCefBrowser::IsMouseInputEnabled ) );
        
        }
        { //::SrcCefBrowser::IsValid
        
            typedef bool ( ::SrcCefBrowser::*IsValid_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsValid"
                , IsValid_function_type( &::SrcCefBrowser::IsValid ) );
        
        }
        { //::SrcCefBrowser::IsVisible
        
            typedef bool ( ::SrcCefBrowser::*IsVisible_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "IsVisible"
                , IsVisible_function_type( &::SrcCefBrowser::IsVisible ) );
        
        }
        { //::SrcCefBrowser::KeyInput
        
            typedef int ( ::SrcCefBrowser::*KeyInput_function_type )( int,::ButtonCode_t,char const * ) ;
            typedef int ( SrcCefBrowser_wrapper::*default_KeyInput_function_type )( int,::ButtonCode_t,char const * ) ;
            
            SrcCefBrowser_exposer.def( 
                "KeyInput"
                , KeyInput_function_type(&::SrcCefBrowser::KeyInput)
                , default_KeyInput_function_type(&SrcCefBrowser_wrapper::default_KeyInput)
                , ( bp::arg("down"), bp::arg("keynum"), bp::arg("pszCurrentBinding") ) );
        
        }
        { //::SrcCefBrowser::LoadURL
        
            typedef void ( ::SrcCefBrowser::*LoadURL_function_type )( char const * ) ;
            
            SrcCefBrowser_exposer.def( 
                "LoadURL"
                , LoadURL_function_type( &::SrcCefBrowser::LoadURL )
                , ( bp::arg("url") ) );
        
        }
        { //::SrcCefBrowser::NotifyScreenInfoChanged
        
            typedef void ( ::SrcCefBrowser::*NotifyScreenInfoChanged_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "NotifyScreenInfoChanged"
                , NotifyScreenInfoChanged_function_type( &::SrcCefBrowser::NotifyScreenInfoChanged ) );
        
        }
        { //::SrcCefBrowser::OnAfterCreated
        
            typedef void ( ::SrcCefBrowser::*OnAfterCreated_function_type )(  ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnAfterCreated_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnAfterCreated"
                , OnAfterCreated_function_type(&::SrcCefBrowser::OnAfterCreated)
                , default_OnAfterCreated_function_type(&SrcCefBrowser_wrapper::default_OnAfterCreated) );
        
        }
        { //::SrcCefBrowser::OnContextCreated
        
            typedef void ( ::SrcCefBrowser::*OnContextCreated_function_type )(  ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnContextCreated_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnContextCreated"
                , OnContextCreated_function_type(&::SrcCefBrowser::OnContextCreated)
                , default_OnContextCreated_function_type(&SrcCefBrowser_wrapper::default_OnContextCreated) );
        
        }
        { //::SrcCefBrowser::OnDestroy
        
            typedef void ( ::SrcCefBrowser::*OnDestroy_function_type )(  ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnDestroy_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnDestroy"
                , OnDestroy_function_type(&::SrcCefBrowser::OnDestroy)
                , default_OnDestroy_function_type(&SrcCefBrowser_wrapper::default_OnDestroy) );
        
        }
        { //::SrcCefBrowser::OnLoadingStateChange
        
            typedef void ( ::SrcCefBrowser::*OnLoadingStateChange_function_type )( bool,bool,bool ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnLoadingStateChange_function_type )( bool,bool,bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnLoadingStateChange"
                , OnLoadingStateChange_function_type(&::SrcCefBrowser::OnLoadingStateChange)
                , default_OnLoadingStateChange_function_type(&SrcCefBrowser_wrapper::default_OnLoadingStateChange)
                , ( bp::arg("isLoading"), bp::arg("canGoBack"), bp::arg("canGoForward") ) );
        
        }
        { //::SrcCefBrowser::OnThink
        
            typedef void ( ::SrcCefBrowser::*OnThink_function_type )(  ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnThink_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnThink"
                , OnThink_function_type(&::SrcCefBrowser::OnThink)
                , default_OnThink_function_type(&SrcCefBrowser_wrapper::default_OnThink) );
        
        }
        { //::SrcCefBrowser::PerformLayout
        
            typedef void ( ::SrcCefBrowser::*PerformLayout_function_type )(  ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_PerformLayout_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "PerformLayout"
                , PerformLayout_function_type(&::SrcCefBrowser::PerformLayout)
                , default_PerformLayout_function_type(&SrcCefBrowser_wrapper::default_PerformLayout) );
        
        }
        { //::SrcCefBrowser::Ping
        
            typedef void ( ::SrcCefBrowser::*Ping_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "Ping"
                , Ping_function_type( &::SrcCefBrowser::Ping ) );
        
        }
        { //::SrcCefBrowser::PyCreateFunction
        
            typedef ::boost::python::api::object ( ::SrcCefBrowser::*CreateFunction_function_type )( char const *,::PyJSObject *,bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "CreateFunction"
                , CreateFunction_function_type( &::SrcCefBrowser::PyCreateFunction )
                , ( bp::arg("name"), bp::arg("object")=bp::object(), bp::arg("hascallback")=(bool)(false) ) );
        
        }
        { //::SrcCefBrowser::PyCreateGlobalObject
        
            typedef ::boost::python::api::object ( ::SrcCefBrowser::*CreateGlobalObject_function_type )( char const * ) ;
            
            SrcCefBrowser_exposer.def( 
                "CreateGlobalObject"
                , CreateGlobalObject_function_type( &::SrcCefBrowser::PyCreateGlobalObject )
                , ( bp::arg("name") ) );
        
        }
        { //::SrcCefBrowser::PyExecuteJavaScriptWithResult
        
            typedef ::boost::python::api::object ( ::SrcCefBrowser::*ExecuteJavaScriptWithResult_function_type )( char const *,char const *,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "ExecuteJavaScriptWithResult"
                , ExecuteJavaScriptWithResult_function_type( &::SrcCefBrowser::PyExecuteJavaScriptWithResult )
                , ( bp::arg("code"), bp::arg("script_url"), bp::arg("start_line")=(int)(0) ) );
        
        }
        { //::SrcCefBrowser::PyGetMainFrame
        
            typedef ::boost::python::api::object ( ::SrcCefBrowser::*GetMainFrame_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "GetMainFrame"
                , GetMainFrame_function_type( &::SrcCefBrowser::PyGetMainFrame ) );
        
        }
        { //::SrcCefBrowser::PyInvoke
        
            typedef void ( ::SrcCefBrowser::*Invoke_function_type )( ::PyJSObject *,char const *,::boost::python::list ) ;
            
            SrcCefBrowser_exposer.def( 
                "Invoke"
                , Invoke_function_type( &::SrcCefBrowser::PyInvoke )
                , ( bp::arg("object"), bp::arg("methodname"), bp::arg("methodargs")=boost::python::list() ) );
        
        }
        { //::SrcCefBrowser::PyInvokeWithResult
        
            typedef ::boost::python::api::object ( ::SrcCefBrowser::*InvokeWithResult_function_type )( ::PyJSObject *,char const *,::boost::python::list ) ;
            
            SrcCefBrowser_exposer.def( 
                "InvokeWithResult"
                , InvokeWithResult_function_type( &::SrcCefBrowser::PyInvokeWithResult )
                , ( bp::arg("object"), bp::arg("methodname"), bp::arg("methodargs") ) );
        
        }
        { //::SrcCefBrowser::PyObjectGetAttr
        
            typedef ::boost::python::api::object ( ::SrcCefBrowser::*ObjectGetAttr_function_type )( ::PyJSObject *,char const * ) ;
            
            SrcCefBrowser_exposer.def( 
                "ObjectGetAttr"
                , ObjectGetAttr_function_type( &::SrcCefBrowser::PyObjectGetAttr )
                , ( bp::arg("object"), bp::arg("attrname") ) );
        
        }
        { //::SrcCefBrowser::PyObjectSetAttr
        
            typedef void ( ::SrcCefBrowser::*ObjectSetAttr_function_type )( ::PyJSObject *,char const *,::boost::python::api::object ) ;
            
            SrcCefBrowser_exposer.def( 
                "ObjectSetAttr"
                , ObjectSetAttr_function_type( &::SrcCefBrowser::PyObjectSetAttr )
                , ( bp::arg("object"), bp::arg("attrname"), bp::arg("value") ) );
        
        }
        { //::SrcCefBrowser::PyOnLoadEnd
        
            typedef void ( ::SrcCefBrowser::*OnLoadEnd_function_type )( ::boost::python::api::object,int ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnLoadEnd_function_type )( ::boost::python::api::object,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnLoadEnd"
                , OnLoadEnd_function_type(&::SrcCefBrowser::PyOnLoadEnd)
                , default_OnLoadEnd_function_type(&SrcCefBrowser_wrapper::default_OnLoadEnd)
                , ( bp::arg("frame"), bp::arg("httpStatusCode") ) );
        
        }
        { //::SrcCefBrowser::PyOnLoadError
        
            typedef void ( ::SrcCefBrowser::*OnLoadError_function_type )( ::boost::python::api::object,int,::boost::python::api::object,::boost::python::api::object ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnLoadError_function_type )( ::boost::python::api::object,int,::boost::python::api::object,::boost::python::api::object ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnLoadError"
                , OnLoadError_function_type(&::SrcCefBrowser::PyOnLoadError)
                , default_OnLoadError_function_type(&SrcCefBrowser_wrapper::default_OnLoadError)
                , ( bp::arg("frame"), bp::arg("errorCode"), bp::arg("errorText"), bp::arg("failedUrl") ) );
        
        }
        { //::SrcCefBrowser::PyOnLoadStart
        
            typedef void ( ::SrcCefBrowser::*OnLoadStart_function_type )( ::boost::python::api::object ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnLoadStart_function_type )( ::boost::python::api::object ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnLoadStart"
                , OnLoadStart_function_type(&::SrcCefBrowser::PyOnLoadStart)
                , default_OnLoadStart_function_type(&SrcCefBrowser_wrapper::default_OnLoadStart)
                , ( bp::arg("frame") ) );
        
        }
        { //::SrcCefBrowser::PyOnMethodCall
        
            typedef void ( ::SrcCefBrowser::*OnMethodCall_function_type )( ::boost::python::api::object,::boost::python::api::object,::boost::python::api::object ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_OnMethodCall_function_type )( ::boost::python::api::object,::boost::python::api::object,::boost::python::api::object ) ;
            
            SrcCefBrowser_exposer.def( 
                "OnMethodCall"
                , OnMethodCall_function_type(&::SrcCefBrowser::PyOnMethodCall)
                , default_OnMethodCall_function_type(&SrcCefBrowser_wrapper::default_OnMethodCall)
                , ( bp::arg("identifier"), bp::arg("methodargs"), bp::arg("callbackid") ) );
        
        }
        { //::SrcCefBrowser::PySendCallback
        
            typedef void ( ::SrcCefBrowser::*SendCallback_function_type )( ::boost::python::api::object,::boost::python::list ) ;
            
            SrcCefBrowser_exposer.def( 
                "SendCallback"
                , SendCallback_function_type( &::SrcCefBrowser::PySendCallback )
                , ( bp::arg("callbackid"), bp::arg("methodargs") ) );
        
        }
        { //::SrcCefBrowser::Reload
        
            typedef void ( ::SrcCefBrowser::*Reload_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "Reload"
                , Reload_function_type( &::SrcCefBrowser::Reload ) );
        
        }
        { //::SrcCefBrowser::ReloadIgnoreCache
        
            typedef void ( ::SrcCefBrowser::*ReloadIgnoreCache_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "ReloadIgnoreCache"
                , ReloadIgnoreCache_function_type( &::SrcCefBrowser::ReloadIgnoreCache ) );
        
        }
        { //::SrcCefBrowser::SetCursor
        
            typedef void ( ::SrcCefBrowser::*SetCursor_function_type )( ::vgui::HCursor ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetCursor"
                , SetCursor_function_type( &::SrcCefBrowser::SetCursor )
                , ( bp::arg("cursor") ) );
        
        }
        { //::SrcCefBrowser::SetGameInputEnabled
        
            typedef void ( ::SrcCefBrowser::*SetGameInputEnabled_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetGameInputEnabled"
                , SetGameInputEnabled_function_type( &::SrcCefBrowser::SetGameInputEnabled )
                , ( bp::arg("state") ) );
        
        }
        { //::SrcCefBrowser::SetIgnoreTabKey
        
            typedef void ( ::SrcCefBrowser::*SetIgnoreTabKey_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetIgnoreTabKey"
                , SetIgnoreTabKey_function_type( &::SrcCefBrowser::SetIgnoreTabKey )
                , ( bp::arg("ignoreTabKey") ) );
        
        }
        { //::SrcCefBrowser::SetKeyBoardInputEnabled
        
            typedef void ( ::SrcCefBrowser::*SetKeyBoardInputEnabled_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetKeyBoardInputEnabled"
                , SetKeyBoardInputEnabled_function_type( &::SrcCefBrowser::SetKeyBoardInputEnabled )
                , ( bp::arg("state") ) );
        
        }
        { //::SrcCefBrowser::SetMouseInputEnabled
        
            typedef void ( ::SrcCefBrowser::*SetMouseInputEnabled_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetMouseInputEnabled"
                , SetMouseInputEnabled_function_type( &::SrcCefBrowser::SetMouseInputEnabled )
                , ( bp::arg("state") ) );
        
        }
        { //::SrcCefBrowser::SetPassMouseTruIfAlphaZero
        
            typedef void ( ::SrcCefBrowser::*SetPassMouseTruIfAlphaZero_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetPassMouseTruIfAlphaZero"
                , SetPassMouseTruIfAlphaZero_function_type( &::SrcCefBrowser::SetPassMouseTruIfAlphaZero )
                , ( bp::arg("passtruifzero") ) );
        
        }
        { //::SrcCefBrowser::SetPos
        
            typedef void ( ::SrcCefBrowser::*SetPos_function_type )( int,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetPos"
                , SetPos_function_type( &::SrcCefBrowser::SetPos )
                , ( bp::arg("x"), bp::arg("y") ) );
        
        }
        { //::SrcCefBrowser::SetSize
        
            typedef void ( ::SrcCefBrowser::*SetSize_function_type )( int,int ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetSize"
                , SetSize_function_type( &::SrcCefBrowser::SetSize )
                , ( bp::arg("wide"), bp::arg("tall") ) );
        
        }
        { //::SrcCefBrowser::SetUseMouseCapture
        
            typedef void ( ::SrcCefBrowser::*SetUseMouseCapture_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetUseMouseCapture"
                , SetUseMouseCapture_function_type( &::SrcCefBrowser::SetUseMouseCapture )
                , ( bp::arg("usemousecapture") ) );
        
        }
        { //::SrcCefBrowser::SetVisible
        
            typedef void ( ::SrcCefBrowser::*SetVisible_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetVisible"
                , SetVisible_function_type( &::SrcCefBrowser::SetVisible )
                , ( bp::arg("state") ) );
        
        }
        { //::SrcCefBrowser::SetZPos
        
            typedef void ( ::SrcCefBrowser::*SetZPos_function_type )( int ) ;
            
            SrcCefBrowser_exposer.def( 
                "SetZPos"
                , SetZPos_function_type( &::SrcCefBrowser::SetZPos )
                , ( bp::arg("z") ) );
        
        }
        { //::SrcCefBrowser::ShowDevTools
        
            typedef void ( ::SrcCefBrowser::*ShowDevTools_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "ShowDevTools"
                , ShowDevTools_function_type( &::SrcCefBrowser::ShowDevTools ) );
        
        }
        { //::SrcCefBrowser::StopLoad
        
            typedef void ( ::SrcCefBrowser::*StopLoad_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "StopLoad"
                , StopLoad_function_type( &::SrcCefBrowser::StopLoad ) );
        
        }
        { //::SrcCefBrowser::Unfocus
        
            typedef void ( ::SrcCefBrowser::*Unfocus_function_type )(  ) ;
            
            SrcCefBrowser_exposer.def( 
                "Unfocus"
                , Unfocus_function_type( &::SrcCefBrowser::Unfocus ) );
        
        }
        { //::SrcCefBrowser::WasHidden
        
            typedef void ( ::SrcCefBrowser::*WasHidden_function_type )( bool ) ;
            typedef void ( SrcCefBrowser_wrapper::*default_WasHidden_function_type )( bool ) ;
            
            SrcCefBrowser_exposer.def( 
                "WasHidden"
                , WasHidden_function_type(&::SrcCefBrowser::WasHidden)
                , default_WasHidden_function_type(&SrcCefBrowser_wrapper::default_WasHidden)
                , ( bp::arg("hidden") ) );
        
        }
    }

    { //::CEFSystem
    
        typedef ::CCefSystem & ( *CEFSystem_function_type )(  );
        
        bp::def( 
            "CEFSystem"
            , CEFSystem_function_type( &::CEFSystem )
            , bp::return_value_policy< bp::reference_existing_object >() );
    
    }
}
