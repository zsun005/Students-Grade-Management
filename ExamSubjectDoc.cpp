// ExamSubjectDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "ExamSubjectDoc.h"


// CExamSubjectDoc

IMPLEMENT_DYNCREATE(CExamSubjectDoc, CDocument)

CExamSubjectDoc::CExamSubjectDoc()
{
}

BOOL CExamSubjectDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	this->SetTitle("班级成绩信息:考试编号("+m_ExamNo+")班级编号("+m_ExamClassNo+")");
	this->m_ExamSubject.GetExamSubjectBy(m_ExamNo,m_ExamClassNo); 
	return TRUE;
}

CExamSubjectDoc::~CExamSubjectDoc()
{
}


BEGIN_MESSAGE_MAP(CExamSubjectDoc, CDocument)
END_MESSAGE_MAP()


// CExamSubjectDoc 诊断

#ifdef _DEBUG
void CExamSubjectDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExamSubjectDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExamSubjectDoc 序列化

void CExamSubjectDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}


// CExamSubjectDoc 命令
void CExamSubjectDoc::GetStudents()
{
	this->m_ExamSubject.GetStudentsByClassNo(this->m_ExamClassNo);   
}
void CExamSubjectDoc::GetSubjects()
{
	this->m_ExamSubject.GetSubjectsByClassNo(this->m_ExamClassNo);  
}
void CExamSubjectDoc::Refresh()
{
	this->m_ExamSubject.GetExamSubjectBy(m_ExamNo,m_ExamClassNo); 
}
