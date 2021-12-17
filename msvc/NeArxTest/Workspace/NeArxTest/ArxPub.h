// ArxPub.h: tools
#pragma once

namespace ArxPub
{
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 取实体颜色（保留随层颜色）
	// Parameters:
	//   pEntity                - 指定实体
	//   color                  - 返回颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	bool GetEntityColor(const AcDbEntity* pEntity, AcCmColor& color);

	// --
	AcDbBlockTableRecord* OpenCurrentSpaceBlock(AcDb::OpenMode mode, AcDbDatabase* pDB);

	// --
	Acad::ErrorStatus AddToCurrentSpace(AcDbEntity* pNewEnt, AcDbObjectId& objId = AcDbObjectId(), AcDbDatabase* pDB = NULL);

	// --
	Acad::ErrorStatus AddToCurrentSpaceAndClose(AcDbEntity* pNewEnt, AcDbObjectId& objId = AcDbObjectId(), AcDbDatabase* pDb = NULL);

	// --
	int AppendAndClose(const AcArray<AcDbEntity*>& ptrEnts, AcDbObjectIdArray& objIds = AcDbObjectIdArray(), AcDbDatabase* pDb = NULL);

	// 取指定范围内的随机数
	double Random(double dRangeMin, double dRangeMax);

	// 取当前时间字符串
	CString FormatTime(time_t tmValue, bool bUesLocalArea = true);
}
