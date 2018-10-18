// StudentScoreDoc.h :  CStudentScoreDoc 类的接口
//
#include "User.h"
#define WM_REFRESHLIST =WM_USER+50
#pragma once
class CStudentScoreDoc : public CDocument
{
protected: // 仅从序列化创建
	CStudentScoreDoc();
	DECLARE_DYNCREATE(CStudentScoreDoc)

// 属性
public:
  // 操作
public:
  CBaseTbl m_BaseTblList;
// 重写
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
 
// 实现
public:
	virtual ~CStudentScoreDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};


