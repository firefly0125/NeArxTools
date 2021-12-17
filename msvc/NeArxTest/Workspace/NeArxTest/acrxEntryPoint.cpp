// acrxEntryPoint.h
#include "StdAfx.h"
#include "resource.h"

#define szRDS _RXST("")


// ObjectARX EntryPoint
class CNeArxTestApp : public AcRxDbxApp
{
#if _MSC_VER < 1300
	DECLARE_DBX_ENTRY()
#endif

public:
	CNeArxTestApp() {}

	virtual AcRx::AppRetCode On_kInitAppMsg(void* pkt)
	{
		// TODO: Load dependencies here

		// You *must* call On_kInitAppMsg here
		AcRx::AppRetCode retCode = AcRxDbxApp::On_kInitAppMsg(pkt);

		// TODO: 在此添加额外的初始化代码

		return retCode;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
	{
		// TODO: 在此添加额外的清理代码

		// You *must* call On_kUnloadAppMsg here
		AcRx::AppRetCode retCode = AcRxDbxApp::On_kUnloadAppMsg(pkt);

		// TODO: Unload dependencies here

		return retCode;
	}

	virtual void RegisterServerComponents()
	{
	}
};

#if _MSC_VER < 1300
BEGIN_DBX_ENTRY(CNeArxTestApp)
	// 在 VC6 下按照指定格式添加需要自动注册的自定义对象/实体。
	// 格式: DBX_ITEM(类名)，例如: DBX_ITEM(CMyEntity)
END_DBX_ENTRY()
#endif


IMPLEMENT_ARX_ENTRYPOINT(CNeArxTestApp)
