// ALL SKIP STATEMENTS THAT AFFECT THIS SHADER!!!
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW
// defined $PIXELFOGTYPE && defined $WRITEWATERFOGTODESTALPHA && ( $PIXELFOGTYPE != 1 ) && $WRITEWATERFOGTODESTALPHA
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPTINT && $LIGHTING_PREVIEW && $FASTPATHENVMAPTINT
// defined $LIGHTING_PREVIEW && defined $FASTPATHENVMAPCONTRAST && $LIGHTING_PREVIEW && $FASTPATHENVMAPCONTRAST
// defined $LIGHTING_PREVIEW && defined $FASTPATH && $LIGHTING_PREVIEW && $FASTPATH
// ($FLASHLIGHT || $FLASHLIGHTSHADOWS) && $LIGHTING_PREVIEW

#pragma once
#include "shaderlib/cshader.h"
class sprite_ps20b_Static_Index
{
	unsigned int m_nVERTEXCOLOR : 2;
	unsigned int m_nCONSTANTCOLOR : 2;
	unsigned int m_nHDRTYPE : 2;
	unsigned int m_nSRGB : 2;
#ifdef _DEBUG
	bool m_bVERTEXCOLOR : 1;
	bool m_bCONSTANTCOLOR : 1;
	bool m_bHDRTYPE : 1;
	bool m_bSRGB : 1;
#endif	// _DEBUG
public:
	void SetVERTEXCOLOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nVERTEXCOLOR = i;
#ifdef _DEBUG
		m_bVERTEXCOLOR = true;
#endif	// _DEBUG
	}

	void SetCONSTANTCOLOR( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nCONSTANTCOLOR = i;
#ifdef _DEBUG
		m_bCONSTANTCOLOR = true;
#endif	// _DEBUG
	}

	void SetHDRTYPE( int i )
	{
		Assert( i >= 0 && i <= 2 );
		m_nHDRTYPE = i;
#ifdef _DEBUG
		m_bHDRTYPE = true;
#endif	// _DEBUG
	}

	void SetSRGB( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nSRGB = i;
#ifdef _DEBUG
		m_bSRGB = true;
#endif	// _DEBUG
	}

	sprite_ps20b_Static_Index( IShaderShadow* pShaderShadow, IMaterialVar** params )
	{
		m_nVERTEXCOLOR = 0;
		m_nCONSTANTCOLOR = 0;
		m_nHDRTYPE = 0;
		m_nSRGB = 0;
#ifdef _DEBUG
		m_bVERTEXCOLOR = false;
		m_bCONSTANTCOLOR = false;
		m_bHDRTYPE = false;
		m_bSRGB = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bVERTEXCOLOR && m_bCONSTANTCOLOR && m_bHDRTYPE && m_bSRGB );
		return ( 4 * m_nVERTEXCOLOR ) + ( 8 * m_nCONSTANTCOLOR ) + ( 16 * m_nHDRTYPE ) + ( 48 * m_nSRGB ) + 0;
	}
};

#define shaderStaticTest_sprite_ps20b psh_forgot_to_set_static_VERTEXCOLOR + psh_forgot_to_set_static_CONSTANTCOLOR + psh_forgot_to_set_static_HDRTYPE + psh_forgot_to_set_static_SRGB


class sprite_ps20b_Dynamic_Index
{
	unsigned int m_nHDRENABLED : 2;
	unsigned int m_nPIXELFOGTYPE : 2;
#ifdef _DEBUG
	bool m_bHDRENABLED : 1;
#endif	// _DEBUG
public:
	void SetHDRENABLED( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nHDRENABLED = i;
#ifdef _DEBUG
		m_bHDRENABLED = true;
#endif	// _DEBUG
	}

	void SetPIXELFOGTYPE( int i )
	{
		Assert( i >= 0 && i <= 1 );
		m_nPIXELFOGTYPE = i;
	}

	sprite_ps20b_Dynamic_Index( IShaderDynamicAPI* pShaderAPI )
	{
		m_nHDRENABLED = 0;
		m_nPIXELFOGTYPE = ( pShaderAPI->GetSceneFogMode() == MATERIAL_FOG_LINEAR_BELOW_FOG_Z ) ;
#ifdef _DEBUG
		m_bHDRENABLED = false;
#endif	// _DEBUG
	}

	int GetIndex() const
	{
		Assert( m_bHDRENABLED );
		return ( 1 * m_nHDRENABLED ) + ( 2 * m_nPIXELFOGTYPE ) + 0;
	}
};

#define shaderDynamicTest_sprite_ps20b psh_forgot_to_set_dynamic_HDRENABLED
