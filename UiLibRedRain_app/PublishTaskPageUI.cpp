#include "StdAfx.h"
#include "PublishTaskPageUI.h"


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

CPublishTaskPageUI::CPublishTaskPageUI( CPaintManagerUI* pm ):
m_pPaintManager(pm)
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
	m_bzhan_xian_baobeiChecked = m_pCheckbox_zhi_tong_che->IsSelected();
}
void CPublishTaskPageUI::OnSelectChange_Checkbox_timer_for_publish()
{
	m_btimer_for_publishChecked = m_pCheckbox_timer_for_publish->IsSelected();
}

void CPublishTaskPageUI::DoInit11()
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
