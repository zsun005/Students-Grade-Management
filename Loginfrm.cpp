// Loginfrm.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "Loginfrm.h"
#include "User.h"
// CLoginfrm 对话框

IMPLEMENT_DYNAMIC(CLoginfrm, CDialog)
CLoginfrm::CLoginfrm(CWnd* pParent /*=NULL*/)
	: CDialog(CLoginfrm::IDD, pParent)
{
}

CLoginfrm::~CLoginfrm()
{
}

void CLoginfrm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginfrm, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// CLoginfrm 消息处理程序

BOOL CLoginfrm::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//CMenu* pMenu=this->GetSystemMenu(true);
	//pMenu->DeleteMenu(
	int i=0;
	CString name;
    CComboBox* pCombobox=(CComboBox*) this->GetDlgItem(IDC_COMBO1);
	theApp.m_pUser->GetUserNames();
	POSITION p=theApp.m_pUser->m_NameList.GetHeadPosition();   
	while(p)
	{
		name=theApp.m_pUser->m_NameList.GetNext(p);
    	pCombobox->AddString(name);
	}
	pCombobox->SetCurSel(0);
	CEdit* pEdit=(CEdit*) this->GetDlgItem(IDC_EDIT1);
	pEdit->SetWindowText("");
	pEdit->SetFocus();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常：OCX 属性页应返回 FALSE
}

void CLoginfrm::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CEdit* pEdit=(CEdit*) this->GetDlgItem(IDC_EDIT1);
	CComboBox* pCombobox=(CComboBox*) this->GetDlgItem(IDC_COMBO1);
	CString username,password;
	pEdit->GetWindowText(password);
	pCombobox->GetWindowText(username);
	if(!theApp.m_pUser->Check(username,password))
	{	
		//AfxMessageBox("密码错误,请重新输入!");
		MessageBox("密码错误,请重新输入","秘码错误",MB_OK|MB_ICONWARNING);
		pEdit->SetWindowText("");
	    pEdit->SetFocus();
 	}
	else
	{
	    OnOK();
	}
}

void CLoginfrm::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	if(MessageBox("真的要退出系统吗?","退出询问",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	  OnCancel();
}
