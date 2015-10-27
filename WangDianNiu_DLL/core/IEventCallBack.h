#pragma once
#include <string>
#ifdef WANGDIANNIU_DLL_EXPORTS
#define ICALLBACK_API __declspec(dllexport)
#else
#define ICALLBACK_API __declspec(dllimport)
#endif
class ICALLBACK_API IEventCallBack
{
public:
	IEventCallBack(void);
	virtual ~IEventCallBack(void);
public:
	virtual int deviceStatusCallBack(std::string result)=0;
	virtual int taskStatusCallBack(std::string result)=0;
	virtual int NotifyCheckEndCallBack(bool checkEnd)=0;
};

