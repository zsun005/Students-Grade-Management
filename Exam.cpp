// Exam.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "Exam.h"


// CExam

CExam::CExam()
{
	this->m_TblName="Exam"; 
}

CExam::~CExam()
{
	if(this->m_TermList.GetCount()>0)
   {
      this->ClearTermList();
   }
}

// CExam ��Ա����

CStringList& CExam::GetTerms()
{
   this->m_Storage.OpenSql("Term","ѧ�ڱ��");
   int count=this->m_Storage.GetRecordCount();
   if(this->m_TermList.GetCount()>0)
   {
      this->ClearTermList();
   }
   if(count>0)
   {
      this->m_Storage.MoveFirst();
	  CString value;
	  while(!this->m_Storage.IsEof())
	  {
         this->m_Storage.GetFieldValue(0,value);
	     m_TermList.AddTail(value);
		 this->m_Storage.MoveNext();
	  }
   }
  return this->m_TermList;
}

void CExam::ClearTermList(void)
{
	/*
	POSITION p;
	p=this->m_TermList.GetHeadPosition();
	while(p)
	{
	   delete this->m_TermList.GetNext(p);
	}
	*/
	this->m_TermList.RemoveAll();
}

CStringList* CExam::GetNos()
{
   this->m_Storage.OpenSql("Exam","���Ա��");
   int count=this->m_Storage.GetRecordCount();
   if(this->m_NoList.GetCount()>0)
   {
      this->ClearNoList();
   }
   if(count>0)
   {
      this->m_Storage.MoveFirst();
	  CString value;
	  while(!this->m_Storage.IsEof())
	  {
         this->m_Storage.GetFieldValue(0,value);
	     m_NoList.AddTail(value);
		 this->m_Storage.MoveNext();
	  }
   }
  return &this->m_NoList;

}

void CExam::ClearNoList(void)
{
	/*
	POSITION p;
	p=this->m_NoList.GetHeadPosition();
	while(p)
	{
	   delete this->m_NoList.GetNext(p);
	}
	*/
	this->m_NoList.RemoveAll();
}
void CExam::GetExamByNo(CString No)//��ȡ������Ϣ
{
   CString ConStr;
   ConStr="where ���Ա��='"+No+"'";
   this->m_Storage.OpenSql(this->m_TblName,"*",ConStr);
   if(this->m_Storage.GetRecordCount()>0)
   {
      this->m_No=No;
	  this->m_Storage.GetFieldValue("��������",(COleDateTime*) &this->m_Date);
	  this->m_Storage.GetFieldValue("ѧ�ڱ��",this->m_TermNo);
   }
   else
   {
      this->m_No="";
	  this->m_TermNo=""; 
   }
}
bool CExam::IsNoExisted(CString No)
{
   CString ConStr;
   ConStr="where ���Ա��='"+No+"'";
   this->m_Storage.OpenSql(this->m_TblName,"*",ConStr);
   if(this->m_Storage.GetRecordCount()>0)
   {
      return true;
   }
   else
   {
      return false;
   }
}
void CExam::AddExam()
{
   CString FldList,ValueList;
   FldList="���Ա��,��������,ѧ�ڱ��";
   ValueList="'"+this->m_No+"','"+this->m_Date.Format()+"','"+this->m_TermNo+"'";
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}
void CExam::DeleteExamByNo(CString No)
{
	CString ConStr;
    ConStr="where ���Ա��='"+No+"'";
    this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}
// CExamClass

CExamClass::CExamClass()
{
	this->m_TblName="ExamClass"; 
}

CExamClass::~CExamClass()
{
}

