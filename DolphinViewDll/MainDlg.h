#pragma once
#include "afxwin.h"


// CMainDlg �Ի���

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CMainDlg();

// �Ի�������
	enum { IDD = IDD_DIALOG_MAIN };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CListBox m_boxMain;
	afx_msg void OnBnClickedButtonExec();

	afx_msg LRESULT OnUninstallDll(WPARAM wParam, LPARAM lParam);
	afx_msg void OnDestroy();
};
