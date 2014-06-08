/********************************************************************
	Created Date:	2014/06/08
	Created Time:	22:30
	Last Edit Date:	2014/06/08
	Last Edit Time:	22:30
	Component Name: 表格
	Purpose:	  表格
*********************************************************************/

#pragma once

#include "common/BaseDataCmd.h"
#include "common/ItemUserCmd.h"
#include "common/MagicUserDataCmd.h"
#include "common/MapUserDataCmd.h"


// 物品基本表
typedef struct _MakeEquipBase
{
	int32_t ID;	//物品ID
	char name[MAX_NAME_LEN];		//物品名称
	int32_t icon;			//图标ID
	BYTE itemType;		//道具类型 eItemType
	BYTE equiptType;			//装备类型 eEquipType
	int32_t pos;				//装备位置 eEquipPosition
	int32_t career;		//职业限制
	int32_t needlevel;		//穿戴等级限制
	int32_t setid;			//套装ID
	int32_t setpos;			//套装位置
	BYTE quality;				//装备品质
	int32_t maxdamage;		//攻击上限
	int32_t mindamage;		//攻击下限
	int32_t armor;				//护甲
	int32_t attackspeed;		//每秒攻击次数
	int32_t durability;			//耐久度
	int32_t sellprice;			//出售售价

	int32_t maxnum;		//堆叠数量
	int32_t cooldown;		//使用后CD时间
	int32_t needblacksmith;		//使用所需铁匠技能等级
	int32_t needjewelry;				//使用所需珠宝技能等级

}ObjectBase_t;