// CExamClass ��Ա����
void CExamClass::GetExamClassByExamNo(CString ExamNo)
{
   CString SqlStr;
   SqlStr="select a.���,a.�༶���,b.�༶����,a.�༶ƽ���ɼ�,a.�༶�ܳɼ� ";
   SqlStr+=" from ExamClass a,Class b where a.�༶���=b.�༶��� and ";
   SqlStr+=" a.���Ա��='"+ExamNo+"'";
   this->m_Storage.Open(SqlStr,CADODataset::openQuery);
}
void CExamClass::GetGrades()
{
	if(this->m_GradeList.GetCount()>0)
	{
	  this->m_GradeList.RemoveAll();  
	}
	CFldValue value;
	this->m_Storage.OpenSql("Grade","�꼶���,�꼶����");
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("�꼶���",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("�꼶����",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_GradeList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}

}
void CExamClass::GetClassesByGradeNo(CString GradeNo)
{
	if(this->m_ClassList.GetCount()>0)
	{
	  this->m_ClassList.RemoveAll();  
	}
	CFldValue value;
	CString ConStr;
	ConStr="where �꼶���='"+GradeNo+"'";
	this->m_Storage.OpenSql("Class","�༶���,�༶����",ConStr);
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("�༶���",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("�༶����",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_ClassList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}

void CExamClass::AddClass()
{
   CString FldList,ValueList;
   FldList="���Ա��,�༶���";
   ValueList="'"+this->m_ExamNo+"','"+this->m_ClassNo+"'";
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}
bool CExamClass::IsClassNoExisted(const CString ExamNo,CString ClassNo)//����Ƿ����
{
   CString ConStr;
   ConStr="where �༶���='"+ClassNo+"' and  ���Ա��='"+ExamNo+"'";
   this->m_Storage.OpenSql(this->m_TblName,"���",ConStr);
   if(this->m_Storage.GetRecordCount()>0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void CExamClass::DelClassByNo(CString No)
{
  CString constr;
  constr="where ���="+No;
  this->m_Storage.ExceDeleteSql(this->m_TblName,constr); 
}

//CExamStudent

CExamStudent::CExamStudent()
{
    this->m_TblName="ExamStudent" ;
}
CExamStudent::~CExamStudent()
{

}

//CExamStudent��Ա����

void CExamStudent::GetExamStudentBy(const CString ExamNo,const CString ClassNo)
{
   CString SqlStr;
   SqlStr="select a.������� ,a.ѧ��,b.����,a.�ܳɼ�,a.ƽ���ɼ� ";
   SqlStr+=" from ExamStudent a,student b where a.���Ա��='"+ExamNo+"' and  a.�༶���='"+ClassNo+"'";
   SqlStr+=" and a.ѧ��=b.ѧ��";
   this->m_Storage.Open(SqlStr,CADODataset::openQuery); 
}

void CExamStudent::AddStudent()
{
    CString FldList,ValueList;
   FldList="���Ա��,�༶���,ѧ��";
   ValueList="'"+this->m_ExamNo+"','"+this->m_ClassNo+"','"+this->m_StudentNo+"'";
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}

void CExamStudent::GetStudentsByClassNo(CString ClassNo)
{
	if(this->m_StudentList.GetCount()>0)
	{
	  this->m_StudentList.RemoveAll();  
	}
	CFldValue value;
	CString ConStr;
	ConStr="where �༶���='"+ClassNo+"'";
	this->m_Storage.OpenSql("student","ѧ��,����",ConStr);
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("ѧ��",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("����",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_StudentList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}

bool CExamStudent::IsStudentNoExisted(const CString ExamNo,const CString ClassNo,const CString StudentNo)//����Ƿ����
{
	CString ConStr;
	ConStr="where ���Ա��='"+ExamNo+"' and �༶���='"+ClassNo+"' and ѧ��='";
	ConStr+=StudentNo+"'";
   this->m_Storage.OpenSql(this->m_TblName,"�������",ConStr);
   if(this->m_Storage.GetRecordCount()>0)
   {
      return true;
   }
   else
   {
      return false;
   }
}

void CExamStudent::DelStudent(const CString ExamNo,const CString ClassNo,const CString StudentNo)
{
	CString ConStr;
	ConStr="where ���Ա��='"+ExamNo+"' and �༶���='"+ClassNo+"' and ѧ��='";
	ConStr+=StudentNo+"'";
	this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}
void CExamStudent::DelStudentByNo(const CString No)
{
    CString ConStr;
	ConStr="where �������="+No;
	this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}

//CExamSubject
void CExamSubject::GetExamSubjectBy(const CString ExamNo,const CString ClassNo)
{
   CString SqlStr;
   SqlStr="select a.��� ,a.ѧ��,b.����,a.�γ̱��,c.�γ�����,a.�ɼ� ";
   SqlStr+=" from ExamSubject a,student b,subject c where a.���Ա��='"+ExamNo+"' and  a.�༶���='"+ClassNo+"'";
   SqlStr+=" and a.ѧ��=b.ѧ�� and a.�γ̱��=c.�γ̱��";
   this->m_Storage.Open(SqlStr,CADODataset::openQuery); 
}
void CExamSubject::GetStudentsByClassNo(CString ClassNo)//��ȡѧ���б�
{
   	if(this->m_StudentList.GetCount()>0)
	{
	  this->m_StudentList.RemoveAll();  
	}
	CFldValue value;
	CString ConStr;
	ConStr="where �༶���='"+ClassNo+"'";
	this->m_Storage.OpenSql("student","ѧ��,����",ConStr);
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("ѧ��",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("����",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_StudentList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}
void CExamSubject::GetSubjectsByClassNo(CString ClassNo)//��Ŀ�б�
{
   	if(this->m_SubjectList.GetCount()>0)
	{
	  this->m_SubjectList.RemoveAll();  
	}
	CFldValue value;
	CString SqlStr;
	SqlStr="select a.�γ̱��,b.�γ����� from SubjectClass a,Subject b ";
	SqlStr+="where a.�γ̱��=b.�γ̱�� and a.�༶���='"+ClassNo+"'";
    this->m_Storage.Open(SqlStr,CADODataset::openQuery); 
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("�γ̱��",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("�γ�����",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_SubjectList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}
void CExamSubject::AddSubject()//��ӿ�Ŀ
{
   CString FldList,ValueList;
   char a[50];
   FldList="���Ա��,�༶���,ѧ��,�γ̱��,�ɼ�";
   ValueList="'"+this->m_ExamNo+"','"+this->m_ClassNo+"','";
   ValueList+=this->m_StudentNo+"','"+this->m_SubjectNo+"',";
   sprintf(a,"%f",this->m_Score); 
   ValueList+=a;
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}
void CExamSubject::DelSubjectByNo(const CString No)//ɾ����Ŀ
{
    CString ConStr;
	ConStr="where ���="+No;
	this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}