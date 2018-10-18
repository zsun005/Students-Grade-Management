/*********************************************************************
*             
*               CFieldRecord      字段信息结构量    
*               CFldValue        字段值结构量
*               CUser            系统用户类
*               CADOStorage      封装的数据集类
*               CBaseTbl         基本表信息类(负责对基础表数据的管理)
***********************************************************************/
#pragma once
#include "ADODB.h"
#include "afxtempl.h"
// CUser 命令目标
class CStudentScoreDoc;
//记录信息量
struct CFieldRecord
{
   char FieldName[20];//字段名(如果为外键字段，则为显示字段)
   char Value[255];   //值
   bool IsBool;       //是否布尔
   bool IsStrType;    //是否字符串
   bool IsVisible;    //是否显示
   char DisplayName[20];      //对应ID值（用于外键）
   char FKtbl[20];    //外键表名或基本表名
   CFieldRecord* pFK; //外键信息 
};

struct CFldValue
{
   char DispalyFieldValue[50];
   char FieldValue[50];
};

//
class CADOStorage:public CADODataset
{
public:
 	CADOStorage();
    virtual ~CADOStorage();
   	void ExecInsertSql(CString TblName,CString Fldlist,CString ValueList);
	void ExecUpdateSql(CString TblName,CString UpdateStr,CString Constr="");
	void ExceDeleteSql(CString TblName,CString Constr="");
};

class CUser 
{
public:
	CUser();
	virtual ~CUser();
	void GetUserNames();
	CString m_UserName;//用户名
	CString m_Password;//秘码
	bool m_IsLogin;   //是否登陆
	int m_Right;      //权限 
	CTime m_LoginDate;//登陆日期
	CList<CString,CString&>   m_NameList;//名称列表
	bool Check(CString UserName,CString Password);
    
protected:
   CADOStorage* m_pStorage;
private:
   CString m_TblName;
};


class CBaseTbl : public CObject
{
public:
	CBaseTbl();
	virtual ~CBaseTbl();
	CList<CString,CString&>   m_TblList;//名称列表
    void GetTblnames();
	bool GetFieldRecord(CPtrArray& FieldArray,CString ctblname,CString constr=""); //单表记录数组,默认记录最后一条 
    bool RemoveRecord(int CurRecordPos);
protected:
   CADOStorage m_Storage;
   void AddExtraFieldRecord(CPtrArray& FieldArray,CString ctblname); //单表记录数组,默认记录最后一条 
private:
   CString m_TblName;
public:
	bool SelectUnionTbl(CString StrTblname,CString& Realtbl,bool ByRealTblName=false);//选择联合表
	void RefreshList(CListCtrl& List1);
	void ReQuery(CString TblName);
	void ExecSql(CString SqlStr);
};
