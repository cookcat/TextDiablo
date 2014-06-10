/********************************************************************
	Created Date:	2014/06/08
	Created Time:	12:19
	Last Edit Date:	2014/06/08
	Last Edit Time:	12:19
	Component Name: 地图用户数据定义
	Purpose:	  地图用户数据定义
*********************************************************************/

#pragma once

#include <vector>

#include "BaseDataCmd.h"
#include "ItemUserCmd.h"
#include "MagicUserDataCmd.h"


#define MAX_USESKILLLIST_NUM 6

namespace Cmd{

	//基础属性
	struct stBaseProperty
	{
		BYTE byMainBaseProperty;	//4维的主要属性
		int32_t property[eBasePropertyTypeNum];	//属性列表
		stBaseProperty()
		{
			byMainBaseProperty = eBasePropertyType_Str;
			memset(property,0,sizeof(property[0])*eBasePropertyTypeNum);
		}
	};

	//冒险属性
	struct stAdventureProperty
	{
		int32_t luck;	//幸运
		int32_t movespeed;	//移动速度
		int32_t magicEquipDrop;	//魔法装备掉落概率‰
		int32_t goldDrop;		//金币掉落概率‰
		int32_t goldAdd;		//金币获取数量加成‰
		int32_t expAdd;	//经验加成
		int32_t npcExpAdd;	//杀怪经验值加成‰
		stAdventureProperty()
		{
			luck = movespeed = magicEquipDrop = goldDrop = goldAdd = expAdd = npcExpAdd = 0;
		}
	};

	//攻击属性
	struct stAttackProperty 
	{
		BYTE attackMode;
		int32_t basePropDamageAdd[eBasePropertyTypeNum];		//4维属性伤害加成‰

		int32_t attackSpeed;			//攻击速度‰
		int32_t bangRate;				//暴击概率‰
		int32_t bangDamage;		//暴击伤害‰

		int32_t attackDamageAddMin[eAttackTypeNum];	//附加伤害类型下限
		int32_t attackDamageAddMax[eAttackTypeNum];	//附加伤害类型上限

		stAttackProperty()
		{
			attackMode = eAttackMode_Local;
			attackSpeed = bangRate = bangDamage = 0;
			memset(basePropDamageAdd,0,sizeof(basePropDamageAdd[0])*eBasePropertyTypeNum);
			memset(attackDamageAddMin,0,sizeof(attackDamageAddMin[0])*eAttackTypeNum);
			memset(attackDamageAddMax,0,sizeof(attackDamageAddMax[0])*eAttackTypeNum);
		}
	};

	//防御属性
	struct stDefenceProperty
	{
		int32_t armor;	//护甲
		int32_t blockDamage;	//格挡值
		int32_t blockRate;			//格挡概率‰
		int32_t ignore;				//闪避概率‰
		int32_t reduce;				//伤害减免
		int32_t attackTypeResistance[eAttackTypeNum];	//伤害类型抗性
		int32_t attackModeReduce[eAttackModeNum];		//攻击方式伤害减免‰

		stDefenceProperty()
		{
			armor = blockDamage = blockRate = ignore =reduce =0;
			memset(attackTypeResistance,0,sizeof(attackTypeResistance[0])*eAttackTypeNum);
			memset(attackModeReduce,0,sizeof(attackModeReduce[0])*eAttackModeNum);
		}
	};

	//生命属性
	struct stHPProperty
	{
		int32_t hp;	//当前生命
		int32_t maxhp;		//生命值上限
		int32_t hpAdd;		//总生命值加成
		int32_t recover;	//每秒生命回复
		int32_t leech;		//攻击吸血‰
		int32_t killRecover;	//击杀生命恢复
		int32_t hitRecover;	//命中生命恢复
		int32_t hpBallAdd;		//生命之球效果加成

		stHPProperty()
		{
			hp = maxhp = hpAdd = recover = leech =  killRecover =  hitRecover =  hpBallAdd =0;
		}
	};


	//当前-最大-回复 三元组
	struct stTriValCurMaxRecover
	{
		int32_t val;			//当前值
		int32_t maxval;	//最大值
		int32_t recover;	//回复值
		stTriValCurMaxRecover()
		{
			val = maxval = recover = 0;
		}
	};

	//人物能量
	struct stEnergyProperty
	{
		stTriValCurMaxRecover energy[eEnergyTypeNum];	//能量列表
	};

	//NPC数据
	struct stNpcData
	{
		int id;//NPC ID
		int perfixid;	//前缀ID
		char name[MAX_NAME_LEN];//NPC名称
		char describe[MAX_DESCRIBE_LEN];//NPC描述

		stBaseProperty baseProperty;					//基础属性
		stAttackProperty attackProperty;				//攻击属性
		stDefenceProperty defenceProperty;			//防御属性
		stHPProperty hpProperty;							//生命属性

		stNpcData()
		{
			id = perfixid = 0;
			memset(name,0,sizeof(name[0])*MAX_NAME_LEN);
			memset(describe,0,sizeof(describe[0])*MAX_DESCRIBE_LEN);
		}
	};


	//角色数据
	struct stUserData : stNpcData
	{
		int32_t career;		//职业
		stAdventureProperty adventureProperty;	//冒险属性

		stItemData equipList[eEquipPositionNum];		//装备格子
		stSkill useSkillList[MAX_USESKILLLIST_NUM];	//装备的技能
	};


	//主角数据
	struct stMainUserData : stUserData
	{
		int32_t bagnum;	//背包格子数
		std::vector<stItemData> bag;	//背包列表

		int32_t skillnum;	//技能总数
		std::vector<stSkill> skillList;	//技能列表
	};

};