#pragma once



// CExamSubjectView 窗体视图
class CExamSubjectDoc;
class CExamSubjectView : public CFormView
{
	DECLARE_DYNCREATE(CExamSubjectView)

protected:
	CExamSubjectView();           // 动态创建所使用的受保护的构造函数
	virtual ~CExamSubjectView();

public:
	enum { IDD = IDD_EXAMSUBJECTVIEW };
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
    CExamSubjectDoc* GetDocument() const;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
protected:
	virtual void OnDraw(CDC* /*pDC*/);
public:
	int m_CurRecordPos;
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void onAddSubject();
	void RefreshShow();
	afx_msg void On159();
};


