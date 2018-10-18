// Exam.cpp : ÊµÏÖÎÄ¼þ
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

// CExam ³ÉÔ±º¯Êý

CStringList& CExam::GetTerms()
{
   this->m_Storage.OpenSql("Term","Ñ§ÆÚ±àºÅ");
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
   this->m_Storage.OpenSql("Exam","¿¼ÊÔ±àºÅ");
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
void CExam::GetExamByNo(CString No)//»ñÈ¡¿¼ÊÔÐÅÏ¢
{
   CString ConStr;
   ConStr="where ¿¼ÊÔ±àºÅ='"+No+"'";
   this->m_Storage.OpenSql(this->m_TblName,"*",ConStr);
   if(this->m_Storage.GetRecordCount()>0)
   {
      this->m_No=No;
	  this->m_Storage.GetFieldValue("¿¼ÊÔÈÕÆÚ",(COleDateTime*) &this->m_Date);
	  this->m_Storage.GetFieldValue("Ñ§ÆÚ±àºÅ",this->m_TermNo);
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
   ConStr="where ¿¼ÊÔ±àºÅ='"+No+"'";
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
   FldList="¿¼ÊÔ±àºÅ,¿¼ÊÔÈÕÆÚ,Ñ§ÆÚ±àºÅ";
   ValueList="'"+this->m_No+"','"+this->m_Date.Format()+"','"+this->m_TermNo+"'";
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}
void CExam::DeleteExamByNo(CString No)
{
	CString ConStr;
    ConStr="where ¿¼ÊÔ±àºÅ='"+No+"'";
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

// CExamClass ³ÉÔ±º¯Êý
void CExamClass::GetExamClassByExamNo(CString ExamNo)
{
   CString SqlStr;
   SqlStr="select a.±àºÅ,a.°à¼¶±àºÅ,b.°à¼¶Ãû³Æ,a.°à¼¶Æ½¾ù³É¼¨,a.°à¼¶×Ü³É¼¨ ";
   SqlStr+=" from ExamClass a,Class b where a.°à¼¶±àºÅ=b.°à¼¶±àºÅ and ";
   SqlStr+=" a.¿¼ÊÔ±àºÅ='"+ExamNo+"'";
   this->m_Storage.Open(SqlStr,CADODataset::openQuery);
}
void CExamClass::GetGrades()
{
	if(this->m_GradeList.GetCount()>0)
	{
	  this->m_GradeList.RemoveAll();  
	}
	CFldValue value;
	this->m_Storage.OpenSql("Grade","Äê¼¶±àºÅ,Äê¼¶Ãû³Æ");
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("Äê¼¶±àºÅ",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("Äê¼¶Ãû³Æ",fldvalue);
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
	ConStr="where Äê¼¶±àºÅ='"+GradeNo+"'";
	this->m_Storage.OpenSql("Class","°à¼¶±àºÅ,°à¼¶Ãû³Æ",ConStr);
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("°à¼¶±àºÅ",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("°à¼¶Ãû³Æ",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_ClassList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}

void CExamClass::AddClass()
{
   CString FldList,ValueList;
   FldList="¿¼ÊÔ±àºÅ,°à¼¶±àºÅ";
   ValueList="'"+this->m_ExamNo+"','"+this->m_ClassNo+"'";
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}
bool CExamClass::IsClassNoExisted(const CString ExamNo,CString ClassNo)//±àºÅÊÇ·ñ´æÔÚ
{
   CString ConStr;
   ConStr="where °à¼¶±àºÅ='"+ClassNo+"' and  ¿¼ÊÔ±àºÅ='"+ExamNo+"'";
   this->m_Storage.OpenSql(this->m_TblName,"±àºÅ",ConStr);
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
  constr="where ±àºÅ="+No;
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

//CExamStudent³ÉÔ±º¯Êý

void CExamStudent::GetExamStudentBy(const CString ExamNo,const CString ClassNo)
{
   CString SqlStr;
   SqlStr="select a.¿¼Éú±àºÅ ,a.Ñ§ºÅ,b.ÐÕÃû,a.×Ü³É¼¨,a.Æ½¾ù³É¼¨ ";
   SqlStr+=" from ExamStudent a,student b where a.¿¼ÊÔ±àºÅ='"+ExamNo+"' and  a.°à¼¶±àºÅ='"+ClassNo+"'";
   SqlStr+=" and a.Ñ§ºÅ=b.Ñ§ºÅ";
   this->m_Storage.Open(SqlStr,CADODataset::openQuery); 
}

void CExamStudent::AddStudent()
{
    CString FldList,ValueList;
   FldList="¿¼ÊÔ±àºÅ,°à¼¶±àºÅ,Ñ§ºÅ";
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
	ConStr="where °à¼¶±àºÅ='"+ClassNo+"'";
	this->m_Storage.OpenSql("student","Ñ§ºÅ,ÐÕÃû",ConStr);
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("Ñ§ºÅ",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("ÐÕÃû",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_StudentList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}

bool CExamStudent::IsStudentNoExisted(const CString ExamNo,const CString ClassNo,const CString StudentNo)//±àºÅÊÇ·ñ´æÔÚ
{
	CString ConStr;
	ConStr="where ¿¼ÊÔ±àºÅ='"+ExamNo+"' and °à¼¶±àºÅ='"+ClassNo+"' and Ñ§ºÅ='";
	ConStr+=StudentNo+"'";
   this->m_Storage.OpenSql(this->m_TblName,"¿¼Éú±àºÅ",ConStr);
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
	ConStr="where ¿¼ÊÔ±àºÅ='"+ExamNo+"' and °à¼¶±àºÅ='"+ClassNo+"' and Ñ§ºÅ='";
	ConStr+=StudentNo+"'";
	this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}
void CExamStudent::DelStudentByNo(const CString No)
{
    CString ConStr;
	ConStr="where ¿¼Éú±àºÅ="+No;
	this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}

//CExamSubject
void CExamSubject::GetExamSubjectBy(const CString ExamNo,const CString ClassNo)
{
   CString SqlStr;
   SqlStr="select a.±àºÅ ,a.Ñ§ºÅ,b.ÐÕÃû,a.¿Î³Ì±àºÅ,c.¿Î³ÌÃû³Æ,a.³É¼¨ ";
   SqlStr+=" from ExamSubject a,student b,subject c where a.¿¼ÊÔ±àºÅ='"+ExamNo+"' and  a.°à¼¶±àºÅ='"+ClassNo+"'";
   SqlStr+=" and a.Ñ§ºÅ=b.Ñ§ºÅ and a.¿Î³Ì±àºÅ=c.¿Î³Ì±àºÅ";
   this->m_Storage.Open(SqlStr,CADODataset::openQuery); 
}
void CExamSubject::GetStudentsByClassNo(CString ClassNo)//»ñÈ¡Ñ§ÉúÁÐ±í
{
   	if(this->m_StudentList.GetCount()>0)
	{
	  this->m_StudentList.RemoveAll();  
	}
	CFldValue value;
	CString ConStr;
	ConStr="where °à¼¶±àºÅ='"+ClassNo+"'";
	this->m_Storage.OpenSql("student","Ñ§ºÅ,ÐÕÃû",ConStr);
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("Ñ§ºÅ",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("ÐÕÃû",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_StudentList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}
void CExamSubject::GetSubjectsByClassNo(CString ClassNo)//¿ÆÄ¿ÁÐ±í
{
   	if(this->m_SubjectList.GetCount()>0)
	{
	  this->m_SubjectList.RemoveAll();  
	}
	CFldValue value;
	CString SqlStr;
	SqlStr="select a.¿Î³Ì±àºÅ,b.¿Î³ÌÃû³Æ from SubjectClass a,Subject b ";
	SqlStr+="where a.¿Î³Ì±àºÅ=b.¿Î³Ì±àºÅ and a.°à¼¶±àºÅ='"+ClassNo+"'";
    this->m_Storage.Open(SqlStr,CADODataset::openQuery); 
	if(this->m_Storage.GetRecordCount()>0)
	{   
		this->m_Storage.MoveFirst();
		CString fldvalue;
		while(!this->m_Storage.IsEof())
		{
		   this->m_Storage.GetFieldValue("¿Î³Ì±àºÅ",fldvalue);
		   strcpy(value.FieldValue,fldvalue);
    	   this->m_Storage.GetFieldValue("¿Î³ÌÃû³Æ",fldvalue);
		   strcpy(value.DispalyFieldValue,fldvalue);
           this->m_SubjectList.AddTail(value);
		   this->m_Storage.MoveNext();
		}
	
	}
}
void CExamSubject::AddSubject()//Ìí¼Ó¿ÆÄ¿
{
   CString FldList,ValueList;
   char a[50];
   FldList="¿¼ÊÔ±àºÅ,°à¼¶±àºÅ,Ñ§ºÅ,¿Î³Ì±àºÅ,³É¼¨";
   ValueList="'"+this->m_ExamNo+"','"+this->m_ClassNo+"','";
   ValueList+=this->m_StudentNo+"','"+this->m_SubjectNo+"',";
   sprintf(a,"%f",this->m_Score); 
   ValueList+=a;
   this->m_Storage.ExecInsertSql(this->m_TblName,FldList,ValueList); 
}
void CExamSubject::DelSubjectByNo(const CString No)//É¾³ý¿ÆÄ¿
{
    CString ConStr;
	ConStr="where ±àºÅ="+No;
	this->m_Storage.ExceDeleteSql(this->m_TblName,ConStr); 
}