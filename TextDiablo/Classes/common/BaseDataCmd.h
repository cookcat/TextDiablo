/********************************************************************
	Created Date:	2014/06/03
	Created Time:	23:53
	Last Edit Date:	2014/06/08
	Last Edit Time:	11:35
	Component Name: 基础属性定义
	Purpose:	 基础属性的定义
*********************************************************************/

#pragma once

#define MAX_NAME_LEN	16
#define MAX_DESCRIBE_LEN			256

#define MAX_MAINMAGICPROP_NUM 5
#define MAX_SUBMAGICPROP_NUM 5

typedef unsigned char uint8_t;
typedef unsigned char BYTE;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

namespace Cmd{

	//4维属性类型
	enum eBasePropertyType
	{
		eBasePropertyType_Str = 0,		//力量
		eBasePropertyType_Dex,			//敏捷
		eBasePropertyType_Inte,			//智力
		eBasePropertyType_Vit,				//体力

		eBasePropertyTypeNum,			//4维属性数目
	};

	//伤害类型
	enum eCalcAttackType
	{
		eAttackType_Phy = 0,		//物理伤害
		eAttackType_Ice,					//冰伤害
		eAttackType_Fire,					//火伤害
		eAttackType_Flash,				//雷伤害
		eAttackType_Poision,			//毒伤害
		eAttackType_Arcane,				//奥术伤害
		eAttackType_Holy,				//神圣伤害

		eAttackTypeNum,		//伤害类型数目
	};

	//攻击方式
	enum eAttackMode
	{
		eAttackMode_Local = 0,		//近战
		eAttackMode_Remote,			//远程

		eAttackModeNum,					//攻击方式数目
	};

	//能量类型
	enum eEnergyType
	{
		eEnergyType_SP = 0,		//内力
		eEnergyType_XP,				//奥术能量
		eEnergyType_MP,				//法力
		eEnergyType_Hate,			//憎恨
		eEnergyType_Sermon,		//戒律
		eEnergyType_Anger,			//怒气

		eEnergyTypeNum,		//能量类型数目
	};


	//职业类型
	enum eCareerType
	{
		eCareerType_DemonHunter = 1,		//猎魔人
		eCareerType_Crusader  = 1<<1,		//圣教军
		eCareerType_Wizard = 1<<2,			//魔法师
	};

	//魔法属性类型
	enum eMagicPropertyType
	{
		eMagicPropertyType_Null = 0,	//无属性
		eMagicPropertyType_Str,			//力量增加值
		eMagicPropertyType_Dex,			//敏捷增加值
		eMagicPropertyType_Inte,			//智力增加值
		eMagicPropertyType_Vit,			//体力增加值
		eMagicPropertyType_BangRate,		//暴击几率增加值
		eMagicPropertyType_BangDamage,		//暴击伤害增加值
	};

	//魔法属性数据
	struct stMagicProperty
	{
		int32_t type;		//魔法属性类型	eMagicPropertyType
		int32_t val;		//属性值
		BYTE ismain;		//是否是主要属性

		stMagicProperty()
		{
			type = val = ismain = 0;
		}
	};


};