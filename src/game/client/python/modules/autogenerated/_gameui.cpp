// This file has been generated by Py++.

#include "cbase.h"



#include "gameui/gameui_util.h"

#include "videocfg/videocfg.h"

#include "cbase.h"

#include "srcpy_gameui.h"

#include "srcpy.h"

#include "tier0/memdbgon.h"

namespace bp = boost::python;

BOOST_PYTHON_MODULE(_gameui){
    bp::docstring_options doc_options( true, true, false );

    bp::enum_< BaseModUI::WINDOW_TYPE>("WINDOW_TYPE")
        .value("WT_NONE", BaseModUI::WT_NONE)
        .value("WT_ACHIEVEMENTS", BaseModUI::WT_ACHIEVEMENTS)
        .value("WT_AUDIO", BaseModUI::WT_AUDIO)
        .value("WT_AUDIOVIDEO", BaseModUI::WT_AUDIOVIDEO)
        .value("WT_CLOUD", BaseModUI::WT_CLOUD)
        .value("WT_CONTROLLER", BaseModUI::WT_CONTROLLER)
        .value("WT_CONTROLLER_STICKS", BaseModUI::WT_CONTROLLER_STICKS)
        .value("WT_CONTROLLER_BUTTONS", BaseModUI::WT_CONTROLLER_BUTTONS)
        .value("WT_DOWNLOADS", BaseModUI::WT_DOWNLOADS)
        .value("WT_GAMELOBBY", BaseModUI::WT_GAMELOBBY)
        .value("WT_GAMEOPTIONS", BaseModUI::WT_GAMEOPTIONS)
        .value("WT_GAMESETTINGS", BaseModUI::WT_GAMESETTINGS)
        .value("WT_GENERICCONFIRMATION", BaseModUI::WT_GENERICCONFIRMATION)
        .value("WT_INGAMEDIFFICULTYSELECT", BaseModUI::WT_INGAMEDIFFICULTYSELECT)
        .value("WT_INGAMEMAINMENU", BaseModUI::WT_INGAMEMAINMENU)
        .value("WT_INGAMECHAPTERSELECT", BaseModUI::WT_INGAMECHAPTERSELECT)
        .value("WT_INGAMEKICKPLAYERLIST", BaseModUI::WT_INGAMEKICKPLAYERLIST)
        .value("WT_VOTEOPTIONS", BaseModUI::WT_VOTEOPTIONS)
        .value("WT_KEYBOARDMOUSE", BaseModUI::WT_KEYBOARDMOUSE)
        .value("WT_LOADINGPROGRESSBKGND", BaseModUI::WT_LOADINGPROGRESSBKGND)
        .value("WT_LOADINGPROGRESS", BaseModUI::WT_LOADINGPROGRESS)
        .value("WT_MAINMENU", BaseModUI::WT_MAINMENU)
        .value("WT_MULTIPLAYER", BaseModUI::WT_MULTIPLAYER)
        .value("WT_OPTIONS", BaseModUI::WT_OPTIONS)
        .value("WT_SEARCHINGFORLIVEGAMES", BaseModUI::WT_SEARCHINGFORLIVEGAMES)
        .value("WT_SIGNINDIALOG", BaseModUI::WT_SIGNINDIALOG)
        .value("WT_SINGLEPLAYER", BaseModUI::WT_SINGLEPLAYER)
        .value("WT_GENERICWAITSCREEN", BaseModUI::WT_GENERICWAITSCREEN)
        .value("WT_ATTRACTSCREEN", BaseModUI::WT_ATTRACTSCREEN)
        .value("WT_ALLGAMESEARCHRESULTS", BaseModUI::WT_ALLGAMESEARCHRESULTS)
        .value("WT_FOUNDPUBLICGAMES", BaseModUI::WT_FOUNDPUBLICGAMES)
        .value("WT_TRANSITIONSCREEN", BaseModUI::WT_TRANSITIONSCREEN)
        .value("WT_PASSWORDENTRY", BaseModUI::WT_PASSWORDENTRY)
        .value("WT_VIDEO", BaseModUI::WT_VIDEO)
        .value("WT_STEAMCLOUDCONFIRM", BaseModUI::WT_STEAMCLOUDCONFIRM)
        .value("WT_STEAMGROUPSERVERS", BaseModUI::WT_STEAMGROUPSERVERS)
        .value("WT_CUSTOMCAMPAIGNS", BaseModUI::WT_CUSTOMCAMPAIGNS)
        .value("WT_ADDONS", BaseModUI::WT_ADDONS)
        .value("WT_DOWNLOADCAMPAIGN", BaseModUI::WT_DOWNLOADCAMPAIGN)
        .value("WT_LEADERBOARD", BaseModUI::WT_LEADERBOARD)
        .value("WT_ADDONASSOCIATION", BaseModUI::WT_ADDONASSOCIATION)
        .value("WT_GETLEGACYDATA", BaseModUI::WT_GETLEGACYDATA)
        .value("WT_JUKEBOX", BaseModUI::WT_JUKEBOX)
        .value("WT_WINDOW_COUNT", BaseModUI::WT_WINDOW_COUNT)
        .export_values()
        ;

    { //::CGameUIConVarRef
        typedef bp::class_< CGameUIConVarRef > CGameUIConVarRef_exposer_t;
        CGameUIConVarRef_exposer_t CGameUIConVarRef_exposer = CGameUIConVarRef_exposer_t( "CGameUIConVarRef", bp::init< char const * >(( bp::arg("pName") )) );
        bp::scope CGameUIConVarRef_scope( CGameUIConVarRef_exposer );
        bp::implicitly_convertible< char const *, CGameUIConVarRef >();
        CGameUIConVarRef_exposer.def( bp::init< char const *, bool >(( bp::arg("pName"), bp::arg("bIgnoreMissing") )) );
        CGameUIConVarRef_exposer.def( bp::init< IConVar * >(( bp::arg("pConVar") )) );
        bp::implicitly_convertible< IConVar *, CGameUIConVarRef >();
        { //::CGameUIConVarRef::GetBaseName
        
            typedef char const * ( ::CGameUIConVarRef::*GetBaseName_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetBaseName"
                , GetBaseName_function_type( &::CGameUIConVarRef::GetBaseName ) );
        
        }
        { //::CGameUIConVarRef::GetBool
        
            typedef bool ( ::CGameUIConVarRef::*GetBool_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetBool"
                , GetBool_function_type( &::CGameUIConVarRef::GetBool ) );
        
        }
        { //::CGameUIConVarRef::GetDefault
        
            typedef char const * ( ::CGameUIConVarRef::*GetDefault_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetDefault"
                , GetDefault_function_type( &::CGameUIConVarRef::GetDefault ) );
        
        }
        { //::CGameUIConVarRef::GetFloat
        
            typedef float ( ::CGameUIConVarRef::*GetFloat_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetFloat"
                , GetFloat_function_type( &::CGameUIConVarRef::GetFloat ) );
        
        }
        { //::CGameUIConVarRef::GetInt
        
            typedef int ( ::CGameUIConVarRef::*GetInt_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetInt"
                , GetInt_function_type( &::CGameUIConVarRef::GetInt ) );
        
        }
        { //::CGameUIConVarRef::GetName
        
            typedef char const * ( ::CGameUIConVarRef::*GetName_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetName"
                , GetName_function_type( &::CGameUIConVarRef::GetName ) );
        
        }
        { //::CGameUIConVarRef::GetString
        
            typedef char const * ( ::CGameUIConVarRef::*GetString_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "GetString"
                , GetString_function_type( &::CGameUIConVarRef::GetString ) );
        
        }
        { //::CGameUIConVarRef::Init
        
            typedef void ( ::CGameUIConVarRef::*Init_function_type )( char const *,bool ) ;
            
            CGameUIConVarRef_exposer.def( 
                "Init"
                , Init_function_type( &::CGameUIConVarRef::Init )
                , ( bp::arg("pName"), bp::arg("bIgnoreMissing") ) );
        
        }
        { //::CGameUIConVarRef::IsFlagSet
        
            typedef bool ( ::CGameUIConVarRef::*IsFlagSet_function_type )( int ) const;
            
            CGameUIConVarRef_exposer.def( 
                "IsFlagSet"
                , IsFlagSet_function_type( &::CGameUIConVarRef::IsFlagSet )
                , ( bp::arg("nFlags") ) );
        
        }
        { //::CGameUIConVarRef::IsValid
        
            typedef bool ( ::CGameUIConVarRef::*IsValid_function_type )(  ) const;
            
            CGameUIConVarRef_exposer.def( 
                "IsValid"
                , IsValid_function_type( &::CGameUIConVarRef::IsValid ) );
        
        }
        { //::CGameUIConVarRef::SetValue
        
            typedef void ( ::CGameUIConVarRef::*SetValue_function_type )( char const * ) ;
            
            CGameUIConVarRef_exposer.def( 
                "SetValue"
                , SetValue_function_type( &::CGameUIConVarRef::SetValue )
                , ( bp::arg("pValue") ) );
        
        }
        { //::CGameUIConVarRef::SetValue
        
            typedef void ( ::CGameUIConVarRef::*SetValue_function_type )( float ) ;
            
            CGameUIConVarRef_exposer.def( 
                "SetValue"
                , SetValue_function_type( &::CGameUIConVarRef::SetValue )
                , ( bp::arg("flValue") ) );
        
        }
        { //::CGameUIConVarRef::SetValue
        
            typedef void ( ::CGameUIConVarRef::*SetValue_function_type )( int ) ;
            
            CGameUIConVarRef_exposer.def( 
                "SetValue"
                , SetValue_function_type( &::CGameUIConVarRef::SetValue )
                , ( bp::arg("nValue") ) );
        
        }
        { //::CGameUIConVarRef::SetValue
        
            typedef void ( ::CGameUIConVarRef::*SetValue_function_type )( bool ) ;
            
            CGameUIConVarRef_exposer.def( 
                "SetValue"
                , SetValue_function_type( &::CGameUIConVarRef::SetValue )
                , ( bp::arg("bValue") ) );
        
        }
    }

    { //::GetCurrentKeyboardLangId
    
        typedef ::boost::python::api::object ( *GetCurrentKeyboardLangId_function_type )(  );
        
        bp::def( 
            "GetCurrentKeyboardLangId"
            , GetCurrentKeyboardLangId_function_type( &::GetCurrentKeyboardLangId ) );
    
    }

    { //::GetKeyboardLangIds
    
        typedef ::boost::python::api::object ( *GetKeyboardLangIds_function_type )(  );
        
        bp::def( 
            "GetKeyboardLangIds"
            , GetKeyboardLangIds_function_type( &::GetKeyboardLangIds ) );
    
    }

    { //::GetMainMenu
    
        typedef ::boost::python::api::object ( *GetMainMenu_function_type )(  );
        
        bp::def( 
            "GetMainMenu"
            , GetMainMenu_function_type( &::GetMainMenu ) );
    
    }

    { //::OpenGammaDialog
    
        typedef void ( *OpenGammaDialog_function_type )( ::vgui::VPANEL );
        
        bp::def( 
            "OpenGammaDialog"
            , OpenGammaDialog_function_type( &::OpenGammaDialog )
            , ( bp::arg("parent") ) );
    
    }

    { //::PyGameUICommand
    
        typedef void ( *GameUICommand_function_type )( char const * );
        
        bp::def( 
            "GameUICommand"
            , GameUICommand_function_type( &::PyGameUICommand )
            , ( bp::arg("command") ) );
    
    }

    { //::PyGameUIOpenWindow
    
        typedef void ( *GameUIOpenWindow_function_type )( ::BaseModUI::WINDOW_TYPE,bool,::KeyValues * );
        
        bp::def( 
            "GameUIOpenWindow"
            , GameUIOpenWindow_function_type( &::PyGameUIOpenWindow )
            , ( bp::arg("windowtype"), bp::arg("hideprevious")=(bool)(true), bp::arg("parameters")=bp::object() ) );
    
    }

    { //::ReadCurrentVideoConfig
    
        typedef bool ( *ReadCurrentVideoConfig_function_type )( ::KeyValues *,bool );
        
        bp::def( 
            "ReadCurrentVideoConfig"
            , ReadCurrentVideoConfig_function_type( &::ReadCurrentVideoConfig )
            , ( bp::arg("pConfigKeys"), bp::arg("bDefault")=(bool)(false) ) );
    
    }
}
