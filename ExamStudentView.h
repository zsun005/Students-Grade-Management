#pragma once



// CExamStudentView 窗体视图
class CExamStudentDoc;
class CExamStudentView : public CFormView
{
	DECLARE_DYNCREATE(CExamStudentView)

protected:
	CExamStudentView();           // 动态创建所使用的受保护的构造函数
	virtual ~CExamStudentView();
    
public:
	enum { IDD = IDD_EXAMSTUDENTVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
    CExamStudentDoc* GetDocument() const;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
	virtual void OnDraw(CDC* /*pDC*/);
public:
	int m_CurRecordPos;
	virtual void OnInitialUpdate();
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onAddStudent();
	void RefreshShow();
	afx_msg void OnDelStudent();
};


