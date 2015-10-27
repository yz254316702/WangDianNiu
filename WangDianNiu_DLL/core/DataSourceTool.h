#pragma once

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
	CDataSourceTool(void);
	~CDataSourceTool(void);
	std::string getSearchKeyStrng();
	std::string PartOfTitle() const;
	void PartOfTitle(std::string val);
	int getviewTargetTime();
	bool isViewSecTarget();
	int sec_viewTargetTime();
	std::string TargetTitle() const;
	void TargetTitle(std::string val);

	std::string m_searchString;
	std::string m_targetTitle;
	std::string m_partOfTitle;

	std::string m_sec_searchString;
	std::string m_sec_targetTitle;
	std::string m_sec_partOfTitle;

	int m_viewTargetTime;
	bool m_bViewSecTarget;
	int m_sec_viewTargetTime;
	int m_viewPingLunTime;
	std::string m_sortType;
	int m_minPrice;
	int m_maxPrice;
	std::string m_strMinPrice;
	std::string m_strMaxPrice;
	std::string m_youhui;
	std::string m_SendPlace;

	int ViewPingLunTime() const;
	void ViewPingLunTime(int val);
	std::string SendPlace() const;
	void SendPlace(std::string val);
	std::string SortType() const;
	void SortType(std::string val);
	int MinPrice() const;
	void MinPrice(int val);
	int MaxPrice() const;
	void MaxPrice(int val);
	std::string Youhui() const;
	void Youhui(std::string val);
	std::string strMaxPrice() const;
	void strMaxPrice(std::string val);
	std::string strMinPrice() const;
	void strMinPrice(std::string val);
	std::string Sec_partOfTitle() const;
	void Sec_partOfTitle(std::string val);
	std::string Sec_targetTitle() const;
	void Sec_targetTitle(std::string val);
	std::string Sec_searchString() const;
	void Sec_searchString(std::string val);

};

