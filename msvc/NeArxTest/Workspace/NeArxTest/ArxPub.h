// ArxPub.h: tools
#pragma once

namespace ArxPub
{
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ȡʵ����ɫ�����������ɫ��
	// Parameters:
	//   pEntity                - ָ��ʵ��
	//   color                  - ������ɫ
	// Returns: �ɹ�����true�����򷵻�false
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

	// ȡָ����Χ�ڵ������
	double Random(double dRangeMin, double dRangeMax);

	// ȡ��ǰʱ���ַ���
	CString FormatTime(time_t tmValue, bool bUesLocalArea = true);
}
