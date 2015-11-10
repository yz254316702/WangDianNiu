#include "StdAfx.h"
#include "pubInclude.h"
#include "TaoBaoTask.h"
#include <process.h>
#include "DataSourceTool.h"
#include "IEventCallBack.h"

std::string getTaskStatusString(int status) 
{
	std::string tmp;
	switch(status)
	{
	case TASK_STATUS_IDLE:
		tmp=("TASK_STATUS_IDLE");
		break;
	case TASK_STATUS_CHECK_DEVICE:
		tmp=("TASK_STATUS_CHECK_DEVICE");
		break;
	case TASK_STATUS_EXIT:
		tmp=("TASK_STATUS_EXIT");
		break;
	case TASK_STATUS_STARTING :
		tmp=("TASK_STATUS_STARTING");
		break;
	case TASK_STATUS_WELCOME :
		tmp=("TASK_STATUS_WELCOME");
		break;
	case TASK_STATUS_CHECKWIFI :
		tmp=("TASK_STATUS_CHECKWIFI");
		break;
	case TASK_STATUS_HOMEPAGE :
		tmp=("TASK_STATUS_HOMEPAGE");
		break;
	case TASK_STATUS_TODO_SEARCH:
		tmp=("TASK_STATUS_TODO_SEARCH");
		break;
	case TASK_STATUS_CHECK_SEARCH_RESULT:
		tmp=("TASK_STATUS_CHECK_SEARCH_RESULT");
		break;
	case TASK_STATUS_SEARCH_TITLE:
		tmp=("TASK_STATUS_SEARCH_TITLE");
		break;
	case TASK_STATUS_CLICK_TITLE_IN:
		tmp=("TASK_STATUS_CLICK_TITLE_IN");
		break;
	case TASK_STATUS_VIEW_TARGET:
		tmp=("TASK_STATUS_VIEW_TARGET");
		break;
	case TASK_STATUS_REFRESHVIEW:
		tmp=("TASK_STATUS_REFRESHVIEW");
		break;
	case TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED:
		tmp=("TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED");
		break;
	case TASK_STATUS_CHANGE_SORT_OF_SEARCHED:
		tmp=("TASK_STATUS_CHANGE_SORT_OF_SEARCHED");
		break;
	case TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT:
		tmp=("TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT");
		break;
	case TASK_STATUS_CHANGE_MIN_MAX_PRICE:
		tmp=("TASK_STATUS_CHANGE_MIN_MAX_PRICE");
		break;
	case TASK_STATUS_CHANGE_SEND_PLACE:
		tmp=("TASK_STATUS_CHANGE_SEND_PLACE");
		break;
	case TASK_STATUS_CLICK_SEND_PLACE:
		tmp=("TASK_STATUS_CLICK_SEND_PLACE");
		break;
	case TASK_STATUS_SCROLL_IN_SEND_PLACE:
		tmp=("TASK_STATUS_SCROLL_IN_SEND_PLACE");
		break;
	case TASK_STATUS_CONFIRM_SEARCH_FILTER:
		tmp=("TASK_STATUS_CONFIRM_SEARCH_FILTER");
		break;
	case TASK_STATUS_AFTER_CHANGE_FILTER:
		tmp=("TASK_STATUS_AFTER_CHANGE_FILTER");
		break;
	case TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET:
		tmp=("TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET");
		break;
	case TASK_STATUS_CLICK_PingLun:
		tmp=("TASK_STATUS_CLICK_PingLun");
		break;
	case TASK_STATUS_VIEW_PingLun:
		tmp=("TASK_STATUS_VIEW_PingLun");
		break;
	case TASK_STATUS_RETURN_TO_VIEWTARGET:
		tmp=("TASK_STATUS_RETURN_TO_VIEWTARGET");
		break;
	case TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP:
		tmp=("TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP");
		break;
	case TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP:
		tmp=("TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP");
		break;
	case TASK_STATUS_CLICK_SEC_TARGET_TITLE:
		tmp=("TASK_STATUS_CLICK_SEC_TARGET_TITLE");
		break;
	case TASK_STATUS_VIEW_SEC_TARGET:
		tmp=("TASK_STATUS_VIEW_SEC_TARGET");
		break;
	case TASK_STATUS_CLOSE_TAOBAO:
		tmp=("TASK_STATUS_CLOSE_TAOBAO");
		break;
	case TASK_STATUS_UNKNOWN:
		tmp=("TASK_STATUS_UNKNOWN");
		break;
	default:
		tmp ="ssssssssssssss";
		break;
	}
	
	return tmp;
}
void printTaskStatus(std::string pre_or_cur, int status)
{
	printLog("%s ----- %s\n",pre_or_cur.c_str(),getTaskStatusString(status).c_str());
}
void __cdecl taoBaoTask( LPVOID param )
{
	long tm_startViewTarget=0;
	long tm_startViewSecTarget=0;
	long tm_ViewPingLun=0;
	long tm_curTime=0;
	bool isPingLunViewed = false;

	int boundsX=0;
	int boundsY=0;
	int boundsX2=0;
	int boundsY2=0;
	int boundsX1=0;
	int boundsY1=0;
	int boundsX12=0;
	int boundsY12=0;
	int backStatus = TASK_STATUS_UNKNOWN;
	CTaoBaoTask *task = (CTaoBaoTask*)param;
	CDataSourceTool *dataTool  = task->m_dataTool;
	while (true)
	{
		if (task->m_willExit)
		{
			task->m_willExit = false;
			break;
		}
		if (task->m_bStopManually == true)
		{
			task->setTaskStatus(TASK_STATUS_IDLE);
			task->m_bStopManually = false;
		}
		if (task->getTaskStatus() == TASK_STATUS_IDLE)
		{
			Sleep(200);
			continue;
		}
		printTaskStatus("Pre     Task Status",backStatus);
		printTaskStatus("Current Task Status",task->getTaskStatus());
		switch(task->getTaskStatus())
		{
		case TASK_STATUS_CHECK_DEVICE://检测设备
			task->checkDeviceStatus();
			task->setTaskStatus(TASK_STATUS_IDLE);
			backStatus = TASK_STATUS_CHECK_DEVICE;
			break;
		case TASK_STATUS_STARTING://启动操作
			tm_startViewTarget=0;
			tm_startViewSecTarget = 0;
			tm_ViewPingLun=0;
			tm_curTime=0;
			isPingLunViewed = false;
			if (task->m_callBack)
			{
				task->m_callBack->taskStatusCallBack("正在启动淘宝应用");
			}
			task->m_CmdTool->clearPackageData((TAOBAO_PCK_NAME));
			task->m_CmdTool->startApp((TAOBAO_PCK_NAME),(TAOBAO_PCK_WELCOME_NAME));
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			backStatus = TASK_STATUS_STARTING;
			break;
		case TASK_STATUS_REFRESHVIEW://更新界面数据
			task->refreshXml();

			if (backStatus != TASK_STATUS_CHECKWIFI &&task->checkElementById(("com.taobao.taobao:id/TBDialog_buttons_OK"),task->m_XEp_main))
			{
				task->setTaskStatus(TASK_STATUS_CHECKWIFI);
			}
			else if (task->checkElementById(("com.taobao.taobao:id/vp_guide_photos"),task->m_XEp_main))
			{
				task->setTaskStatus(TASK_STATUS_WELCOME);
			}
			else if (backStatus != TASK_STATUS_HOMEPAGE &&task->checkElementById(("com.taobao.taobao:id/home_searchedit"),task->m_XEp_main))
			{
				task->setTaskStatus(TASK_STATUS_HOMEPAGE);
				if (task->m_callBack)
				{
					task->m_callBack->taskStatusCallBack("正在输入搜索关键字");
				}
			}
			else if (backStatus != TASK_STATUS_TODO_SEARCH &&task->checkElementById(("com.taobao.taobao:id/searchbtn"),task->m_XEp_main))
			{
				task->setTaskStatus(TASK_STATUS_TODO_SEARCH);
			}
			else if (backStatus == TASK_STATUS_TODO_SEARCH)
			{
				if (dataTool->SortType() == ("销量优先"))
				{
					task->setTaskStatus(TASK_STATUS_CHANGE_SORT_OF_SEARCHED);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在设置搜索结果的排序方式");
					}
				}
				else if (dataTool->SortType() != ("综合排序"))
				{
					task->setTaskStatus(TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在设置搜索结果的排序方式");
					}
				}
				else 
				{
					task->setTaskStatus(TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在设置筛选宝贝的过滤条件");
					}
				}
			}
			else if (backStatus == TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED)
			{
				if (task->checkElementByText(dataTool->SortType(),task->m_XEp_main))
				{
					task->setTaskStatus(TASK_STATUS_CHANGE_SORT_OF_SEARCHED);
				}
			}
			else if (backStatus == TASK_STATUS_CHANGE_SORT_OF_SEARCHED)
			{
				if (task->checkElementById(("com.taobao.taobao:id/filter_img_upanddown"),task->m_XEp_main))
				{
					task->setTaskStatus(TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在设置筛选宝贝的过滤条件");
					}
				}
				else
				{
					task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
				}
			}
			else if (backStatus == TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT)
			{
				if (task->checkElementById(("com.taobao.taobao:id/min_price"),task->m_XEp_main))
				{
					task->setTaskStatus(TASK_STATUS_CHANGE_MIN_MAX_PRICE);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在设置价格范围");
					}
				}
			}
			else if (backStatus == TASK_STATUS_CHANGE_MIN_MAX_PRICE)
			{
				if (task->getTextById(("com.taobao.taobao:id/user_location"),task->m_XEp_main) != dataTool->SendPlace())
				{
					task->setTaskStatus(TASK_STATUS_CHANGE_SEND_PLACE);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在设置区域");
					}
				}
				else
				{
					task->setTaskStatus(TASK_STATUS_CONFIRM_SEARCH_FILTER);
				}
			}
			else if (backStatus == TASK_STATUS_CHANGE_SEND_PLACE ||
				     backStatus == TASK_STATUS_SCROLL_IN_SEND_PLACE)
			{
				if (task->checkElementByText(dataTool->SendPlace(),task->m_XEp_main))
				{
					task->getBoundsByText(dataTool->SendPlace(),task->m_XEp_main,&boundsX,&boundsY,&boundsX2,&boundsY2);
					task->getBoundsById(("com.taobao.taobao:id/filter_confirm_btn"),task->m_XEp_main,&boundsX1,&boundsY1,&boundsX12,&boundsY12);
					if (boundsY+3 < boundsY1)
					{
						task->setTaskStatus(TASK_STATUS_CLICK_SEND_PLACE);
					}
					else
					{
						task->setTaskStatus(TASK_STATUS_SCROLL_IN_SEND_PLACE);
					}
				}
				else
				{
					task->setTaskStatus(TASK_STATUS_SCROLL_IN_SEND_PLACE);
				}
			}
			else if (backStatus == TASK_STATUS_CLICK_SEND_PLACE)
			{
				task->setTaskStatus(TASK_STATUS_CONFIRM_SEARCH_FILTER);
			}
			else if (backStatus == TASK_STATUS_CONFIRM_SEARCH_FILTER)
			{
				task->setTaskStatus(TASK_STATUS_AFTER_CHANGE_FILTER);
				if (task->m_callBack)
				{
					task->m_callBack->taskStatusCallBack("正在搜索的结果中查找宝贝");
				}
			}
			else if (backStatus == TASK_STATUS_AFTER_CHANGE_FILTER
				|| backStatus == TASK_STATUS_SEARCH_TITLE)
			{
				//if (task->checkElementByText(dataTool->getAllTitleForSearch(),task->m_XEp_main))
				if(task->checkNodesByIdAndText("com.taobao.taobao:id/title",dataTool->PartOfTitle(),task->m_XEp_main,dataTool->m_targetTitle))
				{//task->checkNodesByIdAndText()
					task->setTaskStatus(TASK_STATUS_CLICK_TITLE_IN);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在浏览宝贝");
					}
				}
				else
				{
					task->setTaskStatus(TASK_STATUS_SEARCH_TITLE);
				}
			}
			else if (TASK_STATUS_CLICK_TITLE_IN == backStatus)
			{
				if (task->checkElementById(("com.taobao.taobao:id/buy"),task->m_XEp_main))
				{
					tm_startViewTarget = GetTickCount();
					task->setTaskStatus(TASK_STATUS_VIEW_TARGET);
				}
				else
				{
					task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
				}
			}
			else if (TASK_STATUS_VIEW_TARGET == backStatus ||backStatus == TASK_STATUS_RETURN_TO_VIEWTARGET)
			{
				if (!isPingLunViewed && task->checkElementById("com.taobao.taobao:id/detail_main_comment_view_all_comments",task->m_XEp_main))
				{
					isPingLunViewed = true;
					task->setTaskStatus(TASK_STATUS_CLICK_PingLun);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在浏览评论");
					}
					tm_ViewPingLun = GetTickCount();
					break;
				}
				tm_curTime = GetTickCount();
				if ((tm_curTime-tm_startViewTarget)/1000 > dataTool->getviewTargetTime())
				{
					if (dataTool->isViewSecTarget())
					{
						backStatus = TASK_STATUS_VIEW_TARGET;
						task->setTaskStatus(TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET);
						if (task->m_callBack)
						{
							task->m_callBack->taskStatusCallBack("正在浏览商店首页和副宝贝");
						}
					}
					else
					{
						task->setTaskStatus(TASK_STATUS_CLOSE_TAOBAO);
					}
					break;
				}
				task->setTaskStatus(TASK_STATUS_VIEW_TARGET);
			}
			else if (backStatus == TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET)
			{
				if (task->checkElementById("com.taobao.taobao:id/shop_new_homepage_head_tab_shop_tv",task->m_XEp_main) && task->checkElementById("com.taobao.taobao:id/shop_new_homepage_head_tab_dongtai_tv",task->m_XEp_main))
				{
					task->setTaskStatus(TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP);
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("查看店铺中所有宝贝");
					}
				}
			}
			else if (backStatus == TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP)
			{
				task->setTaskStatus(TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP);
				if (task->m_callBack)
				{
					task->m_callBack->taskStatusCallBack("在店铺的宝贝中搜索副宝贝");
				}
			}
			else if (backStatus == TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP)
			{
				if (task->checkNodesByIdAndText("com.taobao.taobao:id/title",dataTool->Sec_partOfTitle(),task->m_XEp_main,dataTool->m_sec_targetTitle))
				{
					task->setTaskStatus(TASK_STATUS_CLICK_SEC_TARGET_TITLE);
					tm_startViewSecTarget = GetTickCount();
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("正在浏览副宝贝");
					}
				}
				else if (task->checkElementByText("加载完成",task->m_XEp_main))
				{
					if (task->m_callBack)
					{
						task->m_callBack->taskStatusCallBack("未查找到副宝贝");
					}
					task->setTaskStatus(TASK_STATUS_CLOSE_TAOBAO);
				}
				else
				{
					task->setTaskStatus(TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP);
				}
			}
			else if (TASK_STATUS_CLICK_SEC_TARGET_TITLE == backStatus)
			{
				task->setTaskStatus(TASK_STATUS_VIEW_SEC_TARGET);
			}
			else 
			{
				task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
				Sleep(100);
			}
			break;
		case TASK_STATUS_WELCOME://滑动欢迎界面
			task->m_CmdTool->swipe(task->m_deviceWidth-50,200,50,200);
			task->m_CmdTool->simulateClik(300,300);
			backStatus = TASK_STATUS_WELCOME;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
			break;
		case TASK_STATUS_CHECKWIFI://点击是否使用流量提示
			task->click(("com.taobao.taobao:id/TBDialog_buttons_OK"),task->m_XEp_main);
			backStatus = TASK_STATUS_CHECKWIFI;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_HOMEPAGE://在首页，点击搜索框
			task->click(("com.taobao.taobao:id/home_searchedit"),task->m_XEp_main);
			backStatus = TASK_STATUS_HOMEPAGE;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_TODO_SEARCH:
			//TODO : 很多判断来执行一些操作
			task->m_CmdTool->typeRawText(dataTool->getSearchKeyStrng());
			task->click(("com.taobao.taobao:id/searchbtn"),task->m_XEp_main);
			backStatus = TASK_STATUS_TODO_SEARCH;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_SEARCH_TITLE:
			//没有找到要查找的项目，滑动屏幕。
			task->m_CmdTool->swipe(200,task->m_deviceHeight-task->m_deviceHeight/9,200,task->m_deviceHeight*4/9);
			backStatus = TASK_STATUS_SEARCH_TITLE;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CLICK_TITLE_IN://点击标题进入宝贝
			task->clickByText(dataTool->TargetTitle(),task->m_XEp_main);
			backStatus = TASK_STATUS_CLICK_TITLE_IN;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_VIEW_TARGET://浏览找到的宝贝
			task->m_CmdTool->swipe(200,task->m_deviceHeight-task->m_deviceHeight/9,200,task->m_deviceHeight*4/9);
			backStatus = TASK_STATUS_VIEW_TARGET;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CLICK_PingLun:
			task->click("com.taobao.taobao:id/detail_main_comment_view_all_comments",task->m_XEp_main);
			backStatus = TASK_STATUS_CLICK_PingLun;
			task->setTaskStatus(TASK_STATUS_VIEW_PingLun);
			break;
		case TASK_STATUS_VIEW_PingLun:
			task->m_CmdTool->swipe(200,task->m_deviceHeight-task->m_deviceHeight/9,200,task->m_deviceHeight*4/9);
			tm_curTime = GetTickCount();
			if (tm_curTime - tm_ViewPingLun > dataTool->ViewPingLunTime()*1000)
			{
				backStatus = TASK_STATUS_VIEW_PingLun;
				task->setTaskStatus(TASK_STATUS_RETURN_TO_VIEWTARGET);
			}
			else
			{
				backStatus = TASK_STATUS_VIEW_PingLun;
				task->setTaskStatus(TASK_STATUS_VIEW_PingLun);
			}
			break;
		case TASK_STATUS_RETURN_TO_VIEWTARGET:
			task->m_CmdTool->simulateKey(4);
			Sleep(200);
			backStatus = TASK_STATUS_RETURN_TO_VIEWTARGET;
			task->setTaskStatus(TASK_STATUS_VIEW_TARGET);
			break;
		case TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED://点击弹出排序框
			task->click(("com.taobao.taobao:id/inner_sort_arrow"),task->m_XEp_main);
			backStatus = TASK_STATUS_PreCHANGE_SORT_OF_SEARCHED;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CHANGE_SORT_OF_SEARCHED://选择排序方式
			task->clickByText(dataTool->SortType(),task->m_XEp_main);
			backStatus = TASK_STATUS_CHANGE_SORT_OF_SEARCHED;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			Sleep(200);
			break;
		case TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT://点击筛选按钮
			task->click(("com.taobao.taobao:id/filter_img_upanddown"),task->m_XEp_main);
			backStatus = TASK_STATUS_SHAIXUAN_IN_SEARCH_RESULT;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CHANGE_MIN_MAX_PRICE://输入价格范围
			if (dataTool->MaxPrice() > 0)
			{
				task->click(("com.taobao.taobao:id/min_price"),task->m_XEp_main);
				task->m_CmdTool->typeRawText(dataTool->strMinPrice());
				task->click(("com.taobao.taobao:id/max_price"),task->m_XEp_main);
				task->m_CmdTool->typeRawText(dataTool->strMaxPrice());
			}
			backStatus = TASK_STATUS_CHANGE_MIN_MAX_PRICE;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CHANGE_SEND_PLACE:
			task->click(("com.taobao.taobao:id/location_expand_btn"),task->m_XEp_main);
			backStatus = TASK_STATUS_CHANGE_SEND_PLACE;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_SCROLL_IN_SEND_PLACE:
			task->m_CmdTool->swipe(350,500,300,250);
			backStatus = TASK_STATUS_SCROLL_IN_SEND_PLACE;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CLICK_SEND_PLACE:
			task->clickByText(dataTool->SendPlace(),task->m_XEp_main);
			backStatus = TASK_STATUS_CLICK_SEND_PLACE;
			task->setTaskStatus(TASK_STATUS_CONFIRM_SEARCH_FILTER);
			break;
		case TASK_STATUS_CONFIRM_SEARCH_FILTER:
			task->click(("com.taobao.taobao:id/filter_confirm_btn"),task->m_XEp_main);
			backStatus = TASK_STATUS_CONFIRM_SEARCH_FILTER;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_AFTER_CHANGE_FILTER:
			backStatus = TASK_STATUS_AFTER_CHANGE_FILTER;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET:
			task->click(("com.taobao.taobao:id/shop_title"),task->m_XEp_main);
			backStatus = TASK_STATUS_CLICK_SHOP_WHILE_VIEWING_TARGET;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP:
			task->clickByText("全部宝贝",task->m_XEp_main);
			backStatus = TASK_STATUS_CLICK_ALL_BAOBEI_IN_SHOP;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP:
			//没有找到要查找的项目，滑动屏幕。
			task->m_CmdTool->swipe(200,task->m_deviceHeight-task->m_deviceHeight/9,200,task->m_deviceHeight*4/9);
			backStatus = TASK_STATUS_SEARCH_SEC_TARGET_IN_SHOP;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_CLICK_SEC_TARGET_TITLE:
			task->clickByText(dataTool->Sec_targetTitle(),task->m_XEp_main);
			backStatus = TASK_STATUS_CLICK_SEC_TARGET_TITLE;
			task->setTaskStatus(TASK_STATUS_REFRESHVIEW);
			break;
		case TASK_STATUS_VIEW_SEC_TARGET:
			tm_curTime = GetTickCount();
			if (tm_curTime-tm_startViewSecTarget>dataTool->sec_viewTargetTime()*1000)
			{
				task->setTaskStatus(TASK_STATUS_CLOSE_TAOBAO);
			}
			else
			{
				task->m_CmdTool->swipe(200,task->m_deviceHeight-task->m_deviceHeight/9,200,task->m_deviceHeight*4/9);
				backStatus = TASK_STATUS_VIEW_SEC_TARGET;
				task->setTaskStatus(TASK_STATUS_VIEW_SEC_TARGET);
			}
			break;
		case TASK_STATUS_CLOSE_TAOBAO:
			if (task->m_callBack)
			{
				task->m_callBack->taskStatusCallBack("任务完成正在关闭淘宝");
			}
			task->m_CmdTool->stopApp((TAOBAO_PCK_NAME));
			task->resetTask();
			Sleep(3000);
			task->startTask();
			break;
		}
	}
}

