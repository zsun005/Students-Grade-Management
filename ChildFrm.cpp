// ChildFrm.cpp : CChildFrame ���ʵ��
//
#include "stdafx.h"
#include "StudentScore.h"
#include "StudentScoreView.h" //

#include "ChildFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
END_MESSAGE_MAP()


// CChildFrame ����/����

CChildFrame::CChildFrame()
{
	// TODO���ڴ���ӳ�Ա��ʼ������
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ��������ʽ
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// CChildFrame ���

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG


// CChildFrame ��Ϣ�������

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���
   /*
	if (!m_wndSplitter1.CreateStatic(this, 1, 2))
	{
		TRACE0("Failed to Splitter window\n");
		return FALSE;
	}

	// add the first splitter pane - the default view in column 0
	if (!m_wndSplitter1.CreateView(0, 0,
		RUNTIME_CLASS(CTblMsgView), CSize(150, 150), pContext))
	{
		TRACE0("Failed to create first pane\n");
		return FALSE;
	}

	// add the second splitter pane - an input view in column 1
	if (!m_wndSplitter1.CreateView(0, 1,
			RUNTIME_CLASS(CStudentScoreView), CSize(0, 0), pContext))
	{
		TRACE0("Failed to create second pane\n");
		return FALSE;
	}

	// activate the input view
	SetActiveView((CView*)m_wndSplitter1.GetPane(0,1));

	return TRUE;
   */
	return CMDIChildWnd::OnCreateClient(lpcs, pContext);
}
