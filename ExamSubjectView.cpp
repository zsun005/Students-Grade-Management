// ExamSubjectView.cpp : ʵ���ļ�
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


// CExamSubjectView ���

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


// CExamSubjectView ��Ϣ�������
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
	// TODO: �ڴ����ר�ô����/����û���
	CExamSubjectDoc* pDoc=this->GetDocument();
	pDoc->m_ExamSubject.FillList(*pList); 
}

void CExamSubjectView::OnDraw(CDC* /*pDC*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	 CRect rect;
   this->GetClientRect(&rect);
   CListCtrl* pList=(CListCtrl*) this->GetDlgItem(IDC_LIST1);
   pList->MoveWindow(&rect);
}

void CExamSubjectView::OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���������������
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
	// TODO: �ڴ���������������
	 CString value;
	 CExamSubjectDoc* pDoc=this->GetDocument();
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 value=list->GetItemText(this->m_CurRecordPos,0); 
	 if(MessageBox("���Ҫɾ�����Ϊ:"+value+"�ļ�¼��?","ɾ��ѯ��",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
        pDoc->m_ExamSubject.DelSubjectByNo(value);
		this->RefreshShow();
	}
}
