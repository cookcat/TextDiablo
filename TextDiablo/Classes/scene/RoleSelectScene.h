/********************************************************************
	Created Date:	2014/06/11
	Created Time:	00:48
	Last Edit Date:	2014/06/11
	Last Edit Time:	00:48
	Component Name: ѡ�˽���
	Purpose:	 ѡ��ְҵ
*********************************************************************/

#pragma once

#include "cocos2d.h"
#include "public.h"

using namespace cocos2d;

class CRoleSelectScene : public Scene
{
public:
	enum emLayerDefine
	{
		eLayer_Back = 0,
	};

	CRoleSelectScene();

	bool init();


    CREATE_FUNC(CRoleSelectScene);
};
