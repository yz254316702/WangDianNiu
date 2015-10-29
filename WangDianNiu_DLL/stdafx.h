// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

#define  DEBUG_MSG 1
#if DEBUG_MSG
#define printLog(format, ...) fprintf(stdout, format, __VA_ARGS__);fprintf(stderr, format, __VA_ARGS__)
#else
#define printLog(format, ...) fprintf(stderr, format, __VA_ARGS__)
#endif