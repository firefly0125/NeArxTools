// ArxPub.cpp: 辅助方法
#include "StdAfx.h"
#include "ArxPub.h"

// --
bool ArxPub::GetEntityColor(const AcDbEntity* pEntity, AcCmColor& color)
{
	color = pEntity->color();

	// --
	if (color.isByLayer())
	{
		AcDbLayerTableRecordPointer spLayerRec(pEntity->layerId(), AcDb::kForRead);
		if (Acad::eOk == spLayerRec.openStatus())
		{
			color = spLayerRec->color();
		}
		spLayerRec->close();
	}

	return true;
}

Acad::ErrorStatus ArxPub::AddToCurrentSpaceAndClose(AcDbEntity* pNewEnt, AcDbObjectId& objId, AcDbDatabase* pDb)
{
	const Acad::ErrorStatus eRet = ArxPub::AddToCurrentSpace(pNewEnt, objId, pDb);
	if (eRet == Acad::eOk)
	{
		pNewEnt->close();
	}
	else
	{
		delete pNewEnt;
	}

	// --
	return eRet;
}

AcDbBlockTableRecord* ArxPub::OpenCurrentSpaceBlock(AcDb::OpenMode mode, AcDbDatabase* pDB)
{
	if (!pDB)
	{
		return NULL;
	}
	AcDbBlockTableRecord* pBlkRec = NULL;
	const Acad::ErrorStatus eRet = acdbOpenObject(pBlkRec, pDB->currentSpaceId(), mode);

	// --
	return Acad::eOk == eRet ? pBlkRec : NULL;
}

Acad::ErrorStatus ArxPub::AddToCurrentSpace(AcDbEntity* pNewEnt, AcDbObjectId& objId, AcDbDatabase* pDB)
{
	if (!pNewEnt)
	{
		return Acad::eInvalidInput;
	}
	if (!pDB)
	{
		pDB = acdbHostApplicationServices()->workingDatabase();
	}
	if (!pDB)
	{
		return Acad::eNullPtr;
	}

	// --
	AcDbBlockTableRecord* blkRec = OpenCurrentSpaceBlock(AcDb::kForWrite, pDB);
	if (!blkRec)
	{
		return Acad::eInvalidInput;
	}
	const Acad::ErrorStatus eRet = blkRec->appendAcDbEntity(objId, pNewEnt);
	blkRec->close();
	if (Acad::eOk != eRet)
	{
		//DebugCore::Trace(_T("QC, Error append entity to block failed...:%s"), AcDbCore::rxErrorStr(eRet));
	}

	// 
	return eRet;
}

int ArxPub::AppendAndClose(const AcArray<AcDbEntity*>& ptrEnts, AcDbObjectIdArray& objIds, AcDbDatabase* pDb)
{
	if (pDb == NULL)
	{
		pDb = acdbHostApplicationServices()->workingDatabase();
	}

	// --
	AcDbBlockTableRecord* pRecord = OpenCurrentSpaceBlock(AcDb::kForWrite, pDb);
	if (!pRecord)
	{
		return -1;
	}
	int nFailed = 0;
	for (int i = 0; i < ptrEnts.length(); i++)
	{
		AcDbEntity* pEnt = ptrEnts[i];
		if (pEnt == NULL)
		{
			continue;
		}
		AcDbObjectId objId;
		if (Acad::eOk != pRecord->appendAcDbEntity(objId, pEnt))
		{
			nFailed++;
		}
		objIds.append(objId);
		pEnt->close();
	}
	pRecord->close();

	return nFailed;
}

double ArxPub::Random(double dRangeMin, double dRangeMax)
{
	double dRet = (double(rand()) / (RAND_MAX + 1.0))*(dRangeMax - dRangeMin) + dRangeMin;

	return dRet;
}

CString ArxPub::FormatTime(time_t tmValue, bool bUesLocalArea)
{
	tm data;
	// 当前时区时间 or 格林尼治时间
	const int nRet = bUesLocalArea ? localtime_s(&data, &tmValue) : gmtime_s(&data, &tmValue);

	// --
	CString sRet;
	sRet.Format(_T("%d-%d-%d %d:%d:%d"), data.tm_year + 1900, data.tm_mon + 1, data.tm_mday, data.tm_hour, data.tm_min, data.tm_sec);

	return sRet;
}
