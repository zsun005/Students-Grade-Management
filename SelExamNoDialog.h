#pragma once


// CSelExamNoDialog 对话框
class CExamView;
class CSelExamNoDialog : public CDialog
{
	DECLARE_DYNAMIC(CSelExamNoDialog)

public:
	CSelExamNoDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSelExamNoDialog();

// 对话框数据
	enum { IDD = IDD_SELEXAMNODIALOG };
    
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    
	DECLARE_MESSAGE_MAP()
public:
	CExamView* pExamView; 
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
