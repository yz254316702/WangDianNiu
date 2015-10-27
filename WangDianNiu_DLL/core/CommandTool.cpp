#include "StdAfx.h"
#include "pubInclude.h"
#include "CommandTool.h"
#include "Base64.h"
#include <SetupAPI.h>
#include <shellapi.h>


CommandTool::CommandTool()
{
	m_isTaoBaoInstalled = false;
	m_isInputInstalled = false;	
	m_adb_device_name.clear();
	m_adb_device_name_list.clear();
	m_inputMethods.clear();
}

CommandTool::~CommandTool(void)
{
}

std::string CommandTool::GetWorkDir()
{
#ifdef _UNICODE
	WCHAR pFileName[MAX_PATH];
#else
	CHAR pFileName[MAX_PATH];
#endif
	std::string  csFullPath("");  
	int nPos = GetCurrentDirectory( MAX_PATH, pFileName);
	Unicode_to_UTF8(pFileName,wcslen(pFileName),csFullPath);

	if( nPos < 0 )
	{
		return   ("");
	}
	else
	{
		return csFullPath;
	}

}

void CommandTool::setAndroidDefaultInputMethod(   std::string   m )
{
	std::string result;
	std::string   cmd;
	if (m_inputMethods.size() == 0 || m_inputMethods.empty())
	{
		getAndroidInputMethod();
	}
	if (m.empty()||m.size() == 0)
	{
		for (int i=0;i <m_inputMethods.size();i++)
		{
			if (m_inputMethods[i].find(MY_INPUT_METHOD_SERVICE) == -1)
			{
				cmd = ("adb -s ")+m_adb_device_name+(" shell ime set ")+m_inputMethods[i];
				execCmd(cmd);
				return;
			}
		}
	}
	else
	{
		cmd = ("adb -s ")+m_adb_device_name+(" shell ime enable ")+m;
		execCmd(cmd);
		cmd = ("adb -s ")+m_adb_device_name+(" shell ime set ")+m;
		result = execCmd(cmd	);
	}

}

void CommandTool::simulateKey( int keyValue )
{
	  std::string   cmd;
	  std::string  tmpcmd;
	  char tmp[30] = {0};
	  tmpcmd = _itoa_s(keyValue,tmp,10);
	cmd = ("adb -s ")+m_adb_device_name+(" shell input keyevent  ")+tmp;
	execCmd(cmd);
}

bool CommandTool::simulateClik( int paramInt1, int paramInt2 )
{
	  std::string   cmd,result;
	  char tmp[50] = {0};
	  sprintf_s(tmp," %d %d ",paramInt1,paramInt2);
	cmd =  ("adb -s ")+m_adb_device_name+(" shell input tap ");
	cmd.append(tmp);
	result = execCmd(cmd);
	if (result.find_first_of(("QWERTYUIOPASDFGHJKLZXCVBNMqwertyuiopasdfghjklzxcvbnm1234567890")) < 0)
	{
		return TRUE;
	}
	return FALSE;
}

bool CommandTool::startApp( std::string package, std::string classname )
{
	std::string cmd("");
	std::string res("");
	cmd = ("adb -s ")+m_adb_device_name+(" shell am start -n ")+package+("/")+classname;
	res = execCmd(cmd);
	std::string err(("Error type"));
	if (res.find(err) < 0)
	{
		return TRUE;
	}
	return FALSE;
}

int CommandTool::stopApp(   std::string   p )
{
	std::string   cmd;
	cmd =  ("adb -s ")+m_adb_device_name+(" shell am force-stop ")+ p;
	execCmd(cmd);
	return 0;
}

void CommandTool::swipe( int paramInt1, int paramInt2, int paramInt3, int paramInt4 )
{
	char tmp[100] = {0};
	std::string   cmd;
	cmd = ("adb -s ");
	cmd += m_adb_device_name;
	cmd += (" shell input swipe ");
	sprintf_s(tmp," %d %d %d %d ",paramInt1,paramInt2,paramInt3,paramInt4);
	cmd.append(tmp);
	execCmd(cmd);
}

void CommandTool::typeRawText( std::string value ,bool bBack)
{
#if 1
	//  std::string   cmd("adb  -s %s shell input text %s");
	int len=0;
	std::wstring tmpWstr;
	ANSI_to_Unicode(value.c_str(),value.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),value);
	std::string stmp = base64_encode((const unsigned char *)value.c_str(),value.length());
	//cmd.Format(cmd,m_adb_device_name,stmp.c_str());
	//execCmd(cmd);
	  std::string   action(BROADCAST_ACTION_TO_DEVICE);
	  std::string   stringV(stmp);
	  std::string   boolV("false");
	sendBroadcase2AndroidDevices(action,stringV,boolV);
