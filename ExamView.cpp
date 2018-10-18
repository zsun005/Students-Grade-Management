// ExamView.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "ExamView.h"
#include "ExamDoc.h"
#include "SelExamNoDialog.h"//ѡ���ŶԻ���
#include "AddClassDialog.h"//��Ӱ༶
#include "examview.h"
#include "ExamStudentView.h"//����ѧ����
#include "ExamStudentDoc.h" //����ѧ���ĵ�

#include "ExamSubjectView.h"//���Կγ���
#include "ExamSubjectDoc.h"//���Կγ��ĵ�

#include "ChildFrm.h"
// CExamView

IMPLEMENT_DYNCREATE(CExamView, CFormView)

CExamView::CExamView()
	: CFormView(CExamView::IDD)
{
	this->m_CurRecordPos=-1; 
}

CExamView::~CExamView()
{
}

void CExamView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CExamView, CFormView)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnNMRclickList1)
	ON_COMMAND(ID_153, OnAddExamClass)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_COMMAND(ID_154, OnDelClass)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedBtnClose)
	ON_COMMAND(ID_155, OnExamStudent)
	ON_COMMAND(ID_156, OnExamSubject)
END_MESSAGE_MAP()


// CExamView ���

#ifdef _DEBUG
void CExamView::AssertValid() const
{
	CFormView::AssertValid();
}

void CExamView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

 CExamDoc* CExamView::GetDocument() const
 {
	 ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExamDoc)));
	return (CExamDoc*)m_pDocument;
 }
