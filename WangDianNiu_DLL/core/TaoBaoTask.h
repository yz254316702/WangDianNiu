#pragma once
#include <string>
#include "CommandTool.h"
#include "xpath_static.h"



typedef enum {
	TASK_STATUS_IDLE,
	TASK_STATUS_CHECK_DEVICE,
	TASK_STATUS_STARTING ,
	TASK_STATUS_WELCOME ,
	TASK_STATUS_CHECKWIFI ,
	TASK_STATUS_HOMEPAGE ,
	TASK_STATUS_TODO_SEARCH,
	TASK_STATUS_CHECK_SEARCH_RESULT,
	TASK_STATUS_SEARCH_TITLE,
	TASK_STATUS_CLICK_TITLE_IN,
	TASK_STATUS_VIEW_TARGET,
	TASK_STATUS_REFRESHVIEW,
	TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED,
	TASK_STATUS_CHANGE_SORT_OF_SEARCHED,
	TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT,
	TASK_STATUS_CHANGE_MIN_MAX_PRICE,
	TASK_STATUS_CHANGE_SEND_PLACE,
	TASK_STATUS_CLICK_SEND_PLACE,
	TASK_STATUS_SCROLL_IN_SEND_PLACE,
	TASK_STATUS_CONFIRM_SEARCH_FILTER,
	TASK_STATUS_AFTER_CHANGE_FILTER,
	TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET,
	TASK_STATUS_CLICK_PingLun,
	TASK_STATUS_VIEW_PingLun,
	TASK_STATUS_RETURN_TO_VIEWTARGET,
	TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP,
	TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP,
	TASK_STATUS_CLICK_SEC_TARGET_TITLE,
	TASK_STATUS_VIEW_SEC_TARGET,
	TASK_STATUS_CLOSE_TAOBAO,

	TASK_STATUS_EXIT,
	TASK_STATUS_UNKNOWN
};
class IEventCallBack;
class CDataSourceTool;
class CTaoBaoTask 
{
public:
	IEventCallBack *m_callBack;
public:
	CTaoBaoTask(void);
	CTaoBaoTask(std::string xmlPath,CommandTool *tool);
	~CTaoBaoTask(void);
	static std::vector<std::string> getDevices();
	int getTaskStatus();
	int getPageStatus();
	void startTask();
	void stopTask();
	void resetTask();
	void exitTask();
	void setCmdTool(CommandTool *tool);
	void setTaskStatus(int status);
	void setPageStatus(int status);
	void refreshXml();
	void getBoundsById(std::string idValue,TiXmlElement *root,int* left,int* top,int* right,int*bottom);
	void waitTaskStop();
	void checkDeviceStatus();
	void setEventCallBack(IEventCallBack *callback);
	//************************************
	// Method:    click
	// FullName:  CTaoBaoTask::click
	// Access:    public 
	// Returns:   int, 0-success
	// Qualifier:
	// Parameter: std::string idValue
	// Parameter: TiXmlElement * root
	//************************************
	int click(std::string idValue,TiXmlElement *root);
	bool checkElementById(std::string idValue,TiXmlElement *root );
	std::string getTextById(std::string idValue,TiXmlElement *root);
	bool checkNodesByIdAndText(std::string idValue, std::string textValue, TiXmlElement *root, std::string &outString);
	bool checkElementByText( std::string textValue,TiXmlElement *root );
	void getBoundsByText( std::string textValue,TiXmlElement *root,int* ileft,int* itop,int* iright,int *ibottom );
	int clickByText(std::string textValue, TiXmlElement* root);
public:
	CDataSourceTool *m_dataTool;
	CommandTool *m_CmdTool;
	bool m_bStarted;
	bool m_bStopManually;
	bool m_willExit;
	uintptr_t threadHandle;

	int m_deviceWidth;
	int m_deviceHeight;

public:
	uintptr_t  m_TaskHandle;
	int m_TaskStatus;
	TiXmlDocument * m_XDp_doc;
	TiXmlElement * m_XEp_main;
};

