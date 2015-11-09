#pragma once
#define PUBLISH_TASK_PAGE "PublishTaskPage"
class CPublishTaskPageUI: public CContainerUI
{
public:
	CPublishTaskPageUI(CPaintManagerUI* pm);
	virtual ~CPublishTaskPageUI(void);
	virtual void CtrlInit();
	virtual LPCTSTR GetClass() const;
	virtual LPVOID GetInterface(LPCTSTR pstrName);
private:
	CPublishTaskPageUI(void);

	CPaintManagerUI *m_pPaintManager;

	CDialogBuilder m_builder;

public:
	DuiLib::CWkeWebkitUI *m_pWkeWebkit;
	DuiLib::CEditUI		*m_pEdit_total_title;				
	DuiLib::CEditUI		*m_pEdit_fu_biao_ti;				
	DuiLib::CEditUI		*m_pEdit_search_key;				
	DuiLib::CEditUI		*m_pEdit_target_price;				
	DuiLib::CComboUI	*m_pCombo_search_sort;
	DuiLib::CCheckBoxUI *m_pCheckbox_price_min_max;
	DuiLib::CEditUI		*m_pEdit_target_price_min;			
	DuiLib::CEditUI		*m_pEdit_target_price_max;			
	DuiLib::CCheckBoxUI *m_pCheckbox_mian_yun_fei;
	DuiLib::CCheckBoxUI *m_pCheckbox_tian_mao;
	DuiLib::CCheckBoxUI *m_pCheckbox_shouji_zhuanxiang;
	DuiLib::CCheckBoxUI *m_pCheckbox_jinbi_money;
	DuiLib::CCheckBoxUI *m_pCheckbox_huo_dao_fu_kuan;
	DuiLib::CCheckBoxUI *m_pCheckbox_qitian_tui_huo;
	DuiLib::CCheckBoxUI *m_pCheckbox_cu_xiao;
	DuiLib::CComboUI	*m_pCombo_send_place;
	DuiLib::CEditUI		*m_pEdit_max_search_time;			
	DuiLib::CEditUI		*m_pEdit_baobei_url;				
	DuiLib::CEditUI		*m_pEdit_view_main_baobei_time;		
	DuiLib::CComboUI	*m_pCombo_fu_baobei_count;
	DuiLib::CEditUI		*m_pEdit_view_fubaobei_time;		
	DuiLib::CComboUI	*m_pCombo_target_compare_count;
	DuiLib::CEditUI		*m_pEdit_view_other_shop_time;		
	DuiLib::CCheckBoxUI *m_pCheckbox_zhan_xian_baobei;
	DuiLib::CCheckBoxUI *m_pCheckbox_chakan_chanpin_canshu;
	DuiLib::CCheckBoxUI *m_pCheckbox_view_shop_homepage;
	DuiLib::CCheckBoxUI *m_pCheckbox_view_baobei_pingjia;
	DuiLib::CCheckBoxUI *m_pCheckbox_shoucang_baobei;
	DuiLib::CCheckBoxUI *m_pCheckbox_zhi_tong_che;

	DuiLib::CCheckBoxUI *m_pCheckbox_timer_for_publish;
	DuiLib::CEditUI		*m_pEdit_publish_timer_year;		
	DuiLib::CEditUI		*m_pEdit_publish_timer_month;		
	DuiLib::CEditUI		*m_pEdit_publish_timer_day;			
	DuiLib::CEditUI		*m_pEdit_publish_timer_hour;		
	DuiLib::CEditUI		*m_pEdit_publish_timer_minute;		

	DuiLib::CEditUI		*m_pEdit_publish_time_split;		
	DuiLib::CEditUI		*m_pEdit_publish_count;				

	DuiLib::CButtonUI	*m_pButtonUI_Check_found_or_not;
	DuiLib::CButtonUI	*m_pButtonUI_publish_task;

	void OnBtnClick_ButtonUI_Check_found_or_not();
	void OnBtnClick_ButtonUI_publish_task();

	bool m_bprice_min_maxChecked;
	void OnSelectChange_Checkbox_price_min_max();
	bool m_bmian_yun_feiChecked;
	void OnSelectChange_Checkbox_mian_yun_fei();
	bool m_btian_maoChecked;
	void OnSelectChange_Checkbox_tian_mao();
	bool m_bshouji_zhuanxiangChecked;
	void OnSelectChange_Checkbox_shouji_zhuanxiang();
	bool m_bjinbi_moneyChecked;
	void OnSelectChange_Checkbox_jinbi_money();
	bool m_bhuo_dao_fu_kuanChecked;
	void OnSelectChange_Checkbox_huo_dao_fu_kuan();
	bool m_bqitian_tui_huoChecked;
	void OnSelectChange_Checkbox_qitian_tui_huo();
	bool m_bcu_xiaoChecked;
	void OnSelectChange_Checkbox_cu_xiao();
	bool m_bzhan_xian_baobeiChecked;
	void OnSelectChange_Checkbox_zhan_xian_baobei();
	bool m_bchakan_chanpin_canshuChecked;
	void OnSelectChange_Checkbox_chakan_chanpin_canshu();
	bool m_bview_shop_homepageChecked;
	void OnSelectChange_Checkbox_view_shop_homepage();
	bool m_bview_baobei_pingjiaChecked;
	void OnSelectChange_Checkbox_view_baobei_pingjia();
	bool m_bshoucang_baobeiChecked;
	void OnSelectChange_Checkbox_shoucang_baobei();
	bool m_bzhi_tong_cheChecked;
	void OnSelectChange_Checkbox_zhi_tong_che();
	bool m_btimer_for_publishChecked;
	void OnSelectChange_Checkbox_timer_for_publish();


	DuiLib::CDuiString	m_sCombo_search_sort;
	DuiLib::CDuiString	m_sCombo_send_place;
	int					m_iCombo_fu_baobei_count;
	int					m_iCombo_target_compare_count;
	void OnItemSelect_ComboSearchSort();
	void OnItemSelect_ComboSendPlace();
	void OnItemSelect_ComboFuBaoBeiCount();
	void OnItemSelect_ComboTargetCompareCount();

	DuiLib::CDuiString		m_sEdit_total_title;
	DuiLib::CDuiString		m_sEdit_fu_biao_ti;
	DuiLib::CDuiString		m_sEdit_search_key;
	DuiLib::CDuiString		m_sEdit_target_price;
	DuiLib::CDuiString		m_sEdit_target_price_min;
	DuiLib::CDuiString		m_sEdit_target_price_max;
	DuiLib::CDuiString		m_sEdit_max_search_time;
	DuiLib::CDuiString		m_sEdit_baobei_url;
	DuiLib::CDuiString		m_sEdit_view_main_baobei_time;
	DuiLib::CDuiString		m_sEdit_view_fubaobei_time;
	DuiLib::CDuiString		m_sEdit_view_other_shop_time;
	DuiLib::CDuiString		m_sEdit_publish_timer_year;
	DuiLib::CDuiString		m_sEdit_publish_timer_month;
	DuiLib::CDuiString		m_sEdit_publish_timer_day;
	DuiLib::CDuiString		m_sEdit_publish_timer_hour;
	DuiLib::CDuiString		m_sEdit_publish_timer_minute;
	DuiLib::CDuiString		m_sEdit_publish_time_split;
	DuiLib::CDuiString		m_sEdit_publish_count;
};

