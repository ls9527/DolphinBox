// DolphinViewDll.h : DolphinViewDll DLL ����ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CDolphinViewDllApp
// �йش���ʵ�ֵ���Ϣ������� DolphinViewDll.cpp
//

class CDolphinViewDllApp : public CWinApp
{
public:
	CDolphinViewDllApp();

// ��д
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
