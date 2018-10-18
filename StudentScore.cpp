// StudentScore.cpp : 定义应用程序的类行为。
//

#include "stdafx.h"
#include "StudentScore.h"

#include "MainFrm.h"
#include "ChildFrm.h"
//用户类模块
#include "User.h"
//基本信息文档/视
#include "StudentScoreDoc.h"
#include "StudentScoreView.h"
//考试信息文档/视
#include "ExamDoc.h"
#include "ExamView.h"

#include "ADODB.h" //数据单元
#include "Loginfrm.h"//登陆窗体

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CStudentScoreApp

BEGIN_MESSAGE_MAP(CStudentScoreApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_146, OnBaseView)
	ON_COMMAND(ID_149, OnExamView)
END_MESSAGE_MAP()


// CStudentScoreApp 构造

CStudentScoreApp::CStudentScoreApp()
{
	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}


// 唯一的一个 CStudentScoreApp 对象

CStudentScoreApp theApp;

// CStudentScoreApp 初始化

BOOL CStudentScoreApp::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControls()。否则，将无法创建窗口。
	InitCommonControls();

	CWinApp::InitInstance();

	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}
	AfxEnableControlContainer();
	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	//SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
    //数据连接及登陆窗体
	
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

	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项（包括 MRU）
	// 注册应用程序的文档模板。文档模板
	// 将用作文档、框架窗口和视图之间的连接
	//主过程
	// 创建主 MDI 框架窗口
	CMainFrame* pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;
	// 仅当具有后缀时才调用 DragAcceptFiles
	//  在 MDI 应用程序中，这应在设置 m_pMainWnd 之后立即发生
	// 启用拖/放
	m_pMainWnd->DragAcceptFiles();
	// 启用“DDE 执行”
	EnableShellOpen();
    //RegisterShellFileTypes(TRUE);
	// 分析标准外壳命令、DDE、打开文件操作的命令行
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	cmdInfo.m_nShellCommand=CCommandLineInfo::FileNothing;
	// 调度在命令行中指定的命令。如果
	// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;
	// 主窗口已初始化，因此显示它并对其进行更新
	m_nCmdShow=SW_SHOWMAXIMIZED;
	pMainFrame->ShowWindow(m_nCmdShow);
	pMainFrame->UpdateWindow();
	return TRUE;
}



// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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

// 用于运行对话框的应用程序命令
void CStudentScoreApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}


// CStudentScoreApp 消息处理程序


int CStudentScoreApp::ExitInstance()
{
	// TODO: 在此添加专用代码和/或调用基类
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
	// TODO: 在此添加专用代码和/或调用基类
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
	 
	// TODO: 在此添加命令处理程序代码
	if(this->m_pDocManager==NULL||this->m_pBaseTemplate==NULL)//没有初始化文档
	{
		CMultiDocTemplate* pDocTemplate;
	    pDocTemplate = new CMultiDocTemplate(IDR_StudentScoreTYPE,
		RUNTIME_CLASS(CStudentScoreDoc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CStudentScoreView));
	    AddDocTemplate(pDocTemplate);
		this->m_pBaseTemplate=pDocTemplate; 
		RegisterShellFileTypes(TRUE);
		pDocTemplate->OpenDocumentFile(NULL);
	}
	else 
	{   
        POSITION p=this->m_pBaseTemplate->GetFirstDocPosition();
		if(p)//活动文档存在
		{
			CDocument* pDoc=this->m_pBaseTemplate->GetNextDoc(p);
			p=pDoc->GetFirstViewPosition();
			if(p)//视存在
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
	// TODO: 在此添加命令处理程序代码
	if(this->m_pDocManager==NULL||this->m_pExamTemplate==NULL)//没有初始化文档
	{
		CMultiDocTemplate* pDocTemplate;
	    pDocTemplate = new CMultiDocTemplate(IDR_StudentScoreTYPE,
		RUNTIME_CLASS(CExamDoc),
		RUNTIME_CLASS(CChildFrame), // 自定义 MDI 子框架
		RUNTIME_CLASS(CExamView));
	    AddDocTemplate(pDocTemplate);
		this->m_pExamTemplate=pDocTemplate; 
		pDocTemplate->OpenDocumentFile(NULL);
	}
	else 
	{   
        POSITION p=this->m_pExamTemplate->GetFirstDocPosition();
		if(p)//活动文档存在
		{
			CDocument* pDoc=this->m_pExamTemplate->GetNextDoc(p);
			p=pDoc->GetFirstViewPosition();
			if(p)//视存在
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
