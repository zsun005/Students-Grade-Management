/*********************************************************************
*             
*               CFieldRecord      �ֶ���Ϣ�ṹ��    
*               CFldValue        �ֶ�ֵ�ṹ��
*               CUser            ϵͳ�û���
*               CADOStorage      ��װ�����ݼ���
*               CBaseTbl         ��������Ϣ��(����Ի��������ݵĹ���)
***********************************************************************/
#pragma once
#include "ADODB.h"
#include "afxtempl.h"
// CUser ����Ŀ��
class CStudentScoreDoc;
//��¼��Ϣ��
struct CFieldRecord
{
   char FieldName[20];//�ֶ���(���Ϊ����ֶΣ���Ϊ��ʾ�ֶ�)
   char Value[255];   //ֵ
   bool IsBool;       //�Ƿ񲼶�
   bool IsStrType;    //�Ƿ��ַ���
   bool IsVisible;    //�Ƿ���ʾ
   char DisplayName[20];      //��ӦIDֵ�����������
   char FKtbl[20];    //����������������
   CFieldRecord* pFK; //�����Ϣ 
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
	CString m_UserName;//�û���
	CString m_Password;//����
	bool m_IsLogin;   //�Ƿ��½
	int m_Right;      //Ȩ�� 
	CTime m_LoginDate;//��½����
	CList<CString,CString&>   m_NameList;//�����б�
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
	CList<CString,CString&>   m_TblList;//�����б�
    void GetTblnames();
	bool GetFieldRecord(CPtrArray& FieldArray,CString ctblname,CString constr=""); //�����¼����,Ĭ�ϼ�¼���һ�� 
    bool RemoveRecord(int CurRecordPos);
protected:
   CADOStorage m_Storage;
   void AddExtraFieldRecord(CPtrArray& FieldArray,CString ctblname); //�����¼����,Ĭ�ϼ�¼���һ�� 
private:
   CString m_TblName;
public:
	bool SelectUnionTbl(CString StrTblname,CString& Realtbl,bool ByRealTblName=false);//ѡ�����ϱ�
	void RefreshList(CListCtrl& List1);
	void ReQuery(CString TblName);
	void ExecSql(CString SqlStr);
};
