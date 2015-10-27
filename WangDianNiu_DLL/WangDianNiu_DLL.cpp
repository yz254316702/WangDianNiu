// WangDianNiu_DLL.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include ".\core\TaoBaoTask.h"
#include ".\core\IEventCallBack.h"
#include "WangDianNiu_DLL.h"


int nCrt = 0;
FILE* fp_err;
FILE* fp_out;
void InitConsoleWindow()
{
#if DEBUG_MSG
	AllocConsole();
	fp_out = freopen("CONOUT$", "w", stdout);
#endif
	fp_err = freopen("wnd.log","w",stderr);
	setlocale(LC_ALL,"chs");
}
void FreeConsoleWindow()
{
	fclose( fp_err );
#if DEBUG_MSG
	fclose( fp_out );
	FreeConsole();
#endif
}


// This is the constructor of a class that has been exported.
// see WangDianNiu_DLL.h for the class definition
CWangDianNiu_DLL::CWangDianNiu_DLL()
{
	InitConsoleWindow();
	m_TaoBaoisIntalled = false;
	m_InputMethodIsInstalled = false;
	m_sDeviceStatus = ("");
	m_CurDeviceIndex = -1;
	m_TaoTaskList.clear();
	m_CmdTools.clear();
	m_TaoTask = new CTaoBaoTask();
	return;
}

CWangDianNiu_DLL::~CWangDianNiu_DLL()
{
	int i=0;
	delete m_TaoTask;
	for (i=0; i<m_CmdTools.size(); i++)
	{
		if (m_CmdTools[i] != NULL)
		{
			delete m_CmdTools[i];
		}
	}
	for (i=0; i<m_TaoTaskList.size(); i++)
	{
		if (m_TaoTaskList[i] != NULL)
		{
			delete m_TaoTaskList[i];
		}
	}
	FreeConsoleWindow();
}

int CWangDianNiu_DLL::Init( IEventCallBack* callback )
{
	if (callback == NULL)
	{
		printLog("CWangDianNiu_DLL Init callback is null\n");
	}
	m_pCallBackObj = callback;
	m_TaoTask->setEventCallBack(m_pCallBackObj);
	//chechDevice();
	return 0;
}

int CWangDianNiu_DLL::startTask()
{
	if (m_CurDeviceIndex!=-1 && m_TaoBaoisIntalled && m_InputMethodIsInstalled)
	{
		m_TaoTask->startTask();
		return 0;
	}
	return -1;
}

int CWangDianNiu_DLL::stopTask()
{
	if (m_TaoTask->m_bStarted)
	{
		m_TaoTask->stopTask();
		return 0;
	}
	return -1;
}

int CWangDianNiu_DLL::chechDevice()
{
	if (m_pCallBackObj)
	{
		m_pCallBackObj->NotifyCheckEndCallBack(false);
	}
	std::vector<std::string>deviceNames = CTaoBaoTask::getDevices();
	if (!deviceNames.empty() ||deviceNames.size() > 0)
	{
		for (UINT i = 0;i < deviceNames.size();i++)
		{
			CommandTool *cmdtool = new CommandTool();
			cmdtool->setAndroidDevice(deviceNames[i]);
			m_CmdTools.push_back(cmdtool);

		}
		m_CurDeviceIndex = 0;

		m_TaoTask->setCmdTool(m_CmdTools[m_CurDeviceIndex]);
		m_TaoTask->setTaskStatus(TASK_STATUS_CHECK_DEVICE);
		m_TaoBaoisIntalled = m_TaoTask->m_CmdTool->taoBaoIsInstalled();
		m_InputMethodIsInstalled = m_TaoTask->m_CmdTool->inputIsInstalled();
	}
	else
	{
		m_sDeviceStatus = "没有检测到设备或者设备没有打开USB调试选项";
		if (m_pCallBackObj)
		{
			m_pCallBackObj->deviceStatusCallBack(m_sDeviceStatus);
			m_pCallBackObj->NotifyCheckEndCallBack(true);
		}
	}
	return 0;
}

CWangDianNiu_DLL* CWangDianNiu_DLL::CreateInstance()
{
	static CWangDianNiu_DLL handle;
	return &handle;
}

int CWangDianNiu_DLL::UnInit()
{
	m_TaoTask->exitTask();
	return 0;
}

bool CWangDianNiu_DLL::isInitOK()
{
	return m_CurDeviceIndex!=-1 && m_TaoBaoisIntalled &&m_InputMethodIsInstalled;
}

bool CWangDianNiu_DLL::isTaskStarted()
{
	return m_TaoTask->m_bStarted;
}
