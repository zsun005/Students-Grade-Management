// SelExamNoDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "SelExamNoDialog.h"
#include "ExamDoc.h"
#include "ExamView.h"

// CSelExamNoDialog 对话框

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


// CSelExamNoDialog 消息处理程序

BOOL CSelExamNoDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
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
	// 异常：OCX 属性页应返回 FALSE
}

void CSelExamNoDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
    CListBox* pListBox=(CListBox*)this->GetDlgItem(IDC_LIST1);
	int i=pListBox->GetCurSel();
	if(i<0)
	{
	   AfxMessageBox("请选择一个编号!");
	   return;
	}
	CString ExamNo;
	pListBox->GetText(i,ExamNo);
	this->pExamView->RefreshShow(ExamNo); 
	OnOK();
}
