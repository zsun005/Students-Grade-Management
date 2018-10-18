#pragma once



// CExamView ������ͼ
class CExamDoc;
class CExamView : public CFormView
{
	DECLARE_DYNCREATE(CExamView)

protected:
	CExamView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CExamView();

public:
	enum { IDD = IDD_EXAMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
  CExamDoc* GetDocument() const;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	virtual void OnInitialUpdate();
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_CurRecordPos;               //��ǰ��¼(�༶��)
	afx_msg void OnAddExamClass();    //��Ӱ༶
	afx_msg void OnBnClickedButton1();//ѡ����
	void RefreshShow(CString ExamNo);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnDelClass();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnExamStudent();
	afx_msg void OnExamSubject();
	//��ʾExamStudentView
	void ShowExamStudentView(CString ExamNo,CString ExamClassNo);
	void ShowExamSubjectView(CString ExamNo,CString ExamClassNo);
};


