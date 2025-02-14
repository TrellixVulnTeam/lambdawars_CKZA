// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// $PERPARTICLEOUTLINE && ( $ORIENTATION == 3 )
// $DUALSEQUENCE && ( $PERPARTICLEOUTLINE || ( $ORIENTATION == 3 ) )
// $HARDWAREFOGBLEND && !SPRITECARDVERTEXFOG
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
#include "shaderlib/cshader.h"
class spritecard_vs30_Static_Index
{
private:
	int m_nDUALSEQUENCE;
#ifdef _DEBUG
	bool m_bDUALSEQUENCE;
#endif
public:
	void SetDUALSEQUENCE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nDUALSEQUENCE = i;
#ifdef _DEBUG
		m_bDUALSEQUENCE = true;
#endif
	}
	void SetDUALSEQUENCE( bool i )
	{
		m_nDUALSEQUENCE = i ? 1 : 0;
#ifdef _DEBUG
		m_bDUALSEQUENCE = true;
#endif
	}
private:
	int m_nADDBASETEXTURE2;
#ifdef _DEBUG
	bool m_bADDBASETEXTURE2;
#endif
public:
	void SetADDBASETEXTURE2( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nADDBASETEXTURE2 = i;
#ifdef _DEBUG
		m_bADDBASETEXTURE2 = true;
#endif
	}
	void SetADDBASETEXTURE2( bool i )
	{
		m_nADDBASETEXTURE2 = i ? 1 : 0;
#ifdef _DEBUG
		m_bADDBASETEXTURE2 = true;
#endif
	}
private:
	int m_nEXTRACTGREENALPHA;
#ifdef _DEBUG
	bool m_bEXTRACTGREENALPHA;
#endif
public:
	void SetEXTRACTGREENALPHA( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nEXTRACTGREENALPHA = i;
#ifdef _DEBUG
		m_bEXTRACTGREENALPHA = true;
#endif
	}
	void SetEXTRACTGREENALPHA( bool i )
	{
		m_nEXTRACTGREENALPHA = i ? 1 : 0;
#ifdef _DEBUG
		m_bEXTRACTGREENALPHA = true;
#endif
	}
private:
	int m_nDEPTHBLEND;
#ifdef _DEBUG
	bool m_bDEPTHBLEND;
#endif
public:
	void SetDEPTHBLEND( int i )
	{
		Assert( i >= 0 && i <= 0 );
		m_nDEPTHBLEND = i;
#ifdef _DEBUG
		m_bDEPTHBLEND = true;
#endif
	}
	void SetDEPTHBLEND( bool i )
	{
		m_nDEPTHBLEND = i ? 1 : 0;
#ifdef _DEBUG
		m_bDEPTHBLEND = true;
#endif
	}
private:
	int m_nANIMBLEND_OR_MAXLUMFRAMEBLEND1;
#ifdef _DEBUG
	bool m_bANIMBLEND_OR_MAXLUMFRAMEBLEND1;
#endif
public:
	void SetANIMBLEND_OR_MAXLUMFRAMEBLEND1( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nANIMBLEND_OR_MAXLUMFRAMEBLEND1 = i;
#ifdef _DEBUG
		m_bANIMBLEND_OR_MAXLUMFRAMEBLEND1 = true;
#endif
	}
	void SetANIMBLEND_OR_MAXLUMFRAMEBLEND1( bool i )
	{
		m_nANIMBLEND_OR_MAXLUMFRAMEBLEND1 = i ? 1 : 0;
#ifdef _DEBUG
		m_bANIMBLEND_OR_MAXLUMFRAMEBLEND1 = true;
#endif
	}
private:
	int m_nCROP;
#ifdef _DEBUG
	bool m_bCROP;
#endif
public:
	void SetCROP( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCROP = i;
#ifdef _DEBUG
		m_bCROP = true;
#endif
	}
	void SetCROP( bool i )
	{
		m_nCROP = i ? 1 : 0;
#ifdef _DEBUG
		m_bCROP = true;
#endif
	}
