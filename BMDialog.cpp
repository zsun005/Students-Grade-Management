// BMDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "StudentScore.h"
#include "BMDialog.h"


// CBMDialog 对话框

IMPLEMENT_DYNAMIC(CBMDialog, CDialog)
CBMDialog::CBMDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CBMDialog::IDD, pParent)
{
}

CBMDialog::~CBMDialog()
{
}

void CBMDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CBMDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON1, OnAddRec)
END_MESSAGE_MAP()


// CBMDialog 消息处理程序

BOOL CBMDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//动态创建组件
	CFieldRecord* pRecord;
	int top=0;
	for(int i=1;i<=this->RecordArray.GetSize();i++)
	{
		
        top=(i-1)*22; 
        pRecord=(CFieldRecord*)RecordArray.GetAt(i-1); 
        this->CreateStatic(pRecord,top,70+i);
	
		if((pRecord->IsBool)||(pRecord->pFK!=NULL))//布尔或有关联外键
		{
			this->CreateCombo(pRecord,top,10+i);
 		}
		else
		{
	        this->CreateEdit(pRecord,top,10+i);
		}

	}

	CWnd* pWnd;
	CRect rect;
	
	pWnd=this->GetDlgItem(IDC_BUTTON1);
    pWnd->GetWindowRect(&rect);
	rect.top=top+30;
	rect.bottom=rect.top+25;
	pWnd->MoveWindow(&rect);

	pWnd=this->GetDlgItem(IDOK);
    pWnd->GetWindowRect(&rect);
	rect.top=top+30;
	rect.bottom=rect.top+25;
	pWnd->MoveWindow(&rect);
    
	pWnd=this->GetDlgItem(IDCANCEL);
    pWnd->GetWindowRect(&rect);
	rect.top=top+30;
	rect.bottom=rect.top+25;
	pWnd->MoveWindow(&rect);
    
	this->GetWindowRect(&rect);
	int width=rect.right-rect.left; 
    this->MoveWindow(rect.left,rect.top,width,top+100);  

	if(!this->ISADD)
	{
		this->GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	    this->SetWindowText("修改记录");
	}
	else
	{   
		this->GetDlgItem(IDOK)->EnableWindow(false);
		this->GetDlgItem(IDCANCEL)->SetWindowText("关闭");
	    this->SetWindowText("添加记录");
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常：OCX 属性页应返回 FALSE
}


void CBMDialog::PostNcDestroy()
{

	CDialog::PostNcDestroy();
}

void CBMDialog::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//判断添加内容(编辑框)是否为空
    this->SendChangeMsg();		
	OnOK();
}
//释放创建的组件
void CBMDialog::FreeControls(void)
{
	CWnd *pWnd;
    for(int i=1;i<=this->RecordArray.GetSize();i++)
	{
		//释放静态框
	   	pWnd=this->GetDlgItem(70+i);
		if (pWnd)
		{
			pWnd->DestroyWindow();
			delete pWnd;
			pWnd=NULL;
		}
		//释放文本框或其它
		pWnd=this->GetDlgItem(10+i);
		if(pWnd)
		{
			if (pWnd->IsKindOf(RUNTIME_CLASS(CComboBox)))
			{
			   CComboBox* pComboBox=(CComboBox*) pWnd;
			   void* p;
			   for(int j=0;j<pComboBox->GetCount();j++)
			   {
				   p=pComboBox->GetItemDataPtr(j);
				   if(p)
				   delete p;
			   }
               for(j=0;j<pComboBox->GetCount();j++)
			   {
			      	pComboBox->DeleteString(0);
			   }
			   
			}
			pWnd->DestroyWindow();
			delete pWnd;
			pWnd=NULL;		
		}
	}
	//释放数组
    i=0;
	CFieldRecord* pRecord=NULL;
	while(i<this->RecordArray.GetSize()) 
	{
      pRecord=(CFieldRecord*)RecordArray.GetAt(i); 
      if(pRecord->pFK)//如果有外键,释放外键
	  {
	     delete pRecord->pFK; 
	  }
	  delete pRecord;
	  i++;
   }
   this->RecordArray.RemoveAll();
}

