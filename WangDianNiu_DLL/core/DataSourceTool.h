#pragma once

#define SORT_BY_XINYONG "信用排序"
#define SORT_BY_ZONGHE "综合排序"
#define SORT_BY_JIAGE_UP "价格从低到高"
#define SORT_BY_JIAGE_DOWN "价格从高到低"
#define SORT_BY_XIAOLIANG_UP "销量优先"

#define YOUHUI_MIANYUNFEI "免运费"
#define YOUHUI_TIANMAO "天猫"
#define YOUHUI_QUANQIUGOU "全球购"
#define YOUHUI_BAOZHANG "消费者保障"

#ifdef WANGDIANNIU_DLL_EXPORTS
#define ICALLBACK_API __declspec(dllexport)
#else
#define ICALLBACK_API __declspec(dllimport)
#endif
class ICALLBACK_API CDataSourceTool
{
public:
	CDataSourceTool(void){
	};
	virtual ~CDataSourceTool(void){
	};
	std::string m_targetTitle;
	std::string m_FuTargetTitle;
	int m_viewPingLunTime;
	std::string strMinPrice(){
		char tmp[100] = {0};
		sprintf(tmp,"%d",sEdit_target_price_min());
		std::string stmp = tmp;
		return stmp;
	}
	std::string strMaxPrice(){
		char tmp[100] = {0};
		sprintf(tmp,"%d",sEdit_target_price_max());
		std::string stmp = tmp;
		return stmp;
	}


	virtual bool bprice_min_maxChecked()=0;
	virtual bool bmian_yun_feiChecked()=0;
	virtual bool btian_maoChecked()=0;
	virtual bool bshouji_zhuanxiangChecked()=0;
	virtual bool bjinbi_moneyChecked()=0;
	virtual bool bhuo_dao_fu_kuanChecked()=0;
	virtual bool bqitian_tui_huoChecked()=0;
	virtual bool bcu_xiaoChecked()=0;
	virtual bool bzhan_xian_baobeiChecked()=0;
	virtual bool bchakan_chanpin_canshuChecked()=0;
	virtual bool bview_shop_homepageChecked()=0;
	virtual bool bview_baobei_pingjiaChecked()=0;
	virtual bool bshoucang_baobeiChecked()=0;
	virtual bool bzhi_tong_cheChecked()=0;
	virtual bool btimer_for_publishChecked()=0;


	virtual std::string	sCombo_search_sort()=0;
	virtual std::string	sCombo_send_place()=0;
	virtual int					iCombo_fu_baobei_count()=0;
	virtual int					iCombo_target_compare_count()=0;

	virtual std::string		sEdit_part_of_title()=0;
	virtual std::string		sEdit_part_of_fu_biao_ti()=0;
	virtual std::string		sEdit_search_key()=0;
	virtual int		sEdit_target_price()=0;
	virtual int		sEdit_target_price_min()=0;
	virtual int		sEdit_target_price_max()=0;
	virtual int		sEdit_max_search_time()=0;
	virtual std::string		sEdit_baobei_url()=0;
	virtual int		sEdit_view_main_baobei_time()=0;
	virtual int		sEdit_view_fubaobei_time()=0;
	virtual int		sEdit_view_other_shop_time()=0;
	virtual int		sEdit_publish_timer_year()=0;
	virtual int		sEdit_publish_timer_month()=0;
	virtual int		sEdit_publish_timer_day()=0;
	virtual int		sEdit_publish_timer_hour()=0;
	virtual int		sEdit_publish_timer_minute()=0;
	virtual int		sEdit_publish_time_split()=0;
	virtual int		sEdit_publish_count()=0;


};

