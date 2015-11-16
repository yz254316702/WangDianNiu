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
		//wprintf(_T("HandleMessage --- msg = %d   : %d   %d\n"),uMsg,wParam,lParam);
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
		//publish 
		m_pPublishTaskPage = static_cast<CPublishTaskPageUI*>(m_PaintManager.FindControl(_T("Page_PublishTask")));
		m_pPublishTaskPage->CtrlInit();

		printf(" CMainWnd::InitWindow\n");
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
	//wprintf(_T("Notify --- msg type = %s  :  %s\n"),msg.sType,msg.pSender->GetName());
	if( msg.sType == DUI_MSGTYPE_CLICK )
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
		else if (msg.pSender == m_pPublishTaskPage->m_pButtonUI_Check_found_or_not)
		{
			m_pPublishTaskPage->OnBtnClick_ButtonUI_Check_found_or_not();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pButtonUI_publish_task)
		{
			m_pPublishTaskPage->OnBtnClick_ButtonUI_publish_task();
		}
	}
	else if ( msg.sType == DUI_MSGTYPE_SELECTCHANGED )
	{	
		if (msg.pSender->GetName() == _T("OptionUI_StartTask"))
		{
			m_pTabCtrl->SelectItem(0);
		}
		else if( msg.pSender->GetName() == _T("OptionUI_PublishTask"))
		{
			m_pTabCtrl->SelectItem(1);
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_price_min_max)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_price_min_max();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_mian_yun_fei)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_mian_yun_fei();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_tian_mao)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_tian_mao();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_shouji_zhuanxiang)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_shouji_zhuanxiang();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_jinbi_money)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_jinbi_money();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_huo_dao_fu_kuan)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_huo_dao_fu_kuan();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_qitian_tui_huo)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_qitian_tui_huo();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_cu_xiao)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_cu_xiao();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_zhan_xian_baobei)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_zhan_xian_baobei();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_chakan_chanpin_canshu)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_chakan_chanpin_canshu();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_view_shop_homepage)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_view_shop_homepage();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_view_baobei_pingjia)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_view_baobei_pingjia();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_shoucang_baobei)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_shoucang_baobei();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_zhi_tong_che)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_zhi_tong_che();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCheckbox_timer_for_publish)
		{
			m_pPublishTaskPage->OnSelectChange_Checkbox_timer_for_publish();
		}
	}
	else if (msg.sType == DUI_MSGTYPE_ITEMSELECT)
	{
		if (msg.pSender == m_pPublishTaskPage->m_pCombo_search_sort)
		{
			m_pPublishTaskPage->OnItemSelect_ComboSearchSort();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCombo_send_place)
		{
			m_pPublishTaskPage->OnItemSelect_ComboSendPlace();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCombo_fu_baobei_count)
		{
			m_pPublishTaskPage->OnItemSelect_ComboFuBaoBeiCount();
		}
		else if (msg.pSender == m_pPublishTaskPage->m_pCombo_target_compare_count)
		{
			m_pPublishTaskPage->OnItemSelect_ComboTargetCompareCount();
		}
	}
	else
	{
		//wprintf(_T("CMainWnd::Notify  - type = %s\n"),msg.sType);
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
