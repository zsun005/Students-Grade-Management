// ChildFrm.cpp : CChildFrame 类的实现
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


// CChildFrame 构造/销毁

CChildFrame::CChildFrame()
{
	// TODO：在此添加成员初始化代码
}

CChildFrame::~CChildFrame()
{
}


BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或样式
	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;

	return TRUE;
}


// CChildFrame 诊断

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


// CChildFrame 消息处理程序

BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类
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