#else
	std::string   cmd("");
	cmd = ("adb -s ")+m_adb_device_name+(" shell input text ");
	int len=0;
	std::wstring tmpWstr;
	ANSI_to_Unicode(value.c_str(),value.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),value);
	cmd += value;
	if (bBack)
	{
		Sleep(500);
		simulateKey(4);
		Sleep(500);
	}
	execCmd(cmd);
#endif
}

std::string CommandTool::refreshView()
{
	std::string   cmd;
	std::string s;
	cmd = ("adb -s ")+m_adb_device_name+(" shell rm ")+(Window_Path_Android);
	execCmd(cmd);//delete xml file

REDOCMD:
	cmd = ("adb -s ")+m_adb_device_name+(" shell uiautomator dump ") +(Window_Path_Android);
	s= execCmd(cmd);//create xml file
	if (s.find("UI hierchary dumped to:")== -1)
	{
		Sleep(400);
		goto REDOCMD;
	}

	cmd = ("adb -s ")+m_adb_device_name+(" pull ")+ (Window_Path_Android) +(" ")+(Window_Path_PC);
	//cmd = "adb -s "+m_adb_device_name+" shell cat "+Window_Path_Android;
	execCmd(cmd);
	return s;
}

bool CommandTool::clearPackageData( std::string pck )
{
	  std::string   cmd;
	  std::string result;
	cmd =  ("adb -s ")+m_adb_device_name+(" shell pm clear ") + pck;
	result = execCmd(cmd);
	if (result.find(("Success")) >= 0)
	{
		return TRUE;
	}
	return FALSE;
}

  std::string   CommandTool::getAndroidInputMethod()
{
	  std::string   cmd;
	  std::string result;
	cmd = ("adb -s ")+m_adb_device_name+(" shell ime list -s");
	result = execCmd(cmd);
	splitString(result,("\r\n"),&m_inputMethods,false);
	if (m_inputMethods.empty() ||m_inputMethods.size() == 0)
	{
		return ("");
	}
	int i = 0;
	while(i < m_inputMethods.size())
	{
		printLog("m_inputMethods  %d  %s\n",i,m_inputMethods[i]);
		i++;
	}
	return m_inputMethods[0];

}

  std::string CommandTool::execCmd( std::string cmd )
  {
	 printLog("[= execCmd =]:\n    %s\n",cmd.c_str());
	std::string ret = ("");
	SECURITY_ATTRIBUTES sa;
	HANDLE hRead,hWrite;
	//::MessageBoxA(NULL,str.c_str(),NULL,0);
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;
	if (!CreatePipe(&hRead,&hWrite,&sa,0))
	{
		return ret;
	}
	STARTUPINFOA si={sizeof(si)};
	PROCESS_INFORMATION pi;
	si.hStdError = hWrite;
	si.hStdOutput = hWrite;
	si.wShowWindow = SW_HIDE;
	si.dwFlags = STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
	long cmdStartTime ;
	long cmdENdTime ;
	if (!CreateProcessA(NULL,(LPSTR)cmd.c_str(),NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi))
	{
		return ret;
	}
	cmdStartTime = GetTickCount();

	CloseHandle(hWrite);

	char buffer[200];
	memset(buffer,0,200);
	std::string   output;
	DWORD byteRead;
	while(true)
	{
		if (ReadFile(hRead,buffer,190,&byteRead,NULL) == FALSE)
		{
			break;
		}
		output += buffer;
		cmdENdTime = GetTickCount();
		if (cmdENdTime - cmdStartTime > 10000)//20s
		{
			//不使用的句柄最好关掉
			TerminateProcess(pi.hProcess,0);
			break;
		}
	}

	CloseHandle(hRead);
	printLog("[= execCmd Result=]:\n    %s\n",output.c_str());

	return output;
}



