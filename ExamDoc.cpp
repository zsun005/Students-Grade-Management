// ExamDoc.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "ExamDoc.h"


// CExamDoc

IMPLEMENT_DYNCREATE(CExamDoc, CDocument)

CExamDoc::CExamDoc()
{
}

BOOL CExamDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;
	this->SetTitle("������Ϣ");
	return TRUE;
}

CExamDoc::~CExamDoc()
{
}


BEGIN_MESSAGE_MAP(CExamDoc, CDocument)
END_MESSAGE_MAP()


// CExamDoc ���

#ifdef _DEBUG
void CExamDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CExamDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CExamDoc ���л�

void CExamDoc::Serialize(CArchive& ar)
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


// CExamDoc ����
