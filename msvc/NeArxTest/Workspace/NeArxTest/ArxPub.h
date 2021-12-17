// ArxPub.h: ≤‚ ‘∑Ω∑®
#pragma once

namespace ArxPub
{
	bool GetEntityColor(const AcDbEntity* pEntity, AcCmColor& color);

	// --
	AcDbBlockTableRecord* OpenCurrentSpaceBlock(AcDb::OpenMode mode, AcDbDatabase* pDB);

	// --
	Acad::ErrorStatus AddToCurrentSpace(AcDbEntity* pNewEnt, AcDbObjectId& objId = AcDbObjectId(), AcDbDatabase* pDB = NULL);

	// --
	Acad::ErrorStatus AddToCurrentSpaceAndClose(AcDbEntity* pNewEnt, AcDbObjectId& objId = AcDbObjectId(), AcDbDatabase* pDb = NULL);

	// --
	int AppendAndClose(const AcArray<AcDbEntity*>& ptrEnts, AcDbObjectIdArray& objIds = AcDbObjectIdArray(), AcDbDatabase* pDb = NULL);

	// --
	double Random(double dRangeMin, double dRangeMax);

	// --
	CString FormatTime(time_t tmValue, bool bUesLocalArea = true);
}