CTaoBaoTask::CTaoBaoTask(void)
{
	m_willExit = false;
	m_bStarted = false;
	m_XEp_main = NULL;
	m_CmdTool = NULL;
	m_XDp_doc = NULL;
	m_TaskStatus = TASK_STATUS_IDLE;
	m_TaskHandle = 0;
	m_bStopManually = false;
	threadHandle = 0;
	m_callBack = NULL;
	m_dataTool = new CDataSourceTool();
}

CTaoBaoTask::CTaoBaoTask( std::string xmlPath ,CommandTool *tool)
{
	m_willExit = false;
	m_bStarted = false;
	m_XEp_main = NULL;
	m_XDp_doc = NULL;
	m_TaskStatus = TASK_STATUS_IDLE;
	m_TaskHandle = 0;
	m_bStopManually = false;
	threadHandle = 0;
	m_callBack = NULL;
	m_dataTool = new CDataSourceTool();
	setCmdTool(tool);
}

void CTaoBaoTask::setCmdTool( CommandTool *tool )
{
	if (tool)
	{
		m_CmdTool = tool;
		m_TaskStatus = TASK_STATUS_IDLE;
		m_CmdTool->getDeviceWidthHeight(&m_deviceWidth,&m_deviceHeight);
		if (threadHandle == 0)
		{
			threadHandle = _beginthread(taoBaoTask,0,this);
		}
	}
}


