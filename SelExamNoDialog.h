#pragma once


// CSelExamNoDialog �Ի���
class CExamView;
class CSelExamNoDialog : public CDialog
{
	DECLARE_DYNAMIC(CSelExamNoDialog)

public:
	CSelExamNoDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CSelExamNoDialog();

// �Ի�������
	enum { IDD = IDD_SELEXAMNODIALOG };
    
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
    
	DECLARE_MESSAGE_MAP()
public:
	CExamView* pExamView; 
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
