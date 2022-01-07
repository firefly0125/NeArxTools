// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
#pragma once

//- 'DEBUG workaround' below prevents the MFC or ATL #include-s from pulling 
//- in "Afx.h" that would force the debug CRT through #pragma-s.
#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
#define _DEBUG_WAS_DEFINED
#undef _DEBUG
#pragma message("     �� Release ģʽ���� MFC / STL / ATL ͷ�ļ�.")
#endif

#pragma pack(push, 8)
#pragma warning(disable: 4786)
//#pragma warning(disable: 4098)

#define STRICT

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN			// �� Windows ͷ���ų�����ʹ�õ�����
#endif

#if _MSC_VER > 1200

// ���º궨��Ҫ������ƽ̨��Ҫ������ƽ̨
// �Ǿ�������Ӧ�ó������蹦�ܵ� Windows��Internet Explorer �Ȳ�Ʒ��
// ����汾��ͨ����ָ���汾�����Ͱ汾��ƽ̨���������п��õĹ��ܣ������
// ����������

// �������Ҫ��Ե�������ָ���汾��ƽ̨�����޸����ж��塣
// �йز�ͬƽ̨��Ӧֵ��������Ϣ����ο� MSDN��
#ifndef WINVER					// ָ��Ҫ������ƽ̨�� Windows NT 4��
#define WINVER 0x0501			// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif

#ifndef _WIN32_WINNT			// ����ʹ���ض��� Windows NT 4 ����߰汾�Ĺ��ܡ�
#define _WIN32_WINNT 0x0501		// ����ֵ����Ϊ��Ӧ��ֵ���������� Windows �������汾��
#endif						

#ifndef _WIN32_WINDOWS			// ָ��Ҫ������ƽ̨�� Windows 98��
#define _WIN32_WINDOWS 0x0410	// ����ֵ����Ϊ�ʵ���ֵ���������� Windows Me ����߰汾��
#endif

#ifndef _WIN32_IE				// ָ��Ҫ������ƽ̨�� Internet Explorer 4.0��
#define _WIN32_IE 0x0600		// ����ֵ����Ϊ��Ӧ��ֵ���������� IE �������汾��
#endif

#endif


// ObjectARX and OMF headers needs this
#include <map>

#include <afxwin.h>				// MFC ��������ͱ�׼���
#include <afxext.h>				// MFC ��չ

#ifndef _AFX_NO_OLE_SUPPORT
#include <afxole.h>				// MFC OLE ��
#include <afxodlgs.h>			// MFC OLE �Ի�����
#include <afxdisp.h>			// MFC �Զ�����
#endif // _AFX_NO_OLE_SUPPORT

#ifndef _AFX_NO_DB_SUPPORT
#include <afxdb.h>				// MFC ODBC ���ݿ���
#endif // _AFX_NO_DB_SUPPORT

#ifndef _AFX_NO_DAO_SUPPORT
#include <afxdao.h>				// MFC DAO ���ݿ���
#endif // _AFX_NO_DAO_SUPPORT

#include <afxdtctl.h>			// MFC �� Internet Explorer 4 �����ؼ���֧��
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>				// MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#pragma warning(push)
#pragma warning(disable: 4996)

// ���� ObjectDBX/ObjectARX ͷ�ļ�
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

//#pragma warning(disable: 4819)		// ���ΰ��� XTToolKitPro.h ͷ�ļ�ʱ�ľ���

//#define _XTP_STATICLINK				// ��̬���� XTP �����
//#define _HFC_STATICLINK				// ��̬���Ӻ�ҵ���ÿ�

//#include "XTToolKitPro.h"			// XT �����
//#include "DtKernel.h"				// ��ҵ��������
//#include "HFCBase.h"				// ��ҵ������ÿ�

#ifdef _DEBUG_WAS_DEFINED
#define _DEBUG
#undef _DEBUG_WAS_DEFINED
#endif

//#include "HFCAcad.h"				// ��ҵ CAD ���ÿ�
//#include "HFCAcadUi.h"			// ��ҵ CAD �����
