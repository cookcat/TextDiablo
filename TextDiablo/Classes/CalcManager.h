/********************************************************************
	Created Date:	2014/06/03
	Created Time:	23:41
	Component Name: ���������
	Purpose:	 ��������������ʹ�ô������������˺����̼���
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