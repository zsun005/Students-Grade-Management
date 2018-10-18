// StudentScoreView.h : CStudentScoreView 类的接口
//


#pragma once


class CStudentScoreDoc;
class CStudentScoreView : public CFormView
{
protected: // 仅从序列化创建
	CStudentScoreView();
	DECLARE_DYNCREATE(CStudentScoreView)

public:
	enum{ IDD = IDD_STUDENTSCORE_FORM };

// 属性
public:
	CStudentScoreDoc* GetDocument() const;
    CSplitterWnd   m_wndSplitter1;
    CMultiDocTemplate* m_pDocTemplate;
	CString m_CurTblName;//当前数据表
	int m_CurRecordPos;//当前记录位置
// 操作
public:

// 重写
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	virtual void OnInitialUpdate(); // 构造后第一次调用

// 实现
public:
	virtual ~CStudentScoreView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg LRESULT OnRefreshList1(WPARAM wParam,LPARAM lParam);
	afx_msg LRESULT OnExecSql(WPARAM wParam,LPARAM lParam);
protected:
	virtual void OnDraw(CDC* /*pDC*/);
public:
	afx_msg void OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult);

	CImageList  m_ImageList;
	afx_msg void OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnADDRecord();   //添加记录
	afx_msg void OnDelRecord();
	afx_msg void OnAlterRecord();
	void RefreshShow(bool ISUnionQuery=true);  //刷新显示
};

#ifndef _DEBUG  // StudentScoreView.cpp 的调试版本
inline CStudentScoreDoc* CStudentScoreView::GetDocument() const
   { return reinterpret_cast<CStudentScoreDoc*>(m_pDocument); }
#endif

