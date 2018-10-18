#pragma once
#include "Exam.h"

// CExamStudentDoc 文档

class CExamStudentDoc : public CDocument
{
	DECLARE_DYNCREATE(CExamStudentDoc)

public:
	CExamStudentDoc();
	virtual ~CExamStudentDoc();
	virtual void Serialize(CArchive& ar);   // 为文档 i/o 重写
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual BOOL OnNewDocument();

protected:

	DECLARE_MESSAGE_MAP()
public:
	CString m_ExamNo;     //考试编号
	CString m_ExamClassNo;//考试班级编号
    CExamStudent m_ExamStudent;//考试学生
};