CTaoBaoTask::~CTaoBaoTask(void)
{
	if (m_XDp_doc != NULL)
	{
		delete m_XDp_doc;
	}
	if (m_dataTool != NULL)
	{
		delete m_dataTool;
	}
}

void CTaoBaoTask::startTask()
{
	m_TaskStatus = TASK_STATUS_STARTING;
	m_bStarted = true;
}

void CTaoBaoTask::stopTask()
{
	m_bStopManually = true;
}

void CTaoBaoTask::resetTask()
{
	m_TaskStatus = TASK_STATUS_IDLE;
	m_bStarted = false;
	m_bStopManually = false;
}

void CTaoBaoTask::setTaskStatus( int status )
{
	m_TaskStatus = status;
	if (TASK_STATUS_IDLE == m_TaskStatus  )
	{
		m_bStarted = false;
		m_bStopManually = false;
	}
	else if(TASK_STATUS_STARTING == m_TaskStatus)
	{
		m_bStarted = true;
	}
}

int CTaoBaoTask::getTaskStatus()
{
	return m_TaskStatus;
}

void CTaoBaoTask::refreshXml()
{
	std::string result = m_CmdTool->refreshView();
	Sleep(50);
	if (m_XDp_doc == NULL)
	{
		m_XDp_doc = new TiXmlDocument();
	}

	if (m_XDp_doc -> LoadFile(Window_Path_PC))
	{
		m_XEp_main = m_XDp_doc->RootElement();
	}
	else
	{
		delete m_XDp_doc;
		m_XDp_doc = NULL;
	}
}

