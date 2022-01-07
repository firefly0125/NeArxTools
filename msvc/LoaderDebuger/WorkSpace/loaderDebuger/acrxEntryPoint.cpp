// acrxEntryPoint.h
#include "StdAfx.h"
#include "resource.h"

#define szRDS _RXST("HY")


// ObjectARX EntryPoint
class CLoaderDebugerApp : public AcRxArxApp
{
#if _MSC_VER < 1300
	DECLARE_DBX_ENTRY()
#endif
#if _MSC_VER < 1300
	DECLARE_CMD_ENTRY()
#endif

public:
	CLoaderDebugerApp() {}

	virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
	{
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode = AcRxArxApp::On_kInitAppMsg(pkt);

		// TODO: 在此添加额外的初始化代码

		return retCode;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
	{
		// TODO: 在此添加额外的清理代码

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode = AcRxArxApp::On_kUnloadAppMsg(pkt);

		// TODO: Unload dependencies here

		return retCode;
	}

	virtual void RegisterServerComponents()
	{
	}

	static void LDtestLoad()
	{
		CWnd* pParent = acedGetAcadFrame();

		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("程序文件(*.arx;*.dbx;*.dll)|*.arx;*.dbx;*.dll||"), pParent);
		if(dlg.DoModal() != IDOK)
		{
			return;
		}

		SetErrorMode(0);
		HMODULE hMd = LoadLibrary(dlg.GetPathName());
		if(hMd)
		{
			pParent->MessageBox(_T("加载成功!"), _T("信息"), MB_OK|MB_ICONINFORMATION);
			FreeLibrary(hMd);
		}
		else
		{
			acutPrintf(_T("加载失败: 0x%x"), GetLastError());
		}
	}

	static void LDtestLoad2()
	{
		CWnd* pParent = acedGetAcadFrame();

		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("程序文件(*.arx;*.dbx;*.dll)|*.arx;*.dbx;*.dll||"), pParent);
		if(dlg.DoModal() != IDOK)
		{
			return;
		}

		SetErrorMode(0);
		HMODULE hMd = LoadLibrary(dlg.GetPathName());
		if(hMd)
		{
			pParent->MessageBox(_T("加载成功!"), _T("信息"), MB_OK|MB_ICONINFORMATION);

			typedef void* (WINAPI* ARXAPI) (void) ;

			ARXAPI ptr = (ARXAPI)GetProcAddress(hMd, ("acrxGetApiVersion"));
			if(ptr)
			{
				acutPrintf(_T("\nacrxGetApiVersion ret def:")
					_T("\n0x000E0000 for V14")
					_T("\n0x000F0000 for V2000-2002")
					_T("\n0x00100000 for V2004-2006")
					_T("\n0x00110000 for V2007-2009")
					_T("\n0x00120000 for V2010-2012"));

				BYTE* pData = (BYTE*)ptr();
				acutPrintf(_T("\nret: %X"), (int)pData);
			}
			else
			{
				acutPrintf(_T("\nfailed2"));
			}

			FreeLibrary(hMd);
		}
		else
		{
			acutPrintf(_T("加载失败: 0x%x"), GetLastError());
		}
	}

	static void LDtestLoad3()
	{
		CWnd* pParent = acedGetAcadFrame();

		CFileDialog dlg(TRUE, NULL, NULL, OFN_HIDEREADONLY, _T("程序文件(*.arx;*.dbx;*.dll)|*.arx;*.dbx;*.dll||"), pParent);
		if(dlg.DoModal() != IDOK)
		{
			return;
		}

		SetErrorMode(0);
		bool bRet = acrxLoadModule(dlg.GetPathName(), true, true);
		acutPrintf(_T("\n加载: %s"), bRet ? _T("成功") : _T("失败"));
	}
};

#if _MSC_VER < 1300
BEGIN_DBX_ENTRY(CLoaderDebugerApp)
	// 在 VC6 下按照指定格式添加需要自动注册的自定义对象/实体。
	// 格式: DBX_ITEM(类名)，例如: DBX_ITEM(CMyEntity)
END_DBX_ENTRY()
#endif

#if _MSC_VER < 1300
BEGIN_ARXCMD_ENTRY(CLoaderDebugerApp)
	// 在 VC6 下添加 ARX 命令的步骤如下:
	// 1. 复制 IMPLEMENT_ARX_ENTRYPOINT 后所有含有 ACED_ARXCOMMAND_ENTRY_AUTO 的行到下面。
	// 2. 修改 ACED_ARXCOMMAND_ENTRY_AUTO 为 ARXCMD_ITEM 。
	ARXCMD_ITEM(CLoaderDebugerApp, LD, testLoad, testLoad, ACRX_CMD_MODAL, NULL)
END_ARXCMD_ENTRY()

BEGIN_ADSCMD_ENTRY(CLoaderDebugerApp)
	// 在 VC6 下添加 Lisp 函数的步骤如下:
	// 1. 复制 IMPLEMENT_ARX_ENTRYPOINT 后所有含有 ACED_ADSSYMBOL_ENTRY_AUTO 的行到下面。
	// 2. 修改 ACED_ADSSYMBOL_ENTRY_AUTO 为 ADSSYM_ITEM 。
	// 
	// 在 VC6 下添加 Lisp 命令的步骤如下:
	// 1. 复制 IMPLEMENT_ARX_ENTRYPOINT 后所有含有 ACED_ADSCOMMAND_ENTRY_AUTO 的行到下面。
	// 2. 修改 ACED_ADSCOMMAND_ENTRY_AUTO 为 ADSCMD_ITEM 。
END_ADSCMD_ENTRY()
#endif

IMPLEMENT_ARX_ENTRYPOINT(CLoaderDebugerApp)
ACED_ARXCOMMAND_ENTRY_AUTO(CLoaderDebugerApp, LD, testLoad, testLoad, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CLoaderDebugerApp, LD, testLoad2, testLoad2, ACRX_CMD_MODAL, NULL)
ACED_ARXCOMMAND_ENTRY_AUTO(CLoaderDebugerApp, LD, testLoad3, testLoad3, ACRX_CMD_MODAL, NULL)
