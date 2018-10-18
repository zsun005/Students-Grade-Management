// StudentScoreView.cpp : CStudentScoreView 类的实现
//
//bugs:修改和删除的默认主键值为char型 
#include "stdafx.h"
#include "StudentScore.h"
#include "BMDialog.h"  //记录编辑窗体
#include "StudentScoreView.h"
#include "StudentScoreDoc.h"
#include "Childfrm.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentScoreView

IMPLEMENT_DYNCREATE(CStudentScoreView, CFormView)

BEGIN_MESSAGE_MAP(CStudentScoreView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnNMClickList1)
	ON_MESSAGE(WM_USER+50,OnRefreshList1)
	ON_MESSAGE(WM_USER+51,OnExecSql)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnNMRclickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_TREE1, OnNMDblclkTree1)
	ON_COMMAND(ID_LIST142, OnADDRecord)
	ON_COMMAND(ID_138, OnDelRecord)
	ON_COMMAND(ID_139, OnAlterRecord)
END_MESSAGE_MAP()

// CStudentScoreView 构造/销毁

CStudentScoreView::CStudentScoreView()
	: CFormView(CStudentScoreView::IDD)
{
	// TODO: 在此处添加构造代码
    this->m_pDocTemplate=NULL; 
}

CStudentScoreView::~CStudentScoreView()
{
	if(this->m_pDocTemplate)
	{
	   delete this->m_pDocTemplate; 
	}
}

void CStudentScoreView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
}

BOOL CStudentScoreView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改 CREATESTRUCT cs 来修改窗口类或
	// 样式
	cs.style |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CFormView::PreCreateWindow(cs);
}

void CStudentScoreView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	 CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 list->SetExtendedStyle( LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES );

   //填充树形控件
    CTreeCtrl* ptree=(CTreeCtrl*)this->GetDlgItem(IDC_TREE1);
    CString tblname;
    POSITION p;
	
	m_ImageList.Create (IDB_IL_CLASS, 16, 1, RGB(0,255,0));
	ptree->SetImageList (&m_ImageList, TVSIL_NORMAL);

    CStudentScoreDoc* pDoc=(CStudentScoreDoc*) GetDocument();
	//CStudentScoreDoc* pDoc=reinterpret_cast<CStudentScoreDoc*>(m_pDocument);
	pDoc->m_BaseTblList.GetTblnames();
	
	HTREEITEM RootNode=ptree->InsertItem("基础数据表");
	ptree->SetItemState(RootNode,TVIS_BOLD, TVIS_BOLD);

	p=pDoc->m_BaseTblList.m_TblList.GetHeadPosition();
	while(p)
	{
		tblname=pDoc->m_BaseTblList.m_TblList.GetNext(p);
        ptree->InsertItem(tblname,1,1,RootNode,TVI_LAST);       
	}
	ptree->Expand(RootNode,TVE_EXPAND);

	 
}


// CStudentScoreView 诊断

#ifdef _DEBUG
void CStudentScoreView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStudentScoreView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CStudentScoreDoc* CStudentScoreView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentScoreDoc)));
	return (CStudentScoreDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentScoreView 消息处理程序

void CStudentScoreView::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//CStudentScoreDoc* pDoc=this->GetDocument();
	//pDoc->m_puser=new CUser();
	
}


void CStudentScoreView::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	
	 
	*pResult = 0;
}
LRESULT CStudentScoreView::OnRefreshList1(WPARAM wParam,LPARAM lParam)
{
   char a[256];
   strcpy(a,(char *)lParam);
   //AfxMessageBox(a);
   CStudentScoreDoc* pDoc=this->GetDocument();
   if(pDoc->m_BaseTblList.SelectUnionTbl(a,this->m_CurTblName ))
   {
	   CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1); 
      pDoc->m_BaseTblList.RefreshList(*list);
   }
   return 0;
}
void CStudentScoreView::OnDraw(CDC* pDC)
{
	// TODO: 在此添加专用代码和/或调用基类
	 CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 CTreeCtrl* tree=(CTreeCtrl*)this->GetDlgItem(IDC_TREE1);
	 CRect rect;
     this->GetClientRect(&rect);
	CRect rect1;
	rect1.CopyRect(&rect);
	rect1.right=rect1.left+100;  
	tree->MoveWindow(&rect1);
	rect.left=rect1.right+2;
	 //rect.top=rect.top;  
	list->MoveWindow(&rect);
}

void CStudentScoreView::OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	this->m_CurRecordPos=pNMLV->iItem; 

	CMenu menu1;
	CPoint p;
	menu1.LoadMenu(IDR_MENU1);
	CMenu* menu2=menu1.GetSubMenu(0);
	GetCursorPos(&p);
	menu2->TrackPopupMenu(TPM_LEFTALIGN |TPM_RIGHTBUTTON ,p.x,p.y,this);  
	*pResult = 0;
}

