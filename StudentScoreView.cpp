// StudentScoreView.cpp : CStudentScoreView ���ʵ��
//
//bugs:�޸ĺ�ɾ����Ĭ������ֵΪchar�� 
#include "stdafx.h"
#include "StudentScore.h"
#include "BMDialog.h"  //��¼�༭����
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

// CStudentScoreView ����/����

CStudentScoreView::CStudentScoreView()
	: CFormView(CStudentScoreView::IDD)
{
	// TODO: �ڴ˴���ӹ������
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
	// TODO: �ڴ˴�ͨ���޸� CREATESTRUCT cs ���޸Ĵ������
	// ��ʽ
	cs.style |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT;
	return CFormView::PreCreateWindow(cs);
}

void CStudentScoreView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	ResizeParentToFit();
	 CListCtrl* list=(CListCtrl*)this->GetDlgItem(IDC_LIST1);
	 list->SetExtendedStyle( LVS_EX_FULLROWSELECT| LVS_EX_GRIDLINES );

   //������οؼ�
    CTreeCtrl* ptree=(CTreeCtrl*)this->GetDlgItem(IDC_TREE1);
    CString tblname;
    POSITION p;
	
	m_ImageList.Create (IDB_IL_CLASS, 16, 1, RGB(0,255,0));
	ptree->SetImageList (&m_ImageList, TVSIL_NORMAL);

    CStudentScoreDoc* pDoc=(CStudentScoreDoc*) GetDocument();
	//CStudentScoreDoc* pDoc=reinterpret_cast<CStudentScoreDoc*>(m_pDocument);
	pDoc->m_BaseTblList.GetTblnames();
	
	HTREEITEM RootNode=ptree->InsertItem("�������ݱ�");
	ptree->SetItemState(RootNode,TVIS_BOLD, TVIS_BOLD);

	p=pDoc->m_BaseTblList.m_TblList.GetHeadPosition();
	while(p)
	{
		tblname=pDoc->m_BaseTblList.m_TblList.GetNext(p);
        ptree->InsertItem(tblname,1,1,RootNode,TVI_LAST);       
	}
	ptree->Expand(RootNode,TVE_EXPAND);

	 
}


// CStudentScoreView ���

#ifdef _DEBUG
void CStudentScoreView::AssertValid() const
{
	CFormView::AssertValid();
}

void CStudentScoreView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CStudentScoreDoc* CStudentScoreView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CStudentScoreDoc)));
	return (CStudentScoreDoc*)m_pDocument;
}
#endif //_DEBUG


// CStudentScoreView ��Ϣ�������

void CStudentScoreView::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CStudentScoreDoc* pDoc=this->GetDocument();
	//pDoc->m_puser=new CUser();
	
}


void CStudentScoreView::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	 
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
	// TODO: �ڴ����ר�ô����/����û���
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
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
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    CTreeCtrl* tree=(CTreeCtrl*)this->GetDlgItem(IDC_TREE1);
	CString c=tree->GetItemText(tree->GetSelectedItem()); 
    c.TrimRight();
	if(c!="�������ݱ�")
	{       
	  char a[256];
	  strcpy(a,c);
	  this->SendMessage(WM_USER+50,0,(LPARAM)a);
	   CStudentScoreDoc* pDoc=this->GetDocument();
	   c="��������["+c+"]";
	   pDoc->SetTitle(c);
	}
	*pResult = 0;
}
//ѡ����Ӽ�¼
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
	  AfxMessageBox("��Ӽ�¼!");
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
	// TODO: �ڴ���������������
	if(this->m_CurRecordPos<0)
	{
	  AfxMessageBox("û��ѡ���¼,����ɾ��!");
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
	if(MessageBox("���Ҫɾ����¼Ϊ:"+FldName+"="+value+"��?","ɾ��ѯ��",
		          MB_OKCANCEL|MB_ICONQUESTION)==IDOK)
	{
	    CStudentScoreDoc* pDoc=this->GetDocument();
		//**ע��,�˴ε��ֶ�ֵĬ��Ϊchar��
		SqlStr="delete from "+this->m_CurTblName+" where "+FldName+"='"+value+"'"; 
		pDoc->m_BaseTblList.ExecSql(SqlStr);
	    this->RefreshShow();
	}
	
}

void CStudentScoreView::OnAlterRecord()
{
	// TODO: �ڴ���������������
	if(this->m_CurRecordPos<0)
	{
	  AfxMessageBox("û��ѡ���¼,�����޸�!");
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
    //ע�����ڼ�¼�ƶ�,�п���ʹ��¼ƫ��
	pDoc->m_BaseTblList.GetFieldRecord(dialog1.RecordArray,this->m_CurTblName,ConStr);
	dialog1.ISADD=false;
	dialog1.m_hParent=this->m_hWnd;  
	dialog1.m_OprTblName=this->m_CurTblName;  
	dialog1.DoModal();
}
void  CStudentScoreView::RefreshShow(bool ISUnionQuery)
{
     CStudentScoreDoc* pDoc=this->GetDocument();  
	 if(ISUnionQuery)//�����ϲ�ѯ
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