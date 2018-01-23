// MainDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "DolphinViewDll.h"
#include "MainDlg.h"
#include "afxdialogex.h"
#include <stack>

using namespace std;
// CMainDlg 对话框

IMPLEMENT_DYNAMIC(CMainDlg, CDialogEx)

CMainDlg::CMainDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMainDlg::IDD, pParent)
{

}

CMainDlg::~CMainDlg()
{
}

void CMainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_BOX_MAIN, m_boxMain);
}


BEGIN_MESSAGE_MAP(CMainDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_EXEC, &CMainDlg::OnBnClickedButtonExec)
END_MESSAGE_MAP()


// CMainDlg 消息处理程序
typedef struct tagSkillTree{
	struct tagSkillTree* left;
	char tag_0010[4];
	struct tagSkillTree* right;
	int id;
	//16
	char tag_0011[20];
	char end;// == 1 就会退出循环
}SkillTree,*LPSkillTree;



//db [[[[[[[[[0b285d8]+0x5c]+0x1d0]+0x4]+2908+4]+0x4]+n]+0x10+0x4]+0xc]
void CMainDlg::OnBnClickedButtonExec()
{
	// TODO: 在此添加控件通知处理程序代码
	m_boxMain.ResetContent();
	LPSkillTree point = 0;
	
	__asm{
		mov eax,0b285d8h
		mov eax,[eax+5ch]
		mov eax,[eax+1d0h]
		mov eax,[eax+4h]
		lea eax,[eax+2908h]
		mov eax,[eax+4h]
		mov eax,[eax+4h]
		mov point,eax
	}
	stack<LPSkillTree> sta;
	//遍历二叉树并显示出来的初步思想
	while(!point->end){
		if(point!=NULL){
			sta.push(point);
			point = point->left;
		}else{
			point = sta.top();
			sta.pop();
			point = point->right;
		}
		char *skillName = NULL;
		__asm{
			mov eax,point;
			add eax,10h
			add eax,4h
			mov eax,[eax+0ch]
			mov skillName,eax
		}
	}

	//技能名称偏移
	/*
	__asm{
		add eax,10h
		add eax,4h
		mov eax,[eax+0ch]
		mov 
	}
	*/
	m_boxMain.AddString(_T("str1"));
	m_boxMain.AddString(_T("str2"));
	m_boxMain.AddString(_T("str3"));

}