void CStudentScoreView::OnNMDblclkTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
    CTreeCtrl* tree=(CTreeCtrl*)this->GetDlgItem(IDC_TREE1);
	CString c=tree->GetItemText(tree->GetSelectedItem()); 
    c.TrimRight();
	if(c!="基础数据表")
	{       
	  char a[256];
	  strcpy(a,c);
	  this->SendMessage(WM_USER+50,0,(LPARAM)a);
	   CStudentScoreDoc* pDoc=this->GetDocument();
	   c="基础数据["+c+"]";
	   pDoc->SetTitle(c);
	}
	*pResult = 0;
}
//选择添加记录
void CStudentScoreView::OnADDRecord()
{  
	ASSERT(this->m_hWnd); 
	CBMDialog dialog1;
    CStudentScoreDoc* pDoc=this->GetDocument();
	pDoc->m_BaseTblList.GetFieldRecord(dialog1.RecordArray,this->m_CurTblName);
	dialog1.ISADD=true;
	dialog1.m_hParent=this->m_hWnd;  
	dialog1.m_OprTblName=this->m_CurTblName;  
	if(dialog1.DoModal()==IDOK)
	{
	  AfxMessageBox("添加记录!");
	  //ASSERT(dialog1.m_hWnd);
	}
	
}
LRESULT CStudentScoreView::OnExecSql(WPARAM wParam,LPARAM lParam)
{
   CString c;
   c=*((CString*)lParam);
   CStudentScoreDoc* pDoc=this->GetDocument();  
   pDoc->m_BaseTblList.ExecSql(c);
   this->RefreshShow();
   //AfxMessageBox(c);
   return 0;
}

void CStudentScoreView::OnDelRecord()
{
	// TODO: 在此添加命令处理程序代码
	if(this->m_CurRecordPos<0)
	{
	  AfxMessageBox("没有选择记录,不能删除!");
	  return;
	}
    CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
   	CString value; 
    TCHAR buf[50];
    HDITEM item;
	item.mask=HDI_TEXT;
    item.cchTextMax=MAX_PATH; 
    item.pszText=buf;  
	if(!list->GetHeaderCtrl()->GetItem(0,&item))
	{
	  return; 
	}
	value=list->GetItemText(this->m_CurRecordPos,0); 
	CString SqlStr;
	CString FldName;
	FldName=item.pszText; 
	if(MessageBox("真的要删除记录为:"+FldName+"="+value+"吗?","删除询问",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
	    CStudentScoreDoc* pDoc=this->GetDocument();
		//**注意,此次的字段值默认为char型
		SqlStr="delete from "+this->m_CurTblName+" where "+FldName+"='"+value+"'"; 
		pDoc->m_BaseTblList.ExecSql(SqlStr);
	    this->RefreshShow();
	}
	
}

void CStudentScoreView::OnAlterRecord()
{
	// TODO: 在此添加命令处理程序代码
	if(this->m_CurRecordPos<0)
	{
	  AfxMessageBox("没有选择记录,不能修改!");
	  return;
	}

	ASSERT(this->m_hWnd); 
	CBMDialog dialog1;
    CStudentScoreDoc* pDoc=this->GetDocument();
 
	CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
   	CString value; 
    TCHAR buf[50];
    HDITEM item;
	item.mask=HDI_TEXT;
    item.cchTextMax=MAX_PATH; 
    item.pszText=buf;  
	if(!list->GetHeaderCtrl()->GetItem(0,&item))
	{
	  return; 
	}
	value=list->GetItemText(this->m_CurRecordPos,0); 
	CString SqlStr;
	CString FldName;
	FldName=item.pszText; 

    CString ConStr="where "+FldName+"='"+value+"'";
    //注意由于记录移动,有可能使记录偏移
	pDoc->m_BaseTblList.GetFieldRecord(dialog1.RecordArray,this->m_CurTblName,ConStr);
	dialog1.ISADD=false;
	dialog1.m_hParent=this->m_hWnd;  
	dialog1.m_OprTblName=this->m_CurTblName;  
	dialog1.DoModal();
}
void  CStudentScoreView::RefreshShow(bool ISUnionQuery)
{
     CStudentScoreDoc* pDoc=this->GetDocument();  
	 if(ISUnionQuery)//是联合查询
	 {
         pDoc->m_BaseTblList.SelectUnionTbl("",this->m_CurTblName,true); 
	 }
	 else
	 {
	    pDoc->m_BaseTblList.ReQuery(this->m_CurTblName);
	 }	
	 CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1); 
     pDoc->m_BaseTblList.RefreshList(*list);
}