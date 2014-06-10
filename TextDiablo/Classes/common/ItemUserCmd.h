/********************************************************************
	Created Date:	2014/06/08
	Created Time:	11:35
	Last Edit Date:	2014/06/08
	Last Edit Time:	11:35
	Component Name: ����װ������
	Purpose:	  ����װ�����ԵĶ����Լ� ����װ���ֶ�
*********************************************************************/

#pragma once

#include "BaseDataCmd.h"
#include "MagicUserDataCmd.h"

namespace Cmd{

	//��������
	enum eItemType
	{
		eItemType_Equip = 0,			//װ��
		eItemType_Gem,					//��ʯ
		eItemType_Drug,					//ҩ��
		eItemType_Material,				//����
		eItemType_BlacksmithPlan,	//����ͼֽ
		eItemType_JewelerDesign,	//�鱦ͼֽ
		eItemType_Other,					//����
	};

	//Ʒ�ʶ���
	enum eQualityType
	{
		eQualityType_Null = 0,	//��Ʒ��
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

	//װ������
	enum eEquipType
	{
		eEquipType_Null = 0,		//��Ч����
		eEquipType_WeaponOneHand,		//����������
		eEquipType_WeaponTwoHand,		//˫�ֽ�ս����
		eEquipTypeNum,	//װ��������Ŀ
	};

	//װ��λ������
	enum eEquipPosition
	{
		eEquipPosition_Null = 0, //��Чλ��
		eEquipPosition_Head = 1,		//ͷ��
		eEquipPosition_Necklace = 1<<1,		//����
		eEquipPostion_Shoulder = 1<<2,		//�粿
		eEquipPosition_Body = 1<<3,		//����
		eEquipPosition_Wrist = 1<<4,		//����
		eEquipPosition_HandMain = 1<<5,	//����
		eEquipPosition_HandSub = 1<<6,	//����
		eEquipPosition_RingMain  = 1<<7,			//���ֽ�ָ
		eEquipPosition_RingSub  = 1<<8,			//���ֽ�ָ
		eEquipPosition_Waist = 1<<9,		//����
		eEquipPosition_Leg = 1<<10,			//�Ȳ�
		eEquipPosition_Shoe = 1<<11,			//�Ų�

		eEquipPositionNum = 11,  //װ��λ����Ŀ
	};

	//��������
	struct stItemData
	{
		uint32_t thisID;		//��ʱID
		int32_t id;		//����ID
		char name[MAX_NAME_LEN];		//װ������
		int32_t icon;			//ͼ��ID
		BYTE itemType;		//�������� eItemType
		BYTE equiptType;			//װ������ eEquipType
		int32_t pos;				//װ��λ�� eEquipPosition
		int32_t career;		//ְҵ����
		int32_t needlevel;		//�����ȼ�����
		int32_t setid;			//��װID
		int32_t setpos;			//��װλ��
		BYTE quality;				//װ��Ʒ��
		int32_t maxdamage;		//��������
		int32_t mindamage;		//��������
		int32_t armor;				//����
		int32_t attackspeed;		//ÿ�빥������
		int32_t durability;			//�;ö�
		int32_t sellprice;			//�����ۼ�

		int32_t maxnum;		//�ѵ�����
		int32_t cooldown;		//ʹ�ú�CDʱ��
		int32_t needblacksmith;		//ʹ�������������ܵȼ�
		int32_t needjewelry;				//ʹ�������鱦���ܵȼ�
		Cmd::stEffectData effect;			//ʹ��Ч��

		int32_t mainMagicNum;		//��ħ��������Ŀ
		stMagicProperty mainMagicProperty[MAX_MAINMAGICPROP_NUM];	//��ħ������
		int32_t subMagicNum;		//����ħ��������Ŀ
		stMagicProperty subMagicProperty[MAX_SUBMAGICPROP_NUM];		//����ħ������

		stItemData()
		{
			id = icon = itemType = equiptType = pos = career = needlevel = setid = setpos = quality = 
				maxdamage = mindamage = armor = attackspeed = durability = sellprice =
				maxnum = cooldown = needblacksmith = needjewelry = mainMagicNum = subMagicNum = 0;
		}
	};


	
};