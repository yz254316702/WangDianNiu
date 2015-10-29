#include "StdAfx.h"
#include "DoTaskPageUI.h"


CDoTaskPageUI::CDoTaskPageUI(void):
m_pPaintManager(NULL)
{
	CContainerUI* pDoTaskPage = static_cast<CContainerUI*>(m_builder.Create(_T("DoTaskPage.xml"), (UINT)0,NULL,m_pPaintManager));
	if( pDoTaskPage ) {
		this->Add(pDoTaskPage);
	}
	else {
		this->RemoveAll();
		return;
	}
}

CDoTaskPageUI::CDoTaskPageUI( CPaintManagerUI* pm ):
m_pPaintManager(pm)
{
	CContainerUI* pDoTaskPage = static_cast<CContainerUI*>(m_builder.Create(_T("DoTaskPage.xml"), (UINT)0,NULL,m_pPaintManager));
	if( pDoTaskPage ) {
		this->Add(pDoTaskPage);
	}
	else {
		this->RemoveAll();
		return;
	}
}


CDoTaskPageUI::~CDoTaskPageUI(void)
{
}
