//====== Copyright � Sandern Corporation, All rights reserved. ===========//
//
// Purpose: 
//
// $NoKeywords: $
//=============================================================================//

#include "cbase.h"
#include "wars_network.h"
#include "wars_matchmaking.h"
#include "steam/steam_api.h"

#ifdef ENABLE_PYTHON
#include "srcpy.h"
#endif // ENABLE_PYTHON

// memdbgon must be the last include file in a .cpp file!!!
#include "tier0/memdbgon.h"

#ifdef ENABLE_PYTHON
ConVar wars_net_debug_receive( "wars_net_debug_receive", "0", FCVAR_CHEAT );
ConVar wars_net_debug_receive_track_var( "wars_net_debug_receive_track_var", "", FCVAR_CHEAT );

static boost::python::object WarsNet_ReadPythonVarData( CUtlBuffer &data, bool &success );

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadVector( CUtlBuffer &data )
{
	Vector vecData;
	data.Get( &vecData, sizeof( Vector ) );
	return boost::python::object( vecData );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadQAngle( CUtlBuffer &data )
{
	QAngle vecData;
	data.Get( &vecData, sizeof( QAngle ) );
	return boost::python::object( vecData );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadColor( CUtlBuffer &data )
{
	Color c;
	data.Get( &c, sizeof( c ) );
	return boost::python::object( c );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadSteamID( CUtlBuffer &data )
{
	uint64 steamIDUint64;
	data.Get( &steamIDUint64, sizeof( steamIDUint64 ) );
	return boost::python::object( CSteamID( steamIDUint64 ) );
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadHandle( CUtlBuffer &data )
{
	int iSerialNum, iEntryIndex;
	long iEncodedEHandle;

	data.Get( &iEncodedEHandle, sizeof( iEncodedEHandle ) );
	iSerialNum = (iEncodedEHandle >> MAX_EDICT_BITS);
	iEntryIndex = iEncodedEHandle & ~(iSerialNum << MAX_EDICT_BITS);

	// If the entity already exists on te client, return the handle from the entity
	EHANDLE handle( iEntryIndex, iSerialNum );
	if( handle )
	{
		return handle->GetPyHandle();
	}

	// If it does not exist, create a new handle
	try 
	{																
		return _entities.attr("PyHandle")( iEntryIndex, iSerialNum );							
	} 
	catch( boost::python::error_already_set & ) 
	{					
		Warning( "WarsNet_ReadHandle: Failed to create a PyHandle!\n" );				
		PyErr_Print();											
	}	
	return boost::python::object();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadList( CUtlBuffer &data )
{
	bool success;
	boost::python::list l;
	int len = data.GetInt();
	for( int i = 0; i < len; i++ )
	{
		l.append( WarsNet_ReadPythonVarData( data, success ) );
	}
	return l;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadDict( CUtlBuffer &data )
{
	bool success;
	boost::python::dict d;
	int len = data.GetInt();
	for( int i = 0; i < len; i++ )
	{
		d[ WarsNet_ReadPythonVarData( data, success ) ] = WarsNet_ReadPythonVarData( data, success );
	}
	return d;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadString( CUtlBuffer &data )
{
	int lenStr = data.GetInt();
	char *strData = (char *)stackalloc( lenStr + 1 );
	data.Get( strData, lenStr );
	strData[lenStr] = 0;
	boost::python::object pyData = boost::python::object( (const char *)strData );
	stackfree( strData );
	return pyData;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static boost::python::object WarsNet_ReadPythonVarData( CUtlBuffer &data, bool &success )
{
	success = true;
	WarsNetType_e type = (WarsNetType_e)data.GetUnsignedChar();

	try
	{
		switch( type )
		{
		case WARSNET_INT:
			return boost::python::object( data.GetInt() );
		case WARSNET_FLOAT:
			return boost::python::object( data.GetFloat() );
		case WARSNET_STRING:
			return WarsNet_ReadString( data );
		case WARSNET_BOOL:
			return boost::python::object( (bool)data.GetUnsignedChar() );
		case WARSNET_NONE:
			return boost::python::object();
		case WARSNET_VECTOR:
			return WarsNet_ReadVector( data );
		case WARSNET_QANGLE:
			return WarsNet_ReadQAngle( data );
		case WARSNET_HANDLE:
			return WarsNet_ReadHandle( data );
		case WARSNET_LIST:
			return WarsNet_ReadList( data );
		case WARSNET_TUPLE:
			return boost::python::tuple( WarsNet_ReadList( data ) );
		case WARSNET_SET:
			return builtins.attr("set")( WarsNet_ReadList( data ) );
		case WARSNET_DICT:
			return WarsNet_ReadDict( data );
		case WARSNET_COLOR:
			return WarsNet_ReadColor( data );
		case WARSNET_STEAMID:
			return WarsNet_ReadSteamID( data );
		default:
			Warning("WarsNet_ReadPythonVarData: Type %d not handled\n", type);
			break;
		}
	}
	catch( boost::python::error_already_set & ) 
	{
		Warning( "WarsNet_ReadPythonVarData: failed to parse data for type %d: \n", type );
		PyErr_Print();
	}

	// Error state
	success = false;
	return boost::python::object();
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
static bool WarsNet_ReadEntityVar( EHANDLE &ent, CUtlBuffer &data )
{
	// Read expected start type
	WarsNetType_e entExpectedType = (WarsNetType_e)data.GetUnsignedChar();
	if( entExpectedType != WARSNET_ENTVAR && entExpectedType != WARSNET_ENTVAR_CC )
	{
		return false;
	}

	// Read variable name
	int lenName = data.GetInt();
	if( lenName <= 0 )
	{
		Warning("WarsNet_ReadEntityVar: Reading wars net var, but no name written\n");
		return false;
	}
	char *varName = (char *)stackalloc( lenName + 1 );
	data.Get( varName, lenName );
	varName[lenName] = 0;

	bool success;
	boost::python::object pyData = WarsNet_ReadPythonVarData( data, success );

	if( success )
	{
		if( ent )
		{
			if( wars_net_debug_receive.GetBool() || !V_strcmp( wars_net_debug_receive_track_var.GetString(), varName ) )
			{
				Msg( "%.2f: #%d Received PyNetworkVar %s\n", Plat_FloatTime(), ent->entindex(), varName );
			}
			ent->PyUpdateNetworkVar( varName, pyData, entExpectedType == WARSNET_ENTVAR_CC );
		}
		else
		{
			if( wars_net_debug_receive.GetBool() || !V_strcmp( wars_net_debug_receive_track_var.GetString(), varName ) )
			{
				Msg( "%.2f: #%d Received PyNetworkVar, but entity is NULL. Delaying apply data for \"%s\" until entity exists...\n", 
					Plat_FloatTime(), ent.GetEntryIndex(), varName );
			}
			SrcPySystem()->AddToDelayedUpdateList( ent, varName, pyData, entExpectedType == WARSNET_ENTVAR_CC );
		}
	}

	stackfree( varName );

	return success;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void WarsNet_ReceiveEntityUpdate( CUtlBuffer &data )
{
	if( data.TellMaxPut() <  sizeof(WarsEntityUpdateMessage_t) )
	{
		Warning("Received invalid WarsEntityUpdateMessage!\n");
		return;
	}

	int iSerialNum, iEntryIndex;

	WarsEntityUpdateMessage_t *entityUpdateMsg = (WarsEntityUpdateMessage_t *)data.Base();

	iSerialNum = (entityUpdateMsg->iEncodedEHandle >> MAX_EDICT_BITS);
	iEntryIndex = entityUpdateMsg->iEncodedEHandle & ~(iSerialNum << MAX_EDICT_BITS);

	EHANDLE handle( iEntryIndex, iSerialNum );
	data.SeekGet( CUtlBuffer::SEEK_HEAD, sizeof(WarsEntityUpdateMessage_t) );

	if( wars_net_debug_receive.GetBool() )
	{
		Msg( "%.2f: WarsNet_ReceiveEntityUpdate: got entity data update of size %d bytes\n", Plat_FloatTime(), data.TellMaxPut() );
	}

	while( WarsNet_ReadEntityVar( handle, data ) )
		continue;
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void WarsNet_ReceiveMessageUpdate( CUtlBuffer &data )
{
	if( data.TellMaxPut() <  sizeof(WarsMessage_t) )
	{
		Warning("Received invalid WarsMessage!\n");
		return;
	}

	data.SeekGet( CUtlBuffer::SEEK_HEAD, sizeof(WarsMessage_t) );

	// Read message name
	int lenName = data.GetInt();
	if( lenName == 0 )
	{
		Warning("WarsNet_ReceiveMessageUpdate: Reading message name, but no name written\n");
		return;
	}
	char *msgName = (char *)stackalloc( lenName + 1 );
	data.Get( msgName, lenName );
	msgName[lenName] = 0;

	if( wars_net_debug_receive.GetBool() )
	{
		Msg( "%.2f: WarsNet_ReceiveMessageUpdate: got message update %s of size %d bytes\n", Plat_FloatTime(), msgName, data.TellMaxPut() );
	}

	bool success;
	boost::python::object pyData = WarsNet_ReadPythonVarData( data, success );

	if( success )
	{
		SrcPySystem()->Run<const char *, boost::python::object>( SrcPySystem()->Get("_DispatchMessage", "core.usermessages", true ), msgName, pyData );
	}
	else
	{
		Warning( "WarsNet_ReceiveMessageUpdate: Failed to read message %s\n", msgName );
		return;
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
void WarsNet_ProcessWarsMessages()
{
	// Receive/Process client messages
	if( warsextension )
	{
		warsextension->ReceiveClientSteamP2PMessages( steamapicontext->SteamNetworking() );

		// Process client messages
		WarsMessageData_t *messageData = warsextension->ClientMessageHead();
		while( messageData )
		{
			EMessageClient eMsg = (EMessageClient)( *(uint32*)messageData->buf.Base() );
			const CSteamID &steamIDRemote = messageData->steamIDRemote;

#ifdef ENABLE_PYTHON
			boost::python::dict kwargs;
			boost::python::object signal;
#endif // ENABLE_PYTHON
			uint32 publicIP = 0;
			uint32 gamePort = 0;
			CSteamID serverSteamID;
			WarsAcceptGameMessage_t *acceptMessageData;

			switch( eMsg )
			{
				case k_EMsgClientRequestGameAccepted:
					if( messageData->buf.TellMaxPut() < sizeof(WarsAcceptGameMessage_t) )
					{
						break;
					}
					if( WarsGetActiveRequestGameServerSteamID() != steamIDRemote )
					{
						break;
					}
					
					acceptMessageData = (WarsAcceptGameMessage_t *)messageData->buf.Base();

					publicIP = acceptMessageData->publicIP;
					gamePort = acceptMessageData->gamePort;
					serverSteamID.SetFromUint64(acceptMessageData->serverSteamID);

#ifdef ENABLE_PYTHON
					kwargs["sender"] = boost::python::object();
					kwargs["publicip"] = publicIP;
					kwargs["gameport"] = gamePort;
					kwargs["serversteamid"] = serverSteamID;
					signal = SrcPySystem()->Get("lobby_gameserver_accept", "core.signals", true);
					SrcPySystem()->CallSignal( signal, kwargs );
#endif // ENABLE_PYTHON
					break;
				case k_EMsgClientRequestGameDenied:
					if( WarsGetActiveRequestGameServerSteamID() != steamIDRemote )
					{
						break;
					}
#ifdef ENABLE_PYTHON
					SrcPySystem()->CallSignalNoArgs( SrcPySystem()->Get( "lobby_gameserver_denied", "core.signals", true ) );
#endif // ENABLE_PYTHON
					break;
				case k_EMsgClient_PyEntityClasses:
#ifdef ENABLE_PYTHON
					WarsNet_ReceiveEntityClasses( messageData->buf );
#endif // ENABLE_PYTHON
					break;
				case k_EMsgClient_PyEntityUpdate:
#ifdef ENABLE_PYTHON
					WarsNet_ReceiveEntityUpdate( messageData->buf );
#endif // ENABLE_PYTHON
					break;
				case k_EMsgClient_PyMessageUpdate:
#ifdef ENABLE_PYTHON
					WarsNet_ReceiveMessageUpdate( messageData->buf );
#endif // ENABLE_PYTHON
					break;
				case k_EMsgClient_Ping:
				{
					WarsSendPongMessage( messageData->steamIDRemote );
					break;
				}
				case k_EMsgClient_Pong:
				{
#ifdef ENABLE_PYTHON
					try
					{
						boost::python::dict kwargs;
						kwargs["sender"] = boost::python::object();
						kwargs["steamidremote"] = messageData->steamIDRemote;
						SrcPySystem()->CallSignal( SrcPySystem()->Get( "lobby_received_pong", "core.signals", true ), kwargs );
					}
					catch( boost::python::error_already_set & ) 
					{
						PyErr_Print();
					}
#endif // ENABLE_PYTHON
					break;
				}
				default:
					Warning("Unknown client message type %d\n", eMsg); 
					break;
			}

			warsextension->NextClientMessage();
			messageData = warsextension->ClientMessageHead();
		}
	}
}

//-----------------------------------------------------------------------------
// Purpose: 
//-----------------------------------------------------------------------------
class CWarsNet
{
public:
	CWarsNet() : m_CallbackP2PSessionRequest( this, &CWarsNet::OnP2PSessionRequest ),
		m_CallbackP2PSessionConnectFail( this, &CWarsNet::OnP2PSessionConnectFail )
	{
	}

	STEAM_CALLBACK( CWarsNet, OnP2PSessionRequest, P2PSessionRequest_t, m_CallbackP2PSessionRequest );
	STEAM_CALLBACK( CWarsNet, OnP2PSessionConnectFail, P2PSessionConnectFail_t, m_CallbackP2PSessionConnectFail );
};

static CWarsNet *s_pWarsNet = NULL;

//-----------------------------------------------------------------------------
// Purpose: Handle clients connecting
//-----------------------------------------------------------------------------
void CWarsNet::OnP2PSessionRequest( P2PSessionRequest_t *pCallback )
{
	// we'll accept a connection from anyone
	steamapicontext->SteamNetworking()->AcceptP2PSessionWithUser( pCallback->m_steamIDRemote );
}

//-----------------------------------------------------------------------------
// Purpose: Handle errors
//-----------------------------------------------------------------------------
void CWarsNet::OnP2PSessionConnectFail( P2PSessionConnectFail_t *pCallback )
{
	Warning( "CWarsNet::OnP2PSessionConnectFail: %s\n", WarsNet_TranslateP2PConnectErr( pCallback->m_eP2PSessionError ) );

#ifdef ENABLE_PYTHON
	boost::python::dict kwargs;
	kwargs["sender"] = boost::python::object();
	kwargs["steamidremote"] = pCallback->m_steamIDRemote;
	kwargs["p2psessionerror"] = pCallback->m_eP2PSessionError;
	SrcPySystem()->CallSignal( SrcPySystem()->Get( "steam_p2p_connectfail", "core.signals", true ), kwargs );
#endif // ENABLE_PYTHON
}

void WarsNet_Init()
{
	s_pWarsNet = new CWarsNet();
}
void WarsNet_Shutdown()
{
	delete s_pWarsNet;
	s_pWarsNet = NULL;
}
#endif // ENABLE_PYTHON