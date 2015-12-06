#pragma once
#include "Base64.h"
#include "pubInclude.h"
#include "xpath_static.h"
#define SORT_BY_XINYONG "��������"
#define SORT_BY_ZONGHE "�ۺ�����"
#define SORT_BY_JIAGE_UP "�۸�ӵ͵���"
#define SORT_BY_JIAGE_DOWN "�۸�Ӹߵ���"
#define SORT_BY_XIAOLIANG_UP "��������"

#define YOUHUI_MIANYUNFEI "���˷�"
#define YOUHUI_TIANMAO "��è"
#define YOUHUI_QUANQIUGOU "ȫ��"
#define YOUHUI_BAOZHANG "�����߱���"

class CDataSourceTool
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

	bool fetchTaskData(){

		TiXmlDocument * m_XDp_doc;
		TiXmlElement * m_XEp_main;
		m_XDp_doc = new TiXmlDocument();
		if (m_XDp_doc == NULL)
		{
			printf("fetchTaskData --- new TiXmlDocument() null\n");
			return false;
		}
		if (m_XDp_doc -> LoadFile("c:\\result.xml"))
		{
			m_XEp_main = m_XDp_doc->RootElement();
		}
		else
		{
			printf("fetchTaskData --- LoadFile failed\n");
			delete m_XDp_doc;
			m_XDp_doc = NULL;
			return false;
		}
		TiXmlString baseString;
		std::string ansiString;

		baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bprice_min_maxChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bprice_min_maxChecked = ansiString=="true"?true:false;

			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bmian_yun_feiChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bmian_yun_feiChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_btian_maoChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_btian_maoChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bshouji_zhuanxiangChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bshouji_zhuanxiangChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bjinbi_moneyChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bjinbi_moneyChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bhuo_dao_fu_kuanChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bhuo_dao_fu_kuanChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bqitian_tui_huoChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bqitian_tui_huoChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bcu_xiaoChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bcu_xiaoChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bzhan_xian_baobeiChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bzhan_xian_baobeiChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bchakan_chanpin_canshuChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bchakan_chanpin_canshuChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bview_shop_homepageChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bview_shop_homepageChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bview_baobei_pingjiaChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bview_baobei_pingjiaChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bshoucang_baobeiChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bshoucang_baobeiChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_bzhi_tong_cheChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_bzhi_tong_cheChecked = ansiString=="true"?true:false;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_btimer_for_publishChecked']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_btimer_for_publishChecked = ansiString=="true"?true:false;

			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_total_title']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_total_title = ansiString.c_str();
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_fu_biao_ti']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_fu_biao_ti = ansiString.c_str();
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_search_key']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_search_key = ansiString.c_str();


			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sCombo_search_sort']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sCombo_search_sort = ansiString.c_str();
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sCombo_send_place']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sCombo_send_place = ansiString.c_str();
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_total_title']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_total_title = ansiString.c_str();
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_fu_biao_ti']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_fu_biao_ti = ansiString.c_str();
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_baobei_url']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_baobei_url = ansiString.c_str();


			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_iCombo_fu_baobei_count']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_iCombo_fu_baobei_count = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_iCombo_target_compare_count']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_iCombo_target_compare_count = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_target_price']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_target_price = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_target_price_min']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_target_price_min = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_target_price_max']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_target_price_max = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_max_search_time']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_max_search_time = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_view_main_baobei_time']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_view_main_baobei_time = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_view_fubaobei_time']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_view_fubaobei_time = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_view_other_shop_time']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_view_other_shop_time = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_timer_year']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_timer_year = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_timer_month']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_timer_month = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_timer_day']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_timer_day = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_timer_hour']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_timer_hour = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_timer_minute']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_timer_minute = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_time_split']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_time_split = atoi(ansiString.c_str()) ;
			baseString = TinyXPath::S_xpath_string(m_XEp_main,"//*[name()='m_sEdit_publish_count']/text()");
		ansiString = base64_decode((const unsigned char *)baseString.c_str(),baseString.length());
		m_sEdit_publish_count = atoi(ansiString.c_str()) ;
		printLog(("fetchTaskData --- �ֻ������б��������ı�������:%s\n"),m_sEdit_total_title.c_str());
		printLog(("fetchTaskData --- ������:%s\n"),m_sEdit_fu_biao_ti.c_str());
		printLog(("fetchTaskData --- �����ؼ���:%s\n"),m_sEdit_search_key.c_str());
		printLog(("fetchTaskData --- ��Ʒ�۸�:%d\n"),m_sEdit_target_price);
		printLog(("fetchTaskData --- ��������:%s\n"),m_sCombo_search_sort.c_str());
		printLog(("fetchTaskData --- �޼�����:%d\n"),m_bzhan_xian_baobeiChecked);
		printLog(("fetchTaskData --- �޼����� MIN:%d  MAX:%d\n"),m_sEdit_target_price_min,m_sEdit_target_price_max);
		printLog("fetchTaskData --- �ۿۺͷ���  ���˷� %d\n",m_bmian_yun_feiChecked);
		printLog("fetchTaskData --- �ۿۺͷ���  ��è %d\n",m_btian_maoChecked);
		printLog("fetchTaskData --- �ۿۺͷ���  �ֻ�ר�� %d\n",m_bshouji_zhuanxiangChecked);
		printLog("fetchTaskData --- �ۿۺͷ���  �Խ�ҵ�Ǯ %d\n",m_bjinbi_moneyChecked);
		printLog("fetchTaskData --- �ۿۺͷ���  �������� %d\n",m_bhuo_dao_fu_kuanChecked);
		printLog("fetchTaskData --- �ۿۺͷ���  7+���˻��� %d\n",m_bqitian_tui_huoChecked);
		printLog("fetchTaskData --- �ۿۺͷ���  ���� %d\n",m_bcu_xiaoChecked);
		printLog("fetchTaskData --- ������:%s\n",m_sCombo_send_place.c_str());
		printLog(("fetchTaskData --- �����������ʱ��:%d\n"),m_sEdit_max_search_time);
		printLog(("fetchTaskData --- ��������:%s\n"),m_sEdit_baobei_url.c_str());
		printLog(("fetchTaskData --- �����������ʱ��:%d\n"),m_sEdit_view_main_baobei_time);
		printLog("fetchTaskData --- ��������������� %d\n",m_iCombo_fu_baobei_count);
		printLog("fetchTaskData --- ����%d���ٽ���\n",m_iCombo_target_compare_count);
		printLog(("fetchTaskData --- �����������ʱ��:%d\n"),m_sEdit_view_fubaobei_time);
		printLog(("fetchTaskData --- �����������ʱ��:%d\n"),m_sEdit_view_other_shop_time);
		printLog("fetchTaskData --- ��Ҫִ�еĲ���  չ�ֱ���  %d\n",m_bzhan_xian_baobeiChecked);
		printLog("fetchTaskData --- ��Ҫִ�еĲ���  �鿴��Ʒ����  %d\n",m_bchakan_chanpin_canshuChecked);
		printLog("fetchTaskData --- ��Ҫִ�еĲ���  ���������ҳ  %d\n",m_bview_shop_homepageChecked);
		printLog("fetchTaskData --- ��Ҫִ�еĲ���  �����������  %d\n",m_bview_baobei_pingjiaChecked);
		printLog("fetchTaskData --- ��Ҫִ�еĲ���  �ղر���  %d\n",m_bshoucang_baobeiChecked);
		printLog("fetchTaskData --- ��Ҫִ�еĲ���  ֱͨ��  %d\n",m_bzhi_tong_cheChecked);
		printLog(("fetchTaskData --- ��ʱ�������� %d��%d��%d��%dʱ%d��\n"),m_sEdit_publish_timer_year
			,m_sEdit_publish_timer_month
			,m_sEdit_publish_timer_day
			,m_sEdit_publish_timer_hour
			,m_sEdit_publish_timer_minute);
		printLog(("fetchTaskData --- ����ʱ����:%d\n"),m_sEdit_publish_time_split);
		printLog(("fetchTaskData --- ��������:%d\n"),m_sEdit_publish_count);


		delete m_XDp_doc;
		m_XDp_doc = NULL;
		return true;
	};

	bool bprice_min_maxChecked(){
		return m_bprice_min_maxChecked;
	};
	bool bmian_yun_feiChecked(){
		return m_bmian_yun_feiChecked;
	};
	bool btian_maoChecked(){
		return m_btian_maoChecked;
	};
	bool bshouji_zhuanxiangChecked(){
		return m_bshouji_zhuanxiangChecked;
	};
	bool bjinbi_moneyChecked(){
		return m_bjinbi_moneyChecked;
	};
	bool bhuo_dao_fu_kuanChecked(){
		return m_bhuo_dao_fu_kuanChecked;
	};
	bool bqitian_tui_huoChecked(){
		return m_bqitian_tui_huoChecked;
	};
	bool bcu_xiaoChecked(){
		return m_bcu_xiaoChecked;
	};
	bool bzhan_xian_baobeiChecked(){
		return m_bzhan_xian_baobeiChecked;
	};
	bool bchakan_chanpin_canshuChecked(){
		return m_bchakan_chanpin_canshuChecked;
	};
	bool bview_shop_homepageChecked(){
		return m_bview_shop_homepageChecked;
	};
	bool bview_baobei_pingjiaChecked(){
		return m_bview_baobei_pingjiaChecked;
	};
	bool bshoucang_baobeiChecked(){
		return m_bshoucang_baobeiChecked;
	};
	bool bzhi_tong_cheChecked(){
		return m_bzhi_tong_cheChecked;
	};
	bool btimer_for_publishChecked(){
		return m_btimer_for_publishChecked;
	};


	std::string	sCombo_search_sort(){
		return m_sCombo_search_sort;
	};
	std::string	sCombo_send_place(){
		return m_sCombo_send_place;
	};
	int					iCombo_fu_baobei_count(){
		return m_iCombo_fu_baobei_count;
	};
	int					iCombo_target_compare_count(){
		return m_iCombo_target_compare_count;
	};

	std::string		sEdit_part_of_title(){
		return m_sEdit_total_title;
	};
	std::string		sEdit_part_of_fu_biao_ti(){
		return m_sEdit_fu_biao_ti;
	};
	std::string		sEdit_search_key(){
		return m_sEdit_search_key;
	};
	int		sEdit_target_price(){
		return m_sEdit_target_price;
	};
	int		sEdit_target_price_min(){
		return m_sEdit_target_price_min;
	};
	int		sEdit_target_price_max(){
		return m_sEdit_target_price_max;
	};
	int		sEdit_max_search_time(){
		return m_sEdit_max_search_time;
	};
	std::string		sEdit_baobei_url(){
		return m_sEdit_baobei_url;
	};
	int		sEdit_view_main_baobei_time(){
		return m_sEdit_view_main_baobei_time;
	};
	int		sEdit_view_fubaobei_time(){
		return m_sEdit_view_fubaobei_time;
	};
	int		sEdit_view_other_shop_time(){
		return m_sEdit_view_other_shop_time;
	};
	int		sEdit_publish_timer_year(){
		return m_sEdit_publish_timer_year;
	};
	int		sEdit_publish_timer_month(){
		return m_sEdit_publish_timer_month;
	};
	int		sEdit_publish_timer_day(){
		return m_sEdit_publish_timer_day;
	};
	int		sEdit_publish_timer_hour(){
		return m_sEdit_publish_timer_hour;
	};
	int		sEdit_publish_timer_minute(){
		return m_sEdit_publish_timer_minute;
	};
	int		sEdit_publish_time_split(){
		return m_sEdit_publish_time_split;
	};
	int		sEdit_publish_count(){
		return m_sEdit_publish_count;
	};


