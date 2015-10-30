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
};

