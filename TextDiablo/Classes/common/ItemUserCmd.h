/********************************************************************
	Created Date:	2014/06/08
	Created Time:	11:35
	Last Edit Date:	2014/06/08
	Last Edit Time:	11:35
	Component Name: 道具装备定义
	Purpose:	  道具装备属性的定义以及 道具装备字段
*********************************************************************/

#pragma once

#include "BaseDataCmd.h"
#include "MagicUserDataCmd.h"

namespace Cmd{

	//道具类型
	enum eItemType
	{
		eItemType_Equip = 0,			//装备
		eItemType_Gem,					//宝石
		eItemType_Drug,					//药物
		eItemType_Material,				//材料
		eItemType_BlacksmithPlan,	//铁匠图纸
		eItemType_JewelerDesign,	//珠宝图纸
		eItemType_Other,					//其他
	};

	//品质定义
	enum eQualityType
	{
		eQualityType_Null = 0,	//无品质
		eQualityType_Level1,
		eQualityType_Gray = eQualityType_Level1,
		eQualityType_Level2,
		eQualityType_White = eQualityType_Level2,
		eQualityType_Level3,
		eQualityType_Blue = eQualityType_Level3,
		eQualityType_Level4,
		eQualityType_Yellow = eQualityType_Level4,
		eQualityType_Level5,
		eQualityType_Green = eQualityType_Level5,
		eQualityType_Level6,
		eQualityType_Holy = eQualityType_Level6,
	};

	//装备类型
	enum eEquipType
	{
		eEquipType_Null = 0,		//无效类型
		eEquipType_WeaponOneHand,		//单手主武器
		eEquipType_WeaponTwoHand,		//双手近战武器
		eEquipTypeNum,	//装备类型数目
	};

	//装备位置类型
	enum eEquipPosition
	{
		eEquipPosition_Null = 0, //无效位置
		eEquipPosition_Head = 1,		//头盔
		eEquipPosition_Necklace = 1<<1,		//项链
		eEquipPostion_Shoulder = 1<<2,		//肩部
		eEquipPosition_Body = 1<<3,		//身躯
		eEquipPosition_Wrist = 1<<4,		//手腕
		eEquipPosition_HandMain = 1<<5,	//主手
		eEquipPosition_HandSub = 1<<6,	//副手
		eEquipPosition_RingMain  = 1<<7,			//主手戒指
		eEquipPosition_RingSub  = 1<<8,			//副手戒指
		eEquipPosition_Waist = 1<<9,		//腰部
		eEquipPosition_Leg = 1<<10,			//腿部
		eEquipPosition_Shoe = 1<<11,			//脚部

		eEquipPositionNum = 11,  //装备位置数目
	};

	//道具数据
	struct stItemData
	{
		uint32_t thisID;		//临时ID
		int32_t id;		//道具ID
		char name[MAX_NAME_LEN];		//装备名称
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
		Cmd::stEffectData effect;			//使用效果

		int32_t mainMagicNum;		//主魔法属性数目
		stMagicProperty mainMagicProperty[MAX_MAINMAGICPROP_NUM];	//主魔法属性
		int32_t subMagicNum;		//附加魔法属性数目
		stMagicProperty subMagicProperty[MAX_SUBMAGICPROP_NUM];		//附加魔法属性

		stItemData()
		{
			id = icon = itemType = equiptType = pos = career = needlevel = setid = setpos = quality = 
				maxdamage = mindamage = armor = attackspeed = durability = sellprice =
				maxnum = cooldown = needblacksmith = needjewelry = mainMagicNum = subMagicNum = 0;
		}
	};


	
};