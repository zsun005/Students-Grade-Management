#pragma once



// CExamView 窗体视图
class CExamDoc;
class CExamView : public CFormView
{
	DECLARE_DYNCREATE(CExamView)

protected:
	CExamView();           // 动态创建所使用的受保护的构造函数
	virtual ~CExamView();

public:
	enum { IDD = IDD_EXAMVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
  CExamDoc* GetDocument() const;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	virtual void OnInitialUpdate();
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	int m_CurRecordPos;               //当前记录(班级表)
	afx_msg void OnAddExamClass();    //添加班级
	afx_msg void OnBnClickedButton1();//选择编号
	void RefreshShow(CString ExamNo);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnDelClass();
	afx_msg void OnBnClickedBtnClose();
	afx_msg void OnExamStudent();
	afx_msg void OnExamSubject();
	//显示ExamStudentView
	void ShowExamStudentView(CString ExamNo,CString ExamClassNo);
	void ShowExamSubjectView(CString ExamNo,CString ExamClassNo);
};