void CTaoBaoTask::getBoundsById( std::string idValue,TiXmlElement *root,int* ileft,int* itop,int* iright,int *ibottom )
{
	std::string left ;
	std::string top ;
	std::string right ;
	std::string bottom ;
	std::string s_bounds;
	TiXmlString s1;
	int pos = 0;
	s_bounds = ("//*[@resource-id='");
	s_bounds +=	idValue;
	s_bounds += ("']/@bounds");
	std::wstring tmpWstr;
	ANSI_to_Unicode(s_bounds.c_str(),s_bounds.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),s_bounds);
	s1 = TinyXPath::S_xpath_string(root,s_bounds.c_str());
	if (s1.empty()||s1.length()==0)
	{
		return ;
	}
	s_bounds = s1.c_str();

	pos = s_bounds.find_first_of("0123456789");
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("[], ");
	if (pos == -1)
	{
		return ;
	}
	left = s_bounds.substr(0,pos);

	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("0123456789");
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("[], ");
	if (pos == -1)
	{
		return ;
	}
	top = s_bounds.substr(0, pos);

	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("0123456789");
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("[], ");
	if (pos == -1)
	{
		return ;
	}
	right = s_bounds.substr(0, pos);

	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("0123456789");
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of("[], ");
	if (pos == -1)
	{
		return ;
	}
	bottom = s_bounds.substr(0, pos);
	*ileft = atoi(left.c_str())+1;
	*itop = atoi(top.c_str())+1;
	*iright = atoi(right.c_str());
	*ibottom = atoi(bottom.c_str());
	return ;
}
void CTaoBaoTask::getBoundsByText( std::string idValue,TiXmlElement *root,int* ileft,int* itop,int* iright,int *ibottom )
{
	int outLen = 0;
	std::string left ;
	std::string top ;
	std::string right ;
	std::string bottom ;
	std::string s_bounds;
	TiXmlString s1;
	int pos = 0;
	s_bounds = ("//*[@text='");
	s_bounds +=	idValue;
	s_bounds += ("']/@bounds");
	std::wstring tmpWstr;
	ANSI_to_Unicode(s_bounds.c_str(),s_bounds.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),s_bounds);
	s1 = TinyXPath::S_xpath_string(root,s_bounds.c_str());
	if (s1.empty()||s1.length()==0)
	{
		return ;
	}
	s_bounds = s1.c_str();

	pos = s_bounds.find_first_of(("0123456789"));
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("[], "));
	if (pos == -1)
	{
		return ;
	}
	left = s_bounds.substr(0, pos);

	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("0123456789"));
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("[], "));
	if (pos == -1)
	{
		return ;
	}
	top = s_bounds.substr(0, pos);

	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("0123456789"));
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("[], "));
	if (pos == -1)
	{
		return ;
	}
	right = s_bounds.substr(0, pos);

	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("0123456789"));
	if (pos == -1)
	{
		return ;
	}
	s_bounds = s_bounds.substr(pos);
	pos = s_bounds.find_first_of(("[], "));
	if (pos == -1)
	{
		return ;
	}
	bottom = s_bounds.substr(0, pos);
	*ileft = atoi(left.c_str())+1;
	*itop = atoi(top.c_str())+1;
	*iright = atoi(right.c_str());
	*ibottom = atoi(bottom.c_str());
	return ;
}
int CTaoBaoTask::clickByText(std::string textValue, TiXmlElement* root)
{
	int left;
	int top;
	int right;
	int bottom;
	getBoundsByText(textValue,root,&left,&top,&right,&bottom);
	if (bottom-  top> 0 && right- left> 0)
	{
		if (m_CmdTool->simulateClik(left,top) == TRUE)
		{
			return 0;
		}
	}
	return -1;
}
int CTaoBaoTask::click( std::string idValue,TiXmlElement *root )
{
	int left;
	int top;
	int right;
	int bottom;
	getBoundsById(idValue,root,&left,&top,&right,&bottom);
	if (bottom-  top> 0 && right- left> 0)
	{
		if (m_CmdTool->simulateClik(left,top) == TRUE)
		{
			return 0;
		}
	}
	return -1;
}

