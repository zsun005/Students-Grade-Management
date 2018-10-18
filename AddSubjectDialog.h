#pragma once


// CAddSubjectDialog 对话框
class CExamSubjectView;
class CAddSubjectDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddSubjectDialog)

public:
	CAddSubjectDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddSubjectDialog();

// 对话框数据
	enum { IDD = IDD_ADDSUBJECTDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CExamSubjectView* m_pExamSubjectView;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
