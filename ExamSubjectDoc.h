#pragma once
#include "Exam.h"

// CExamSubjectDoc �ĵ�

class CExamSubjectDoc : public CDocument
{
	DECLARE_DYNCREATE(CExamSubjectDoc)

public:
	CExamSubjectDoc();
	virtual ~CExamSubjectDoc();
	virtual void Serialize(CArchive& ar);   // Ϊ�ĵ� i/o ��д
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL OnNewDocument();

protected:

	DECLARE_MESSAGE_MAP()
public:
	CString m_ExamNo;     //���Ա��
	CString m_ExamClassNo;//���԰༶���
	CExamSubject m_ExamSubject;//���Կ�Ŀ
	void GetStudents();
	void GetSubjects();
	void Refresh();
};
