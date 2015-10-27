// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"
#include "resource.h"

#define WIN32_LEAN_AND_MEAN             // Exclude rarely-used stuff from Windows headers
// Windows Header Files:
#include <windows.h>

// C RunTime Header Files
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: reference additional headers your program requires here

#include "Uilib.h"
using namespace UiLib;
//������ڴ����øú��������ڴ�й¶���
//�����˳�ǰ����_CrtDumpMemoryLeaks();�����ɲ鿴�ڴ�й¶��ID�ţ���ID�ſ���ΪBreakpoint�Ĳ���������ʱ��������Ӧλ���Զ��ϵ�
inline  void  EnableMemLeakCheck(int Breakpoint = 0){
	_CrtSetDbgFlag(_CrtSetDbgFlag(_CRTDBG_REPORT_FLAG)  |  _CRTDBG_LEAK_CHECK_DF);
	if(Breakpoint)
		_CrtSetBreakAlloc ( 1912 );
}

#ifdef _DEBUG
#define  new   new(_NORMAL_BLOCK, __FILE__, __LINE__) 
#endif 
#define _CRT_SECURE_NO_DEPRECATE


#if _MSC_VER == 1500
#ifdef _DEBUG
#ifndef Uilib_u_EXPORTS
#pragma comment(lib, ".Uilib_ud.lib")
#else
#pragma comment(lib, "Uilib_ud.lib")
#endif
#else
#ifndef Uilib_u_EXPORTS
#pragma comment(lib, "Uilib_u.lib")
#else
#pragma comment(lib, "Uilib_u.lib")
#endif
#endif
#endif

#if _MSC_VER == 1600
#ifdef _DEBUG
#ifndef Uilib_u_EXPORTS
#pragma comment(lib, "Uilib_ud.lib")
#else
#pragma comment(lib, "Uilib_ud.lib")
#endif
#else
#ifndef Uilib_u_EXPORTS
#pragma comment(lib, "Uilib_u.lib")
#else
#pragma comment(lib, "Uilib_u.lib")
#endif
#endif
#endif

#if _MSC_VER == 1700
#ifdef _DEBUG
#ifndef Uilib_u_EXPORTS
#pragma comment(lib, "Uilib_ud.lib")
#else
#pragma comment(lib, "Uilib_ud.lib")
#endif
#else
#ifndef Uilib_u_EXPORTS
#pragma comment(lib, "Uilib_u.lib")
#else
#pragma comment(lib, "Uilib_u_u.lib")
#endif
#endif
#endif

#pragma comment(lib,"WangDianNiu_DLL.lib")

typedef enum{
	USER_MSG_DEVICE_STATUS = WM_USER+100,
	USER_MSG_TASK_STATUS,
	USER_MSG_CHECK_DEVICE_END,
};