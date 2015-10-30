#pragma once
#include "core/IEventCallBack.h"
#include"WangDianNiu_DLL.h"
#include "DoTaskPageUI.h"
#include "PublishTaskPageUI.h"

class CMainWnd:public WindowImplBase, public IEventCallBack,  public CWkeWebkitLoadCallback  
{
public:
	CMainWnd(void);
	~CMainWnd(void);
	//IEventCallBack
	virtual int deviceStatusCallBack(std::string result);
	virtual int taskStatusCallBack(std::string result);
	virtual int NotifyCheckEndCallBack(bool checkEnd);
	//CWkeWebkitLoadCallback
	virtual void    OnLoadFailed();  
	virtual void    OnLoadComplete();  
	virtual void    OnDocumentReady();

	bool OnMsgBtnMouseEnter( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );
	bool OnMsgBtnMouseLeave( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );
	bool OnMsgBtnLButtonDown( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );
	bool OnMsgBtnLButtonUp( TEventUI* pTEventUI,LPARAM lParam,WPARAM wParam );


	CDuiString GetSkinFolder();
	CDuiString GetSkinFile();
	LPCTSTR GetWindowClassName() const ;
	LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
	void InitWindow();
	void Notify(TNotifyUI& msg);
	void OnFinalMessage(HWND hWnd);
	void OnBnClickedButtonStarttask();
	void OnBnClickedButtonDevicecheck();
	void OnBnClickedButtonLogin();

	CControlUI* CreateControl(LPCTSTR pstrClass) 
	{
		if( _tcscmp(pstrClass, _T(DO_TASK_PAGE)) == 0 ) return new CDoTaskPageUI(&m_PaintManager);
		else if ( _tcscmp(pstrClass, _T(PUBLISH_TASK_PAGE)) == 0 ) return new CPublishTaskPageUI(&m_PaintManager);
		return NULL;
	}
private:
	CWangDianNiu_DLL *m_WndObj;
	CWkeWebkitUI	*m_pWke;
	CButtonUI* m_pCheckDeviceBtn;
	CButtonUI* m_pStartTaskBtn;
	CLabelUI*  m_pLabelDeviceStatus;
	CLabelUI*  m_pLabelTaskStatus;
	CButtonUI* m_pCreateLoginBtn;
	UiLib::CTabLayoutUI* m_pTabCtrl;
};

