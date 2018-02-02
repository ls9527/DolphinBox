
// DolphinBoxDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "DolphinBox.h"
#include "DolphinBoxDlg.h"
#include "afxdialogex.h"
#include "..\DolphinViewDll\DolphinViewHeader.h"
#include "..\DolphinCore\DolphinCore.h"
#include "AyaProp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDolphinBoxDlg �Ի���



CDolphinBoxDlg::CDolphinBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDolphinBoxDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDolphinBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK_HOOK, m_btnHook);
	DDX_Control(pDX, IDC_CHECK1, m_coreHook);
	DDX_Control(pDX, IDC_CHECK_LIB, m_chkHookLib);
}

BEGIN_MESSAGE_MAP(CDolphinBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CHECK_HOOK, &CDolphinBoxDlg::OnBnClickedCheckHook)
	ON_BN_CLICKED(IDC_BUTTON1, &CDolphinBoxDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHECK1, &CDolphinBoxDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK_LIB, &CDolphinBoxDlg::OnBnClickedCheckLib)
END_MESSAGE_MAP()


// CDolphinBoxDlg ��Ϣ�������

BOOL CDolphinBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CDolphinBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CDolphinBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CDolphinBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


HMODULE handle = NULL;
void CDolphinBoxDlg::OnBnClickedCheckHook()
{
	HWND hwnd = ::FindWindow(_T("SciCalc"),NULL);
	//HWND hwnd = ::FindWindow(_T("Notepad"),NULL);
	//HWND hwnd = ::FindWindow(NULL,_T("Windows ���������"));
	
	DWORD dwProcessId;
	DWORD threadId = GetWindowThreadProcessId(hwnd,&dwProcessId);
	ASSERT(threadId);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_btnHook.GetCheck()){
		//handle = LoadLibrary(_T("DolphinViewDll.dll"));
		
		SetViewHook(threadId);
	}else{
		//::FreeLibrary(handle);
		UnViewHook();
		
	}
}

typedef struct tagStudent{
	 tagStudent *m1;
	 char a_1[8];
	 tagStudent *m2;
	 char a_2[4];
	 tagStudent *m3;
}Student;
void CDolphinBoxDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	Student stu1,stu2,stu3,stu10,stu12,stu13;
	stu1.m1 = &stu2;
	stu1.m2=&stu3;
	stu1.m3=&stu10;
	stu2.m2=&stu12;
	stu12.m1=&stu13;
	
	UINT stu1Addr = (UINT)&stu1;
	UINT stu2Addr = (UINT)&stu1.m2->m2;
	
	AyaChain chain;
	chain.AddLeaAddr((UINT)&stu1);
	chain.AddMovAddr(0xC);//m2
	chain.AddLeaAddr(0xC);//m2
	//chain.AddMovAddr(0xC);
	UINT stuEndValue = chain.GetEndValue();
	UINT stu1GetAddr = stuEndValue;
	
}


void CDolphinBoxDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	
	CDialogEx::OnClose();
	UnViewHook();
}

HMODULE m_module = NULL;
void CDolphinBoxDlg::OnBnClickedCheck1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindow(_T("SciCalc"),NULL);
	//HWND hwnd = ::FindWindow(_T("Notepad"),NULL);
	//HWND hwnd = ::FindWindow(NULL,_T("Windows ���������"));
	
	DWORD dwProcessId;
	DWORD threadId = GetWindowThreadProcessId(hwnd,&dwProcessId);
	ASSERT(threadId);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_coreHook.GetCheck()){
		m_module = LoadLibrary(_T("DolphinViewDll.dll"));
		//m_module = LoadLibrary(_T("DolphinCore.dll"));
		void (*DCSetHook)(DWORD) = (void (*)(DWORD))GetProcAddress(m_module,"SetViewHook");
		DCSetHook(threadId);
	}else{
		//::FreeLibrary(handle);
		void (*DCUnHook)(void) = (void (*)(void))GetProcAddress(m_module,"UnViewHook");
		DCUnHook();
		FreeLibrary(m_module);
	}
}


void CDolphinBoxDlg::OnBnClickedCheckLib()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HWND hwnd = ::FindWindow(_T("SciCalc"),NULL);
	//HWND hwnd = ::FindWindow(_T("Notepad"),NULL);
	//HWND hwnd = ::FindWindow(NULL,_T("Windows ���������"));

	DWORD dwProcessId;
	DWORD threadId = GetWindowThreadProcessId(hwnd,&dwProcessId);
	ASSERT(threadId);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if(m_chkHookLib.GetCheck()){
	
		
		DCSetHook(threadId);
	}else{
		//::FreeLibrary(handle);
	
		DCUnHook();
		//FreeLibrary(m_module);
	}

}