bool CTaoBaoTask::checkElementById( std::string idValue,TiXmlElement *root )
{
	std::string s_bounds;
	std::string idValueA;
	idValueA = idValue;
	TiXmlString s1;
	int pos = 0;//name(//*[@resource-id=' '])
	s_bounds = ("name(//*[@resource-id='");
	s_bounds +=	idValueA;
	s_bounds += ("'])");
	std::wstring tmpWstr;
	ANSI_to_Unicode(s_bounds.c_str(),s_bounds.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),s_bounds);
	s1 = TinyXPath::S_xpath_string(root,s_bounds.c_str());
	s_bounds = s1.c_str();
	if (s_bounds.empty()||s_bounds.length()==0 ||s_bounds.find("node")==-1)
	{
		return false;
	}
	return true;

}
bool CTaoBaoTask::checkElementByText( std::string idValue,TiXmlElement *root )
{
	int outLen=0;
	std::string s_bounds;
	TiXmlString s1;
	int pos = 0;//name(//*[@resource-id=' '])
	s_bounds = ("name(//*[@text='");
	s_bounds +=	idValue;
	s_bounds += ("'])");
	std::wstring tmpWstr;
	ANSI_to_Unicode(s_bounds.c_str(),s_bounds.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),s_bounds);
	s1 = TinyXPath::S_xpath_string(root,s_bounds.c_str());
	s_bounds = s1.c_str();
	if (s_bounds.empty()||s_bounds.length()==0 ||s_bounds.find(("node"))==-1)
	{
		return false;
	}
	return true;

}


void CTaoBaoTask::waitTaskStop()
{
	while (m_bStopManually)
	{
		Sleep(100);
	}
}

std::vector<std::string> CTaoBaoTask::getDevices()
{
	return CommandTool::getDevicesName();
}

void CTaoBaoTask::checkDeviceStatus()
{
	std::string *m_DeviceStatus= new std::string();
	std::string pckInfo;
	//SendMessage(m_hWnd,MY_MSG_CHECK_DEVICE_INPUTMETHOD,NULL,NULL);
	if (m_callBack)
	{
		m_callBack->deviceStatusCallBack("检查专用输入法");
	}
	if (!m_CmdTool->inputIsInstalled())
	{
		//install 

		char tmpPath[MAX_PATH]={0};
		std::string path;
		GetCurrentDirectoryA(MAX_PATH,tmpPath);
		path = tmpPath;
		//path+="\\Input.apk";
		if (m_CmdTool->installAPK(path,("Inpiut.apk")))
		{
			m_CmdTool->packageisInstalled((INPUT_METHOD_PCK_NAME));
		}
		else
		{
			//SendMessage(m_hWnd,MY_MSG_INSTALL_INPUT_FAILED,NULL,NULL);
			if (m_callBack)
			{
				m_callBack->deviceStatusCallBack("专用输入发安装失败");
				m_callBack->NotifyCheckEndCallBack(true);
			}
			return;
		}
	}

	m_CmdTool->setAndroidDefaultInputMethod(("com.owenyi.input/.InputService"));
	//SendMessage(m_hWnd,MY_MSG_CHECK_DEVICE_SYS_INFO,NULL,NULL);
	if (m_callBack)
	{
		m_callBack->deviceStatusCallBack("检测设备信息");
	}
	*m_DeviceStatus += m_CmdTool->getAndroidSysInfo();


	//SendMessage(m_hWnd,MY_MSG_CHECK_DEVICE_TAO_INSTALLED,NULL,NULL);
	if (m_callBack)
	{
		m_callBack->deviceStatusCallBack("检查淘宝是否安装");
	}
	if (!m_CmdTool->taoBaoIsInstalled())
	{
		//install 
	}


	//SendMessage(m_hWnd,MY_MSG_CHECK_DEVICE_APP_INFO,NULL,NULL);
	if (m_callBack)
	{
		m_callBack->deviceStatusCallBack("检查输入法和淘宝应用版本");
	}
	pckInfo = m_CmdTool->getAppInfo();
	*m_DeviceStatus += (" ");
	*m_DeviceStatus += pckInfo;

	//SendMessage(m_hWnd,MY_MSG_CHECK_DEVICE_END,(WPARAM)m_DeviceStatus,NULL);
	if (m_callBack)
	{
		m_callBack->deviceStatusCallBack(*m_DeviceStatus);
		m_callBack->NotifyCheckEndCallBack(true);
	}
	delete m_DeviceStatus;
}

