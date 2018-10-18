// SelExamNoDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "SelExamNoDialog.h"
#include "ExamDoc.h"
#include "ExamView.h"

// CSelExamNoDialog �Ի���

IMPLEMENT_DYNAMIC(CSelExamNoDialog, CDialog)
CSelExamNoDialog::CSelExamNoDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CSelExamNoDialog::IDD, pParent)
{
}

CSelExamNoDialog::~CSelExamNoDialog()
{
}

void CSelExamNoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CSelExamNoDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CSelExamNoDialog ��Ϣ�������

BOOL CSelExamNoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
    CListBox* pListBox=(CListBox*)this->GetDlgItem(IDC_LIST1);

	CStringList* pSList=this->pExamView->GetDocument()->m_Exam.GetNos();
	POSITION p=pSList->GetHeadPosition();
	CString c;
	while(p)
	{
		c=pSList->GetNext(p);
	    pListBox->AddString(c);
	}
	//dlg.DestroyWindow();
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣��OCX ����ҳӦ���� FALSE
}

void CSelExamNoDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    CListBox* pListBox=(CListBox*)this->GetDlgItem(IDC_LIST1);
	int i=pListBox->GetCurSel();
	if(i<0)
	{
	   AfxMessageBox("��ѡ��һ�����!");
	   return;
	}
	CString ExamNo;
	pListBox->GetText(i,ExamNo);
	this->pExamView->RefreshShow(ExamNo); 
	OnOK();
}