void CBMDialog::OnFinalRelease()
{
	// TODO: 在此添加专用代码和/或调用基类
	CDialog::OnFinalRelease();
}

void CBMDialog::OnDestroy()
{
    this->FreeControls();//释放组件
	CDialog::OnDestroy();

	// TODO: 在此添加消息处理程序代码
}

CString CBMDialog::GenerateInsertSql(void)
{
	CString sqlstr,fldlist,valuelist;
	CFieldRecord* pRecord;
	ASSERT(this->m_OprTblName!=""); 

	for(int i=0;i<this->RecordArray.GetSize();i++)
	{
       pRecord=	(CFieldRecord*)this->RecordArray.GetAt(i);
	   //获得值
	   if (pRecord->IsBool)
	   {
		   if(_stricmp(pRecord->Value,"是")==0) 
		      valuelist=valuelist+"TRUE";
		   else if(_stricmp(pRecord->Value,"否")==0)
		     valuelist=valuelist+"FALSE";

	   }
	   else if(pRecord->IsStrType)
	   {
	      valuelist=valuelist+"'"+pRecord->Value+"'";
	   }
	   else
	   {
	      valuelist=valuelist+pRecord->Value; 
	   }
      //字段
	   fldlist=fldlist+pRecord->FieldName;
	   //判断,
	   if(i!=this->RecordArray.GetSize()-1)
	   {
	      fldlist=fldlist+",";
		  valuelist=valuelist+",";
	   }
	}

	sqlstr="insert into "+this->m_OprTblName+"("+fldlist+") values("+valuelist+")";
	return sqlstr;
}

CString CBMDialog::GenerateUpdateSql(void)
{
	CString sqlstr,updatestr,valuelist,constr;
	CFieldRecord* pRecord;
	ASSERT(this->m_OprTblName!=""); 
	
	pRecord=(CFieldRecord*)this->RecordArray.GetAt(0);
    if(pRecord->IsStrType)
	{
	    valuelist="'";
		valuelist=valuelist+pRecord->Value;
		valuelist=valuelist+"'";
	}
	else
	{
	    valuelist=pRecord->Value; 
	}
    constr="where ";
	constr=constr+pRecord->FieldName+"="+valuelist; 

	for(int i=1;i<this->RecordArray.GetSize();i++)
	{
       pRecord=	(CFieldRecord*)this->RecordArray.GetAt(i);
	   //获得值
	   if (pRecord->IsBool)
	   {
		   if(_stricmp(pRecord->Value,"是")==0) 
		      valuelist="TRUE";
		   else if(_stricmp(pRecord->Value,"否")==0)
		     valuelist="FALSE";

	   }
	   else if(pRecord->IsStrType)
	   {
		  valuelist="'";
		  valuelist=valuelist+pRecord->Value;
		  valuelist=valuelist+"'";
	   }
	   else
	   {
	      valuelist=pRecord->Value; 
	   }
      //字段
	   updatestr=updatestr+pRecord->FieldName+"="+valuelist;
	   //判断,
	   if(i!=this->RecordArray.GetSize()-1)
	   {
	      updatestr=updatestr+",";
	   }
	}

	sqlstr="update "+this->m_OprTblName+" set "+updatestr+" "+constr;
	return sqlstr;
}