bool CommandTool::packageisInstalled(   std::string   pck )
{
	  std::string   cmd;
	cmd = ("adb -s ")+m_adb_device_name+(" shell pm path ")+pck;
	  std::string   ret=execCmd(cmd);
	if (ret.empty() || ret.length() == 0)
	{
		m_isInputInstalled = false;
		return false;
	}
	else if(ret.find(("package:")) >= 0)
	{
		m_isInputInstalled = true;
		return true;
	}
	m_isInputInstalled = false;
	return false;
}

  std::string   CommandTool::getAndroidSysInfo( )
{
	int n = 0;
	  std::string   result;
	  std::string   cmd;
	cmd = ("adb -s ")+m_adb_device_name+(" shell getprop ro.product.brand");
	result += execCmd(cmd);
	n = result.find(("\r"));
	if (n>=0)
	{
		result = result.substr(0,n);
	}
	
	result += " ";
	cmd = ("adb -s ")+m_adb_device_name+(" shell getprop ro.product.model");
	result += execCmd(cmd);
	n = result.find(("\r"));
	if (n>=0)
	{
		result = result.substr(0,n);
	}
	result += " Android";
	cmd = ("adb -s ")+m_adb_device_name+(" shell getprop ro.build.version.release");
	result += execCmd(cmd);
	n = result.find(("\r"));
	if (n>=0)
	{
		result = result.substr(0,n);
	}
	return result;
}

  std::string   CommandTool::sendBroadcase2AndroidDevices(   std::string   action,  std::string   stringV,   std::string   boolV )
{
	  std::string   result;
	if (action.empty()||action.length()==0)
	{
		result=("");
		return result;
	}
	  std::string   cmd;
	cmd = ("adb -s ")+m_adb_device_name+(" shell am broadcast -a ")+action;
	if (false == (stringV.empty()||stringV.length()==0))
	{
		cmd +=(" --es string ");
		cmd +=stringV;
	}
	if (false == (boolV.empty()||boolV.length()==0))
	{
		cmd +=(" --ez boolean ");
		cmd +=boolV;
	}
	result = execCmd(cmd);
	return result;
}


  void CommandTool::getDeviceWidthHeight( int* w,int*h )
  {
	  std::string sW;
	  std::string sH;
	  std::string   cmd;
	  std::string ret;
	  *w = 720;
	  *h = 1280;
	  cmd = ("adb -s ")+m_adb_device_name+" shell dumpsys window displays";
	  ret = execCmd(cmd);
	  int findIndex = ret.find("init=");
	  if (ret.find("mDisplayId=")!= -1 && findIndex!= -1)
	  {
		  ret = ret.substr(findIndex);
		  ret = ret.substr(ret.find_first_of("0123456789"));
		  sW = ret.substr(0,ret.find_first_not_of("0123456789"));
		  ret = ret.substr(ret.find_first_not_of("0123456789"));
		  ret = ret.substr(ret.find_first_of("0123456789"));
		  sH = ret.substr(0,ret.find_first_not_of("0123456789"));
		  *w = atoi(sW.c_str());
		  *h = atoi(sH.c_str());
	  }
	  printLog("DEVICE　WIDTH*HEIGHT = %d * %d\n",*w,*h);
  }

  bool CommandTool::installAPK( std::string path,std::string file )
  {
	  std::string   cmd;
	  std::string ret;
#if 1
	cmd = ("adb -s ")+m_adb_device_name+(" install -r ")+path+("\\")+file;
	//cmd = "adb -s "+ m_adb_device_name+" push  " +path;
	//cmd+=" /sdcard/input.apk";
	// execCmd(cmd);
	// cmd = "adb -s "+m_adb_device_name+" shell pm install -r /sdcard/input.apk";
	 ret = execCmd(cmd);
	 return ret.find(("Success"))>=0?true:false;
#else
	  HINSTANCE hint;
	  cmd = " -s "+m_adb_device_name+" install "+file;
	  SHELLEXECUTEINFO ShExecInfo = {0};
	  ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	  ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	  ShExecInfo.hwnd = NULL;
	  ShExecInfo.lpVerb = NULL;
	  ShExecInfo.lpFile = "adb.exe ";
	  ShExecInfo.lpParameters = cmd.c_str();
	  ShExecInfo.lpDirectory = path.c_str();
	  ShExecInfo.nShow = SW_HIDE;
	  ShExecInfo.hInstApp = NULL;
	  ShellExecuteEx(&ShExecInfo);
	  WaitForSingleObject(ShExecInfo.hProcess,INFINITE);
	  return "";
#endif

}

void CommandTool::setAndroidDevice(   std::string   name )
{
	m_adb_device_name = name;
	m_isTaoBaoInstalled = packageisInstalled((TAOBAO_PCK_NAME));
	m_isInputInstalled = packageisInstalled((INPUT_METHOD_PCK_NAME));
}

