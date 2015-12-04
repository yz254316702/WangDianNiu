#include "StdAfx.h"
#include "PublishTaskPageUI.h"
#include "tinyxml.h"
#include <iostream>
#include <fstream>
#include "WangDianNiu_DLL.h"

CPublishTaskPageUI::CPublishTaskPageUI(void):
m_pPaintManager(NULL)
{
	CContainerUI* pDoTaskPage = static_cast<CContainerUI*>(m_builder.Create(_T("PublishTaskPage.xml"), (UINT)0,NULL,m_pPaintManager));
	if( pDoTaskPage ) {
		this->Add(pDoTaskPage);
	}
	else {
		this->RemoveAll();
		return;
	}
}

CPublishTaskPageUI::CPublishTaskPageUI( CPaintManagerUI* pm )
:m_pPaintManager(pm)
,m_bprice_min_maxChecked(false)
,m_bmian_yun_feiChecked(false)
,m_btian_maoChecked(false)
,m_bshouji_zhuanxiangChecked(false)
,m_bjinbi_moneyChecked(false)
,m_bhuo_dao_fu_kuanChecked(false)
,m_bqitian_tui_huoChecked(false)
,m_bcu_xiaoChecked(false)
,m_bzhan_xian_baobeiChecked(false)
,m_bchakan_chanpin_canshuChecked(false)
,m_bview_shop_homepageChecked(false)
,m_bview_baobei_pingjiaChecked(false)
,m_bshoucang_baobeiChecked(false)
,m_bzhi_tong_cheChecked(false)
,m_btimer_for_publishChecked(false)
,m_sCombo_search_sort(_T(""))
,m_sCombo_send_place(_T(""))
,m_iCombo_fu_baobei_count(0)
,m_iCombo_target_compare_count(0)
,m_sEdit_total_title(_T(""))
,m_sEdit_fu_biao_ti(_T(""))
,m_sEdit_search_key(_T(""))
,m_sEdit_target_price(_T(""))
,m_sEdit_target_price_min(_T(""))
,m_sEdit_target_price_max(_T(""))
,m_sEdit_max_search_time(_T(""))
,m_sEdit_baobei_url(_T(""))
,m_sEdit_view_main_baobei_time(_T(""))
,m_sEdit_view_fubaobei_time(_T(""))
,m_sEdit_view_other_shop_time(_T(""))
,m_sEdit_publish_timer_year(_T(""))
,m_sEdit_publish_timer_month(_T(""))
,m_sEdit_publish_timer_day(_T(""))
,m_sEdit_publish_timer_hour(_T(""))
,m_sEdit_publish_timer_minute(_T(""))
,m_sEdit_publish_time_split(_T(""))
,m_sEdit_publish_count(_T(""))
{
	CContainerUI* pDoTaskPage = static_cast<CContainerUI*>(m_builder.Create(_T("PublishTaskPage.xml"), (UINT)0,NULL,m_pPaintManager));
	printf("pDoTaskPage is %p\n",pDoTaskPage);
	if( pDoTaskPage ) {
		this->Add(pDoTaskPage);
	}
	else {
		this->RemoveAll();
		return;
	}
}


CPublishTaskPageUI::~CPublishTaskPageUI(void)
{
}