void CBMDialog::OnAddRec()
{
	// TODO: 在此添加控件通知处理程序代码
	this->SendChangeMsg();	
}
void CBMDialog::CreateStatic(CFieldRecord* pRecord,int top,UINT CtlID)
{  	
	CStatic *pText;
    pText=new CStatic();
    pText->Create(pRecord->FieldName, WS_CHILD|WS_VISIBLE|SS_CENTER, 
                   CRect(10,2+top, 110, 23+top), this,CtlID);
	pText->ShowWindow(SW_SHOW);
	pText->SetFont(this->GetFont());
}
void CBMDialog::CreateCombo(CFieldRecord* pRecord,int top,UINT CtlID)
{
	CComboBox* pCombo;
    pCombo=new CComboBox();
	pCombo->Create(WS_CHILD|WS_VISIBLE|WS_VSCROLL|CBS_DROPDOWNLIST,
		        CRect(110,2+top, 250, 230+top), this, CtlID);
	pCombo->ShowWindow(SW_SHOW);
    pCombo->SetFont(this->GetFont());
	if(pRecord->IsBool)
	{
		pCombo->AddString("是");
		pCombo->AddString("否");
		if(this->ISADD)
		{
			pCombo->SetCurSel(0);
		}
		else//不是新增加
		{
			if(_stricmp(pRecord->Value,"TRUE")==0)
			{
				pCombo->SetCurSel(0);
			}
			else
			{
				pCombo->SetCurSel(1);
			}
		}
	}
	else//有外键
	{
		this->FillComboByDS(pRecord,pCombo);
	}
}
void CBMDialog::CreateEdit(CFieldRecord* pRecord,int top,UINT CtlID)
{
	    CEdit *pEdit;
	  	pEdit=new CEdit();
    	pEdit->Create(ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,
		            CRect(110,2+top, 250, 23+top), this, CtlID);
		pEdit->ShowWindow(SW_SHOW);
	    pEdit->SetWindowText(pRecord->Value);
		pEdit->SetFont(this->GetFont());
}
void CBMDialog::FillComboByDS(CFieldRecord* pRecord,CComboBox* pCombo)
{
	if(pRecord->pFK==NULL)
		return;
	storage1.OpenSql(pRecord->pFK->FKtbl);
	int count=storage1.GetRecordCount();
	if(count==0)
		return;
	CFldValue* pValue ; //用于添加记录指针
	CString value;      
	int index;         // 
	int selindex=-1;   //选择的记录(用于修改时)
	storage1.MoveFirst();

    for(int i=0;i<count;i++)
	{
	   pValue=new CFldValue();  
	   storage1.GetFieldValue(pRecord->pFK->FieldName,value);
       strcpy(pValue->FieldValue,value);
	   storage1.GetFieldValue(pRecord->pFK->DisplayName,value);
	   strcpy(pValue->DispalyFieldValue,value);
       index=pCombo->AddString(pValue->DispalyFieldValue);
	   pCombo->SetItemDataPtr(index,pValue);
	   //判断当前选项
       if(_stricmp(pValue->FieldValue,pRecord->Value)==0)
		   selindex=index;
	   storage1.MoveNext();
	}
   
	//判断
	if(this->ISADD)
	{
		pCombo->SetCurSel(0);
	}
	else//不是新增加,为修改时
	{
        pCombo->SetCurSel(selindex);
	}

}
//发送修改或添加消息
void CBMDialog::SendChangeMsg(void)
{
	CWnd* pWnd;
	CString value,Msg;
	CFieldRecord* pRecord;
	for(int i=1;i<=this->RecordArray.GetSize();i++)
	{ 
	  pWnd=this->GetDlgItem(10+i);

	  if(pWnd)
	  {
		 pRecord=(CFieldRecord*)RecordArray.GetAt(i-1);
	     if ((!pRecord->IsBool)&&pWnd->IsKindOf(RUNTIME_CLASS(CComboBox)))
			{  	 //非布尔类型,且有关联字段时
			   CComboBox* pCombo=(CComboBox*) pWnd;
			   CFldValue* p;
			   int index=pCombo->GetCurSel();
			   p=(CFldValue*)pCombo->GetItemDataPtr(index);
			   value=p->FieldValue; 
			}
		 else
		 pWnd->GetWindowText(value);
		 value.TrimRight(); 
		 if(value=="")
		 {
           Msg=(CString)pRecord->FieldName+"不能为空!"; 
		   AfxMessageBox(Msg);
		   pWnd->SetFocus();
		   return;
		 }
		 else
		 {
			 if((i==1)&&(!this->ISADD))//如果是修改的话,则不对第一字段操作
			   {}
			 else
			   strcpy(pRecord->Value,value); 
		 }
	  }

	}
 
	//发送字符串
	CString cSend;
	if(this->ISADD)
	{ 
	    cSend=this->GenerateInsertSql();

	}
	else
	{
	     cSend=this->GenerateUpdateSql();
	}
	LPARAM lparam=(LPARAM)&cSend; 
	::SendMessage((HWND)this->m_hParent,WM_USER+51,0,lparam);  

}
