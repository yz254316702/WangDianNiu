// UiLibRedRain_app.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "UiLibRedRain_app.h"
#include "MainWnd.h"

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	EnableMemLeakCheck();

	HRESULT Hr = ::CoInitialize(NULL);
	if( FAILED(Hr) ) return 0;
	CWkeWebkitUI::WkeWebkit_Init();
	CPaintManagerUI::SetInstance(hInstance);
	//DuiLib::CDuiString instancePath = CPaintManagerUI::GetInstancePath();
	//instancePath += "Skin\\";
	//CPaintManagerUI::SetResourcePath(instancePath);


	CMainWnd* pFrame = new CMainWnd();
	if(pFrame == NULL)
		return 0;

	pFrame->Create(NULL,_T("ÍúµêÅ£"), UI_WNDSTYLE_FRAME, 0L, 0, 0, 1120, 600);
	pFrame->CenterWindow();
	::ShowWindow(*pFrame, SW_SHOW);

	CPaintManagerUI::MessageLoop();

	CWkeWebkitUI::WkeWebkit_Shutdown();
	::CoUninitialize();

	_CrtDumpMemoryLeaks();
	return 0;
}

