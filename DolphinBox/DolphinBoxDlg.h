
// DolphinBoxDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "..\DolphinViewDll\DolphinViewHeader.h"


// CDolphinBoxDlg �Ի���
class CDolphinBoxDlg : public CDialogEx
{
// ����
public:
	CDolphinBoxDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_DOLPHINBOX_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
