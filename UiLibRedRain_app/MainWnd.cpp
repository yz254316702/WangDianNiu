#include "StdAfx.h"
#include "MainWnd.h"
#include "LoginDlg.h"
#include "CWebEventHandler.h"

void ANSI_to_Unicode(const char* in, unsigned int len, std::wstring& out)
{
	int wbufferlen = (int)::MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,in,(int)len,NULL,0);
	wchar_t* pwbuffer = new wchar_t[wbufferlen+4];
	if ( NULL == pwbuffer )
	{
		return;
	}
	wbufferlen = (int)::MultiByteToWideChar(CP_ACP,MB_PRECOMPOSED,in,(int)len,pwbuffer,wbufferlen+2);
	pwbuffer[wbufferlen] = '\0';
	out.assign( pwbuffer, wbufferlen );
	delete[] pwbuffer;
	return;
}

CMainWnd::CMainWnd(void)
{

}


CMainWnd::~CMainWnd(void)
{
}

//************************************
// Method:    GetSkinFile
// FullName:  CMainWnd::GetSkinFile
// Access:    public 
// Returns:   UiLib::CDuiString
// Qualifier:
// Note:	  
//************************************
UiLib::CDuiString CMainWnd::GetSkinFile()
{
	try
	{
		return CDuiString(_T("MainSkin.xml"));
	}
	catch (...)
	{
		throw "CMainWnd::GetSkinFile";
	}
}

UiLib::CDuiString CMainWnd::GetSkinFolder()
{
	//DuiLib::CDuiString instancePath = CPaintManagerUI::GetInstancePath();
	//instancePath += "Skin\\";

	return _T("Skin\\");
}
//************************************
// Method:    GetWindowClassName
// FullName:  CMainWnd::GetWindowClassName
// Access:    public 
// Returns:   LPCTSTR
// Qualifier: const
// Note:	  
//************************************
LPCTSTR CMainWnd::GetWindowClassName() const
{
	try
	{
		return _T("Wang_Dian_Niu");
	}
	catch (...)
	{
		throw "CMainWnd::GetWindowClassName";
	}
}

//************************************
// Method:    HandleMessage
// FullName:  CMainWnd::HandleMessage
// Access:    public 
// Returns:   LRESULT
// Qualifier:
// Parameter: UINT uMsg
// Parameter: WPARAM wParam
// Parameter: LPARAM lParam
// Note:	  
//************************************
LRESULT CMainWnd::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	try
	{
		//TODO
		if (uMsg == USER_MSG_DEVICE_STATUS)
		{
			std::wstring *val = (std::wstring *)lParam;
			m_pLabelDeviceStatus->SetText(val->c_str());
			return 0;
		}
		else if (uMsg == USER_MSG_TASK_STATUS)
		{
			std::wstring *val = (std::wstring *)lParam;
			m_pLabelTaskStatus->SetText(val->c_str());
			return 0;
		}
		else if (uMsg == USER_MSG_CHECK_DEVICE_END)
		{
			bool *val = (bool *)lParam;
			m_pCheckDeviceBtn->SetEnabled(*val);
			m_pStartTaskBtn->SetEnabled(*val);
			return 0;
		}
		return WindowImplBase::HandleMessage(uMsg,wParam,lParam);
	}
	catch (...)
	{
		throw "CMainWnd::HandleMessage";
	}
}

void CMainWnd::InitWindow()
{
	try
	{
		WindowImplBase::InitWindow();
		m_WndObj = CWangDianNiu_DLL::CreateInstance();
		m_WndObj->Init(this);
		m_pCheckDeviceBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("ButtonUI_CheckDevice")));
		m_pStartTaskBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("ButtonUI_StartTask")));
		m_pLabelDeviceStatus = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("LabelUI_DeviceStatus")));
		m_pLabelTaskStatus = static_cast<CTextUI*>(m_PaintManager.FindControl(_T("LabelUI_TaskStatus")));
		m_pCreateLoginBtn = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("loginbtn")));
		m_pTabCtrl = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("main_frame_tabCtrl")));

		m_pCreateLoginBtn->OnEvent			+= MakeDelegate(this,&CMainWnd::OnMsgBtnMouseEnter,UIEVENT_MOUSEENTER);
		m_pCreateLoginBtn->OnEvent			+= MakeDelegate(this,&CMainWnd::OnMsgBtnMouseLeave,UIEVENT_MOUSELEAVE);
		m_pCreateLoginBtn->OnEvent			+= MakeDelegate(this,&CMainWnd::OnMsgBtnLButtonDown,UIEVENT_BUTTONDOWN);
		m_pCreateLoginBtn->OnEvent			+= MakeDelegate(this,&CMainWnd::OnMsgBtnLButtonUp,UIEVENT_BUTTONUP);
#if 0
		CWebBrowserUI* pActiveXUI = static_cast<CWebBrowserUI*>(m_PaintManager.FindControl(_T("web_task_manager")));
		if( pActiveXUI ) 
		{
			pActiveXUI->SetDelayCreate(false);
			CCustomWebEventHandler *pWebHandle = new CCustomWebEventHandler;
			pActiveXUI->SetWebBrowserEventHandler(pWebHandle);
			pActiveXUI->Navigate2(L"about:blank");    //这行代码，如果注释掉，就不会去掉边框，IE有bug，第二次加载网页才会让事件处理器有效
			pActiveXUI->Navigate2(L"http://www.baidu.com/");
		}
