// TestCore.h: ���Է���
#pragma once

// ���Ժ��������ռ�
namespace TestCore
{
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ���Ե��λ��
	// Parameters:
	//   ptCenter               - Բ��
	//   radius                 - �뾶
	//   nColor                 - ��ɫ
	//   objId                  - ����ʵ��id
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp Acad::ErrorStatus TestPoint3d(const AcGePoint3d& ptCenter, double radius = 2.0, Adesk::UInt16 nColor = 2);
	NeArxTestExp Acad::ErrorStatus TestPoint2d(const AcGePoint2d& ptCenter, double radius = 2.0, Adesk::UInt16 nColor = 2);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ���Ե���λ��
	// Parameters:
	//   ptList                 - ����
	//   radius                 - �뾶
	//   nColor                 - ��ɫ
	//   bVariableColor         - true:ʹ��������ɫ;false,ʹ����ͬ��ɫ
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestPoint3dArray(const AcGePoint3dArray& ptList, double radius = 2.0, Adesk::UInt16 nColor = 1, bool bVariableColor = false);
	NeArxTestExp bool TestPoint2dArray(const AcGePoint2dArray& ptList, double radius = 2.0, Adesk::UInt16 nColor = 1, bool bVariableColor = false);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ���Ե��飬����Ϊ���������
	// Parameters:
	//   ptList                 - ����
	//   nColor                 - ��ɫ
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestPointsAsPolyline(const AcGePoint2dArray& ptList, Adesk::UInt16 nColor = 251, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ���Ե��飬����Ϊ��ά�����
	// Parameters:
	//   ptList                 - ��ά����
	//   nColor                 - ��ɫ
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestPointsAs3dPolyline(const AcGePoint3dArray& ptList, Adesk::UInt16 nColor = 251, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ȡ��ά����ߵĶ���
	// Parameters:
	//   pLine                  - �����
	//   ptsVertex              - ������ά����
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool Get3dPolylineVertexes(AcDb3dPolyline* pLine, AcGePoint3dArray& ptsVertex);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ����ʵ���λ��
	// Parameters:
	//   pEnt                   - ��Ҫ���Ե�ʵ��
	//   nColor                 - ��ɫ(257��ʾʹ��ʵ���������ɫ)
	//   vec                    - ��������
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestEntity(const AcDbEntity* pEnt, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ���Զ��ʵ��
	// Parameters:
	//   ptrEnts                - ʵ��ָ��
	//   nColor                 - ��ɫ
	//   vec                    - ��������
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestEntities(const AcArray<AcDbEntity*>& ptrEnts, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);
	NeArxTestExp bool TestEntitys(const AcDbVoidPtrArray& ptrEnts, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ����ʵ��ID
	NeArxTestExp bool TestEntId(const AcDbObjectId& objId, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ����ʵ������
	NeArxTestExp bool TestEntIds(const AcDbObjectIdArray& objIds, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ��������
	// Note: �����Ҫ��ͷʹ������н�,�������ѭ���ⲿʹ���������; �����������: srand((unsigned int)time(NULL));
	// Note: rand()������������α�����
	// Parameters:
	//   ptBase                 - ��������
	//   vecDir                 - ָ������
	//   nColor                 - ��ɫ
	//   bArrowRandom           - true,��ͷʹ������н�; false,��ͷʹ�ù̶��н�
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestVector2d(const AcGePoint2d& ptBase, const AcGeVector2d& vecDir, Adesk::UInt16 nColor = 2, bool bArrowRandom = false);
	NeArxTestExp bool TestVector3d(const AcGePoint3d& ptBase, const AcGeVector3d& vecDir, Adesk::UInt16 nColor = 2, bool bArrowRandom = false);
	NeArxTestExp bool TestDirection(const AcGePoint2d& ptBase, double dDirection, double dScaleing = 1.0, Adesk::UInt16 nColor = 2, bool bArrowRandom = false);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: �����߶�
	// Parameters:
	//   lineSeg                - �߶�
	//   nColor                 - ��ɫ
	//   vec                    - ��������
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestLineSeg2d(const AcGeLineSeg2d& lineSeg, Adesk::UInt16 nColor = 2, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ����ֱ��
	// Parameters:
	//   ptStart                - ���
	//   ptEnd                  - �յ�
	//   nColor                 - ��ɫ
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestLine2d(const AcGePoint2d& ptStart, const AcGePoint2d& ptEnd, Adesk::UInt16 nColor = 2);
	NeArxTestExp bool TestLine3d(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd, Adesk::UInt16 nColor = 2);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ���Ծ��ο�
	// Parameters:
	//   ext                    - ���ο�
	//   nColor                 - ��ɫ
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestExtent(const AcDbExtents& ext, Adesk::UInt16 nColor = 2);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: �������ʵ��
	// Parameters:
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool ClearTestEnt();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: Ϊʵ������չ����(����App)
	// Parameters:
	//   pObj                   - ʵ��ָ��
	//   lpszMark               - �Զ�������
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool SetObjectForTest(AcDbEntity* pEntity, LPCTSTR lpszMark = NULL);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ��ͣ(ʵ������Ҫ������ؼ���)
	// Note: �������δ��ʱ����?...����...
	// Parameters:
	//   lpszPrompt             - �������
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool SetPause(LPCTSTR lpszPrompt = _T("Anykey to continue or[P to Pass]:"),...);
	NeArxTestExp void UnPass();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ����ʵ�����ɫ
	// Parameters:
	//   objId                  - ʵ��ID
	//   nColor                 - ��ɫ
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool ResetEntityColor(const AcDbObjectId& objId, Adesk::UInt16 nColor);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: ȡ�����õ�AppName
	// Parameters:
	// Returns: ����AppName
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp CString GetTestAppName();
	
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: �ɾ���ַ���ȡʵ��ID
	// Parameters:
	//   lpszHandle             - ����ַ���
	//   objId                  - ʵ��ID
	//   pDatabase              - ָ�����ݿ�
	// Returns: �ɹ�����true�����򷵻�false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp Acad::ErrorStatus GetHandleObjectId(LPCTSTR lpszHandle, AcDbObjectId& objId, AcDbDatabase* pDatabase = NULL);
}
