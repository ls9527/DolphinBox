#pragma once
#include "afxwin.h"


// CMainDlg 对话框

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CMainDlg();

// 对话框数据
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_boxMain;
	afx_msg void OnBnClickedButtonExec();

	afx_msg LRESULT OnUninstallDll(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
};