#else

		m_pWke = static_cast<CWkeWebkitUI*>(m_PaintManager.FindControl(_T("web_task_manager")));
		if (m_pWke)
		{
			//jsBindFunction("msgBox", js_msgBox, 2);//这里绑定js函数，让js主动调用c++函数
			static wkeClientHandler hander;        //网页标题改变和URL改变的回调
			hander.onTitleChanged = NULL;
			hander.onURLChanged = NULL;
			m_pWke->SetClientHandler(&hander);
			m_pWke->SetLoadCallback(this);
			//m_pWke->SetFile(_T("Html/index.html")/*msg.pSender->GetText().GetData()*/);
			m_pWke->SetURL(L"http://www.baidu.com"); //一个漂亮的网站，大家可以自己试试
		}
#endif

	}
	catch (...)
	{
		throw "CMainWnd::Init";
	}
}
//************************************
// 函数名称: Notify
// 返回类型: void
// 参数信息: TNotifyUI & msg
// 函数说明: 
//************************************
void CMainWnd::Notify( TNotifyUI& msg )
{
	if( msg.sType == _T("click") )
	{
		if( msg.pSender == m_pStartTaskBtn )
		{
			OnBnClickedButtonStarttask();
			return; 
		}
		else if ( msg.pSender == m_pCheckDeviceBtn )
		{
			OnBnClickedButtonDevicecheck();
			return;
		}
		else if (msg.pSender == m_pCreateLoginBtn)
		{
			OnBnClickedButtonLogin();
			return;
		}
	}
	else if ( msg.sType == _T("selectchanged") )
	{	
		if (msg.pSender->GetName() == _T("OptionUI_StartTask"))
		{
			m_pTabCtrl->SelectItem(0);
		}
		else if( msg.pSender->GetName() == _T("OptionUI_PublishTask"))
		{
			m_pTabCtrl->SelectItem(1);
		}
	}
	WindowImplBase::Notify(msg);
}

//************************************
// Method:    OnFinalMessage
// FullName:  CMainWnd::OnFinalMessage
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: HWND hWnd
// Note:	  
//************************************
void CMainWnd::OnFinalMessage( HWND hWnd )
{
	try
	{
		//m_WndObj->UnInit();
		WindowImplBase::OnFinalMessage(hWnd);
		PostQuitMessage(0);
		delete this;
	}
	catch (...)
	{
		throw "CMainWnd::OnFinalMessage";
	}
}

int CMainWnd::deviceStatusCallBack( std::string result )
{
	static std::wstring deviceStatus = L"";
	ANSI_to_Unicode(result.c_str(),result.length(),deviceStatus);
	SendMessage(USER_MSG_DEVICE_STATUS,0,(LPARAM)&deviceStatus);
	return 0;
}

int CMainWnd::taskStatusCallBack( std::string result )
{
	static std::wstring taskStatus = L"";
	ANSI_to_Unicode(result.c_str(),result.length(),taskStatus);
	taskStatus =L"  " + taskStatus;
	SendMessage(USER_MSG_TASK_STATUS,0,(LPARAM)&taskStatus);
	return 0;
}

int CMainWnd::NotifyCheckEndCallBack( bool checkEnd )
{
	static bool s_checkEnd = false;
	s_checkEnd = checkEnd;
	SendMessage(USER_MSG_CHECK_DEVICE_END,0,(LPARAM)&s_checkEnd);
	return 0;
}

void CMainWnd::OnBnClickedButtonStarttask()
{
	if (!m_WndObj->isInitOK())
	{
		taskStatusCallBack("初始化失败,请检查设备是否连接或者USB调试选项是否打开");
		return;
	}
	if (m_WndObj->isTaskStarted())
	{
		m_WndObj->stopTask();
		m_pStartTaskBtn->SetText(_T("开始任务"));
	}
	else
	{
		m_WndObj->startTask();
		m_pStartTaskBtn->SetText(_T("结束任务"));
	}

}

void CMainWnd::OnBnClickedButtonDevicecheck()
{
	m_WndObj->chechDevice();
}

void CMainWnd::OnBnClickedButtonLogin()
{
	CLoginDlg *pLoginDlg = new CLoginDlg();
	pLoginDlg->Create(this->GetHWND(),L"Login",UI_WNDSTYLE_DIALOG&~WS_VISIBLE,WS_EX_WINDOWEDGE);
	pLoginDlg->CenterWindow();
	pLoginDlg->ShowModal();

}

bool CMainWnd::OnMsgBtnMouseEnter( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	if (pTEventUI->pSender == m_pCreateLoginBtn)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(2);
	}
	return true;
}

bool CMainWnd::OnMsgBtnMouseLeave( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	if (pTEventUI->pSender == m_pCreateLoginBtn)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(0);
	}
	return true;
}

bool CMainWnd::OnMsgBtnLButtonDown( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	if (pTEventUI->pSender == m_pCreateLoginBtn)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(0);
	}
	return true;
}

bool CMainWnd::OnMsgBtnLButtonUp( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	return true;
}

void CMainWnd::OnLoadFailed()
{
}

void CMainWnd::OnLoadComplete()
{
	//hide scrollbar in webpage
	//abort at getmessage
	//m_pWke->RunJS(_T("document.body.style.overflow='hidden'"));
}

void CMainWnd::OnDocumentReady()
{
}
