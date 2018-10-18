// StudentScoreView.h : CStudentScoreView ��Ľӿ�
//


#pragma once


class CStudentScoreDoc;
class CStudentScoreView : public CFormView
{
protected: // �������л�����
	CStudentScoreView();
	DECLARE_DYNCREATE(CStudentScoreView)

public:
	enum{ IDD = IDD_STUDENTSCORE_FORM };

// ����
public:
	CStudentScoreDoc* GetDocument() const;
    CSplitterWnd   m_wndSplitter1;
    CMultiDocTemplate* m_pDocTemplate;
	CString m_CurTblName;//��ǰ���ݱ�
	int m_CurRecordPos;//��ǰ��¼λ��
// ����
public:

// ��д
	public:
virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	virtual void OnInitialUpdate(); // ������һ�ε���

// ʵ��
public:
	virtual ~CStudentScoreView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
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
	afx_msg void OnADDRecord();   //��Ӽ�¼
	afx_msg void OnDelRecord();
	afx_msg void OnAlterRecord();
	void RefreshShow(bool ISUnionQuery=true);  //ˢ����ʾ
};

#ifndef _DEBUG  // StudentScoreView.cpp �ĵ��԰汾
inline CStudentScoreDoc* CStudentScoreView::GetDocument() const
   { return reinterpret_cast<CStudentScoreDoc*>(m_pDocument); }
#endif