private:
	int m_nPACKED_INTERPOLATOR;
#ifdef _DEBUG
	bool m_bPACKED_INTERPOLATOR;
#endif
public:
	void SetPACKED_INTERPOLATOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPACKED_INTERPOLATOR = i;
#ifdef _DEBUG
		m_bPACKED_INTERPOLATOR = true;
#endif
	}
	void SetPACKED_INTERPOLATOR( bool i )
	{
		m_nPACKED_INTERPOLATOR = i ? 1 : 0;
#ifdef _DEBUG
		m_bPACKED_INTERPOLATOR = true;
#endif
	}
private:
	int m_nSPRITECARDVERTEXFOG;
#ifdef _DEBUG
	bool m_bSPRITECARDVERTEXFOG;
#endif
public:
	void SetSPRITECARDVERTEXFOG( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSPRITECARDVERTEXFOG = i;
#ifdef _DEBUG
		m_bSPRITECARDVERTEXFOG = true;
#endif
	}
	void SetSPRITECARDVERTEXFOG( bool i )
	{
		m_nSPRITECARDVERTEXFOG = i ? 1 : 0;
#ifdef _DEBUG
		m_bSPRITECARDVERTEXFOG = true;
#endif
	}
private:
	int m_nHARDWAREFOGBLEND;
#ifdef _DEBUG
	bool m_bHARDWAREFOGBLEND;
#endif
public:
	void SetHARDWAREFOGBLEND( int i )
	{
		Assert( i >= 0 && i <= 0 );
		m_nHARDWAREFOGBLEND = i;
#ifdef _DEBUG
		m_bHARDWAREFOGBLEND = true;
#endif
	}
	void SetHARDWAREFOGBLEND( bool i )
	{
		m_nHARDWAREFOGBLEND = i ? 1 : 0;
#ifdef _DEBUG
		m_bHARDWAREFOGBLEND = true;
#endif
	}
private:
	int m_nPERPARTICLEOUTLINE;
#ifdef _DEBUG
	bool m_bPERPARTICLEOUTLINE;
#endif
public:
	void SetPERPARTICLEOUTLINE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPERPARTICLEOUTLINE = i;
#ifdef _DEBUG
		m_bPERPARTICLEOUTLINE = true;
#endif
	}
	void SetPERPARTICLEOUTLINE( bool i )
	{
		m_nPERPARTICLEOUTLINE = i ? 1 : 0;
#ifdef _DEBUG
		m_bPERPARTICLEOUTLINE = true;
#endif
	}
