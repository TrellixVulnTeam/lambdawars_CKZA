//====== Copyright � Sandern Corporation, All rights reserved. ===========//
//
// Purpose: Safely wrap boost/python.hpp for usage in source engine code
//
// $NoKeywords: $
//=============================================================================//

#ifndef SRCPY_BOOSTPYTHON_H
#define SRCPY_BOOSTPYTHON_H
#ifdef _WIN32
#pragma once
#endif

#include <boost/python.hpp>

#ifdef _DEBUG
	// boost redefines _DEBUG to an empty define
	// This will result in a compile error when doing "#if _DEBUG"
	#undef _DEBUG
	#define _DEBUG 1
#endif // _DEBUG

#endif // SRCPY_BOOSTPYTHON_H