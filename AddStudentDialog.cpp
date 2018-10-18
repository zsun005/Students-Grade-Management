// AddStudentDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "AddStudentDialog.h"
#include "ExamStudentView.h"
#include "ExamStudentDoc.h"

// CAddStudentDialog �Ի���

IMPLEMENT_DYNAMIC(CAddStudentDialog, CDialog)
CAddStudentDialog::CAddStudentDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddStudentDialog::IDD, pParent)
{
}

CAddStudentDialog::~CAddStudentDialog()
{
}

void CAddStudentDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddStudentDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CAddStudentDialog ��Ϣ�������

BOOL CAddStudentDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
    CExamStudentDoc* pDoc=this->pExamStudentView->GetDocument();
	pDoc->m_ExamStudent.GetStudentsByClassNo(this->m_ClassNo);
	POSITION p=pDoc->m_ExamStudent.m_StudentList.GetHeadPosition();
	CListBox* pList=(CListBox*)this->GetDlgItem(IDC_LIST1);
	CFldValue* pValue;
	int index;
	while(p)
	{
	  pValue=(CFldValue*)&pDoc->m_ExamStudent.m_StudentList.GetNext(p);
	  index=pList->AddString(pValue->DispalyFieldValue);
      pList->SetItemDataPtr(index,pValue);
	}
  
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣��OCX ����ҳӦ���� FALSE
}

void CAddStudentDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListBox* pList=(CListBox*)this->GetDlgItem(IDC_LIST1);
	int nCount=pList->GetSelCount();
	if(nCount==0)
	{
	  AfxMessageBox("��ѡ��ѧ��!");
	  return;
	}
	CArray<int,int> aryListBoxSel;
	aryListBoxSel.SetSize(nCount);
    pList->GetSelItems(nCount, aryListBoxSel.GetData());  
    int index;
	CString value;
	CFldValue* pValue; 
    CExamStudentDoc* pDoc=this->pExamStudentView->GetDocument();

	for(int i=0;i<aryListBoxSel.GetSize();i++)
	{
 	    index=aryListBoxSel.GetAt(i);
		pValue=(CFldValue*)pList->GetItemDataPtr(index);

   		if(pDoc->m_ExamStudent.IsStudentNoExisted(this->m_ExamNo,
			                     this->m_ClassNo,pValue->FieldValue))
		{
           value=pValue->DispalyFieldValue; 
		   AfxMessageBox("����ѡ���ظ�ѧ�����:"+value);
		   return;
		}
	}

 	for(i=0;i<aryListBoxSel.GetSize();i++)
	{
 	    index=aryListBoxSel.GetAt(i);
		pValue=(CFldValue*)pList->GetItemDataPtr(index);
		pDoc->m_ExamStudent.m_ExamNo=this->m_ExamNo;
		pDoc->m_ExamStudent.m_ClassNo=this->m_ClassNo;
		pDoc->m_ExamStudent.m_StudentNo=pValue->FieldValue;//�༶���
		pDoc->m_ExamStudent.AddStudent();
	}
	this->pExamStudentView->RefreshShow(); 
	OnOK();
}
