// StudentScoreDoc.h :  CStudentScoreDoc ��Ľӿ�
//
#include "User.h"
#define WM_REFRESHLIST =WM_USER+50
#pragma once
class CStudentScoreDoc : public CDocument
{
protected: // �������л�����
	CStudentScoreDoc();
	DECLARE_DYNCREATE(CStudentScoreDoc)

// ����
public:
  // ����
public:
  CBaseTbl m_BaseTblList;
// ��д
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
 
// ʵ��
public:
	virtual ~CStudentScoreDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};


