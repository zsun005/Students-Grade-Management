// StudentScoreDoc.cpp :  CStudentScoreDoc ���ʵ��
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


// CStudentScoreDoc ����/����

CStudentScoreDoc::CStudentScoreDoc()
{
	// TODO���ڴ����һ���Թ������
   //db1.Open("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=studentscoredb.mdb;Persist Security Info=False;Jet OLEDB:Database Password=score");
}

CStudentScoreDoc::~CStudentScoreDoc()
{
}

BOOL CStudentScoreDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO���ڴ�������³�ʼ������
	// ��SDI �ĵ������ø��ĵ���
    this->SetTitle("������Ϣ�Ǽ�");
	return TRUE;
}




// CStudentScoreDoc ���л�

void CStudentScoreDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO���ڴ���Ӵ洢����
	}
	else
	{
		// TODO���ڴ���Ӽ��ش���
	}
}


// CStudentScoreDoc ���

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


// CStudentScoreDoc ����
