#pragma once
#include "Exam.h"

// CExamSubjectDoc ÎÄµµ

class CExamSubjectDoc : public CDocument
{
	DECLARE_DYNCREATE(CExamSubjectDoc)

public:
	CExamSubjectDoc();
	virtual ~CExamSubjectDoc();
	virtual void Serialize(CArchive& ar);   // ÎªÎÄµµ i/o ÖØÐ´
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL OnNewDocument();

protected:

	DECLARE_MESSAGE_MAP()
public:
	CString m_ExamNo;     //¿¼ÊÔ±àºÅ
	CString m_ExamClassNo;//¿¼ÊÔ°à¼¶±àºÅ
	CExamSubject m_ExamSubject;//¿¼ÊÔ¿ÆÄ¿
	void GetStudents();
	void GetSubjects();
	void Refresh();
};
