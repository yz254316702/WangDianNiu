#include "StdAfx.h"
#include "LoginDlg.h"


CLoginDlg::CLoginDlg(void)
{
}


CLoginDlg::~CLoginDlg(void)
{
}



//************************************
// Method:    GetSkinFile
// FullName:  CLoginDlg::GetSkinFile
// Access:    public 
// Returns:   UiLib::CDuiString
// Qualifier:
// Note:	  
//************************************
UiLib::CDuiString CLoginDlg::GetSkinFile()
{
	try
	{
		return CDuiString(_T("LogIn.xml"));
	}
	catch (...)
	{
		throw "CLoginDlg::GetSkinFile";
	}
}

UiLib::CDuiString CLoginDlg::GetSkinFolder()
{
	//DuiLib::CDuiString instancePath = CPaintManagerUI::GetInstancePath();
	//instancePath += "Skin\\";

	return _T("Skin\\");
}
//************************************
// Method:    GetWindowClassName
// FullName:  CLoginDlg::GetWindowClassName
// Access:    public 
// Returns:   LPCTSTR
// Qualifier: const
// Note:	  
//************************************
LPCTSTR CLoginDlg::GetWindowClassName() const
{
	try
	{
		return _T("Wang_Dian_Niu_Login");
	}
	catch (...)
	{
		throw "CLoginDlg::GetWindowClassName";
	}
}

//************************************
// Method:    HandleMessage
// FullName:  CLoginDlg::HandleMessage
// Access:    public 
// Returns:   LRESULT
// Qualifier:
// Parameter: UINT uMsg
// Parameter: WPARAM wParam
// Parameter: LPARAM lParam
// Note:	  
//************************************
LRESULT CLoginDlg::HandleMessage( UINT uMsg, WPARAM wParam, LPARAM lParam )
{
	try
	{
		//TODO
		return WindowImplBase::HandleMessage(uMsg,wParam,lParam);
	}
	catch (...)
	{
		throw "CLoginDlg::HandleMessage";
	}
}

void CLoginDlg::InitWindow()
{
	try
	{
		WindowImplBase::InitWindow();
		m_pBtnExitLogin = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("login_closebtn")));
		m_pBtnLogin = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btnLogin")));
		m_pBtnZhuCeZhangHao = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btnZhuCeZhangHao")));
		m_pBtnWangJiMiMa = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btnWangJiMiMa")));
		m_pEditUserName=static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit_user_name")));
		m_pEditPassWord=static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edit_user_password")));

		m_pBtnLogin->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnMouseEnter,UIEVENT_MOUSEENTER);
		m_pBtnLogin->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnMouseLeave,UIEVENT_MOUSELEAVE);
		m_pBtnLogin->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnLButtonDown,UIEVENT_BUTTONDOWN);
		m_pBtnLogin->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnLButtonUp,UIEVENT_BUTTONUP);
		m_pBtnZhuCeZhangHao->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnMouseEnter,UIEVENT_MOUSEENTER);
		m_pBtnZhuCeZhangHao->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnMouseLeave,UIEVENT_MOUSELEAVE);
		m_pBtnZhuCeZhangHao->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnLButtonDown,UIEVENT_BUTTONDOWN);
		m_pBtnZhuCeZhangHao->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnLButtonUp,UIEVENT_BUTTONUP);
		m_pBtnWangJiMiMa->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnMouseEnter,UIEVENT_MOUSEENTER);
		m_pBtnWangJiMiMa->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnMouseLeave,UIEVENT_MOUSELEAVE);
		m_pBtnWangJiMiMa->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnLButtonDown,UIEVENT_BUTTONDOWN);
		m_pBtnWangJiMiMa->OnEvent			+= MakeDelegate(this,&CLoginDlg::OnMsgBtnLButtonUp,UIEVENT_BUTTONUP);
	}
	catch (...)
	{
		throw "CLoginDlg::Init";
	}
}
//************************************
// ��������: Notify
// ��������: void
// ������Ϣ: TNotifyUI & msg
// ����˵��: 
//************************************
void CLoginDlg::Notify( TNotifyUI& msg )
{
	if( msg.sType == _T("click") )
	{
		if (msg.pSender == m_pBtnExitLogin)
		{
			this->Close(IDOK);
			return;
		}
	}
	WindowImplBase::Notify(msg);
}

//************************************
// Method:    OnFinalMessage
// FullName:  CLoginDlg::OnFinalMessage
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: HWND hWnd
// Note:	  
//************************************
void CLoginDlg::OnFinalMessage( HWND hWnd )
{
	try
	{
		//m_WndObj->UnInit();
		WindowImplBase::OnFinalMessage(hWnd);
		//PostQuitMessage(0);//--��һ��ᵼ���˳�Dialog�󣬳���Ҳ���˳���
		delete this;
	}
	catch (...)
	{
		throw "CLoginDlg::OnFinalMessage";
	}
}

bool CLoginDlg::OnMsgBtnMouseEnter( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	if (pTEventUI->pSender == m_pBtnLogin)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(3);
	}
	else if (pTEventUI->pSender == m_pBtnZhuCeZhangHao)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(5);
	}
	else if (pTEventUI->pSender == m_pBtnWangJiMiMa)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(5);
	}
	return true;
}

bool CLoginDlg::OnMsgBtnMouseLeave( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	if (pTEventUI->pSender == m_pBtnLogin)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(2);
	}
	else if (pTEventUI->pSender == m_pBtnZhuCeZhangHao)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(4);
	}
	else if (pTEventUI->pSender == m_pBtnWangJiMiMa)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(4);
	}
	return true;
}

bool CLoginDlg::OnMsgBtnLButtonDown( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	if (pTEventUI->pSender == m_pBtnLogin)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(2);
	}
	else if (pTEventUI->pSender == m_pBtnZhuCeZhangHao)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(4);
	}
	else if (pTEventUI->pSender == m_pBtnWangJiMiMa)
	{
		((CButtonUI*)(pTEventUI->pSender))->SetFont(4);
	}
	return true;
}

bool CLoginDlg::OnMsgBtnLButtonUp( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam )
{
	return true;
}
