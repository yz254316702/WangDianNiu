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
