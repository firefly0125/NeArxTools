// TestCore.cpp: ≤‚ ‘∑Ω∑®
#include "StdAfx.h"
#include "TestCore.h"
#include "..\..\Workspace\NeArxTest\ArxPub.h"

// --
namespace TestCore
{
	const TCHAR szTestApp[] = _T("NeTestApp");
	const double kPi = 3.14159265358979323846;
}

// ---------------------------------------------------namespace TestCore-------------------------------------------------------
bool TestCore::TestEntity(const AcDbEntity* pEnt, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	if (pEnt == NULL)
	{
		return false;
	}
	AcDbEntity* pEntity = static_cast<AcDbEntity*>(pEnt->clone());
	AcGeMatrix3d xform;
	xform.setToTranslation(vec);

	pEntity->transformBy(xform);
	if (nColor > 256)
	{
		AcCmColor color;
		ArxPub::GetEntityColor(pEnt, color);
		nColor = color.colorIndex();
	}
	pEntity->setColorIndex(nColor);

	// --
	ACHAR* lpszLayer = pEntity->layer();

	// XData
	SetObjectForTest(pEntity, lpszLayer);

	acutDelString(lpszLayer);
	lpszLayer = NULL;

	// 
	pEntity->setLayer(_T("0"));
	const Acad::ErrorStatus kRet = ArxPub::AddToCurrentSpaceAndClose(pEntity);
	
	// --
	return Acad::eOk == kRet ? true : false;
}

bool TestCore::TestEntIds(const AcDbObjectIdArray& objIds, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	int i = 0;
	for (i = 0; i < objIds.length(); i++)
	{
		TestCore::TestEntId(objIds[i], nColor, vec);
	}

	// --
	return true;
}

bool TestCore::TestLineSeg2d(const AcGeLineSeg2d& lineSeg, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	AcDbLine line(AcGePoint3d(AcGePlane::kXYPlane, lineSeg.startPoint()), AcGePoint3d(AcGePlane::kXYPlane, lineSeg.endPoint()));

	// --
	return TestCore::TestEntity(&line, nColor, vec);
}

bool TestCore::TestEntId(const AcDbObjectId& objId, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	AcDbEntityPointer spEnt(objId, AcDb::kForRead);
	if (Acad::eOk != spEnt.openStatus())
	{
		//DebugCore::Trace(_T("QC, Error open entity failed...:%d"), spEnt.openStatus());
		return false;
	}

	return TestCore::TestEntity(spEnt.object(), nColor, vec);
}

bool TestCore::TestEntitys(const AcDbVoidPtrArray& ptrEnts, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	AcArray<AcDbEntity*> ptrEntsT;
	ptrEntsT.setLogicalLength(ptrEnts.length());

	// --
	int i = 0;
	for (i = 0; i < ptrEnts.length(); i++)
	{
		AcDbEntity* pItem = static_cast<AcDbEntity*>(ptrEnts[i]);
		if (!pItem)
		{
			continue;
		}
		ptrEntsT.setAt(i, pItem);
	}

	// --
	return TestEntities(ptrEntsT, nColor, vec);
}

bool TestCore::TestEntities(const AcArray<AcDbEntity*>& ptrEnts, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	const int nLen = ptrEnts.length();

	AcGeMatrix3d xform;
	xform.setToTranslation(vec);
	// --
	AcArray<AcDbEntity*> ptrsTest;
	int i = 0;
	for (i = 0; i < nLen; i++)
	{
		AcDbEntity* pEntItem = ptrEnts[i];
		if (!pEntItem)
		{
			continue;
		}
		AcDbEntity* pEntity = static_cast<AcDbEntity*>(pEntItem->clone());

		pEntity->transformBy(xform);
		Adesk::UInt16 nItemColor = nColor;
		if (nItemColor > 256)
		{
			AcCmColor color;
			ArxPub::GetEntityColor(pEntItem, color);
			nItemColor = color.colorIndex();
		}
		pEntity->setColorIndex(nItemColor);
		
		ACHAR* lpszLayer = pEntity->layer();
		// --XData
		SetObjectForTest(pEntity, lpszLayer);
		acutDelString(lpszLayer);
		lpszLayer = NULL;

		pEntity->setLayer(_T("0"));

		ptrsTest.append(pEntity);
	}

	// --
	const int nFailed = ArxPub::AppendAndClose(ptrsTest);

	return nFailed == 0 ? true : false;
}

