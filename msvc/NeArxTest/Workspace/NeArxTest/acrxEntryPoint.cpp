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

		// TODO: �ڴ���Ӷ���ĳ�ʼ������

		return retCode;
	}

	virtual AcRx::AppRetCode On_kUnloadAppMsg(void* pkt)
	{
		// TODO: �ڴ���Ӷ�����������

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
	// �� VC6 �°���ָ����ʽ�����Ҫ�Զ�ע����Զ������/ʵ�塣
	// ��ʽ: DBX_ITEM(����)������: DBX_ITEM(CMyEntity)
END_DBX_ENTRY()
#endif


IMPLEMENT_ARX_ENTRYPOINT(CNeArxTestApp)
