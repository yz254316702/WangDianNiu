// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the WANGDIANNIU_DLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// WANGDIANNIU_DLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef WANGDIANNIU_DLL_EXPORTS
#define WANGDIANNIU_DLL_API __declspec(dllexport)
#else
#define WANGDIANNIU_DLL_API __declspec(dllimport)
#endif
#include <string>
#include <vector>
class IEventCallBack;
class CTaoBaoTask;
class CommandTool;
// This class is exported from the WangDianNiu_DLL.dll
class WANGDIANNIU_DLL_API CWangDianNiu_DLL {
public:
	static CWangDianNiu_DLL* CreateInstance();
	~CWangDianNiu_DLL();
	// TODO: add your methods here.

	int Init(IEventCallBack* callback);
	int UnInit();
	int startTask();
	int stopTask();
	int chechDevice();
	bool isInitOK();
	bool isTaskStarted();
private:
	CWangDianNiu_DLL(void);
private:
	IEventCallBack *m_pCallBackObj;
	CTaoBaoTask *m_TaoTask;

	bool m_InputMethodIsInstalled;
	bool m_TaoBaoisIntalled;
	std::string m_sDeviceStatus;
	std::vector<CTaoBaoTask*> m_TaoTaskList;
	int m_CurDeviceIndex;
	std::vector<CommandTool*> m_CmdTools;
};

