// ExamStudentView.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "ExamStudentView.h"
#include "ExamStudentDoc.h"
#include "AddStudentDialog.h"
// CExamStudentView

IMPLEMENT_DYNCREATE(CExamStudentView, CFormView)

CExamStudentView::CExamStudentView()
	: CFormView(CExamStudentView::IDD)
{
}

CExamStudentView::~CExamStudentView()
{
}

void CExamStudentView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamStudentView, CFormView)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnNMRclickList1)
	ON_COMMAND(ID_159, onAddStudent)
	ON_COMMAND(ID_190, OnDelStudent)
END_MESSAGE_MAP()


// CExamStudentView 诊断

#ifdef _DEBUG
void CExamStudentView::AssertValid() const
{
	CFormView::AssertValid();
}

void CExamStudentView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG


// CExamStudentView 消息处理程序
CExamStudentDoc* CExamStudentView::GetDocument() const
{
   ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExamStudentDoc)));
	return (CExamStudentDoc*)m_pDocument;
}
void CExamStudentView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
   CRect rect;
   this->GetClientRect(&rect);
   CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
   pList->MoveWindow(&rect);
}

void CExamStudentView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
    CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
    pList->SetExtendedStyle( LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES );
	// TODO: 在此添加专用代码和/或调用基类
	CExamStudentDoc* pDoc=this->GetDocument();
	pDoc->m_ExamStudent.FillList(*pList); 
	this->m_CurRecordPos=-1; 
}

void CExamStudentView::OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	this->m_CurRecordPos=pNMLV->iItem; 
	CMenu menu1;
	CPoint p;
	menu1.LoadMenu(IDR_MENU3);
	CMenu* menu2=menu1.GetSubMenu(0);
	GetCursorPos(&p);
	menu2->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON ,p.x,p.y,this);  
	*pResult = 0;
}

void CExamStudentView::onAddStudent()
{
	// TODO: 在此添加命令处理程序代码
	CExamStudentDoc* pDoc=this->GetDocument();
	CAddStudentDialog dlg;
	dlg.m_ExamNo=pDoc->m_ExamNo;
	dlg.m_ClassNo=pDoc->m_ExamClassNo;
	dlg.pExamStudentView=this; 
	dlg.DoModal();
}
void CExamStudentView::RefreshShow()
{
	CExamStudentDoc* pDoc=this->GetDocument();
	CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
	pDoc->m_ExamStudent.GetExamStudentBy(pDoc->m_ExamNo,pDoc->m_ExamClassNo);
	pDoc->m_ExamStudent.FillList(*pList); 
}
void CExamStudentView::OnDelStudent()
{
	// TODO: 在此添加命令处理程序代码
	 CString value;
	 CExamStudentDoc* pDoc=this->GetDocument();
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 value=list->GetItemText(this->m_CurRecordPos,0); 
	 if(MessageBox("真的要删除编号为:"+value+"的记录吗?","删除询问",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
        pDoc->m_ExamStudent.DelStudentByNo(value);
		this->RefreshShow();
	}
}
