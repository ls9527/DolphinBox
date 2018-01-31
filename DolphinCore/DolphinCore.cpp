// DolphinCore.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "DolphinCore.h"


void test(){
	::MessageBox(NULL,_T("test"),NULL,NULL);
}



HHOOK g_hookId;

LRESULT CALLBACK DCKeyboardProc(
	int code,       // hook code
	WPARAM wParam,  // virtual-key code
	LPARAM lParam   // keystroke-message information
	){
		
		LRESULT lRet = CallNextHookEx(g_hookId,code,wParam,lParam);
		if(code ==HC_ACTION&& (lParam>>30)){

			if(wParam == VK_HOME && (lParam>>29&1)){
				 MessageBox(0,L"enter alt + VK_HOME",0,0);
			}
		}

		return lRet;
}

void DCSetHook(int threadId){
	
	
	
	g_hookId = ::SetWindowsHookEx(WH_KEYBOARD,&DCKeyboardProc,GetModuleHandle(_T("DolphinCore.dll")),threadId);
	if (!g_hookId){
		 MessageBox(0,L"failed to SetWindowsHookEx",0,0);
	}
}


void  DCUnHook(){

	//throw _T("不要调用卸载钩子");
	/*
	if(g_mainHwnd){
		PostMessage(g_mainHwnd,WM_CLOSE,0,0);
		g_mainHwnd = NULL;
	}
	*/
	
	//PostMessage(g_mainHwnd,WM_CLOSE,0,0);
	if(g_hookId == NULL){
		return;
	}
	
	//SendMessage(g_mainHwnd,WM_CLOSE,0,0);
	

	BOOL bRet = ::UnhookWindowsHookEx(g_hookId);

	

}