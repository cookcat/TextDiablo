/********************************************************************
	Created Date:	2014/06/03
	Created Time:	23:41
	Component Name: 计算管理器
	Purpose:	 计算管理器组件。使用此组件可以完成伤害流程计算
*********************************************************************/

#pragma once

#include "cocos2d.h"

#include "Singleton.h"
#include "public.h"

using namespace cocos2d;

class CCalcManager : public Singleton<CCalcManager>
{
public:
	CCalcManager(void);
	~CCalcManager(void);

};