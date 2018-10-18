// AddClassDialog.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "StudentScore.h"
#include "AddClassDialog.h"
#include "ExamDoc.h"
#include "ExamView.h"
// AddClassDialog �Ի���

IMPLEMENT_DYNAMIC(CAddClassDialog, CDialog)
CAddClassDialog::CAddClassDialog(CWnd* pParent /*=NULL*/)
	: CDialog(CAddClassDialog::IDD, pParent)
{
}

CAddClassDialog::~CAddClassDialog()
{
}

void CAddClassDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CAddClassDialog, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// AddClassDialog ��Ϣ�������

void CAddClassDialog::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//1�ж����ݺϷ���
	CString value;

    CListBox*  pList=(CListBox*) this->GetDlgItem(IDC_LIST1); 
    int nCount=pList->GetSelCount();
	if(nCount==0)
	{
		AfxMessageBox("��ѡ��һ���༶!");
		return;
	}

    CExamDoc* pDoc=(CExamDoc*) this->m_pExamView->GetDocument();

	CArray<int,int> aryListBoxSel;
	aryListBoxSel.SetSize(nCount);
    pList->GetSelItems(nCount, aryListBoxSel.GetData());  
    int index;
	CFldValue* pValue; 

	for(int i=0;i<aryListBoxSel.GetSize();i++)
	{
 	    index=aryListBoxSel.GetAt(i);
		pValue=(CFldValue*)pList->GetItemDataPtr(index);

   		if(pDoc->m_ExamClass.IsClassNoExisted(this->m_ExamNo,pValue->FieldValue))
		{
           value=pValue->DispalyFieldValue; 
		   AfxMessageBox("����ѡ���ظ��༶���:"+value);
		   return;
		}
	}

 	for(i=0;i<aryListBoxSel.GetSize();i++)
	{
 	    index=aryListBoxSel.GetAt(i);
		pValue=(CFldValue*)pList->GetItemDataPtr(index);
		pDoc->m_ExamClass.m_No=value;
		pDoc->m_ExamClass.m_ExamNo=this->m_ExamNo;
		pDoc->m_ExamClass.m_ClassNo=pValue->FieldValue;//�༶���
		pDoc->m_ExamClass.AddClass();
	}
	this->m_pExamView->RefreshShow(this->m_ExamNo); 
    
	OnOK();
}

BOOL CAddClassDialog::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CExamDoc* pDoc=(CExamDoc*) this->m_pExamView->GetDocument();
	pDoc->m_ExamClass.GetGrades();
	CComboBox* pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
	CFldValue* pValue;//��ֵ
	int index=0;    //����

	POSITION p=pDoc->m_ExamClass.m_GradeList.GetHeadPosition();   
    while(p)
	{
	   pValue=(CFldValue*)&pDoc->m_ExamClass.m_GradeList.GetNext(p);
       index=pComb->AddString(pValue->DispalyFieldValue);
	   pComb->SetItemDataPtr(index,pValue);
	}
    if(pComb->GetCount()>0)
	{
	   pComb->SetCurSel(0);
	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣��OCX ����ҳӦ���� FALSE
}

void CAddClassDialog::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CComboBox* pComb=(CComboBox*)this->GetDlgItem(IDC_COMBO1);
    CListBox*  pList=(CListBox*) this->GetDlgItem(IDC_LIST1); 
	int selindex=pComb->GetCurSel();
	if(selindex>=0)
	{
		for(int i=0;i<pList->GetCount();i++)
		{
		   pList->DeleteString(i);
		}
		
		//��ȡ���Ա��
		CFldValue* pValue=(CFldValue*)pComb->GetItemDataPtr(selindex);
	   	CExamDoc* pDoc=(CExamDoc*) this->m_pExamView->GetDocument();
		pDoc->m_ExamClass.GetClassesByGradeNo(pValue->FieldValue);
        //����б�
		POSITION p=pDoc->m_ExamClass.m_ClassList.GetHeadPosition();
		CFldValue* pValue1;
		int index;
		while(p)
		{
           pValue1=(CFldValue*)&pDoc->m_ExamClass.m_ClassList.GetNext(p); 
           index=pList->AddString(pValue1->DispalyFieldValue);
		   pList->SetItemDataPtr(index,pValue1);
		}
	}
}
