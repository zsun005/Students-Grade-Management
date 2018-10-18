// StudentScore.h : StudentScore Ӧ�ó������ͷ�ļ�
//
/*********************************************************************************
*
*     ϵͳ����:������Ϣ����ϵͳ
*     ��Ҫ����:��ɶ�һ���꼶��ѧУ��ѧ�����ο��ԵĵǼ�,��ѯ
*     ʱ��:2003.3.23-2003.4.5
*     ������:liu_sir
*     E-Mail:Milo2002@sohu.com 
*     �汾:V1.0
*     ��Ҫ��˵��:
*         ���ݿ������:CADOConnection(���ݿ�����) CADODataset(���ݼ�)
*                      CADOStorage(���ݿ�洢��)
*         ������:  CUser(ϵͳ�û�)  CBaseTbl(��������Ϣ)
*                  CExam ������ ���ڿ��Ե���Ϣ�Ǽ�
*                  CExamClass ���԰༶��
*                  CFldValue  �ṹ��(��ʾֵ/ʵ��ֵ) 
*                  CExamStudent ����ѧ����
*                  CExamSubject ���Կ�Ŀ��
*         
*         �ĵ�����:�����CMainFrame CChildFrame
*                  CStudentScoreView/CStudentScoreDoc  ������Ϣ
*                  CExamView/CExamDoc                 ������Ϣ
*                  CExamStudentView/CExamStudentDoc   ������Ϣ
*                  CExamSubjectView/CExamSubjectDoc   ���Կ�Ŀ��Ϣ
*
*         �Ի�����:CLoginFrm(��½����)
*                  CBMDialog(������Ϣ�༭����)
*                  CAddClassDialog(��ӿ��԰༶ ����)
*                  CAddSujectDialog(��ӿ��Կ�Ŀ����)
*                  CAddStudentDialog(��ӿ���ѧ������)
*                  CSelExamNoDialog(ѡ���Ա�Ŵ���)
*
*********************************************************************************/
#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // ������
 class CUser;
 class CADOConnection;

// CStudentScoreApp:
// �йش����ʵ�֣������ StudentScore.cpp
//

class CStudentScoreApp : public CWinApp
{
public:
	CStudentScoreApp();
// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
	virtual int ExitInstance();
//�û��༰����
public:
    CUser *m_pUser;
    CADOConnection *m_pDBCon;
    
	CMultiDocTemplate* m_pBaseTemplate;//�������ĵ���ģ��
	CMultiDocTemplate* m_pExamTemplate;//�����ĵ���ģ��
	CMultiDocTemplate* m_pExamStudentTemplate;//����ѧ���ĵ���ģ��
	CMultiDocTemplate* m_pExamSubjectTemplate;//���Կ�Ŀ�ĵ���ģ��

	virtual BOOL InitApplication();
	afx_msg void OnBaseView();
	afx_msg void OnExamView();
};

extern CStudentScoreApp theApp;
