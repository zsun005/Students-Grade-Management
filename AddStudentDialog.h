#pragma once


// CAddStudentDialog �Ի���
class CExamStudentView;
class CAddStudentDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddStudentDialog)

public:
	CAddStudentDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddStudentDialog();

// �Ի�������
	enum { IDD = IDD_ADDSTUDENTDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExamStudentView* pExamStudentView;
	CString m_ExamNo;   //���Ա��
	CString m_ClassNo;  //�༶���
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
