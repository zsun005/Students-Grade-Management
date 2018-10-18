// User.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "User.h"

//CADOStorage
CADOStorage::CADOStorage():CADODataset()
{ 
	this->SetConnection(theApp.m_pDBCon);
}
CADOStorage::~CADOStorage()
{

}
void CADOStorage::ExecInsertSql(CString TblName,CString Fldlist,CString ValueList)
{
	CString Sqlstr;
	Sqlstr="Insert into "+TblName+" ("+Fldlist+") values("+ValueList+")";
    this->ExecSql(Sqlstr);
}
void CADOStorage::ExecUpdateSql(CString TblName,CString UpdateStr,CString Constr)
{
	CString Sqlstr;
	Sqlstr="UPdate "+TblName+" set "+UpdateStr+" "+Constr;
    this->ExecSql(Sqlstr);
}
void CADOStorage::ExceDeleteSql(CString TblName,CString Constr)
{
	CString Sqlstr;
	Sqlstr="delete from "+TblName+" "+Constr;
    this->ExecSql(Sqlstr);
}
// CUser

CUser::CUser()
{ 	
	this->m_pStorage=NULL; 
    this->m_TblName="SysUser"; 
	m_pStorage=new CADOStorage();
    ASSERT(this->m_pStorage!=NULL);
	 
	this->m_pStorage->OpenSql(this->m_TblName); 
	
}

CUser::~CUser()
{
	if (m_pStorage!=NULL)
	{
	  delete m_pStorage;
	  this->m_pStorage=NULL; 
	}
	/*
	POSITION p=this->m_NameList.GetHeadPosition();
    while(p)
    {
       delete this->m_NameList.GetNext(p);
   	}
	*/
    this->m_NameList.RemoveAll(); 
}
void CUser::GetUserNames()
{ 
  CString name;
  POSITION p=this->m_NameList.GetHeadPosition();
  
 this->m_NameList.RemoveAll();  
  this->m_pStorage->MoveFirst();
  while(!this->m_pStorage->IsEof())
  {
	  this->m_pStorage->GetFieldValue("�û���",name); 
      this->m_NameList.AddTail(name);
	  this->m_pStorage->MoveNext(); 
  }
 
}
// CUser ��Ա����
bool CUser::Check(CString UserName,CString Password)
{
	this->m_pStorage->OpenSql(this->m_TblName,"*","where �û���='"+UserName+"'");  
	this->m_pStorage->GetFieldValue("����",this->m_Password);
    if(this->m_Password==Password)
	{
	  this->m_pStorage->GetFieldValue("�û���",this->m_UserName); 
	  this->m_pStorage->GetFieldValue("Ȩ��",this->m_Right);
	  this->m_LoginDate=CTime::GetCurrentTime(); 
	  return true;
	}
	else
	{
	  return false;
	}
}
//CBaseTbl
CBaseTbl::CBaseTbl()
{
	this->m_TblName="��˵��"; 
}

CBaseTbl::~CBaseTbl()
{
}
void CBaseTbl::GetTblnames()
{
	this->m_TblList.RemoveAll();
    this->m_Storage.OpenSql(this->m_TblName,"��������","where ������=0","order by ���");
	this->m_Storage.MoveFirst();
	CString name;
	while(!this->m_Storage.IsEof())
	{
		this->m_Storage.GetFieldValue(0,name);
        this->m_TblList.AddTail(name);
		this->m_Storage.MoveNext(); 
	}
}
bool CBaseTbl::SelectUnionTbl(CString StrTblname,CString& Realtbl,bool ByRealTblName)
{
	//1.ѡ�����Ǳ���
	if(!ByRealTblName)
	{
	   this->m_Storage.OpenSql(this->m_TblName,"*","where ��������='"+StrTblname+"'");
	   this->m_Storage.GetFieldValue("������",Realtbl);
	}
	else
	{
	   this->m_Storage.OpenSql(this->m_TblName,"*","where ������='"+Realtbl+"'");	
	}
    //2.��������sql���
	CString sqlstr;
	bool IsSingleTbl;
    this->m_Storage.GetFieldValue("������",IsSingleTbl);
	if(IsSingleTbl)
	{
		sqlstr="select * from "+Realtbl;
	}
	else
	{
    	CString  ExtraTblname=Realtbl;//�ⲿ���ַ���
		CString  FTblname;
    	CString  fldname;             //�ֶ��ַ���
        CString  Dispfldname;
		CString  MKName,FKName;       //���ֶ�,��Ӧ�ֶ�
		CString  ConStr;              //����
		int      FKCount;             //�������
		this->m_Storage.GetFieldValue("�������",FKCount);
		sqlstr="select "+Realtbl+".* ";
		for(int i=0;i<FKCount;i++)
		{
            fldname="��ʾ�ֶ�"+IntToStr(i);
            this->m_Storage.GetFieldValue(fldname,Dispfldname);
            fldname="�ⲿ��"+IntToStr(i);
		    this->m_Storage.GetFieldValue(fldname,FTblname);
            fldname="�ֶ�"+IntToStr(i);
		    this->m_Storage.GetFieldValue(fldname,MKName);
            fldname="���"+IntToStr(i);
		    this->m_Storage.GetFieldValue(fldname,FKName);
            
			sqlstr=sqlstr+","+FTblname+"."+Dispfldname+" ";
			ExtraTblname+=","+FTblname;
			if(i==0)
			{
			   ConStr+=Realtbl+"."+MKName+"="+FTblname+"."+FKName;
			}
			else
			{
			   ConStr+=" and "+Realtbl+"."+MKName+"="+FTblname+"."+FKName;
			}
		}
		sqlstr+=" from "+ExtraTblname+" where "+ConStr;
	}
	//3.��ѯ�ó����
	if(!Realtbl.IsEmpty()&&(Realtbl!=""))
	{
		this->m_Storage.Open(sqlstr,CADODataset::openQuery); 
    	  return true;
	}
	else
	 return false;
}

void CBaseTbl::RefreshList(CListCtrl& List1)
{
	if(this->m_Storage.IsOpen())
	{
	   this->m_Storage.FillList(List1);
	}
}
bool CBaseTbl::GetFieldRecord(CPtrArray& FieldArray,CString ctblname,CString constr) //�����¼���� 
{
   ASSERT(ctblname!="");
   //1.�жϼ�������
   if (this->m_Storage.IsOpen())
   {
     this->m_Storage.Close();
   }
   int ArrayCount=(int)FieldArray.GetSize();
   for(int j=0;j<ArrayCount;j++)
   {
      delete FieldArray.GetAt(j);
   }
   FieldArray.RemoveAll();

   CFieldRecord* fldrec;
   CADOFieldInfo fldinfo;
   CString fldvalue;
   //2.�жϼ�¼λ��
   bool IsZeroRecord;//��¼��Ϊ0
   if(constr == "")//��Ӽ�¼
   {
     this->m_Storage.OpenSql(ctblname);
      if (this->m_Storage.GetRecordCount()>0)
	  {
         this->m_Storage.MoveLast();
		 IsZeroRecord=false;
	  }
	  else
		  IsZeroRecord=true;
   }
   else
   {
     this->m_Storage.OpenSql(ctblname,"*",constr);
	 if(this->m_Storage.GetRecordCount()>0)
	 {
		 this->m_Storage.MoveFirst();
		 IsZeroRecord=false;
	 }
	 else
	 {
		 IsZeroRecord=true;
	     return false;
	 }
   }
   int count=this->m_Storage.GetFieldCount();
   //3.����ֶμ�¼��ָ������
   for(int i=0;i<count;i++)
   {  
      fldrec=new CFieldRecord();
	  if(IsZeroRecord)
	  {
	     fldvalue="";
	  }
	  else
	  {
         this->m_Storage.GetFieldValue(i,fldvalue);
	  }
      this->m_Storage.GetFieldInfo(i,&fldinfo);
      strcpy(fldrec->FKtbl,ctblname);

	  strcpy(fldrec->FieldName,fldinfo.m_strName);
	  strcpy(fldrec->Value,fldvalue);
	  
	  switch(fldinfo.m_nType)
	  {
	      case VT_DATE:
			  fldrec->IsStrType=true;
			  fldrec->IsBool =false; 
		      break;
		  case VT_BSTR:
			  fldrec->IsStrType=true;
			  fldrec->IsBool =false; 
		      break;
		  case 202:
			  fldrec->IsStrType=true;
			  fldrec->IsBool =false; 
		      break;
		  case VT_BOOL:
              fldrec->IsBool=true;
			  fldrec->IsStrType=false; 
			  break;
		  default:
			  fldrec->IsStrType=false; 
              fldrec->IsBool =false;  
			  break;
   	  }
   fldrec->pFK=NULL; 	  
   fldrec->IsVisible=true;
   FieldArray.Add(fldrec);
   }
   //��������Ϣ
   this->AddExtraFieldRecord(FieldArray,ctblname);
   return true;
}

bool CBaseTbl::RemoveRecord(int CurRecordPos)
{
	  if(!this->m_Storage.IsOpen())
	  {return false;} 
	  ASSERT(CurRecordPos>=0);
      if (this->m_Storage.GetRecordCount()>0) 
	  {
          this->m_Storage.MoveFirst();
		  while(CurRecordPos-->0)
		  { this->m_Storage.MoveNext();} 
	  }
	  this->m_Storage.Delete();
	  return true;
}

void CBaseTbl::ReQuery(CString TblName)
{
	this->m_Storage.OpenSql(TblName);
}
void CBaseTbl::ExecSql(CString SqlStr)
{
  this->m_Storage.ExecSql(SqlStr);
}

void CBaseTbl::AddExtraFieldRecord(CPtrArray& FieldArray,CString ctblname) 
{
   CADOStorage mk;
   CFieldRecord* fldrec;//�����Ϣָ��
   CFieldRecord* pMfldrec;//������Ϣָ��
   mk.OpenSql("��˵��","*","where ������='"+ctblname+"'");
   if(mk.GetRecordCount()==0)
   {
      return ;
   }
   else
   {
      bool IsSingleTbl;
      mk.GetFieldValue("������",IsSingleTbl);
	  if(IsSingleTbl)//�Ƕ�����
	  {
	     return ;
	  }
	  else
	  {
		  //�������б�
          int fkcount=0;
          mk.GetFieldValue("�������",fkcount);
		  CString name,value;//
		  char a[10];
          for(int i=0;i<fkcount;i++)
		  { //�������б�
        	  fldrec=new CFieldRecord();
        	  itoa(i,a,10);
			  name="���";
			  name=name+a;
		      mk.GetFieldValue(name,value);
			  strcpy(fldrec->FieldName,value); 
			  name="�ⲿ��";
    		  name=name+a;
		      mk.GetFieldValue(name,value);
			  strcpy(fldrec->FKtbl,value); 
			  name="��ʾ�ֶ�";
			  name=name+a;
              mk.GetFieldValue(name,value);
			  strcpy(fldrec->DisplayName ,value); 
              //ȷ��	
			  name="�ֶ�";
			  name=name+a;
		      mk.GetFieldValue(name,value);
		      fldrec->pFK=NULL; 
			  //ȷ�����ֶ�,��ӵ�����β��
			  for(int j=0;j<FieldArray.GetSize();j++)
			  {  
                 pMfldrec=(CFieldRecord*)FieldArray.GetAt(j);  
                 if(_stricmp(value,pMfldrec->FieldName)==0)
				 {
					 pMfldrec->pFK=fldrec;
                     break; 
				 }
			  }
			  
			   
		  }
	  }
   }

}