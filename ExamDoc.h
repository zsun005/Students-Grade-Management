#pragma once
#include "Exam.h"

// CExamDoc �ĵ�

class CExamDoc : public CDocument
{
	DECLARE_DYNCREATE(CExamDoc)

public:
	CExamDoc();
	virtual ~CExamDoc();
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� i/o ��д
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	virtual BOOL OnNewDocument();

	DECLARE_MESSAGE_MAP()
public:
	CExam m_Exam;           //����ʵ��
	CExamClass m_ExamClass; //������
};
