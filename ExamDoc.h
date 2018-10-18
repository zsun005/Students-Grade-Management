#pragma once
#include "Exam.h"

// CExamDoc 文档

class CExamDoc : public CDocument
{
	DECLARE_DYNCREATE(CExamDoc)

public:
	CExamDoc();
	virtual ~CExamDoc();
	virtual void Serialize(CArchive& ar);   // 为文档 i/o 重写
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
public:
	CExam m_Exam;           //测试实例
	CExamClass m_ExamClass; //测试类
};