bool TestCore::Get3dPolylineVertexes(AcDb3dPolyline* pLine, AcGePoint3dArray& ptsVertex)
{
	if (!pLine)
	{
		return false;
	}
	ptsVertex.removeAll();

	// --		
	AcDbObjectIterator* pIter = pLine->vertexIterator();	
	for (pIter->start(); !pIter->done(); pIter->step())
	{
		AcDb3dPolylineVertex* pItem = NULL;
		if (Acad::eOk != pLine->openVertex(pItem, pIter->objectId(), AcDb::kForRead))
		{
			continue;
		}
		ptsVertex.append(pItem->position());
	}
	delete pIter;

	return ptsVertex.isEmpty() ? false : true;
}

bool TestCore::TestPointsAs3dPolyline(const AcGePoint3dArray& ptList, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	AcGePoint3dArray pts;
	pts.append(ptList);

	// --
	AcDb3dPolyline line(AcDb::k3dSimplePoly, pts);
	return TestCore::TestEntity(&line, nColor, vec);
}

bool TestCore::TestPointsAsPolyline(const AcGePoint2dArray& ptList, Adesk::UInt16 nColor, const AcGeVector3d& vec)
{
	// --
	AcDbPolyline line(ptList.length());

	int i = 0;
	for (i = 0; i < ptList.length(); i++)
	{
		line.addVertexAt(i, ptList[i]);
	}

	return TestCore::TestEntity(&line, nColor, vec);
}

bool TestCore::TestPoint2dArray(const AcGePoint2dArray& ptList, double radius, Adesk::UInt16 nColor, bool bVariableColor)
{
	const int nLen = ptList.length();

	AcArray<AcDbEntity*> ptrEnts;
	ptrEnts.setPhysicalLength(ptList.length());

	// --
	int i = 0;
	for (i = 0; i < nLen; i++)
	{
		AcDbCircle* pCircle = new AcDbCircle(AcGePoint3d(ptList[i].x, ptList[i].y, 0), AcGeVector3d::kZAxis, radius);
		pCircle->setColorIndex(bVariableColor ? (nColor + i):nColor);
		pCircle->setLayer(_T("0"));

		SetObjectForTest(pCircle);

		ptrEnts.append(pCircle);
	}

	// --
	const int nFailed = ArxPub::AppendAndClose(ptrEnts);

	return nFailed == 0 ? true : false;
}

bool TestCore::TestPoint3dArray(const AcGePoint3dArray& ptList, double radius, Adesk::UInt16 nColor, bool bVariableColor)
{
	const int nLen = ptList.length();

	AcArray<AcDbEntity*> ptrEnts;
	ptrEnts.setPhysicalLength(ptList.length());

	// --
	int i = 0;
	for (i = 0; i < nLen; i++)
	{
		AcDbCircle* pCircle = new AcDbCircle(ptList[i], AcGeVector3d::kZAxis, radius);
		pCircle->setColorIndex(bVariableColor ? (nColor + i):nColor);
		pCircle->setLayer(_T("0"));

		SetObjectForTest(pCircle);
		ptrEnts.append(pCircle);
	}
	const int nFailed = ArxPub::AppendAndClose(ptrEnts);

	// --
	return nFailed == 0 ? true : false;
}

Acad::ErrorStatus TestCore::TestPoint3d(const AcGePoint3d& ptCenter, double radius, Adesk::UInt16 nColor)
{
	AcDbCircle* pCircle = new AcDbCircle(ptCenter, AcGeVector3d::kZAxis, radius);
	pCircle->setColorIndex(nColor);

	// --	
	pCircle->setLayer(_T("0"));
	SetObjectForTest(pCircle);

	const Acad::ErrorStatus kRet = ArxPub::AddToCurrentSpaceAndClose(pCircle);

	return kRet;
}

