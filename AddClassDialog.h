#pragma once


// AddClassDialog �Ի���
class CExamView;
class CAddClassDialog : public CDialog
{
	DECLARE_DYNAMIC(CAddClassDialog)

public:
	CAddClassDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CAddClassDialog();

// �Ի�������
	enum { IDD = IDD_ADDCLASSDIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CExamView* m_pExamView;//����ͼ
	CString m_ExamNo;      //���Ա��
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
};
