
#pragma once
#include <vector>
#define Window_Path_Android "/sdcard/winDump.xml"
#define Window_Path_PC "c:\\winDump.xml"

#define MY_INPUT_METHOD_SERVICE "com.owenyi.input/.InputService"
#define BROADCAST_ACTION_TO_DEVICE "com.owenyi.input.INPUTSTRING"
#define INPUT_METHOD_PCK_NAME "com.owenyi.input"
#define TAOBAO_PCK_NAME "com.taobao.taobao"
#define TAOBAO_PCK_WELCOME_NAME "com.taobao.tao.welcome.Welcome"

class CommandTool
{
public:
	CommandTool();
	~CommandTool(void);
	void setAndroidDevice( std::string  name);
	void setAndroidDefaultInputMethod( std::string  m);
	void simulateKey(int keyValue);
	bool simulateClik(int paramInt1, int paramInt2);
	bool startApp( std::string package, std::string classname);
	int stopApp( std::string  p);
	void swipe(int paramInt1, int paramInt2, int paramInt3, int paramInt4);//scroll
	void typeRawText(std::string value,bool bBack = true);
	std::string refreshView();
	bool clearPackageData( std::string pck);
	bool packageisInstalled( std::string  pck);
	 std::string  getAndroidSysInfo();
	 std::string  sendBroadcase2AndroidDevices( std::string  action, std::string  stringV,  std::string  boolV);
	static std::vector< std::string > getDevicesName();
	bool installAPK( std::string path,std::string file);
	 std::string  getAppInfo();
	bool taoBaoIsInstalled();
	bool inputIsInstalled();
	void getDeviceWidthHeight(int* w,int*h);
	
private:
	std::vector<std::string> m_inputMethods;
	bool m_isTaoBaoInstalled;
	bool m_isInputInstalled;
	 std::string  m_adb_device_name;
	std::vector< std::string > m_adb_device_name_list;
	 std::string  getAndroidInputMethod();
	 static std::string execCmd( std::string cmd);
	 std::string GetWorkDir();
	static void  splitString( std::string  s, std::string  subs,std::vector< std::string > *result,bool bAddOne);
	static std::string* stringTrim(std::string* text,std::string subs);
	static std::string stringReplaceAll(std::string *text,std::string subs,std::string newstr);
};

