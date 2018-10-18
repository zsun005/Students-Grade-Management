// ExamSubjectDoc.cpp : ʵ���ļ�
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
	this->SetTitle("�༶�ɼ���Ϣ:���Ա��("+m_ExamNo+")�༶���("+m_ExamClassNo+")");
	this->m_ExamSubject.GetExamSubjectBy(m_ExamNo,m_ExamClassNo); 
	return TRUE;
}

CExamSubjectDoc::~CExamSubjectDoc()
{
}


BEGIN_MESSAGE_MAP(CExamSubjectDoc, CDocument)
END_MESSAGE_MAP()


// CExamSubjectDoc ���

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


// CExamSubjectDoc ���л�

void CExamSubjectDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: �ڴ���Ӵ洢����
	}
	else
	{
		// TODO: �ڴ���Ӽ��ش���
	}
}


// CExamSubjectDoc ����
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
