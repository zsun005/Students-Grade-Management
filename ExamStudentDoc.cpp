// ExamStudentDoc.cpp : ʵ���ļ�
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
	this->SetTitle("�༶������Ϣ:���Ա��("+m_ExamNo+")�༶���("+m_ExamClassNo+")");
	this->m_ExamStudent.GetExamStudentBy(m_ExamNo,m_ExamClassNo); 
	return TRUE;
}

CExamStudentDoc::~CExamStudentDoc()
{
}


BEGIN_MESSAGE_MAP(CExamStudentDoc, CDocument)
END_MESSAGE_MAP()


// CExamStudentDoc ���

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


// CExamStudentDoc ���л�

void CExamStudentDoc::Serialize(CArchive& ar)
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


// CExamStudentDoc ����
