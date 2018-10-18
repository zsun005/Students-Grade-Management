// User.cpp : 实现文件
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
	  this->m_pStorage->GetFieldValue("用户名",name); 
      this->m_NameList.AddTail(name);
	  this->m_pStorage->MoveNext(); 
  }
 
}
// CUser 成员函数
bool CUser::Check(CString UserName,CString Password)
{
	this->m_pStorage->OpenSql(this->m_TblName,"*","where 用户名='"+UserName+"'");  
	this->m_pStorage->GetFieldValue("秘码",this->m_Password);
    if(this->m_Password==Password)
	{
	  this->m_pStorage->GetFieldValue("用户名",this->m_UserName); 
	  this->m_pStorage->GetFieldValue("权限",this->m_Right);
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
	this->m_TblName="表说明"; 
}

CBaseTbl::~CBaseTbl()
{
}
void CBaseTbl::GetTblnames()
{
	this->m_TblList.RemoveAll();
    this->m_Storage.OpenSql(this->m_TblName,"中文名称","where 表属性=0","order by 编号");
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
	//1.选择真是表名
	if(!ByRealTblName)
	{
	   this->m_Storage.OpenSql(this->m_TblName,"*","where 中文名称='"+StrTblname+"'");
	   this->m_Storage.GetFieldValue("表名称",Realtbl);
	}
	else
	{
	   this->m_Storage.OpenSql(this->m_TblName,"*","where 表名称='"+Realtbl+"'");	
	}
    //2.生成联合sql语句
	CString sqlstr;
	bool IsSingleTbl;
    this->m_Storage.GetFieldValue("独立表",IsSingleTbl);
	if(IsSingleTbl)
	{
		sqlstr="select * from "+Realtbl;
	}
	else
	{
    	CString  ExtraTblname=Realtbl;//外部表字符串
		CString  FTblname;
    	CString  fldname;             //字段字符串
        CString  Dispfldname;
		CString  MKName,FKName;       //主字段,对应字段
		CString  ConStr;              //条件
		int      FKCount;             //外键个数
		this->m_Storage.GetFieldValue("外键个数",FKCount);
		sqlstr="select "+Realtbl+".* ";
		for(int i=0;i<FKCount;i++)
		{
            fldname="显示字段"+IntToStr(i);
            this->m_Storage.GetFieldValue(fldname,Dispfldname);
            fldname="外部表"+IntToStr(i);
		    this->m_Storage.GetFieldValue(fldname,FTblname);
            fldname="字段"+IntToStr(i);
		    this->m_Storage.GetFieldValue(fldname,MKName);
            fldname="外键"+IntToStr(i);
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
	//3.查询得出结果
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
bool CBaseTbl::GetFieldRecord(CPtrArray& FieldArray,CString ctblname,CString constr) //单表记录数组 
{
   ASSERT(ctblname!="");
   //1.判断及清理工作
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
   //2.判断记录位置
   bool IsZeroRecord;//记录数为0
   if(constr == "")//添加记录
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
   //3.添加字段记录到指针数组
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
   //添加外键信息
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
   CFieldRecord* fldrec;//外键信息指针
   CFieldRecord* pMfldrec;//主键信息指针
   mk.OpenSql("表说明","*","where 表名称='"+ctblname+"'");
   if(mk.GetRecordCount()==0)
   {
      return ;
   }
   else
   {
      bool IsSingleTbl;
      mk.GetFieldValue("独立表",IsSingleTbl);
	  if(IsSingleTbl)//是独立表
	  {
	     return ;
	  }
	  else
	  {
		  //添加外键列表
          int fkcount=0;
          mk.GetFieldValue("外键个数",fkcount);
		  CString name,value;//
		  char a[10];
          for(int i=0;i<fkcount;i++)
		  { //添加外键列表
        	  fldrec=new CFieldRecord();
        	  itoa(i,a,10);
			  name="外键";
			  name=name+a;
		      mk.GetFieldValue(name,value);
			  strcpy(fldrec->FieldName,value); 
			  name="外部表";
    		  name=name+a;
		      mk.GetFieldValue(name,value);
			  strcpy(fldrec->FKtbl,value); 
			  name="显示字段";
			  name=name+a;
              mk.GetFieldValue(name,value);
			  strcpy(fldrec->DisplayName ,value); 
              //确定	
			  name="字段";
			  name=name+a;
		      mk.GetFieldValue(name,value);
		      fldrec->pFK=NULL; 
			  //确定主字段,添加到链表尾部
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