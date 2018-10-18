#pragma once


// CAddStudentDialog 对话框
class CExamStudentView;
class CAddStudentDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddStudentDialog)

public:
	CAddStudentDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CAddStudentDialog();

// 对话框数据
	enum { IDD = IDD_ADDSTUDENTDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CExamStudentView* pExamStudentView;
	CString m_ExamNo;   //考试编号
	CString m_ClassNo;  //班级编号
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
