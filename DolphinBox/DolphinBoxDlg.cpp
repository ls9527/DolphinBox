
// DolphinBoxDlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
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

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDolphinBoxDlg 对话框



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


// CDolphinBoxDlg 消息处理程序

BOOL CDolphinBoxDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDolphinBoxDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDolphinBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


HMODULE handle = NULL;
void CDolphinBoxDlg::OnBnClickedCheckHook()
{
	HWND hwnd = ::FindWindow(_T("SciCalc"),NULL);
	//HWND hwnd = ::FindWindow(_T("Notepad"),NULL);
	//HWND hwnd = ::FindWindow(NULL,_T("Windows 任务管理器"));
	
	DWORD dwProcessId;
	DWORD threadId = GetWindowThreadProcessId(hwnd,&dwProcessId);
	ASSERT(threadId);
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	
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
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	
	CDialogEx::OnClose();
	UnViewHook();
}

HMODULE m_module = NULL;
void CDolphinBoxDlg::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindow(_T("SciCalc"),NULL);
	//HWND hwnd = ::FindWindow(_T("Notepad"),NULL);
	//HWND hwnd = ::FindWindow(NULL,_T("Windows 任务管理器"));
	
	DWORD dwProcessId;
	DWORD threadId = GetWindowThreadProcessId(hwnd,&dwProcessId);
	ASSERT(threadId);
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO: 在此添加控件通知处理程序代码
	HWND hwnd = ::FindWindow(_T("SciCalc"),NULL);
	//HWND hwnd = ::FindWindow(_T("Notepad"),NULL);
	//HWND hwnd = ::FindWindow(NULL,_T("Windows 任务管理器"));

	DWORD dwProcessId;
	DWORD threadId = GetWindowThreadProcessId(hwnd,&dwProcessId);
	ASSERT(threadId);
	// TODO: 在此添加控件通知处理程序代码
	if(m_chkHookLib.GetCheck()){
	
		
		DCSetHook(threadId);
	}else{
		//::FreeLibrary(handle);
	
		DCUnHook();
		//FreeLibrary(m_module);
	}

}