std::string CTaoBaoTask::getTextById( std::string idValue,TiXmlElement *root )
{
	std::wstring wRet;
	int outLen=0;
	std::string s_bounds;
	TiXmlString s1;
	int pos = 0;//name(//*[@resource-id=' '])
	s_bounds = ("//*[@resource-id='");
	s_bounds +=	idValue;
	s_bounds += ("']/@text");
	std::wstring tmpWstr;
	ANSI_to_Unicode(s_bounds.c_str(),s_bounds.length(),tmpWstr);
	Unicode_to_UTF8(tmpWstr.c_str(),tmpWstr.length(),s_bounds);
	s1 = TinyXPath::S_xpath_string(root,s_bounds.c_str());
	s_bounds = s1.c_str();
	UTF8_to_Unicode(s_bounds.c_str(),s_bounds.length(),wRet);
	Unicode_to_ANSI(wRet.c_str(),wRet.length(),s_bounds);

	printLog("==getTextById== idValue = %s\n",idValue.c_str());
	printLog("==getTextById== Result  = %s\n",s_bounds.c_str());

	return s_bounds;

}

bool CTaoBaoTask::checkNodesByIdAndText( std::string idValue, std::string textValue, TiXmlElement *root, std::string &outString )
{
//	printLog("==checkNodesByIdAndText== idValue = %s\n",idValue.c_str());
//	printLog("==checkNodesByIdAndText== textValue = %s\n",textValue.c_str());
	TiXmlElement *nextElement = root;
	std::string idattr;
	std::string textattr;
	std::wstring wText;
	//循环遍历根节点下的兄弟节点
	while(nextElement)

	{
		const char *c_idattr = nextElement->Attribute("resource-id") ;
		if (!c_idattr)
		{
			goto ERROR__;
		}
		const char *c_textattr = nextElement->Attribute("text");
		if (!c_textattr)
		{
			goto ERROR__;
		}
		idattr=c_idattr ;
		textattr=c_textattr;
		
		UTF8_to_Unicode(textattr.c_str(),textattr.length(),wText);
		Unicode_to_ANSI(wText.c_str(),wText.length(),textattr);
	//	TiXmlAttribute * attr = nextElement->FirstAttribute();

		if (idattr == "com.taobao.taobao:id/title" )
		{

			printLog("id  :%s---%s\n",idattr.c_str(),textattr.c_str());
			if (textattr.find(textValue) != -1)
			{
				printLog("FOUND   ======= %s\n",textattr.c_str());
				m_dataTool->TargetTitle(textattr);
				return true;
			}
		}
ERROR__:
		//查找下一个兄弟节点的指针
		TiXmlElement * firtChildNode = nextElement->FirstChildElement();
		if (firtChildNode)
		{
			if (checkNodesByIdAndText(idValue,textValue,firtChildNode,outString))
			{
				return true;
			}
		}
		nextElement = nextElement->NextSiblingElement();

	}
	return false;
}

void CTaoBaoTask::setEventCallBack( IEventCallBack *callback )
{
	m_callBack = callback;
}

void CTaoBaoTask::exitTask()
{
	m_CmdTool->setAndroidDefaultInputMethod((""));
	if (threadHandle == 0)
	{
		return;
	}
	m_willExit = true;
	while(m_willExit == true){
		Sleep(100);
	}
}

