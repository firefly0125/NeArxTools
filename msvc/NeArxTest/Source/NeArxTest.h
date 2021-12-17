// NeArxTest.h: tools for test arx,code by Q.C
#pragma once

// --
#undef NeArxTestExp
//#ifdef _NEP_STATICLINK
	#define NeArxTestExp
//#else
//	#define NeArxTestExp _declspec(dllimport)
//#endif


// --
#if defined _DEBUG
	#pragma comment(lib, "NeArxTestD.lib")
	#pragma message ("Automatically linking with NeArxTestD.lib.")
#else
	#pragma comment(lib, "NeArxTestS.lib")
	#pragma message ("Automatically linking with NeArxTestS.lib.")
#endif


// --
#define _NAT_STATICLINKED
#include "NeArxTest\TestCore.h"
