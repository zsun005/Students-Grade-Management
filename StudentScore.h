// StudentScore.h : StudentScore 应用程序的主头文件
//
/*********************************************************************************
*
*     系统名称:考试信息管理系统
*     主要功能:完成对一个年级或学校的学生历次考试的登记,查询
*     时间:2003.3.23-2003.4.5
*     编制人:liu_sir
*     E-Mail:Milo2002@sohu.com 
*     版本:V1.0
*     主要类说明:
*         数据库基本类:CADOConnection(数据库连接) CADODataset(数据集)
*                      CADOStorage(数据库存储类)
*         基本类:  CUser(系统用户)  CBaseTbl(基本表信息)
*                  CExam 考试类 用于考试的信息登记
*                  CExamClass 考试班级类
*                  CFldValue  结构量(显示值/实际值) 
*                  CExamStudent 考试学生类
*                  CExamSubject 考试科目类
*         
*         文档视类:框架类CMainFrame CChildFrame
*                  CStudentScoreView/CStudentScoreDoc  基本信息
*                  CExamView/CExamDoc                 考试信息
*                  CExamStudentView/CExamStudentDoc   考生信息
*                  CExamSubjectView/CExamSubjectDoc   考试科目信息
*
*         对话框类:CLoginFrm(登陆窗体)
*                  CBMDialog(基本信息编辑窗体)
*                  CAddClassDialog(添加考试班级 窗体)
*                  CAddSujectDialog(添加考试科目窗体)
*                  CAddStudentDialog(添加考试学生窗体)
*                  CSelExamNoDialog(选择考试编号窗体)
*
*********************************************************************************/
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // 主符号
 class CUser;
 class CADOConnection;

// CStudentScoreApp:
// 有关此类的实现，请参阅 StudentScore.cpp
//

class CStudentScoreApp : public CWinApp
{
public:
	CStudentScoreApp();
// 重写
public:
	virtual BOOL InitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
//用户类及连接
public:
    CUser *m_pUser;
    CADOConnection *m_pDBCon;
    
	CMultiDocTemplate* m_pBaseTemplate;//基本表文档视模板
	CMultiDocTemplate* m_pExamTemplate;//考试文档视模板
	CMultiDocTemplate* m_pExamStudentTemplate;//考试学生文档视模板
	CMultiDocTemplate* m_pExamSubjectTemplate;//考试科目文档视模板

	virtual BOOL InitApplication();
	afx_msg void OnBaseView();
	afx_msg void OnExamView();
};

extern CStudentScoreApp theApp;
