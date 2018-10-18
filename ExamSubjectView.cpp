// ExamSubjectView.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "ExamSubjectView.h"
#include "ExamSubjectDoc.h"
#include "AddSubjectDialog.h"
// CExamSubjectView

IMPLEMENT_DYNCREATE(CExamSubjectView, CFormView)

CExamSubjectView::CExamSubjectView()
	: CFormView(CExamSubjectView::IDD)
{
}

CExamSubjectView::~CExamSubjectView()
{
}

void CExamSubjectView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamSubjectView, CFormView)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnNMRclickList1)
	ON_COMMAND(ID__163, onAddSubject)
	ON_COMMAND(ID_159, On159)
END_MESSAGE_MAP()


// CExamSubjectView 诊断

#ifdef _DEBUG
void CExamSubjectView::AssertValid() const
{
	CFormView::AssertValid();
}

void CExamSubjectView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CExamSubjectView 消息处理程序
CExamSubjectDoc* CExamSubjectView::GetDocument() const
{
   ASSERT(this->m_pDocument->IsKindOf(RUNTIME_CLASS(CExamSubjectDoc)));
      return(CExamSubjectDoc*) this->m_pDocument; 
  }
void CExamSubjectView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
    pList->SetExtendedStyle( LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES );
	// TODO: 在此添加专用代码和/或调用基类
	CExamSubjectDoc* pDoc=this->GetDocument();
	pDoc->m_ExamSubject.FillList(*pList); 
}

void CExamSubjectView::OnDraw(CDC* /*pDC*/)
{
	// TODO: 在此添加专用代码和/或调用基类
	 CRect rect;
   this->GetClientRect(&rect);
   CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
   pList->MoveWindow(&rect);
}

void CExamSubjectView::OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	this->m_CurRecordPos=pNMLV->iItem; 
	CMenu menu1;
	CPoint p;
	menu1.LoadMenu(IDR_MENU4);
	CMenu* menu2=menu1.GetSubMenu(0);
	GetCursorPos(&p);
	menu2->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON ,p.x,p.y,this);  
	*pResult = 0;
}

void CExamSubjectView::onAddSubject()
{
	// TODO: 在此添加命令处理程序代码
	CExamSubjectDoc* pDoc=this->GetDocument();
	CAddSubjectDialog dlg;
	dlg.m_pExamSubjectView=this; 
	dlg.DoModal();
}

void CExamSubjectView::RefreshShow()
{
	CExamSubjectDoc* pDoc=this->GetDocument();
	pDoc->Refresh();
	CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
	pDoc->m_ExamSubject.FillList(*pList);
}
void CExamSubjectView::On159()
{
	// TODO: 在此添加命令处理程序代码
	 CString value;
	 CExamSubjectDoc* pDoc=this->GetDocument();
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 value=list->GetItemText(this->m_CurRecordPos,0); 
	 if(MessageBox("真的要删除编号为:"+value+"的记录吗?","删除询问",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
        pDoc->m_ExamSubject.DelSubjectByNo(value);
		this->RefreshShow();
	}
}
