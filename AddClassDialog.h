#pragma once


// AddClassDialog 对话框
class CExamView;
class CAddClassDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddClassDialog)

public:
	CAddClassDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddClassDialog();

// 对话框数据
	enum { IDD = IDD_ADDCLASSDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CExamView* m_pExamView;//父视图
	CString m_ExamNo;      //考试编号
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
};
