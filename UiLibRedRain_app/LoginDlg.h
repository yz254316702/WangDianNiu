#pragma once
class CLoginDlg:public WindowImplBase
{
public:
	CLoginDlg(void);
	~CLoginDlg(void);


	CDuiString GetSkinFolder();
	CDuiString GetSkinFile();
	LPCTSTR GetWindowClassName() const ;
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void InitWindow();
	void Notify(TNotifyUI& msg);
	void OnFinalMessage(HWND hWnd);

	bool OnMsgBtnMouseEnter( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );
	bool OnMsgBtnMouseLeave( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );
	bool OnMsgBtnLButtonDown( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );
	bool OnMsgBtnLButtonUp( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );

private:
	CButtonUI * m_pBtnExitLogin;
	CButtonUI * m_pBtnLogin;
	CButtonUI * m_pBtnZhuCeZhangHao;
	CButtonUI * m_pBtnWangJiMiMa;
	DuiLib::CEditUI * m_pEditUserName;
	DuiLib::CEditUI * m_pEditPassWord;
};

