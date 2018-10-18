#pragma once
#include "Exam.h"

// CExamStudentDoc �ĵ�

class CExamStudentDoc : public CDocument
{
	DECLARE_DYNCREATE(CExamStudentDoc)

public:
	CExamStudentDoc();
	virtual ~CExamStudentDoc();
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
    CExamStudent m_ExamStudent;//����ѧ��
};
