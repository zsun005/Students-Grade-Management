// StudentScore.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "StudentScore.h"

#include "MainFrm.h"
#include "ChildFrm.h"
//�û���ģ��
#include "User.h"
//������Ϣ�ĵ�/��
#include "StudentScoreDoc.h"
#include "StudentScoreView.h"
//������Ϣ�ĵ�/��
#include "ExamDoc.h"
#include "ExamView.h"

#include "ADODB.h" //���ݵ�Ԫ
#include "Loginfrm.h"//��½����

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentScoreApp

BEGIN_MESSAGE_MAP(CStudentScoreApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// �����ļ��ı�׼�ĵ�����
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_146, OnBaseView)
	ON_COMMAND(ID_149, OnExamView)
END_MESSAGE_MAP()


// CStudentScoreApp ����

CStudentScoreApp::CStudentScoreApp()
{
	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CStudentScoreApp ����

CStudentScoreApp theApp;

// CStudentScoreApp ��ʼ��

BOOL CStudentScoreApp::InitInstance()
{
	// ���һ�������� Windows XP �ϵ�Ӧ�ó����嵥ָ��Ҫ
	// ʹ�� ComCtl32.dll �汾 6 ����߰汾�����ÿ��ӻ���ʽ��
	//����Ҫ InitCommonControls()�����򣬽��޷��������ڡ�
	InitCommonControls();

	CWinApp::InitInstance();

	// ��ʼ�� OLE ��
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// ��׼��ʼ��
	// ���δʹ����Щ���ܲ�ϣ����С
	// ���տ�ִ���ļ��Ĵ�С����Ӧ�Ƴ�����
	// ����Ҫ���ض���ʼ������
	// �������ڴ洢���õ�ע�����
	// TODO: Ӧ�ʵ��޸ĸ��ַ�����
	// �����޸�Ϊ��˾����֯��
	//SetRegistryKey(_T("Ӧ�ó��������ɵı���Ӧ�ó���"));
    //�������Ӽ���½����
	
	this->m_pDBCon =new CADOConnection();
	this->m_pDBCon->ConDB("StudentScoreDB.mdb","score");
	
	this->m_pUser=new CUser(); 
   	CLoginfrm Loginfrm;
	if (Loginfrm.DoModal()==IDOK)
	{
	     
	}
	else
	{
      return false;
	}

	LoadStdProfileSettings(4);  // ���ر�׼ INI �ļ�ѡ����� MRU��
	// ע��Ӧ�ó�����ĵ�ģ�塣�ĵ�ģ��
	// �������ĵ�����ܴ��ں���ͼ֮�������
	//������
	// ������ MDI ��ܴ���
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
	// �������к�׺ʱ�ŵ��� DragAcceptFiles
	//  �� MDI Ӧ�ó����У���Ӧ������ m_pMainWnd ֮����������
	// ������/��
	m_pMainWnd->DragAcceptFiles();
	// ���á�DDE ִ�С�
	EnableShellOpen();
    //RegisterShellFileTypes(TRUE);
	// ������׼������DDE�����ļ�������������
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	cmdInfo.m_nShellCommand=CCommandLineInfo::FileNothing;
	// ��������������ָ����������
	// �� /RegServer��/Register��/Unregserver �� /Unregister ����Ӧ�ó����򷵻� FALSE��
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// �������ѳ�ʼ���������ʾ����������и���
	m_nCmdShow=SW_SHOWMAXIMIZED;
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	return TRUE;
}



// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()

// �������жԻ����Ӧ�ó�������
void CStudentScoreApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CStudentScoreApp ��Ϣ�������


int CStudentScoreApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���
    if(this->m_pUser!=NULL)
	{
	   delete this->m_pUser;
	   this->m_pUser=NULL; 
	}
    if (this->m_pDBCon!=NULL)
	{
	   delete this->m_pDBCon;
	   this->m_pDBCon=NULL;
	}
	return CWinApp::ExitInstance();
}

BOOL CStudentScoreApp::InitApplication()
{
	// TODO: �ڴ����ר�ô����/����û���
    this->m_pUser=NULL;
	this->m_pDBCon=NULL; 
	this->m_pBaseTemplate=NULL;
	this->m_pExamTemplate=NULL; 
	this->m_pExamStudentTemplate=NULL;
	this->m_pExamSubjectTemplate=NULL; 
	return CWinApp::InitApplication();
}

void CStudentScoreApp::OnBaseView()
{
	 
	// TODO: �ڴ���������������
	if(this->m_pDocManager==NULL||this->m_pBaseTemplate==NULL)//û�г�ʼ���ĵ�
	{
		CMultiDocTemplate* pDocTemplate;
	    pDocTemplate = new CMultiDocTemplate(IDR_StudentScoreTYPE,
		RUNTIME_CLASS(CStudentScoreDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CStudentScoreView));
	    AddDocTemplate(pDocTemplate);
		this->m_pBaseTemplate=pDocTemplate; 
		RegisterShellFileTypes(TRUE);
		pDocTemplate->OpenDocumentFile(NULL);
	}
	else 
	{   
        POSITION p=this->m_pBaseTemplate->GetFirstDocPosition();
		if(p)//��ĵ�����
		{
			CDocument* pDoc=this->m_pBaseTemplate->GetNextDoc(p);
			p=pDoc->GetFirstViewPosition();
			if(p)//�Ӵ���
			{
			   CView* pView=pDoc->GetNextView(p);
			   pView->GetParentFrame()->BringWindowToTop();
			}
		}
		else
		{
			this->m_pBaseTemplate->OpenDocumentFile(NULL); 
		}
	}
	
}

void CStudentScoreApp::OnExamView()
{
	// TODO: �ڴ���������������
	if(this->m_pDocManager==NULL||this->m_pExamTemplate==NULL)//û�г�ʼ���ĵ�
	{
		CMultiDocTemplate* pDocTemplate;
	    pDocTemplate = new CMultiDocTemplate(IDR_StudentScoreTYPE,
		RUNTIME_CLASS(CExamDoc),
		RUNTIME_CLASS(CChildFrame), // �Զ��� MDI �ӿ��
		RUNTIME_CLASS(CExamView));
	    AddDocTemplate(pDocTemplate);
		this->m_pExamTemplate=pDocTemplate; 
		pDocTemplate->OpenDocumentFile(NULL);
	}
	else 
	{   
        POSITION p=this->m_pExamTemplate->GetFirstDocPosition();
		if(p)//��ĵ�����
		{
			CDocument* pDoc=this->m_pExamTemplate->GetNextDoc(p);
			p=pDoc->GetFirstViewPosition();
			if(p)//�Ӵ���
			{
			   CView* pView=pDoc->GetNextView(p);
			   pView->GetParentFrame()->BringWindowToTop();
			}
		}
		else
		{
			this->m_pExamTemplate->OpenDocumentFile(NULL); 
		}
	}

}