void CPublishTaskPageUI::OnSelectChange_Checkbox_price_min_max()
{
	m_bprice_min_maxChecked = m_pCheckbox_price_min_max->IsSelected();
	m_pEdit_target_price_min->SetEnabled(m_bprice_min_maxChecked);
	m_pEdit_target_price_max->SetEnabled(m_bprice_min_maxChecked);
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_mian_yun_fei()
{
	m_bmian_yun_feiChecked = m_pCheckbox_mian_yun_fei->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_tian_mao()
{
	m_btian_maoChecked = m_pCheckbox_tian_mao->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_shouji_zhuanxiang()
{
	m_bshouji_zhuanxiangChecked = m_pCheckbox_shouji_zhuanxiang->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_jinbi_money()
{
	m_bjinbi_moneyChecked = m_pCheckbox_jinbi_money->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_huo_dao_fu_kuan()
{
	m_bhuo_dao_fu_kuanChecked = m_pCheckbox_huo_dao_fu_kuan->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_qitian_tui_huo()
{
	m_bqitian_tui_huoChecked = m_pCheckbox_qitian_tui_huo->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_cu_xiao()
{
	m_bcu_xiaoChecked = m_pCheckbox_cu_xiao->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_zhan_xian_baobei()
{
	m_bzhan_xian_baobeiChecked = m_pCheckbox_zhan_xian_baobei->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_chakan_chanpin_canshu()
{
	m_bchakan_chanpin_canshuChecked = m_pCheckbox_chakan_chanpin_canshu->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_view_shop_homepage()
{
	m_bview_shop_homepageChecked = m_pCheckbox_view_shop_homepage->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_view_baobei_pingjia()
{
	m_bview_baobei_pingjiaChecked = m_pCheckbox_view_baobei_pingjia->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_shoucang_baobei()
{
	m_bshoucang_baobeiChecked = m_pCheckbox_shoucang_baobei->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_zhi_tong_che()
{
	m_bzhi_tong_cheChecked = m_pCheckbox_zhi_tong_che->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_timer_for_publish()
{
	m_btimer_for_publishChecked = m_pCheckbox_timer_for_publish->IsSelected();

	m_pEdit_publish_timer_year->SetEnabled(m_btimer_for_publishChecked);
	m_pEdit_publish_timer_month->SetEnabled(m_btimer_for_publishChecked);
	m_pEdit_publish_timer_day->SetEnabled(m_btimer_for_publishChecked);
	m_pEdit_publish_timer_hour->SetEnabled(m_btimer_for_publishChecked);
	m_pEdit_publish_timer_minute->SetEnabled(m_btimer_for_publishChecked);
}

void CPublishTaskPageUI::OnItemSelect_ComboSearchSort()
{
	m_sCombo_search_sort = m_pCombo_search_sort->GetText();
}
void CPublishTaskPageUI::OnItemSelect_ComboSendPlace()
{
	m_sCombo_send_place = m_pCombo_send_place->GetText();
}
void CPublishTaskPageUI::OnItemSelect_ComboFuBaoBeiCount()
{
	m_iCombo_fu_baobei_count = m_pCombo_fu_baobei_count->GetCurSel();
}
void CPublishTaskPageUI::OnItemSelect_ComboTargetCompareCount()
{
	m_iCombo_target_compare_count = m_pCombo_target_compare_count->GetCurSel();
}

void CPublishTaskPageUI::OnBtnClick_ButtonUI_Check_found_or_not()
{

}
void CPublishTaskPageUI::OnBtnClick_ButtonUI_publish_task()
{
	m_sEdit_total_title				= m_pEdit_total_title->GetText();
	m_sEdit_fu_biao_ti				= m_pEdit_fu_biao_ti->GetText();
	m_sEdit_search_key				= m_pEdit_search_key->GetText();
	m_sEdit_target_price			= m_pEdit_target_price->GetText();
	m_sEdit_target_price_min		= m_pEdit_target_price_min->GetText();
	m_sEdit_target_price_max		= m_pEdit_target_price_max->GetText();
	m_sEdit_max_search_time			= m_pEdit_max_search_time->GetText();
	m_sEdit_baobei_url				= m_pEdit_baobei_url->GetText();
	m_sEdit_view_main_baobei_time	= m_pEdit_view_main_baobei_time->GetText();
	m_sEdit_view_fubaobei_time		= m_pEdit_view_fubaobei_time->GetText();
	m_sEdit_view_other_shop_time	= m_pEdit_view_other_shop_time->GetText();
	m_sEdit_publish_timer_year		= m_pEdit_publish_timer_year->GetText();
	m_sEdit_publish_timer_month		= m_pEdit_publish_timer_month->GetText();
	m_sEdit_publish_timer_day		= m_pEdit_publish_timer_day->GetText();
	m_sEdit_publish_timer_hour		= m_pEdit_publish_timer_hour->GetText();
	m_sEdit_publish_timer_minute	= m_pEdit_publish_timer_minute->GetText();
	m_sEdit_publish_time_split		= m_pEdit_publish_time_split->GetText();
	m_sEdit_publish_count			= m_pEdit_publish_count->GetText();
	printf(("手机搜索列表中完整的宝贝标题:%s\n"),m_sEdit_total_title.GetStringA().c_str());
	printf(("副标题:%s\n"),m_sEdit_fu_biao_ti.GetStringA().c_str());
	printf(("搜索关键字:%s\n"),m_sEdit_search_key.GetStringA().c_str());
	printf(("商品价格:%s\n"),m_sEdit_target_price.GetStringA().c_str());
	printf(("排序类型:%s\n"),m_sCombo_search_sort.GetStringA().c_str());
	printf(("限价区间:%d\n"),m_bzhan_xian_baobeiChecked);
	printf(("限价区间 MIN:%s  MAX:%s\n"),m_sEdit_target_price_min.GetStringA().c_str(),m_sEdit_target_price_max.GetStringA().c_str());
	printf("折扣和服务  免运费 %d\n",m_bmian_yun_feiChecked);
	printf("折扣和服务  天猫 %d\n",m_btian_maoChecked);
	printf("折扣和服务  手机专享 %d\n",m_bshouji_zhuanxiangChecked);
	printf("折扣和服务  淘金币抵钱 %d\n",m_bjinbi_moneyChecked);
	printf("折扣和服务  货到付款 %d\n",m_bhuo_dao_fu_kuanChecked);
	printf("折扣和服务  7+天退换货 %d\n",m_bqitian_tui_huoChecked);
	printf("折扣和服务  促销 %d\n",m_bcu_xiaoChecked);
	printf("发货地:%s\n",m_sCombo_send_place.GetStringA().c_str());
	printf(("搜索宝贝最大时间:%s\n"),m_sEdit_max_search_time.GetStringA().c_str());
	printf(("宝贝链接:%s\n"),m_sEdit_baobei_url.GetStringA().c_str());
	printf(("浏览主宝贝的时间:%s\n"),m_sEdit_view_main_baobei_time.GetStringA().c_str());
	printf("浏览副宝贝的数量 %d\n",m_iCombo_fu_baobei_count);
	printf("货比%d家再进店\n",m_iCombo_target_compare_count);
	printf(("浏览副宝贝的时间:%s\n"),m_sEdit_view_fubaobei_time.GetStringA().c_str());
	printf(("其他店铺浏览时间:%s\n"),m_sEdit_view_other_shop_time.GetStringA().c_str());
	printf("需要执行的操作  展现宝贝  %d\n",m_bzhan_xian_baobeiChecked);
	printf("需要执行的操作  查看产品参数  %d\n",m_bchakan_chanpin_canshuChecked);
	printf("需要执行的操作  浏览店铺首页  %d\n",m_bview_shop_homepageChecked);
	printf("需要执行的操作  浏览宝贝评价  %d\n",m_bview_baobei_pingjiaChecked);
	printf("需要执行的操作  收藏宝贝  %d\n",m_bshoucang_baobeiChecked);
	printf("需要执行的操作  直通车  %d\n",m_bzhi_tong_cheChecked);
	printf(("定时发布任务 %s年%s月%s日%s时%s分\n"),m_sEdit_publish_timer_year.GetStringA().c_str()
		,m_sEdit_publish_timer_month.GetStringA().c_str()
		,m_sEdit_publish_timer_day.GetStringA().c_str()
		,m_sEdit_publish_timer_hour.GetStringA().c_str()
		,m_sEdit_publish_timer_minute.GetStringA().c_str());
	printf(("流量时间间隔:%s\n"),m_sEdit_publish_time_split.GetStringA().c_str());
	printf(("任务数量:%s\n"),m_sEdit_publish_count.GetStringA().c_str());

	saveParams();
}

void CPublishTaskPageUI::CtrlInit()
{
	printf(" CPublishTaskPageUI::DoInit  m_pPaintManager = %p\n",m_pPaintManager);
	m_pEdit_total_title = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_total_title")));
	if (!m_pEdit_total_title) printf("m_pEdit_total_title is null\n");
	m_pEdit_fu_biao_ti = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_fu_biao_ti")));
	if (!m_pEdit_fu_biao_ti) printf("m_pEdit_fu_biao_ti is null\n");
	m_pEdit_search_key = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_search_key")));
	if (!m_pEdit_search_key) printf("m_pEdit_search_key is null\n");
	m_pEdit_target_price = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_target_price")));
	if (!m_pEdit_target_price) printf("m_pEdit_target_price is null\n");
	m_pCombo_search_sort = static_cast<CComboUI*>(m_pPaintManager->FindControl(_T("combo_search_sort")));
	if (!m_pCombo_search_sort) printf("m_pCombo_search_sort is null\n");
	m_pCheckbox_price_min_max = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_price_min_max")));
	if (!m_pCheckbox_price_min_max) printf("m_pCheckbox_price_min_max is null\n");
	m_pEdit_target_price_min = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_target_price_min")));
	if (!m_pEdit_target_price_min) printf("m_pEdit_target_price_min is null\n");
	m_pEdit_target_price_max = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_target_price_max")));
	if (!m_pEdit_target_price_max) printf("m_pEdit_target_price_max is null\n");
	m_pCheckbox_mian_yun_fei = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_mian_yun_fei")));
	if (!m_pCheckbox_mian_yun_fei) printf("m_pCheckbox_mian_yun_fei is null\n");
	m_pCheckbox_tian_mao = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_tian_mao")));
	if (!m_pCheckbox_tian_mao) printf("m_pCheckbox_tian_mao is null\n");
	m_pCheckbox_shouji_zhuanxiang = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_shouji_zhuanxiang")));
	if (!m_pCheckbox_shouji_zhuanxiang) printf("m_pCheckbox_shouji_zhuanxiang is null\n");
	m_pCheckbox_jinbi_money = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_jinbi_money")));
	if (!m_pCheckbox_jinbi_money) printf("m_pCheckbox_jinbi_money is null\n");
	m_pCheckbox_huo_dao_fu_kuan = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_huo_dao_fu_kuan")));
	if (!m_pCheckbox_huo_dao_fu_kuan) printf("m_pCheckbox_huo_dao_fu_kuan is null\n");
	m_pCheckbox_qitian_tui_huo = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_qitian_tui_huo")));
	if (!m_pCheckbox_qitian_tui_huo) printf("m_pCheckbox_qitian_tui_huo is null\n");
	m_pCheckbox_cu_xiao = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_cu_xiao")));
	if (!m_pCheckbox_cu_xiao) printf("m_pCheckbox_cu_xiao is null\n");
	m_pCombo_send_place = static_cast<CComboUI*>(m_pPaintManager->FindControl(_T("combo_send_place")));
	if (!m_pCombo_send_place) printf("m_pCombo_send_place is null\n");
	m_pEdit_max_search_time = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_max_search_time")));
	if (!m_pEdit_max_search_time) printf("m_pEdit_max_search_time is null\n");
	m_pEdit_baobei_url = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_baobei_url")));
	if (!m_pEdit_baobei_url) printf("m_pEdit_baobei_url is null\n");
	m_pEdit_view_main_baobei_time = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_view_main_baobei_time")));
	if (!m_pEdit_view_main_baobei_time) printf("m_pEdit_view_main_baobei_time is null\n");
	m_pCombo_fu_baobei_count = static_cast<CComboUI*>(m_pPaintManager->FindControl(_T("combo_fu_baobei_count")));
	if (!m_pCombo_fu_baobei_count) printf("m_pCombo_fu_baobei_count is null\n");
	m_pEdit_view_fubaobei_time = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_view_fubaobei_time")));
	if (!m_pEdit_view_fubaobei_time) printf("m_pEdit_view_fubaobei_time is null\n");
	m_pCombo_target_compare_count = static_cast<CComboUI*>(m_pPaintManager->FindControl(_T("combo_target_compare_count")));
	if (!m_pCombo_target_compare_count) printf("m_pCombo_target_compare_count is null\n");
	m_pEdit_view_other_shop_time = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_view_other_shop_time")));
	if (!m_pEdit_view_other_shop_time) printf("m_pEdit_view_other_shop_time is null\n");
	m_pCheckbox_zhan_xian_baobei = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_zhan_xian_baobei")));
	if (!m_pCheckbox_zhan_xian_baobei) printf("m_pCheckbox_zhan_xian_baobei is null\n");
	m_pCheckbox_chakan_chanpin_canshu = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_chakan_chanpin_canshu")));
	if (!m_pCheckbox_chakan_chanpin_canshu) printf("m_pCheckbox_chakan_chanpin_canshu is null\n");
	m_pCheckbox_view_shop_homepage = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_view_shop_homepage")));
	if (!m_pCheckbox_view_shop_homepage) printf("m_pCheckbox_view_shop_homepage is null\n");
	m_pCheckbox_view_baobei_pingjia = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_view_baobei_pingjia")));
	if (!m_pCheckbox_view_baobei_pingjia) printf("m_pCheckbox_view_baobei_pingjia is null\n");
	m_pCheckbox_shoucang_baobei = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_shoucang_baobei")));
	if (!m_pCheckbox_shoucang_baobei) printf("m_pCheckbox_shoucang_baobei is null\n");
	m_pCheckbox_zhi_tong_che = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_zhi_tong_che")));
	if (!m_pCheckbox_zhi_tong_che) printf("m_pCheckbox_zhi_tong_che is null\n");

	m_pCheckbox_timer_for_publish = static_cast<CCheckBoxUI*>(m_pPaintManager->FindControl(_T("checkbox_timer_for_publish")));
	if (!m_pCheckbox_timer_for_publish) printf("m_pCheckbox_timer_for_publish is null\n");
	m_pEdit_publish_timer_year = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_timer_year")));
	if (!m_pEdit_publish_timer_year) printf("m_pEdit_publish_timer_year is null\n");
	m_pEdit_publish_timer_month = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_timer_month")));
	if (!m_pEdit_publish_timer_month) printf("m_pEdit_publish_timer_month is null\n");
	m_pEdit_publish_timer_day = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_timer_day")));
	if (!m_pEdit_publish_timer_day) printf("m_pEdit_publish_timer_day is null\n");
	m_pEdit_publish_timer_hour = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_timer_hour")));
	if (!m_pEdit_publish_timer_hour) printf("m_pEdit_publish_timer_hour is null\n");
	m_pEdit_publish_timer_minute = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_timer_minute")));
	if (!m_pEdit_publish_timer_minute) printf("m_pEdit_publish_timer_minute is null\n");

	m_pEdit_publish_time_split = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_time_split")));
	if (!m_pEdit_publish_time_split) printf("m_pEdit_publish_time_split is null\n");
	m_pEdit_publish_count = static_cast<CEditUI*>(m_pPaintManager->FindControl(_T("edit_publish_count")));
	if (!m_pEdit_publish_count) printf("m_pEdit_publish_count is null\n");

	m_pButtonUI_Check_found_or_not = static_cast<CButtonUI*>(m_pPaintManager->FindControl(_T("ButtonUI_Check_found_or_not")));
	if (!m_pButtonUI_Check_found_or_not) printf("m_pButtonUI_Check_found_or_not is null\n");
	m_pButtonUI_publish_task = static_cast<CButtonUI*>(m_pPaintManager->FindControl(_T("ButtonUI_publish_task")));
	if (!m_pButtonUI_publish_task) printf("m_pButtonUI_publish_task is null\n");
	
	m_sCombo_search_sort = m_pCombo_search_sort->GetText();
	m_sCombo_send_place = m_pCombo_send_place->GetText();
	m_iCombo_fu_baobei_count = m_pCombo_fu_baobei_count->GetCurSel()+1;
	m_iCombo_target_compare_count = m_pCombo_target_compare_count->GetCurSel()+1;

	m_bmian_yun_feiChecked = true;
	m_pCheckbox_mian_yun_fei->Selected(true);
	m_bhuo_dao_fu_kuanChecked = true;
	m_pCheckbox_huo_dao_fu_kuan->Selected(true);
	m_bzhan_xian_baobeiChecked = true;
	m_pCheckbox_zhan_xian_baobei->Selected(true);
	m_bchakan_chanpin_canshuChecked=true;
	m_pCheckbox_chakan_chanpin_canshu->Selected(true);

	m_sEdit_max_search_time = _T("120");
	m_pEdit_max_search_time->SetText(m_sEdit_max_search_time);

	m_sEdit_view_main_baobei_time = _T("60");
	m_pEdit_view_main_baobei_time->SetText(_T("60"));

	m_sEdit_view_fubaobei_time = _T("20");
	m_pEdit_view_fubaobei_time->SetText(m_sEdit_view_fubaobei_time);

	m_sEdit_view_other_shop_time = _T("20");
	m_pEdit_view_other_shop_time->SetText(m_sEdit_view_other_shop_time);

	m_sEdit_publish_time_split = _T("360");
	m_pEdit_publish_time_split->SetText(m_sEdit_publish_time_split);

	m_sEdit_publish_count = _T("50");
	m_pEdit_publish_count->SetText(m_sEdit_publish_count);

	m_pEdit_target_price_min->SetEnabled(false);
	m_pEdit_target_price_max->SetEnabled(false);

	m_pEdit_publish_timer_year->SetEnabled(false);
	m_pEdit_publish_timer_month->SetEnabled(false);
	m_pEdit_publish_timer_day->SetEnabled(false);
	m_pEdit_publish_timer_hour->SetEnabled(false);
	m_pEdit_publish_timer_minute->SetEnabled(false);
}

LPCTSTR CPublishTaskPageUI::GetClass() const
{
	return _T("PublishTaskPageUI");
}

LPVOID CPublishTaskPageUI::GetInterface( LPCTSTR pstrName )
{
	if( _tcscmp(pstrName, _T(PUBLISH_TASK_PAGE)) == 0 ) return static_cast<CPublishTaskPageUI*>(this);
	return CContainerUI::GetInterface(pstrName);
}

void CPublishTaskPageUI::saveParams()
{
	TiXmlDeclaration * xmlDec = new TiXmlDeclaration("1.0", "UTF-8", "yes");  
	TiXmlDocument * xmlDocs = new TiXmlDocument();  
	xmlDocs->LinkEndChild(xmlDec);  
	TiXmlElement * elementParams = new TiXmlElement("TaskParams");  
	xmlDocs->LinkEndChild(elementParams);  
	TiXmlComment * comment = new TiXmlComment(" This is a list of task params ");  
	elementParams->LinkEndChild(comment);  

	TiXmlElement * element;
	TiXmlText * text;
	std::string textChar , base64Char;


	element = new TiXmlElement("m_bprice_min_maxChecked");  
	textChar = m_bprice_min_maxChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bprice_min_maxChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);  

	element = new TiXmlElement("m_bmian_yun_feiChecked");  
	textChar = m_bmian_yun_feiChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bmian_yun_feiChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_btian_maoChecked");  
	textChar = m_btian_maoChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_btian_maoChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);



	element = new TiXmlElement("m_bshouji_zhuanxiangChecked");  
	textChar = m_bshouji_zhuanxiangChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bshouji_zhuanxiangChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bjinbi_moneyChecked");  
	textChar = m_bjinbi_moneyChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bjinbi_moneyChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bhuo_dao_fu_kuanChecked");  
	textChar = m_bhuo_dao_fu_kuanChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bhuo_dao_fu_kuanChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bqitian_tui_huoChecked");  
	textChar = m_bqitian_tui_huoChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bqitian_tui_huoChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bcu_xiaoChecked");  
	textChar = m_bcu_xiaoChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bcu_xiaoChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bzhan_xian_baobeiChecked");  
	textChar = m_bzhan_xian_baobeiChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bzhan_xian_baobeiChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bchakan_chanpin_canshuChecked");  
	textChar = m_bchakan_chanpin_canshuChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bchakan_chanpin_canshuChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bview_shop_homepageChecked");  
	textChar = m_bview_shop_homepageChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bview_shop_homepageChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bview_baobei_pingjiaChecked");  
	textChar = m_bview_baobei_pingjiaChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bview_baobei_pingjiaChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bshoucang_baobeiChecked");  
	textChar = m_bshoucang_baobeiChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bshoucang_baobeiChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_bzhi_tong_cheChecked");  
	textChar = m_bzhi_tong_cheChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_bzhi_tong_cheChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_btimer_for_publishChecked");  
	textChar = m_btimer_for_publishChecked?"true":"false";
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_btimer_for_publishChecked?"true":"false");  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sCombo_search_sort");  
	textChar = m_sCombo_search_sort.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sCombo_search_sort.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sCombo_send_place");  
	textChar = m_sCombo_send_place.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sCombo_send_place.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_total_title");  
	textChar = m_sEdit_total_title.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_total_title.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_fu_biao_ti");  
	textChar = m_sEdit_fu_biao_ti.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_fu_biao_ti.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_search_key");  
	textChar = m_sEdit_search_key.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_search_key.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_baobei_url");  
	textChar = m_sEdit_baobei_url.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_baobei_url.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	char tmp[1000]={0};
	memset(tmp,0,1000);
	sprintf(tmp,"%d",m_iCombo_fu_baobei_count);
	element = new TiXmlElement("m_iCombo_fu_baobei_count");  
	textChar = tmp;
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(tmp);  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	memset(tmp,0,1000);
	sprintf(tmp,"%d",m_iCombo_target_compare_count);
	element = new TiXmlElement("m_iCombo_target_compare_count");  
	textChar = tmp;
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(tmp);  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_target_price");  
	textChar = m_sEdit_target_price.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_target_price.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_target_price_min");  
	textChar = m_sEdit_target_price_min.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_target_price_min.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_target_price_max");  
	textChar = m_sEdit_target_price_max.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_target_price_max.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_max_search_time");  
	textChar = m_sEdit_max_search_time.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_max_search_time.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_view_main_baobei_time");  
	textChar = m_sEdit_view_main_baobei_time.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_view_main_baobei_time.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_view_fubaobei_time");  
	textChar = m_sEdit_view_fubaobei_time.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_view_fubaobei_time.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_view_other_shop_time");  
	textChar = m_sEdit_view_other_shop_time.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_view_other_shop_time.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_timer_year");  
	textChar = m_sEdit_publish_timer_year.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_timer_year.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_timer_month");  
	textChar = m_sEdit_publish_timer_month.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_timer_month.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_timer_day");  
	textChar = m_sEdit_publish_timer_day.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_timer_day.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_timer_hour");  
	textChar = m_sEdit_publish_timer_hour.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_timer_hour.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_timer_minute");  
	textChar = m_sEdit_publish_timer_minute.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_timer_minute.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_time_split");  
	textChar = m_sEdit_publish_time_split.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_time_split.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);

	element = new TiXmlElement("m_sEdit_publish_count");  
	textChar = m_sEdit_publish_count.GetStringA().c_str();
	base64Char = CWangDianNiu_DLL::base64encode((const unsigned char*)textChar.c_str(),textChar.length());
	text = new TiXmlText(m_sEdit_publish_count.GetStringA().c_str());  
	element->LinkEndChild(text);  
	elementParams->LinkEndChild(element);
	
	TiXmlPrinter printer;
	xmlDocs->Accept(&printer);
	std::string xmlStr = printer.CStr();

	//ANSI_to_Unicode(xmlStr.c_str(),xmlStr.length(),unicode);
	//Unicode_to_UTF8(unicode.c_str(),unicode.length(),utf8);

	char filename[] = "c:\\result.xml"; 
	ofstream fout(filename);
	fout<<xmlStr.c_str()<<endl;
	fout.close();
	//xmlDocs->SaveFile("c:\\result.xml");  

	delete xmlDocs;  
}