// CExamView ��Ϣ�������

 void CExamView::OnDraw(CDC* /*pDC*/)
 {
	 // TODO: �ڴ����ר�ô����/����û���
    CRect rect;
    CRect rect1;
	int height,width;
	this->GetClientRect(&rect);
   	CWnd* pWnd;
	pWnd=this->GetDlgItem(IDC_BUTTON2);
    pWnd->GetWindowRect(&rect1);
    height=rect1.bottom-rect1.top;  
    rect1.bottom=rect.bottom-10;
	rect1.top=rect1.bottom-height;
	width=rect1.right-rect1.left;  
	rect1.left=10; 
	rect1.right=rect1.left+width;  
    pWnd->MoveWindow(&rect1);

	pWnd=this->GetDlgItem(IDC_BUTTON3);
    pWnd->GetWindowRect(&rect1);
    height=rect1.bottom-rect1.top;  
    rect1.bottom=rect.bottom-10;
	rect1.top=rect1.bottom-height;
	width=rect1.right-rect1.left;  
	rect1.left=100; 
	rect1.right=rect1.left+width;  
    pWnd->MoveWindow(&rect1);


	pWnd=this->GetDlgItem(IDC_BUTTON4);
    pWnd->GetWindowRect(&rect1);
    height=rect1.bottom-rect1.top;  
    rect1.bottom=rect.bottom-10;
	rect1.top=rect1.bottom-height;
 	width=rect1.right-rect1.left;  
	rect1.left=200; 
	rect1.right=rect1.left+width;  
   pWnd->MoveWindow(&rect1);

	

	rect.top+=70;
	rect.bottom-=40; 
    CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
  	list->MoveWindow(&rect);

 }

 void CExamView::OnInitialUpdate()
 {
	 CFormView::OnInitialUpdate();

	 // TODO: �ڴ����ר�ô����/����û���
     CExamDoc* pDoc=this->GetDocument();
     
	 CDateTimeCtrl* pPicker=(CDateTimeCtrl*)this->GetDlgItem(IDC_DATETIMEPICKER1);
	 CTime time=CTime::GetCurrentTime();
     pPicker->SetTime(&time);
	 
	 CComboBox* pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
	
	 CStringList& pSList=pDoc->m_Exam.GetTerms();
	 POSITION p=pSList.GetHeadPosition();
	 CString c;
	 while(p)
	 {
        c=pSList.GetNext(p);
	    pComb->AddString(c);   
	 }
    
	 pDoc->m_ExamClass.GetExamClassByExamNo("00");
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 list->SetExtendedStyle( LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES );
     pDoc->m_ExamClass.FillList(*list);	 
 }

 void CExamView::OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
 {
	 // TODO: �ڴ���ӿؼ�֪ͨ����������
 	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	this->m_CurRecordPos=pNMLV->iItem; 
	CMenu menu1;
	CPoint p;
	menu1.LoadMenu(IDR_MENU2);
	CMenu* menu2=menu1.GetSubMenu(0);
	GetCursorPos(&p);
	menu2->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON ,p.x,p.y,this);  
	*pResult = 0;

 }

 void CExamView::OnAddExamClass()
 {
	 // TODO: �ڴ���������������
	 CEdit* pEdit=(CEdit*)this->GetDlgItem(IDC_EDIT1);
	 CString ExamNo;
	 pEdit->GetWindowText(ExamNo);
     ExamNo.TrimRight();
	 if(ExamNo=="")
	 {
	    AfxMessageBox("������Ų���Ϊ��!");
		return;
	 }

	 CExamDoc* pDoc=this->GetDocument();
     CAddClassDialog  dlg;
	 dlg.m_pExamView=this;
	 dlg.m_ExamNo=ExamNo; 
	 dlg.DoModal();
 }

 void CExamView::OnBnClickedButton1()
 {
	CExamDoc* pDoc=this->GetDocument();
    CSelExamNoDialog  dlg;
	dlg.pExamView=this;
	dlg.DoModal();
	
 }
 void CExamView::RefreshShow(CString ExamNo)
 {
     CExamDoc* pDoc=this->GetDocument();
     pDoc->m_Exam.GetExamByNo(ExamNo);

	 CEdit* pEdit=(CEdit*)this->GetDlgItem(IDC_EDIT1);
	 pEdit->SetWindowText(ExamNo);

	 CDateTimeCtrl* pPicker=(CDateTimeCtrl*)this->GetDlgItem(IDC_DATETIMEPICKER1);
     pPicker->SetTime(pDoc->m_Exam.m_Date);
	 
	 CComboBox* pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
     int index=pComb->FindString(0,pDoc->m_Exam.m_TermNo); 	
	 pComb->SetCurSel(index);

	 pDoc->m_ExamClass.GetExamClassByExamNo(ExamNo);
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
     pDoc->m_ExamClass.FillList(*list);	 
 }

 void CExamView::OnBnClickedButton2()
 {
    CEdit* pEdit=(CEdit*) this->GetDlgItem(IDC_EDIT1);
	CString ExamNo;
	pEdit->GetWindowText(ExamNo);
	CExamDoc* pDoc=this->GetDocument();
	if(pDoc->m_Exam.IsNoExisted(ExamNo))
	{
	   AfxMessageBox("��������ظ���¼!");
	   return;
	}
	else
	{
		//��Ӽ�¼
	   pDoc->m_Exam.m_No=ExamNo;
		CDateTimeCtrl* pPicker=
		 (CDateTimeCtrl*)this->GetDlgItem(IDC_DATETIMEPICKER1);
       pPicker->GetTime(pDoc->m_Exam.m_Date);
       
	   CComboBox* pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
       pComb->GetLBText(pComb->GetCurSel(),pDoc->m_Exam.m_TermNo);

	   pDoc->m_Exam.AddExam();
	}

 }

 void CExamView::OnBnClickedButton3()
 {
	 // TODO: �ڴ���ӿؼ�֪ͨ����������
	CString value;
    CEdit* pEdit=(CEdit*) this->GetDlgItem(IDC_EDIT1);
    pEdit->GetWindowText(value);

	if(MessageBox("���Ҫɾ�����Ա��Ϊ:"+value+"�ļ�¼��?","ɾ��ѯ��",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
       CExamDoc* pDoc=this->GetDocument();
       pDoc->m_Exam.DeleteExamByNo(value);
	}
 }

 void CExamView::OnDelClass()
 {
	 // TODO: �ڴ���������������
	 CString value;
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 value=list->GetItemText(this->m_CurRecordPos,0); 
	 if(MessageBox("���Ҫɾ�����Ϊ:"+value+"�ļ�¼��?","ɾ��ѯ��",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
       CExamDoc* pDoc=this->GetDocument();
       pDoc->m_ExamClass.DelClassByNo(value);
	   CEdit* pEdit=(CEdit*) this->GetDlgItem(IDC_EDIT1);
       pEdit->GetWindowText(value);
	   this->RefreshShow(value);
	}
 }

 void CExamView::OnBnClickedBtnClose()
 {
	 // TODO: �ڴ���ӿؼ�֪ͨ����������
	 this->GetParentFrame()->DestroyWindow();
 }
void CExamView::ShowExamStudentView(CString ExamNo,CString ExamClassNo)
{
     	CMultiDocTemplate* pDocTemplate;
		//�����ĵ�����ͼ
		pDocTemplate=theApp.m_pExamStudentTemplate; 
		CExamStudentDoc* pDocument =(CExamStudentDoc*) pDocTemplate->CreateNewDocument();
		ASSERT_VALID(pDocument);
        //��������
		pDocument->m_ExamNo=ExamNo;
		pDocument->m_ExamClassNo=ExamClassNo; 
		CFrameWnd* pFrame = pDocTemplate->CreateNewFrame(pDocument, NULL);
		ASSERT_VALID(pFrame);
    	pDocument->OnNewDocument();
		pDocTemplate->InitialUpdateFrame(pFrame, pDocument, true);
}
 void CExamView::OnExamStudent()
 {
	 // TODO: �ڴ��������������� 
	 CString ExamNo,ExamClassNo;
	 CEdit* pEdit=(CEdit*)this->GetDlgItem(IDC_EDIT1);
	 pEdit->GetWindowText(ExamNo);
     if(ExamNo=="")
	 {
	    AfxMessageBox("������Ų���Ϊ��!");
		return;
	 }
	 if(this->m_CurRecordPos<0)
	 {
	   AfxMessageBox("�༶����Ϊ��!");
	   return;
	 }
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 ExamClassNo=list->GetItemText(this->m_CurRecordPos,1); 

	if(theApp.m_pDocManager==NULL||theApp.m_pExamStudentTemplate==NULL)//û�г�ʼ���ĵ�
	{
		CMultiDocTemplate* pDocTemplate;
	    pDocTemplate = new CMultiDocTemplate(IDR_StudentScoreTYPE,
		RUNTIME_CLASS(CExamStudentDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CExamStudentView));
	    theApp.AddDocTemplate(pDocTemplate);
		theApp.m_pExamStudentTemplate=pDocTemplate; 
        //����ͼ
        this->ShowExamStudentView(ExamNo,ExamClassNo);
	}
	else 
	{   
        POSITION p=theApp.m_pExamStudentTemplate->GetFirstDocPosition();
		if(p)//��ĵ�����
		{
			CDocument* pDoc=theApp.m_pExamStudentTemplate->GetNextDoc(p);
			p=pDoc->GetFirstViewPosition();
			if(p)//�Ӵ���
			{
			   CView* pView=pDoc->GetNextView(p);
			   pView->GetParentFrame()->BringWindowToTop();
			}
		}
		else
		{
            this->ShowExamStudentView(ExamNo,ExamClassNo);
		}
	}
 }
 void CExamView::ShowExamSubjectView(CString ExamNo,CString ExamClassNo)
{
     	CMultiDocTemplate* pDocTemplate;
		//�����ĵ�����ͼ
		pDocTemplate=theApp.m_pExamSubjectTemplate; 
		CExamSubjectDoc* pDocument =(CExamSubjectDoc*) pDocTemplate->CreateNewDocument();
		ASSERT_VALID(pDocument);
        //��������
		pDocument->m_ExamNo=ExamNo;
		pDocument->m_ExamClassNo=ExamClassNo; 
		CFrameWnd* pFrame = pDocTemplate->CreateNewFrame(pDocument, NULL);
		ASSERT_VALID(pFrame);
    	pDocument->OnNewDocument();
		pDocTemplate->InitialUpdateFrame(pFrame, pDocument, true);
}

 void CExamView::OnExamSubject()
 {
     CString ExamNo,ExamClassNo;
	 CEdit* pEdit=(CEdit*)this->GetDlgItem(IDC_EDIT1);
	 pEdit->GetWindowText(ExamNo);
     if(ExamNo=="")
	 {
	    AfxMessageBox("������Ų���Ϊ��!");
		return;
	 }
	 if(this->m_CurRecordPos<0)
	 {
	   AfxMessageBox("�༶����Ϊ��!");
	   return;
	 }
     CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 ExamClassNo=list->GetItemText(this->m_CurRecordPos,1); 

	if(theApp.m_pDocManager==NULL||theApp.m_pExamSubjectTemplate==NULL)//û�г�ʼ���ĵ�
	{
		CMultiDocTemplate* pDocTemplate;
	    pDocTemplate = new CMultiDocTemplate(IDR_StudentScoreTYPE,
		RUNTIME_CLASS(CExamSubjectDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CExamSubjectView));
	    theApp.AddDocTemplate(pDocTemplate);
		theApp.m_pExamSubjectTemplate=pDocTemplate; 
        //����ͼ
        this->ShowExamSubjectView(ExamNo,ExamClassNo);
	}
	else 
	{   
        POSITION p=theApp.m_pExamSubjectTemplate->GetFirstDocPosition();
		if(p)//��ĵ�����
		{
			CDocument* pDoc=theApp.m_pExamSubjectTemplate->GetNextDoc(p);
			p=pDoc->GetFirstViewPosition();
			if(p)//�Ӵ���
			{
			   CView* pView=pDoc->GetNextView(p);
			   pView->GetParentFrame()->BringWindowToTop();
			}
		}
		else
		{
            this->ShowExamSubjectView(ExamNo,ExamClassNo);
		}
	}

 }