private:
	bool m_bprice_min_maxChecked;
	bool m_bmian_yun_feiChecked;
	bool m_btian_maoChecked;
	bool m_bshouji_zhuanxiangChecked;
	bool m_bjinbi_moneyChecked;
	bool m_bhuo_dao_fu_kuanChecked;
	bool m_bqitian_tui_huoChecked;
	bool m_bcu_xiaoChecked;
	bool m_bzhan_xian_baobeiChecked;
	bool m_bchakan_chanpin_canshuChecked;
	bool m_bview_shop_homepageChecked;
	bool m_bview_baobei_pingjiaChecked;
	bool m_bshoucang_baobeiChecked;
	bool m_bzhi_tong_cheChecked;
	bool m_btimer_for_publishChecked;


	std::string 	m_sCombo_search_sort;
	std::string		m_sCombo_send_place;
	int					m_iCombo_fu_baobei_count;
	int					m_iCombo_target_compare_count;

	std::string		m_sEdit_total_title;
	std::string		m_sEdit_fu_biao_ti ;
	std::string		m_sEdit_search_key ;
	int		m_sEdit_target_price;
	int		m_sEdit_target_price_min;
	int		m_sEdit_target_price_max;
	int		m_sEdit_max_search_time;
	std::string		m_sEdit_baobei_url;
	int		m_sEdit_view_main_baobei_time;
	int		m_sEdit_view_fubaobei_time;
	int		m_sEdit_view_other_shop_time;
	int		m_sEdit_publish_timer_year;
	int		m_sEdit_publish_timer_month;
	int		m_sEdit_publish_timer_day;
	int		m_sEdit_publish_timer_hour;
	int		m_sEdit_publish_timer_minute;
	int		m_sEdit_publish_time_split;
	int		m_sEdit_publish_count;
};

