#pragma once


// CLoginfrm �Ի���

class CLoginfrm : public CDialog
{
	DECLARE_DYNAMIC(CLoginfrm)

public:
	CLoginfrm(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginfrm();

// �Ի�������
	enum { IDD = IDD_LOGINFRM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