Acad::ErrorStatus TestCore::TestPoint2d(const AcGePoint2d& ptCenter, double radius, Adesk::UInt16 nColor)
{
	AcGePoint3d ptCircleCen(ptCenter.x, ptCenter.y, 0);

	return TestPoint3d(ptCircleCen, radius, nColor);
}

bool TestCore::TestLine2d(const AcGePoint2d& ptStart, const AcGePoint2d& ptEnd, Adesk::UInt16 nColor)
{
	return TestCore::TestLine3d(AcGePoint3d(ptStart.x, ptStart.y, 0.0), AcGePoint3d(ptEnd.x, ptEnd.y, 0.0), nColor);
}

bool TestCore::TestLine3d(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd, Adesk::UInt16 nColor)
{
	AcDbLine line(ptStart, ptEnd);

	return TestCore::TestEntity(&line, nColor);
}

bool TestCore::TestExtent(const AcDbExtents& ext, Adesk::UInt16 nColor)
{
	const AcGePoint2d ptBL = ext.minPoint().convert2d(AcGePlane::kXYPlane);
	const AcGePoint2d ptTR = ext.maxPoint().convert2d(AcGePlane::kXYPlane);

	const AcGePoint2d ptBR = ptBL + fabs(ptBL.x - ptTR.x)*AcGeVector2d::kXAxis;
	const AcGePoint2d ptTL = ptBL + fabs(ptTR.y - ptBL.y)*AcGeVector2d::kYAxis;

	// --
	AcDbPolyline line(4);
	line.addVertexAt(0, ptBL);
	line.addVertexAt(1, ptBR);
	line.addVertexAt(2, ptTR);
	line.addVertexAt(3, ptTL);
	line.setClosed(Adesk::kTrue);

	return TestCore::TestEntity(&line, nColor);
}

bool TestCore::TestDirection(const AcGePoint2d& ptBase, double dDirection, double dScaleing, Adesk::UInt16 nColor, bool bArrowRandom)
{	
	AcGeVector2d vec(cos(dDirection), sin(dDirection));

	return TestCore::TestVector2d(ptBase, dScaleing*vec, nColor, bArrowRandom);
}

bool TestCore::TestVector3d(const AcGePoint3d& ptBase, const AcGeVector3d& vecDir, Adesk::UInt16 nColor, bool bArrowRandom)
{
	return TestCore::TestVector2d(ptBase.convert2d(AcGePlane::kXYPlane), vecDir.convert2d(AcGePlane::kXYPlane), nColor, bArrowRandom);
}

bool TestCore::TestVector2d(const AcGePoint2d& ptBase, const AcGeVector2d& vecDir, Adesk::UInt16 nColor, bool bArrowRandom)
{
	const double dLength = vecDir.length();
	const AcGePoint2d ptEnd = ptBase + vecDir;	
	const double dAngle = (bArrowRandom ? ArxPub::Random(25, 35) : 30.0)*TestCore::kPi / 180.0;

	// --
	const AcGeVector2d vecL = vecDir.normal().rotateBy(-dAngle);
	const AcGePoint2d ptEndL = ptEnd - vecL*dLength*0.2;

	AcGeVector2d vecR = vecDir.normal().rotateBy(dAngle);
	const AcGePoint2d ptEndR = ptEnd - vecR*dLength*0.2;

	// --
	AcDbPolyline line;
	line.addVertexAt(0, ptBase);
	line.addVertexAt(1, ptEnd);
	line.addVertexAt(2, ptEndL);
	line.addVertexAt(3, ptEnd);
	line.addVertexAt(4, ptEndR);
	line.addVertexAt(5, ptEnd);

	return TestCore::TestEntity(&line, nColor);
}