public:
	// CONSTRUCTOR
	spritecard_vs30_Static_Index( IShaderShadow *pShaderShadow, IMaterialVar **params )
	{
#ifdef _DEBUG
		m_bDUALSEQUENCE = false;
#endif // _DEBUG
		m_nDUALSEQUENCE = 0;
#ifdef _DEBUG
		m_bADDBASETEXTURE2 = false;
#endif // _DEBUG
		m_nADDBASETEXTURE2 = 0;
#ifdef _DEBUG
		m_bEXTRACTGREENALPHA = false;
#endif // _DEBUG
		m_nEXTRACTGREENALPHA = 0;
#ifdef _DEBUG
		m_bDEPTHBLEND = false;
#endif // _DEBUG
		m_nDEPTHBLEND = 0;
#ifdef _DEBUG
		m_bANIMBLEND_OR_MAXLUMFRAMEBLEND1 = false;
#endif // _DEBUG
		m_nANIMBLEND_OR_MAXLUMFRAMEBLEND1 = 0;
#ifdef _DEBUG
		m_bCROP = false;
#endif // _DEBUG
		m_nCROP = 0;
#ifdef _DEBUG
		m_bPACKED_INTERPOLATOR = false;
#endif // _DEBUG
		m_nPACKED_INTERPOLATOR = 0;
#ifdef _DEBUG
		m_bSPRITECARDVERTEXFOG = false;
#endif // _DEBUG
		m_nSPRITECARDVERTEXFOG = 0;
#ifdef _DEBUG
		m_bHARDWAREFOGBLEND = false;
#endif // _DEBUG
		m_nHARDWAREFOGBLEND = 0;
#ifdef _DEBUG
		m_bPERPARTICLEOUTLINE = false;
#endif // _DEBUG
		m_nPERPARTICLEOUTLINE = 0;
	}
	int GetIndex()
	{
		// Asserts to make sure that we aren't using any skipped combinations.
		// Asserts to make sure that we are setting all of the combination vars.
#ifdef _DEBUG
		bool bAllStaticVarsDefined = m_bDUALSEQUENCE && m_bADDBASETEXTURE2 && m_bEXTRACTGREENALPHA && m_bDEPTHBLEND && m_bANIMBLEND_OR_MAXLUMFRAMEBLEND1 && m_bCROP && m_bPACKED_INTERPOLATOR && m_bSPRITECARDVERTEXFOG && m_bHARDWAREFOGBLEND && m_bPERPARTICLEOUTLINE;
		Assert( bAllStaticVarsDefined );
#endif // _DEBUG
		return ( 4 * m_nDUALSEQUENCE ) + ( 8 * m_nADDBASETEXTURE2 ) + ( 16 * m_nEXTRACTGREENALPHA ) + ( 32 * m_nDEPTHBLEND ) + ( 32 * m_nANIMBLEND_OR_MAXLUMFRAMEBLEND1 ) + ( 64 * m_nCROP ) + ( 128 * m_nPACKED_INTERPOLATOR ) + ( 256 * m_nSPRITECARDVERTEXFOG ) + ( 512 * m_nHARDWAREFOGBLEND ) + ( 512 * m_nPERPARTICLEOUTLINE ) + 0;
	}
};
#define shaderStaticTest_spritecard_vs30 vsh_forgot_to_set_static_DUALSEQUENCE + vsh_forgot_to_set_static_ADDBASETEXTURE2 + vsh_forgot_to_set_static_EXTRACTGREENALPHA + vsh_forgot_to_set_static_DEPTHBLEND + vsh_forgot_to_set_static_ANIMBLEND_OR_MAXLUMFRAMEBLEND1 + vsh_forgot_to_set_static_CROP + vsh_forgot_to_set_static_PACKED_INTERPOLATOR + vsh_forgot_to_set_static_SPRITECARDVERTEXFOG + vsh_forgot_to_set_static_HARDWAREFOGBLEND + vsh_forgot_to_set_static_PERPARTICLEOUTLINE + 0
class spritecard_vs30_Dynamic_Index
{
private:
	int m_nORIENTATION;
#ifdef _DEBUG
	bool m_bORIENTATION;
#endif
public:
	void SetORIENTATION( int i )
	{
		Assert( i >= 0 && i <= 3 );
		m_nORIENTATION = i;
#ifdef _DEBUG
		m_bORIENTATION = true;
#endif
	}
	void SetORIENTATION( bool i )
	{
		m_nORIENTATION = i ? 1 : 0;
#ifdef _DEBUG
		m_bORIENTATION = true;
#endif
	}
public:
	// CONSTRUCTOR
	spritecard_vs30_Dynamic_Index( IShaderDynamicAPI *pShaderAPI )
	{
#ifdef _DEBUG
		m_bORIENTATION = false;
#endif // _DEBUG
		m_nORIENTATION = 0;
	}
	int GetIndex()
	{
		// Asserts to make sure that we aren't using any skipped combinations.
		// Asserts to make sure that we are setting all of the combination vars.
#ifdef _DEBUG
		bool bAllDynamicVarsDefined = m_bORIENTATION;
		Assert( bAllDynamicVarsDefined );
#endif // _DEBUG
		return ( 1 * m_nORIENTATION ) + 0;
	}
};
#define shaderDynamicTest_spritecard_vs30 vsh_forgot_to_set_dynamic_ORIENTATION + 0
