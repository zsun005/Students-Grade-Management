/***********************************************************************************
*                           
*              CExam 考试类 用于考试的信息登记
*              CExamClass 考试班级类
*              CFldValue  结构量(显示值/实际值) 
*              CExamStudent 考试学生类
*              CExamSubject 考试科目类
*
*
***********************************************************************************/
#pragma once


#include "User.h"
// CExam 命令目标
class CExam : public CObject
{
public:
	CExam();
	virtual ~CExam();
    
	CString      m_No;     //考试编号
	COleDateTime m_Date;     //考试日期
	CString      m_TermNo; //学期编号
	CStringList& GetTerms();
	CStringList* GetNos();
protected:
	CADOStorage m_Storage;//数据库连接
	CString     m_TblName;    //表名称

private:
    CStringList m_TermList;//学期列表
    CStringList m_NoList; //编号列表
public:
	void ClearTermList(void);
	void ClearNoList(void);
	void GetExamByNo(CString No);//获取考试信息
	bool IsNoExisted(CString No);//编号是否存在
	void AddExam();
	void DeleteExamByNo(CString No);
};

// CExamClass 命令目标
class CExamClass : public CObject
{
public:
	CExamClass();
	virtual ~CExamClass();

	CList<CFldValue,CFldValue>  m_GradeList;//年级列表
	CList<CFldValue,CFldValue>  m_ClassList;//年级列表
    
	CString      m_No;         //编号
	CString      m_ExamNo;     //考试编号
    CString      m_ClassNo;    //班级编号
protected:
	CADOStorage m_Storage;//数据库连接
	CString     m_TblName;    //表名称
public:
	void GetExamClassByExamNo(CString ExamNo);
	void FillList(CListCtrl& list)
	     { if (m_Storage.IsOpen()) this->m_Storage.FillList(list);};
	void GetGrades();
	void GetClassesByGradeNo(CString GradeNo);
	bool IsClassNoExisted(const CString ExamNo,CString ClassNo);//编号是否存在
	void AddClass();
	void DelClassByNo(CString No);
	void CaculateScores();//计算平均成绩和总成绩
};

class CExamStudent
{
public:
   CExamStudent();
   virtual ~CExamStudent();
   CString m_ExamNo;   //考试编号
   CString m_ClassNo;  //班级编号
   CString m_StudentNo;//学号
   CList<CFldValue,CFldValue>  m_StudentList;//学生列表
protected:
    CADOStorage m_Storage;//数据库连接
	CString     m_TblName;    //表名称
public:
	void GetExamStudentBy(const CString ExamNo,const CString ClassNo);
	void FillList(CListCtrl& list)
	     { if (m_Storage.IsOpen()) this->m_Storage.FillList(list);};
	void AddStudent();
    void GetStudentsByClassNo(CString ClassNo);//获取学生列表
	bool IsStudentNoExisted(const CString ExamNo,const CString ClassNo,const CString StudentNo);//编号是否存在
    void DelStudent(const CString ExamNo,const CString ClassNo,const CString StudentNo);
    void DelStudentByNo(const CString No);
};

class CExamSubject
{
public:
	CExamSubject(){ this->m_TblName="ExamSubject";};
	virtual ~CExamSubject(){ };
    CString m_ExamNo;   //考试编号
    CString m_ClassNo;  //班级编号
    CString m_StudentNo;//学号
	CString m_SubjectNo;//课程编号
	double  m_Score;    //成绩
    CList<CFldValue,CFldValue>  m_StudentList;//学生列表
    CList<CFldValue,CFldValue>  m_SubjectList;//学生列表
protected:
    CADOStorage m_Storage;//数据库连接
	CString     m_TblName;    //表名称
public:
	void GetExamSubjectBy(const CString ExamNo,const CString ClassNo);
	void FillList(CListCtrl& list)
	     { if (m_Storage.IsOpen()) this->m_Storage.FillList(list);};
    void GetStudentsByClassNo(CString ClassNo);//获取学生列表
	void GetSubjectsByClassNo(CString ClassNo);//科目列表
	void AddSubject();//添加科目
	void DelSubjectByNo(const CString No);//删除科目
};