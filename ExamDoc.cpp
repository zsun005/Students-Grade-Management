// ExamDoc.cpp : 实现文件
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
	this->SetTitle("考试信息");
	return TRUE;
}

CExamDoc::~CExamDoc()
{
}


BEGIN_MESSAGE_MAP(CExamDoc, CDocument)
END_MESSAGE_MAP()


// CExamDoc 诊断

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


// CExamDoc 序列化

void CExamDoc::Serialize(CArchive& ar)
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


// CExamDoc 命令
