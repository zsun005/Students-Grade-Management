// Loginfrm.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "Loginfrm.h"
#include "User.h"
// CLoginfrm �Ի���

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


// CLoginfrm ��Ϣ�������

BOOL CLoginfrm::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
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
	// �쳣��OCX ����ҳӦ���� FALSE
}

void CLoginfrm::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CEdit* pEdit=(CEdit*) this->GetDlgItem(IDC_EDIT1);
	CComboBox* pCombobox=(CComboBox*) this->GetDlgItem(IDC_COMBO1);
	CString username,password;
	pEdit->GetWindowText(password);
	pCombobox->GetWindowText(username);
	if(!theApp.m_pUser->Check(username,password))
	{	
		//AfxMessageBox("�������,����������!");
		MessageBox("�������,����������","�������",MB_OK|MB_ICONWARNING);
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(MessageBox("���Ҫ�˳�ϵͳ��?","�˳�ѯ��",MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	  OnCancel();
}
