// stdafx.h : 标准系统包含文件的包含文件，
// 或是经常使用但不常更改的
// 特定于项目的包含文件
#pragma once

//- 'DEBUG workaround' below prevents the MFC or ATL #include-s from pulling 
//- in "Afx.h" that would force the debug CRT through #pragma-s.
#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#pragma message("     以 Release 模式编译 MFC / STL / ATL 头文件.")
#endif

#pragma pack(push, 8)
#pragma warning(disable: 4786)
//#pragma warning(disable: 4098)

#define STRICT

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN			// 从 Windows 头中排除极少使用的资料
#endif

#if _MSC_VER > 1200

// 以下宏定义要求的最低平台。要求的最低平台
// 是具有运行应用程序所需功能的 Windows、Internet Explorer 等产品的
// 最早版本。通过在指定版本及更低版本的平台上启用所有可用的功能，宏可以
// 正常工作。

// 如果必须要针对低于以下指定版本的平台，请修改下列定义。
// 有关不同平台对应值的最新信息，请参考 MSDN。
#ifndef WINVER					// 指定要求的最低平台是 Windows NT 4。
#define WINVER 0x0501			// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif

#ifndef _WIN32_WINNT			// 允许使用特定于 Windows NT 4 或更高版本的功能。
#define _WIN32_WINNT 0x0501		// 将此值更改为相应的值，以适用于 Windows 的其他版本。
#endif						

#ifndef _WIN32_WINDOWS			// 指定要求的最低平台是 Windows 98。
#define _WIN32_WINDOWS 0x0410	// 将此值更改为适当的值，以适用于 Windows Me 或更高版本。
#endif

#ifndef _WIN32_IE				// 指定要求的最低平台是 Internet Explorer 4.0。
#define _WIN32_IE 0x0600		// 将此值更改为相应的值，以适用于 IE 的其他版本。
#endif

#endif


// ObjectARX and OMF headers needs this
#include <map>

#include <afxwin.h>				// MFC 核心组件和标准组件
#include <afxext.h>				// MFC 扩展

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>				// MFC OLE 类
#include <afxodlgs.h>			// MFC OLE 对话框类
#include <afxdisp.h>			// MFC 自动化类
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>				// MFC ODBC 数据库类
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>				// MFC DAO 数据库类
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>			// MFC 对 Internet Explorer 4 公共控件的支持
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>				// MFC 对 Windows 公共控件的支持
#endif // _AFX_NO_AFXCMN_SUPPORT

#pragma warning(push)
#pragma warning(disable: 4996)

// 包含 ObjectDBX/ObjectARX 头文件
// Uncomment one of the following lines to bring a given library in your project.
//#define _BREP_SUPPORT_			// Support for the BRep API
//#define _HLR_SUPPORT_				// Support for the Hidden Line Removal API
//#define _AMODELER_SUPPORT_		// Support for the AModeler API

#if _MSC_VER < 1300
// RX Includes
#include "ArxMigrtion.h"
#else
//#define _ASE_SUPPORT_				// Support for the ASI/ASE API
//#define _RENDER_SUPPORT_			// Support for the AutoCAD Render API
//#define _ARX_CUSTOM_DRAG_N_DROP_	// Support for the ObjectARX Drag'n Drop API
//#define _INC_LEAGACY_HEADERS_		// Include legacy headers in this project
#include "arxHeaders.h"

#endif

#pragma warning(pop)

#include "DocData.h" // Your document specific data class holder

// Declare it as an extern here so that it becomes available in all modules
extern AcApDataManager<CDocData> DocVars;

#pragma pack(pop)

//#pragma warning(disable: 4819)		// 屏蔽包含 XTToolKitPro.h 头文件时的警告

//#define _XTP_STATICLINK				// 静态链接 XTP 界面库
//#define _HFC_STATICLINK				// 静态链接鸿业公用库

//#include "XTToolKitPro.h"			// XT 界面库
//#include "DtKernel.h"				// 鸿业三角网库
//#include "HFCBase.h"				// 鸿业软件公用库

#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif

//#include "HFCAcad.h"				// 鸿业 CAD 公用库
//#include "HFCAcadUi.h"			// 鸿业 CAD 界面库