bool TestCore::ClearTestEnt()
{
	resbuf* filter = acutBuildList(-3, 1001, TestCore::szTestApp, RTNONE);

	// --
	ads_name ss;
	const int kRet = acedSSGet(_T("_A"), NULL, NULL, filter, ss);
	acutRelRb(filter);

	// --
	if (RTNORM == kRet)
	{
		Adesk::Int32 length = 0;
		acedSSLength(ss, &length);

		Adesk::Int32 i = 0;
		AcDbObjectId id;
		for (i = 0; i < length; i++)
		{
			ads_name ent;
			const int nRet = acedSSName(ss, i, ent);
			ASSERT(nRet == RTNORM);

			if (Acad::eOk != acdbGetObjectId(id, ent))
			{
				continue;
			}

			AcDbObjectPointer<AcDbEntity> spItem(id, AcDb::kForWrite);
			if (Acad::eOk == spItem.openStatus())
			{
				spItem->erase(Adesk::kTrue);
			}
		}
	}

	return true;
}

bool TestCore::SetObjectForTest(AcDbEntity* pEntity, LPCTSTR lpszMark)
{
	const CString sCurTime = ArxPub::FormatTime(time(NULL));

	// --
	acdbRegApp(TestCore::szTestApp);
	struct resbuf* pXData = acutBuildList(AcDb::kDxfRegAppName, TestCore::szTestApp, AcDb::kDxfXdAsciiString, sCurTime, AcDb::kDxfXdAsciiString, lpszMark, RTNONE);

	// --
	bool bUpgraded = false;
	if (Adesk::kFalse == pEntity->isWriteEnabled())
	{
		bUpgraded = Acad::eOk == pEntity->upgradeOpen() ? true : false;
	}
	const Acad::ErrorStatus eRet = pEntity->setXData(pXData);
	if (bUpgraded)
	{
		pEntity->downgradeOpen();
	}
	acutRelRb(pXData);

	return Acad::eOk == eRet ? true : false;
}

// --
bool g_bPass = false;
void TestCore::UnPass()
{
	g_bPass = false;
}

bool TestCore::SetPause(LPCTSTR lpszPrompt,...)
{
	if (g_bPass)
	{
		return true;
	}

	const int nMaxLen = 4096;

	TCHAR lpBuffer[nMaxLen];
	va_list pArgList;
	va_start(pArgList, lpszPrompt);
	// error here
	_vsntprintf(lpBuffer, nMaxLen, lpszPrompt, pArgList);
	va_end(pArgList);

	CString sMsg = lpBuffer;
	if (sMsg.IsEmpty())
	{
		sMsg.Format(_T("Press anykey to continue or[P to Pass]:"));
	}

	// --
	const CString sKeywords = _T("A B C D E F G H I J K L M N O P Q R S T U V W X Y Z");
	acedInitGet(NULL, sKeywords);

	TCHAR keyword[32];
	const int nRet = acedGetKword(sMsg, keyword);
	const CString sKeyPicked = keyword;

	if (sKeyPicked.CompareNoCase(_T("P")) == 0)
	{
		g_bPass = true;
	}

	return true;
}

bool TestCore::ResetEntityColor(const AcDbObjectId& objId, Adesk::UInt16 nColor)
{
	// --
	AcDbEntityPointer spEnt(objId, AcDb::kForRead);
	if (Acad::eOk != spEnt.openStatus() || Acad::eOk != spEnt->upgradeOpen())
	{
		return false;
	}

	// --
	return Acad::eOk == spEnt->setColorIndex(nColor) ? true : false;
}

CString TestCore::GetTestAppName()
{
	return szTestApp;
}

Acad::ErrorStatus TestCore::GetHandleObjectId(LPCTSTR lpszHandle, AcDbObjectId& objId, AcDbDatabase* pDatabase)
{
	if (!pDatabase)
	{
		pDatabase = acdbHostApplicationServices()->workingDatabase();
	}
	AcDbHandle handle(lpszHandle);

	// --
	return pDatabase->getAcDbObjectId(objId, false, handle);
}
