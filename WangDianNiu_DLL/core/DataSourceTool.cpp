#include "stdafx.h"
#include "pubInclude.h"
#include "DataSourceTool.h"
#include <winbase.h>
#define MAX_LEN 500
CDataSourceTool::CDataSourceTool(void)
{
	//m_searchString = ("雨洁男士");
	//m_targetTitle = ("雨洁新品 男士清爽活力洗发露200ml 专业去屑控油 薄荷持久留香");
	m_searchString = ("雨洁");
	m_targetTitle = ("雨洁新品");
	m_partOfTitle = m_targetTitle;
	m_sec_targetTitle = m_targetTitle;
	m_sec_partOfTitle = m_partOfTitle;
	m_viewTargetTime=10;
	m_bViewSecTarget=true;
	m_sec_viewTargetTime=10;
	m_sortType=("信用排序");
	m_minPrice=10;
	m_maxPrice=500;

	m_strMinPrice=("10");
	m_strMaxPrice=("500");
	m_youhui=("免运费");
	m_SendPlace=("广东");
	m_viewPingLunTime = 20;
}


CDataSourceTool::~CDataSourceTool(void)
{
}

std::string CDataSourceTool::getSearchKeyStrng()
{
	return m_searchString;
}

int CDataSourceTool::getviewTargetTime()
{
	return m_viewTargetTime;
}

bool CDataSourceTool::isViewSecTarget()
{
	return m_bViewSecTarget;
}

int CDataSourceTool::sec_viewTargetTime()
{
	return m_sec_viewTargetTime;
}

std::string CDataSourceTool::SendPlace() const
{
	return m_SendPlace;
}

void CDataSourceTool::SendPlace( std::string val )
{
	m_SendPlace = val;
}

std::string CDataSourceTool::SortType() const
{
	return m_sortType;
}

void CDataSourceTool::SortType( std::string val )
{
	m_sortType = val;
}

int CDataSourceTool::MinPrice() const
{
	return m_minPrice;
}

void CDataSourceTool::MinPrice( int val )
{
	m_minPrice = val;
}

int CDataSourceTool::MaxPrice() const
{
	return m_maxPrice;
}

void CDataSourceTool::MaxPrice( int val )
{
	m_maxPrice = val;
}

std::string CDataSourceTool::Youhui() const
{
	return m_youhui;
}

void CDataSourceTool::Youhui( std::string val )
{
	m_youhui = val;
}

std::string CDataSourceTool::strMaxPrice() const
{
	return m_strMaxPrice;
}

void CDataSourceTool::strMaxPrice( std::string val )
{
	m_strMaxPrice = val;
}

std::string CDataSourceTool::strMinPrice() const
{
	return m_strMinPrice;
}

void CDataSourceTool::strMinPrice( std::string val )
{
	m_strMinPrice = val;
}

std::string CDataSourceTool::PartOfTitle() const
{
	return m_partOfTitle;
}

void CDataSourceTool::PartOfTitle( std::string val )
{
	m_partOfTitle = val;
}

std::string CDataSourceTool::TargetTitle() const
{
	return m_targetTitle;
}

void CDataSourceTool::TargetTitle( std::string val )
{
	m_targetTitle = val;
}

int CDataSourceTool::ViewPingLunTime() const
{
	return m_viewPingLunTime;
}

void CDataSourceTool::ViewPingLunTime( int val )
{
	m_viewPingLunTime = val;
}

std::string CDataSourceTool::Sec_partOfTitle() const
{
	return m_sec_partOfTitle;
}

void CDataSourceTool::Sec_partOfTitle( std::string val )
{
	m_sec_partOfTitle = val;
}

std::string CDataSourceTool::Sec_targetTitle() const
{
	return m_sec_targetTitle;
}

void CDataSourceTool::Sec_targetTitle( std::string val )
{
	m_sec_targetTitle = val;
}

std::string CDataSourceTool::Sec_searchString() const
{
	return m_sec_searchString;
}

void CDataSourceTool::Sec_searchString( std::string val )
{
	m_sec_searchString = val;
}
