/*********************************************************************************
*   �������ɾ����¼���ര��:
*       RecordArray:���ڱ��洫����ֶ���Ϣ
*       Ĭ������:��һ���ֶ�Ϊ����/�����޸�����ֵ
*       ����:��RecordArray���ɽ���,ѡ����ʼsql���,���͵�������ִ��
*
**********************************************************************************/
#pragma once
#include "User.h"

// CBMDialog �Ի���


class CBMDialog : public CDialog
{
	DECLARE_DYNAMIC(CBMDialog)

public:
	CBMDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBMDialog();
    
// �Ի�������
	enum { IDD = IDD_BMDIALOG };
    CPtrArray  RecordArray;//�ֶ�����
	bool ISADD;          //�Ƿ���Ӽ�¼
    HANDLE m_hParent;    //���Ӿ��
	CString m_OprTblName;//����������
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedOk();
	void FreeControls(void);    //�ͷŴ����Ŀؼ�;�����
	virtual void OnFinalRelease();
	afx_msg void OnDestroy();
	//���ɲ�����޸�sql���
	CString GenerateInsertSql(void);
	CString GenerateUpdateSql(void);
	afx_msg void OnAddRec();
private:
	CADOStorage storage1;
	//������̬��,���Ͽ�,�༭��
	void CreateStatic(CFieldRecord* pRecord,int top,UINT CtlID);
	void CreateCombo(CFieldRecord* pRecord,int top,UINT CtlID);
	void CreateEdit(CFieldRecord* pRecord,int top,UINT CtlID);
	void FillComboByDS(CFieldRecord* pRecord,CComboBox* pCombo);

public:
	void SendChangeMsg(void);//�򸸴��崫��sql���
};
