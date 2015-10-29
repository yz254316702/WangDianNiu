#pragma once
#define DO_TASK_PAGE "DoTaskPage"
class CDoTaskPageUI : public CContainerUI
{
public:
	CDoTaskPageUI(CPaintManagerUI* pm);
	virtual ~CDoTaskPageUI(void);
private:
	CDoTaskPageUI(void);

	CPaintManagerUI *m_pPaintManager;

	CDialogBuilder m_builder;
};

