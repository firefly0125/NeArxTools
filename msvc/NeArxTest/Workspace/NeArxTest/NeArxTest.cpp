// NeArxTest.cpp : ���� DLL �ĳ�ʼ�����̡�
//

#include "StdAfx.h"
#include "resource.h"
#include <afxdllx.h>


// Define the sole extension module object.
AC_IMPLEMENT_EXTENSION_MODULE(NeArxTestDLL)
// Please do not remove the 3 following lines. These are here to make .NET MFC Wizards
// running properly. The object will not compile but is require by .NET to recognize
// this project as being an MFC project
#ifdef NEVER
AFX_EXTENSION_MODULE NeArxTestExtDLL = {NULL, NULL};
#endif

// Now you can use the CAcModuleResourceOverride class in
// your application to switch to the correct resource instance.
// Please see the ObjectARX Documentation for more details

// DLL ��ڵ�
extern "C"
BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
	// ���ʹ�� lpReserved���뽫���Ƴ�
	UNREFERENCED_PARAMETER(lpReserved);

	if (dwReason == DLL_PROCESS_ATTACH)
	{
		_hdllInstance = hInstance;
		NeArxTestDLL.AttachInstance(hInstance);
	}
	else if (dwReason == DLL_PROCESS_DETACH)
	{
		NeArxTestDLL.DetachInstance();
	}
	return TRUE;
}

