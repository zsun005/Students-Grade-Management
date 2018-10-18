// ExamStudentDoc.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "ExamStudentDoc.h"


// CExamStudentDoc

IMPLEMENT_DYNCREATE(CExamStudentDoc, CDocument)

CExamStudentDoc::CExamStudentDoc()
{
}

BOOL CExamStudentDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	this->SetTitle("班级考生信息:考试编号("+m_ExamNo+")班级编号("+m_ExamClassNo+")");
	this->m_ExamStudent.GetExamStudentBy(m_ExamNo,m_ExamClassNo); 
	return TRUE;
}

CExamStudentDoc::~CExamStudentDoc()
{
}


BEGIN_MESSAGE_MAP(CExamStudentDoc, CDocument)
END_MESSAGE_MAP()


// CExamStudentDoc 诊断

#ifdef _DEBUG
void CExamStudentDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExamStudentDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExamStudentDoc 序列化

void CExamStudentDoc::Serialize(CArchive& ar)
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


// CExamStudentDoc 命令
