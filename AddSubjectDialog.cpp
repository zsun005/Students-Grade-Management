// AddSubjectDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "AddSubjectDialog.h"
#include "ExamSubjectView.h"
#include "ExamSubjectDoc.h"

// CAddSubjectDialog 对话框

IMPLEMENT_DYNAMIC(CAddSubjectDialog, CDialog)
CAddSubjectDialog::CAddSubjectDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddSubjectDialog::IDD, pParent)
{
}

CAddSubjectDialog::~CAddSubjectDialog()
{
}

void CAddSubjectDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddSubjectDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CAddSubjectDialog 消息处理程序

BOOL CAddSubjectDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	// TODO:  在此添加额外的初始化
    CExamSubjectDoc* pDoc=this->m_pExamSubjectView->GetDocument();
	
	CComboBox* pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
    pDoc->GetStudents();
	POSITION p=pDoc->m_ExamSubject.m_StudentList.GetHeadPosition();
	CFldValue* pValue;
	int index;
	while(p)
	{
	    pValue=(CFldValue*)&pDoc->m_ExamSubject.m_StudentList.GetNext(p);
        index=pComb->AddString(pValue->DispalyFieldValue);
		pComb->SetItemDataPtr(index,pValue);
	}
    if(pComb->GetCount()>0)
	{
	  pComb->SetCurSel(0); 
	}
    
	pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO2);
    pDoc->GetSubjects();
	p=pDoc->m_ExamSubject.m_SubjectList.GetHeadPosition();
	while(p)
	{
	    pValue=(CFldValue*)&pDoc->m_ExamSubject.m_SubjectList.GetNext(p);
        index=pComb->AddString(pValue->DispalyFieldValue);
		pComb->SetItemDataPtr(index,pValue);
	}

    if(pComb->GetCount()>0)
	{
	  pComb->SetCurSel(0); 
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常：OCX 属性页应返回 FALSE
}

void CAddSubjectDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CComboBox* pComb1=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
    if(pComb1->GetCurSel()<0)
	{
	  AfxMessageBox("请选择学生姓名!");
	  return;
	}

	CComboBox* pComb2=(CComboBox*)this->GetDlgItem(IDC_COMBO2);
    if(pComb2->GetCurSel()<0)
	{
	  AfxMessageBox("请选择学生姓名!");
	  return;
	}
    
	CString value;
	CEdit* pEdit=(CEdit*)this->GetDlgItem(IDC_EDIT1);
	pEdit->GetWindowText(value);
    value.TrimRight(); 
	if(value=="")
	{
	   AfxMessageBox("请输入成绩!");
	   return;
	}

	double fscore;
	fscore=atof(value);
	if((fscore<0)||(fscore>150))
	{
	   AfxMessageBox("学生成绩应在0~150之间!");
	   return;
	}	

    CExamSubjectDoc* pDoc=this->m_pExamSubjectView->GetDocument();
	int index;
	CFldValue* pValue;
	
	pDoc->m_ExamSubject.m_ExamNo=pDoc->m_ExamNo;
	pDoc->m_ExamSubject.m_ClassNo=pDoc->m_ExamClassNo; 
	index=pComb1->GetCurSel();
	pValue=(CFldValue*)pComb1->GetItemDataPtr(index);
    pDoc->m_ExamSubject.m_StudentNo=pValue->FieldValue;

	index=pComb2->GetCurSel();
    pValue=(CFldValue*)pComb2->GetItemDataPtr(index);
    pDoc->m_ExamSubject.m_SubjectNo=pValue->FieldValue;

	pDoc->m_ExamSubject.m_Score=fscore;
	pDoc->m_ExamSubject.AddSubject();
    this->m_pExamSubjectView->RefreshShow(); 
}
