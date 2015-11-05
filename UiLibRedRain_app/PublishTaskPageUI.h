#pragma once
#define PUBLISH_TASK_PAGE "PublishTaskPage"
class CPublishTaskPageUI: public CContainerUI
{
public:
	CPublishTaskPageUI(CPaintManagerUI* pm);
	virtual ~CPublishTaskPageUI(void);
private:
	CPublishTaskPageUI(void);

	CPaintManagerUI *m_pPaintManager;

	CDialogBuilder m_builder;

public:
	CWkeWebkitUI *m_pWkeWebkit;
	DuiLib::CEditUI *m_pEdit_total_title;
	DuiLib::CEditUI *m_pEdit_fu_biao_ti;
	DuiLib::CEditUI *m_pEdit_search_key;
	DuiLib::CEditUI *m_pEdit_target_price;
	DuiLib::CComboUI *m_pCombo_search_sort;
	DuiLib::CCheckBoxUI *m_pCheckbox_price_min_max;
	DuiLib::CEditUI *m_pEdit_target_price_min;
	DuiLib::CEditUI *m_pEdit_target_price_max;
	DuiLib::CCheckBoxUI *m_pCheckbox_mian_yun_fei;
	DuiLib::CCheckBoxUI *m_pCheckbox_tian_mao;
	DuiLib::CCheckBoxUI *m_pCheckbox_shouji_zhuanxiang;
	DuiLib::CCheckBoxUI *m_pCheckbox_jinbi_money;
	DuiLib::CCheckBoxUI *m_pCheckbox_huo_dao_fu_kuan;
	DuiLib::CCheckBoxUI *m_pCheckbox_qitian_tui_huo;
	DuiLib::CCheckBoxUI *m_pCheckbox_cu_xiao;
	DuiLib::CComboUI *m_pCombo_send_place;
	DuiLib::CEditUI *m_pEdit_max_search_time;
	DuiLib::CEditUI *m_pEdit_baobei_url;
	DuiLib::CEditUI *m_pEdit_view_main_baobei_time;
	DuiLib::CComboUI *m_pCombo_fu_baobei_count;
	DuiLib::CEditUI *m_pEdit_view_fubaobei_time;
	DuiLib::CComboUI *m_pCombo_target_compare_count;
	DuiLib::CEditUI *m_pEdit_view_other_shop_time;
	DuiLib::CCheckBoxUI *m_pCheckbox_zhan_xian_baobei;
	DuiLib::CCheckBoxUI *m_pCheckbox_chakan_chanpin_canshu;
	DuiLib::CCheckBoxUI *m_pCheckbox_view_shop_homepage;
	DuiLib::CCheckBoxUI *m_pCheckbox_view_baobei_pingjia;
	DuiLib::CCheckBoxUI *m_pCheckbox_shoucang_baobei;
	DuiLib::CCheckBoxUI *m_pCheckbox_zhi_tong_che;

	DuiLib::CCheckBoxUI *m_pCheckbox_timer_for_publish;
	DuiLib::CEditUI *m_pEdit_publish_timer_year;
	DuiLib::CEditUI *m_pEdit_publish_timer_month;
	DuiLib::CEditUI *m_pEdit_publish_timer_day;
	DuiLib::CEditUI *m_pEdit_publish_timer_hour;
	DuiLib::CEditUI *m_pEdit_publish_timer_minute;

	DuiLib::CEditUI *m_pEdit_publish_time_split;
	DuiLib::CEditUI *m_pEdit_publish_count;

	DuiLib::CButtonUI *m_pButtonUI_Check_found_or_not;
	DuiLib::CButtonUI *m_pButtonUI_publish_task;
};

