// TestCore.h: 测试方法
#pragma once

// 测试函数命名空间
namespace TestCore
{
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试点的位置
	// Parameters:
	//   ptCenter               - 圆心
	//   radius                 - 半径
	//   nColor                 - 颜色
	//   objId                  - 返回实体id
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp Acad::ErrorStatus TestPoint3d(const AcGePoint3d& ptCenter, double radius = 2.0, Adesk::UInt16 nColor = 2);
	NeArxTestExp Acad::ErrorStatus TestPoint2d(const AcGePoint2d& ptCenter, double radius = 2.0, Adesk::UInt16 nColor = 2);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试点组位置
	// Parameters:
	//   ptList                 - 点组
	//   radius                 - 半径
	//   nColor                 - 颜色
	//   bVariableColor         - true:使用升序颜色;false,使用相同颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestPoint3dArray(const AcGePoint3dArray& ptList, double radius = 2.0, Adesk::UInt16 nColor = 1, bool bVariableColor = false);
	NeArxTestExp bool TestPoint2dArray(const AcGePoint2dArray& ptList, double radius = 2.0, Adesk::UInt16 nColor = 1, bool bVariableColor = false);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试点组，绘制为轻量多段线
	// Parameters:
	//   ptList                 - 点组
	//   nColor                 - 颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestPointsAsPolyline(const AcGePoint2dArray& ptList, Adesk::UInt16 nColor = 251, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试点组，绘制为三维多段线
	// Parameters:
	//   ptList                 - 三维点组
	//   nColor                 - 颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestPointsAs3dPolyline(const AcGePoint3dArray& ptList, Adesk::UInt16 nColor = 251, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 取三维多段线的顶点
	// Parameters:
	//   pLine                  - 多段线
	//   ptsVertex              - 返回三维点组
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool Get3dPolylineVertexes(AcDb3dPolyline* pLine, AcGePoint3dArray& ptsVertex);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试实体的位置
	// Parameters:
	//   pEnt                   - 需要测试的实体
	//   nColor                 - 颜色(257表示使用实体自身的颜色)
	//   vec                    - 测试向量
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestEntity(const AcDbEntity* pEnt, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试多个实体
	// Parameters:
	//   ptrEnts                - 实体指针
	//   nColor                 - 颜色
	//   vec                    - 测试向量
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestEntities(const AcArray<AcDbEntity*>& ptrEnts, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);
	NeArxTestExp bool TestEntitys(const AcDbVoidPtrArray& ptrEnts, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// 测试实体ID
	NeArxTestExp bool TestEntId(const AcDbObjectId& objId, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// 测试实体数组
	NeArxTestExp bool TestEntIds(const AcDbObjectIdArray& objIds, Adesk::UInt16 nColor = 257, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试向量
	// Note: 如果想要箭头使用随机夹角,则最好在循环外部使用随机种子; 随机种子例如: srand((unsigned int)time(NULL));
	// Note: rand()方法产生的是伪随机数
	// Parameters:
	//   ptBase                 - 向量基点
	//   vecDir                 - 指定向量
	//   nColor                 - 颜色
	//   bArrowRandom           - true,箭头使用随机夹角; false,箭头使用固定夹角
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestVector2d(const AcGePoint2d& ptBase, const AcGeVector2d& vecDir, Adesk::UInt16 nColor = 2, bool bArrowRandom = false);
	NeArxTestExp bool TestVector3d(const AcGePoint3d& ptBase, const AcGeVector3d& vecDir, Adesk::UInt16 nColor = 2, bool bArrowRandom = false);
	NeArxTestExp bool TestDirection(const AcGePoint2d& ptBase, double dDirection, double dScaleing = 1.0, Adesk::UInt16 nColor = 2, bool bArrowRandom = false);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试线段
	// Parameters:
	//   lineSeg                - 线段
	//   nColor                 - 颜色
	//   vec                    - 测试向量
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestLineSeg2d(const AcGeLineSeg2d& lineSeg, Adesk::UInt16 nColor = 2, const AcGeVector3d& vec = AcGeVector3d::kIdentity);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试直线
	// Parameters:
	//   ptStart                - 起点
	//   ptEnd                  - 终点
	//   nColor                 - 颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestLine2d(const AcGePoint2d& ptStart, const AcGePoint2d& ptEnd, Adesk::UInt16 nColor = 2);
	NeArxTestExp bool TestLine3d(const AcGePoint3d& ptStart, const AcGePoint3d& ptEnd, Adesk::UInt16 nColor = 2);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 测试矩形框
	// Parameters:
	//   ext                    - 矩形框
	//   nColor                 - 颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool TestExtent(const AcDbExtents& ext, Adesk::UInt16 nColor = 2);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 清除测试实体
	// Parameters:
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool ClearTestEnt();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 为实体标记扩展数据(测试App)
	// Parameters:
	//   pObj                   - 实体指针
	//   lpszMark               - 自定义数据
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool SetObjectForTest(AcDbEntity* pEntity, LPCTSTR lpszMark = NULL);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 暂停(实际上是要求输入关键字)
	// Note: 输入参数未空时崩溃?...擦嘞...
	// Parameters:
	//   lpszPrompt             - 输入参数
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool SetPause(LPCTSTR lpszPrompt = _T("Anykey to continue or[P to Pass]:"),...);
	NeArxTestExp void UnPass();

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 重设实体的颜色
	// Parameters:
	//   objId                  - 实体ID
	//   nColor                 - 颜色
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp bool ResetEntityColor(const AcDbObjectId& objId, Adesk::UInt16 nColor);

	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 取测试用的AppName
	// Parameters:
	// Returns: 返回AppName
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp CString GetTestAppName();
	
	// ------------------------------------------------------------------------------------------------------------------------
	// Summary: 由句柄字符串取实体ID
	// Parameters:
	//   lpszHandle             - 句柄字符串
	//   objId                  - 实体ID
	//   pDatabase              - 指定数据库
	// Returns: 成功返回true，否则返回false
	// ------------------------------------------------------------------------------------------------------------------------
	NeArxTestExp Acad::ErrorStatus GetHandleObjectId(LPCTSTR lpszHandle, AcDbObjectId& objId, AcDbDatabase* pDatabase = NULL);
}
