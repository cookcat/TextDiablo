/********************************************************************
	Created Date:	2014/06/08
	Created Time:	12:19
	Last Edit Date:	2014/06/08
	Last Edit Time:	12:19
	Component Name: ��ͼ�û����ݶ���
	Purpose:	  ��ͼ�û����ݶ���
*********************************************************************/

#pragma once

#include <vector>

#include "BaseDataCmd.h"
#include "ItemUserCmd.h"
#include "MagicUserDataCmd.h"


#define MAX_USESKILLLIST_NUM 6

namespace Cmd{

	//��������
	struct stBaseProperty
	{
		BYTE byMainBaseProperty;	//4ά����Ҫ����
		int32_t property[eBasePropertyTypeNum];	//�����б�
		stBaseProperty()
		{
			byMainBaseProperty = eBasePropertyType_Str;
			memset(property,0,sizeof(property[0])*eBasePropertyTypeNum);
		}
	};

	//ð������
	struct stAdventureProperty
	{
		int32_t luck;	//����
		int32_t movespeed;	//�ƶ��ٶ�
		int32_t magicEquipDrop;	//ħ��װ��������ʡ�
		int32_t goldDrop;		//��ҵ�����ʡ�
		int32_t goldAdd;		//��һ�ȡ�����ӳɡ�
		int32_t expAdd;	//����ӳ�
		int32_t npcExpAdd;	//ɱ�־���ֵ�ӳɡ�
		stAdventureProperty()
		{
			luck = movespeed = magicEquipDrop = goldDrop = goldAdd = expAdd = npcExpAdd = 0;
		}
	};

	//��������
	struct stAttackProperty 
	{
		BYTE attackMode;
		int32_t basePropDamageAdd[eBasePropertyTypeNum];		//4ά�����˺��ӳɡ�

		int32_t attackSpeed;			//�����ٶȡ�
		int32_t bangRate;				//�������ʡ�
		int32_t bangDamage;		//�����˺���

		int32_t attackDamageAddMin[eAttackTypeNum];	//�����˺���������
		int32_t attackDamageAddMax[eAttackTypeNum];	//�����˺���������

		stAttackProperty()
		{
			attackMode = eAttackMode_Local;
			attackSpeed = bangRate = bangDamage = 0;
			memset(basePropDamageAdd,0,sizeof(basePropDamageAdd[0])*eBasePropertyTypeNum);
			memset(attackDamageAddMin,0,sizeof(attackDamageAddMin[0])*eAttackTypeNum);
			memset(attackDamageAddMax,0,sizeof(attackDamageAddMax[0])*eAttackTypeNum);
		}
	};

	//��������
	struct stDefenceProperty
	{
		int32_t armor;	//����
		int32_t blockDamage;	//��ֵ
		int32_t blockRate;			//�񵲸��ʡ�
		int32_t ignore;				//���ܸ��ʡ�
		int32_t reduce;				//�˺�����
		int32_t attackTypeResistance[eAttackTypeNum];	//�˺����Ϳ���
		int32_t attackModeReduce[eAttackModeNum];		//������ʽ�˺������

		stDefenceProperty()
		{
			armor = blockDamage = blockRate = ignore =reduce =0;
			memset(attackTypeResistance,0,sizeof(attackTypeResistance[0])*eAttackTypeNum);
			memset(attackModeReduce,0,sizeof(attackModeReduce[0])*eAttackModeNum);
		}
	};

	//��������
	struct stHPProperty
	{
		int32_t hp;	//��ǰ����
		int32_t maxhp;		//����ֵ����
		int32_t hpAdd;		//������ֵ�ӳ�
		int32_t recover;	//ÿ�������ظ�
		int32_t leech;		//������Ѫ��
		int32_t killRecover;	//��ɱ�����ָ�
		int32_t hitRecover;	//���������ָ�
		int32_t hpBallAdd;		//����֮��Ч���ӳ�

		stHPProperty()
		{
			hp = maxhp = hpAdd = recover = leech =  killRecover =  hitRecover =  hpBallAdd =0;
		}
	};


	//��ǰ-���-�ظ� ��Ԫ��
	struct stTriValCurMaxRecover
	{
		int32_t val;			//��ǰֵ
		int32_t maxval;	//���ֵ
		int32_t recover;	//�ظ�ֵ
		stTriValCurMaxRecover()
		{
			val = maxval = recover = 0;
		}
	};

	//��������
	struct stEnergyProperty
	{
		stTriValCurMaxRecover energy[eEnergyTypeNum];	//�����б�
	};

	//NPC����
	struct stNpcData
	{
		int id;//NPC ID
		int perfixid;	//ǰ׺ID
		char name[MAX_NAME_LEN];//NPC����
		char describe[MAX_DESCRIBE_LEN];//NPC����

		stBaseProperty baseProperty;					//��������
		stAttackProperty attackProperty;				//��������
		stDefenceProperty defenceProperty;			//��������
		stHPProperty hpProperty;							//��������

		stNpcData()
		{
			id = perfixid = 0;
			memset(name,0,sizeof(name[0])*MAX_NAME_LEN);
			memset(describe,0,sizeof(describe[0])*MAX_DESCRIBE_LEN);
		}
	};


	//��ɫ����
	struct stUserData : stNpcData
	{
		int32_t career;		//ְҵ
		stAdventureProperty adventureProperty;	//ð������

		stItemData equipList[eEquipPositionNum];		//װ������
		stSkill useSkillList[MAX_USESKILLLIST_NUM];	//װ���ļ���
	};


	//��������
	struct stMainUserData : stUserData
	{
		int32_t bagnum;	//����������
		std::vector<stItemData> bag;	//�����б�

		int32_t skillnum;	//��������
		std::vector<stSkill> skillList;	//�����б�
	};

};