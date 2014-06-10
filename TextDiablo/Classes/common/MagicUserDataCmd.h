/********************************************************************
	Created Date:	2014/06/08
	Created Time:	11:35
	Last Edit Date:	2014/06/08
	Last Edit Time:	11:35
	Component Name: 技能定义
	Purpose:	 技能属性的定义以及技能字段
*********************************************************************/

#pragma once

#include <memory.h>
#include "BaseDataCmd.h"

#define MAX_RUNE_NUM 5

namespace Cmd{

	//状态类型
	enum eEffectState
	{
		eEffectState_Null = 0,		//无效果
		eEffectState_LearnSkill,		//学习技能
	};

	//状态数据
	struct stEffectData
	{
		int32_t effecttype;	//状态类型 eEffectState
		int32_t val;				//状态值，如果是持续性的话，则为每次触发产生的值或者保持值
		int32_t lasttime;		//持续时间
		int32_t interval;		//间隔时间
		int32_t usetime;		//已经消耗时间

		stEffectData()
		{
			effecttype = eEffectState_Null;
			val = 0;
			lasttime = interval = usetime = 0;
		}
	};

	//符文
	struct stRune
	{
		int32_t id;		//符文ID
		char name[MAX_NAME_LEN];//符文名称
		char describe[MAX_DESCRIBE_LEN];//符文描述
		int32_t icon;			//符文ID
		int32_t needlevel;		//解锁等级
		int32_t effectid;	//状态ID

		stRune()
		{
			id = icon = needlevel = effectid = 0;
			memset(name,0,sizeof(name[0])*MAX_NAME_LEN);
			memset(describe,0,sizeof(describe[0])*MAX_DESCRIBE_LEN);
		}
	};

	//技能类型
	enum eSkillType
	{
		eSkillType_Active = 0,		//主动技能
		eSkillType_Passive,			//被动技能
	};

	//技能
	struct stSkill
	{
		int32_t id;		//技能ID
		char name[MAX_NAME_LEN];//技能名称
		char describe[MAX_DESCRIBE_LEN];//技能描述
		int32_t icon;			//图标ID
		int32_t needlevel;		//解锁等级
		int32_t skillType;		//技能类型 eSkillType
		int32_t attackType;	//伤害类型	eCalcAttackType
		int32_t addWeaponDamage;		//附加武器伤害‰
		int32_t career;			//职业限定
		int32_t effectrate;		//附带状态特效触发几率
		int32_t effectID;		//附带状态ID
		int32_t colddown;		//技能冷却时间
		int32_t energyCost[eEnergyTypeNum];		//能量消耗。如果是负数表示增加能量
		int32_t runeID;		//所选符文ID
		int32_t runeList[MAX_RUNE_NUM];	//可选符文列表

		stSkill()
		{
			id = icon = needlevel = addWeaponDamage = career = effectrate = effectID = colddown = runeID = 0;
			skillType = eSkillType_Active;
			attackType = eAttackType_Phy;
			memset(name,0,sizeof(name[0])*MAX_NAME_LEN);
			memset(describe,0,sizeof(describe[0])*MAX_DESCRIBE_LEN);
			memset(energyCost,0,sizeof(energyCost[0])*eEnergyTypeNum);
			memset(runeList,0,sizeof(runeList[0])*MAX_RUNE_NUM);
		}
	};
	
	//伤害返回结果
	enum eAttackResultType
	{
		eAttackResult_Null = 0,		//无效类型
		eAttackResult_Ignore,		//闪避
		eAttackResult_Block,			//格挡

	};

};