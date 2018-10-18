/*********************************************************************************
*   用于添加删除记录的类窗体:
*       RecordArray:用于保存传入的字段信息
*       默认条件:第一个字段为主键/不能修改主键值
*       过程:由RecordArray生成界面,选择后初始sql语句,发送到父窗体执行
*
**********************************************************************************/
#pragma once
#include "User.h"

// CBMDialog 对话框


class CBMDialog : public CDialog
{
	DECLARE_DYNAMIC(CBMDialog)

public:
	CBMDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBMDialog();
    
// 对话框数据
	enum { IDD = IDD_BMDIALOG };
    CPtrArray  RecordArray;//字段数组
	bool ISADD;          //是否添加记录
    HANDLE m_hParent;    //父视句柄
	CString m_OprTblName;//操作表名称
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
protected:
	virtual void PostNcDestroy();
public:
	afx_msg void OnBnClickedOk();
	void FreeControls(void);    //释放创建的控件;主外键
	virtual void OnFinalRelease();
	afx_msg void OnDestroy();
	//生成插入和修改sql语句
	CString GenerateInsertSql(void);
	CString GenerateUpdateSql(void);
	afx_msg void OnAddRec();
private:
	CADOStorage storage1;
	//创建静态框,符合框,编辑框
	void CreateStatic(CFieldRecord* pRecord,int top,UINT CtlID);
	void CreateCombo(CFieldRecord* pRecord,int top,UINT CtlID);
	void CreateEdit(CFieldRecord* pRecord,int top,UINT CtlID);
	void FillComboByDS(CFieldRecord* pRecord,CComboBox* pCombo);

public:
	void SendChangeMsg(void);//向父窗体传送sql语句
};
