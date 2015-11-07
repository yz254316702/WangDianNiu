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

void CPublishTaskPageUI::DoInit()
{

}
