#pragma once


// CAddSubjectDialog �Ի���
class CExamSubjectView;
class CAddSubjectDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddSubjectDialog)

public:
	CAddSubjectDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddSubjectDialog();

// �Ի�������
	enum { IDD = IDD_ADDSUBJECTDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExamSubjectView* m_pExamSubjectView;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
