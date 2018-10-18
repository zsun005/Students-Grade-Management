// StudentScoreDoc.cpp :  CStudentScoreDoc 类的实现
//

#include "stdafx.h"
#include "StudentScore.h"

#include "StudentScoreDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentScoreDoc

IMPLEMENT_DYNCREATE(CStudentScoreDoc, CDocument)

BEGIN_MESSAGE_MAP(CStudentScoreDoc, CDocument)
END_MESSAGE_MAP()


// CStudentScoreDoc 构造/销毁

CStudentScoreDoc::CStudentScoreDoc()
{
	// TODO：在此添加一次性构造代码
   //db1.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=studentscoredb.mdb;Persist Security Info=False;Jet OLEDB:Database Password=score");
}

CStudentScoreDoc::~CStudentScoreDoc()
{
}

BOOL CStudentScoreDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO：在此添加重新初始化代码
	// （SDI 文档将重用该文档）
    this->SetTitle("基本信息登记");
	return TRUE;
}




// CStudentScoreDoc 序列化

void CStudentScoreDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO：在此添加存储代码
	}
	else
	{
		// TODO：在此添加加载代码
	}
}


// CStudentScoreDoc 诊断

#ifdef _DEBUG
void CStudentScoreDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CStudentScoreDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CStudentScoreDoc 命令
