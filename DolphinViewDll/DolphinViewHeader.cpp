#include "stdafx.h"
#include "DolphinViewHeader.h"
#include "MainDlg.h"





CMainDlg *mainDlg = NULL;
HHOOK hookId = 0;
LRESULT CALLBACK KeyboardProc(
	int code,       // hook code
	WPARAM wParam,  // virtual-key code
	LPARAM lParam   // keystroke-message information
	){
		AFX_MANAGE_STATE(AfxGetStaticModuleState());
		LRESULT lRet = CallNextHookEx(hookId,code,wParam,lParam);
		if(code ==HC_ACTION&& (lParam>>30)){
			
			if(wParam == VK_HOME && (lParam>>29&1)){
				
				if(mainDlg==NULL){
					mainDlg = new CMainDlg();
					mainDlg->Create(IDD_DIALOG_MAIN);
				}
				
				mainDlg->ShowWindow(SW_SHOWNORMAL);
			}
		}
		
		return lRet;
}



void WINAPI SetViewHook(int processId){
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	hookId = ::SetWindowsHookEx(WH_KEYBOARD,&KeyboardProc,GetModuleHandle(_T("DolphinViewDll.dll")),NULL);
}


void WINAPI UnViewHook(int processId){
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	mainDlg->DestroyWindow();
	UnhookWindowsHookEx(hookId);
}