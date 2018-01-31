
// DolphinBoxDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "..\DolphinViewDll\DolphinViewHeader.h"


// CDolphinBoxDlg 对话框
class CDolphinBoxDlg : public CDialogEx
{
// 构造
public:
	CDolphinBoxDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_DOLPHINBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCheckHook();
	CButton m_btnHook;

private:
	
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnClose();
	CButton m_coreHook;
	afx_msg void OnBnClickedCheck1();
	CButton m_chkHookLib;
	afx_msg void OnBnClickedCheckLib();
};
