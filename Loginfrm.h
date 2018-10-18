#pragma once


// CLoginfrm 对话框

class CLoginfrm : public CDialog
{
	DECLARE_DYNAMIC(CLoginfrm)

public:
	CLoginfrm(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CLoginfrm();

// 对话框数据
	enum { IDD = IDD_LOGINFRM };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