std::vector<  std::string  > CommandTool::getDevicesName()
{
	std::vector<  std::string  > results;
	std::vector<  std::string  > results1;
	  std::string   cmd(("adb devices"));
	  std::string   result = execCmd(cmd);
	  std::string   split(("\r\n"));
	  std::string   split1(("\tdevice"));
	splitString(result,split,&results,false);
	if (results.empty() || results.size() <= 1)
	{
		return results1;
	}
	unsigned int i = 1;
	while (i < results.size())
	{
		splitString(results[i],split1,&results1,true);
		i++;
	}
	return results1;
}


  std::string   CommandTool::getAppInfo()
{
#if 0
	  std::string   result("");
	  std::string   action((BROADCAST_ACTION_TO_DEVICE));
	  std::string   boolV("true");

	  if (!m_isInputInstalled)
	  {
		  return ("");
	  }
	sendBroadcase2AndroidDevices(action,(("getappinfo")),boolV);
	Sleep(1000);
	  std::string   cmd;
	cmd = ("adb -s ")+m_adb_device_name+(" shell cat /data/data/com.owenyi.input/cache/pckInfo.txt");
	result = execCmd(cmd);
	if (result.find(("TaoBao")) < 0 && result.find(("Input")) < 0)
	{
		return ("");
	}
	int posTmp = result.find(("TaoBao"));
	if (posTmp >= 0)
	{
		result.replace(posTmp,strlen("TaoBao"),("淘宝"));
	}
	posTmp = result.find(("Input"));
	if (posTmp  >= 0)
	{
		result.replace(posTmp,strlen("Input"),("输入法"));
	}
	return result;
#else
	std::string   result("");
	std::string   resulttmp("");
	std::string taobaoPckName = TAOBAO_PCK_NAME;
	std::string inputPckName = INPUT_METHOD_PCK_NAME;
	std::string cmd = ("adb -s ")+m_adb_device_name+(" shell dumpsys  package ");
	cmd += taobaoPckName;
	cmd += " |grep versionName";
	std::string ret = execCmd(cmd);
	int findIndex = ret.find("versionName=");
	if (findIndex == -1)
	{
		result = "未安装淘宝 ";
	}
	else
	{
		result = ret.substr(findIndex+strlen("versionName="));
		result = result.substr(0,result.find_first_of("\r\n"));
		result = "淘宝:"+result;
	}
	cmd = ("adb -s ")+m_adb_device_name+(" shell dumpsys  package ");
	cmd += inputPckName;
	cmd += " |grep versionName";
	ret = execCmd(cmd);
	findIndex = ret.find("versionName=");
	if (findIndex == -1)
	{
		resulttmp = " 未安装专用输入法";
	}
	else
	{
		resulttmp = ret.substr(findIndex+strlen("versionName="));
		resulttmp = resulttmp.substr(0,resulttmp.find_first_of("\r\n"));
		resulttmp = " 专用输入法:"+resulttmp;
	}
	result += resulttmp;
	return result;
#endif
}

 void CommandTool::splitString(  std::string   s,   std::string   subs ,std::vector<  std::string  > *result,bool bAddOne)
{
	if (result == NULL)
	{
		return ;
	}

	int n = s.find(subs);

	if (n<0)
	{
		if (!bAddOne)
		{
			stringTrim(&s,subs);
			result->push_back(s);
		}
		
		return ;
	}
	if (n == 0)
	{
		s = s.substr(subs.length());
		splitString(s,subs,result,bAddOne);
	}
	if (n > 0)
	{
		std::string tmp = s.substr(0,n);
		stringTrim(&tmp,subs);
		result->push_back(tmp);
		if (bAddOne)
		{
			return;
		}
		s = s.substr(n+subs.length());
		if (s.empty() || s.length() == 0)
		{
			return;
		}
		splitString(s,subs,result,bAddOne);
	}
}

 bool CommandTool::taoBaoIsInstalled()
 {
	 return m_isTaoBaoInstalled;
 }

 bool CommandTool::inputIsInstalled()
 {
	 return m_isInputInstalled;
 }

std::string* CommandTool::stringTrim(std::string *text,std::string subs)
{
	if(text!= NULL && !text->empty())
	{
		if (text->find(subs) == 0)
		{
			text->erase(0,subs.length());
		}
		int tmpPos = text->rfind(subs);
		if (tmpPos > 0 && tmpPos+subs.length() == text->length())
		{
			text->erase(tmpPos);
		}

		if (text->find_first_of("\r\n\t")==0)
		{
			text->erase(0,text->find_first_not_of("\r\n\t"));
		}
		tmpPos = text->find_last_of("\r\n\t");
		if (tmpPos > 0 && tmpPos == text->length()-1)
		{
			text->erase(text->find_last_not_of("\r\n\t")+1);
		}
	}
	return text;
}

std::string CommandTool::stringReplaceAll( std::string *text,std::string subs ,std::string newstr)
{
	if (subs.empty()||text == NULL || text->empty())
	{
		return *text;
	}
	int tmpPos = -1;
	while ((tmpPos = text->find(subs)) > 0)
	{
		*text = text->replace(tmpPos,subs.length(),newstr);
	}
	return *text;
}