#include "stdafx.h"
#include "DolphinViewHeader.h"
#include "MainDlg.h"
#include "DolphinViewDll.h"
#include "CustomMessage.h"





#pragma data_seg (".MySec")
HWND  g_dolphinViewMainHwnd = NULL;
HHOOK g_dolphinViewHookId = 0;

#pragma data_seg ()
#pragma comment(linker,"/SECTION:.MySec,RWS")

extern CDolphinViewDllApp theApp;
CMainDlg *mainDlg = NULL;

LRESULT CALLBACK KeyboardProc(
	int code,       // hook code
	WPARAM wParam,  // virtual-key code
	LPARAM lParam   // keystroke-message information
	){
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		LRESULT lRet = CallNextHookEx(g_dolphinViewHookId,code,wParam,lParam);
		if(code ==HC_ACTION&& (lParam>>30)){
			
			if(wParam == VK_HOME){// && (lParam>>29&1)
				if( g_dolphinViewMainHwnd == NULL){
					mainDlg = new CMainDlg();
					mainDlg->Create(IDD_DIALOG_MAIN);
					 g_dolphinViewMainHwnd = mainDlg->m_hWnd;
					AfxMessageBox(_T("Create MainWindow"));
				}
				mainDlg->ShowWindow(SW_SHOWNORMAL);
			}
			if(wParam == VK_END){
				mainDlg->DestroyWindow();
				theApp.ExitInstance();
				g_dolphinViewMainHwnd = NULL;
			}
		}
		
		return lRet;
}



void SetViewHook(int threadId){
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	
	
	g_dolphinViewHookId = ::SetWindowsHookEx(WH_KEYBOARD,&KeyboardProc,GetModuleHandle(_T("DolphinViewDll.dll")),threadId);
	if (!g_dolphinViewHookId){
		 MessageBox(0,L"failed to SetWindowsHookEx",0,0);
	}
}


void  UnViewHook(){
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if(g_dolphinViewHookId == NULL){
		return;
	}
	
	if(g_dolphinViewMainHwnd!=NULL){
		PostMessage(g_dolphinViewMainHwnd,WM_UNINSTALL_DLL,0,0);
	}
	UnhookWindowsHookEx(g_dolphinViewHookId);
	g_dolphinViewHookId = NULL;
	
	

}