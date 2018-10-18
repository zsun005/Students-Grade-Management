/***********************************************************************************
*                           
*              CExam ������ ���ڿ��Ե���Ϣ�Ǽ�
*              CExamClass ���԰༶��
*              CFldValue  �ṹ��(��ʾֵ/ʵ��ֵ) 
*              CExamStudent ����ѧ����
*              CExamSubject ���Կ�Ŀ��
*
*
***********************************************************************************/
#pragma once


#include "User.h"
// CExam ����Ŀ��
class CExam : public CObject
{
public:
	CExam();
	virtual ~CExam();
    
	CString      m_No;     //���Ա��
	COleDateTime m_Date;     //��������
	CString      m_TermNo; //ѧ�ڱ��
	CStringList& GetTerms();
	CStringList* GetNos();
protected:
	CADOStorage m_Storage;//���ݿ�����
	CString     m_TblName;    //������

private:
    CStringList m_TermList;//ѧ���б�
    CStringList m_NoList; //����б�
public:
	void ClearTermList(void);
	void ClearNoList(void);
	void GetExamByNo(CString No);//��ȡ������Ϣ
	bool IsNoExisted(CString No);//����Ƿ����
	void AddExam();
	void DeleteExamByNo(CString No);
};

// CExamClass ����Ŀ��
class CExamClass : public CObject
{
public:
	CExamClass();
	virtual ~CExamClass();

	CList<CFldValue,CFldValue>  m_GradeList;//�꼶�б�
	CList<CFldValue,CFldValue>  m_ClassList;//�꼶�б�
    
	CString      m_No;         //���
	CString      m_ExamNo;     //���Ա��
    CString      m_ClassNo;    //�༶���
protected:
	CADOStorage m_Storage;//���ݿ�����
	CString     m_TblName;    //������
public:
	void GetExamClassByExamNo(CString ExamNo);
	void FillList(CListCtrl& list)
	     { if (m_Storage.IsOpen()) this->m_Storage.FillList(list);};
	void GetGrades();
	void GetClassesByGradeNo(CString GradeNo);
	bool IsClassNoExisted(const CString ExamNo,CString ClassNo);//����Ƿ����
	void AddClass();
	void DelClassByNo(CString No);
	void CaculateScores();//����ƽ���ɼ����ܳɼ�
};

class CExamStudent
{
public:
   CExamStudent();
   virtual ~CExamStudent();
   CString m_ExamNo;   //���Ա��
   CString m_ClassNo;  //�༶���
   CString m_StudentNo;//ѧ��
   CList<CFldValue,CFldValue>  m_StudentList;//ѧ���б�
protected:
    CADOStorage m_Storage;//���ݿ�����
	CString     m_TblName;    //������
public:
	void GetExamStudentBy(const CString ExamNo,const CString ClassNo);
	void FillList(CListCtrl& list)
	     { if (m_Storage.IsOpen()) this->m_Storage.FillList(list);};
	void AddStudent();
    void GetStudentsByClassNo(CString ClassNo);//��ȡѧ���б�
	bool IsStudentNoExisted(const CString ExamNo,const CString ClassNo,const CString StudentNo);//����Ƿ����
    void DelStudent(const CString ExamNo,const CString ClassNo,const CString StudentNo);
    void DelStudentByNo(const CString No);
};

class CExamSubject
{
public:
	CExamSubject(){ this->m_TblName="ExamSubject";};
	virtual ~CExamSubject(){ };
    CString m_ExamNo;   //���Ա��
    CString m_ClassNo;  //�༶���
    CString m_StudentNo;//ѧ��
	CString m_SubjectNo;//�γ̱��
	double  m_Score;    //�ɼ�
    CList<CFldValue,CFldValue>  m_StudentList;//ѧ���б�
    CList<CFldValue,CFldValue>  m_SubjectList;//ѧ���б�
protected:
    CADOStorage m_Storage;//���ݿ�����
	CString     m_TblName;    //������
public:
	void GetExamSubjectBy(const CString ExamNo,const CString ClassNo);
	void FillList(CListCtrl& list)
	     { if (m_Storage.IsOpen()) this->m_Storage.FillList(list);};
    void GetStudentsByClassNo(CString ClassNo);//��ȡѧ���б�
	void GetSubjectsByClassNo(CString ClassNo);//��Ŀ�б�
	void AddSubject();//��ӿ�Ŀ
	void DelSubjectByNo(const CString No);//ɾ����Ŀ
};