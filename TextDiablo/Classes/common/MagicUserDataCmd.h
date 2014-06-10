/********************************************************************
	Created Date:	2014/06/08
	Created Time:	11:35
	Last Edit Date:	2014/06/08
	Last Edit Time:	11:35
	Component Name: ���ܶ���
	Purpose:	 �������ԵĶ����Լ������ֶ�
*********************************************************************/

#pragma once

#include <memory.h>
#include "BaseDataCmd.h"

#define MAX_RUNE_NUM 5

namespace Cmd{

	//״̬����
	enum eEffectState
	{
		eEffectState_Null = 0,		//��Ч��
		eEffectState_LearnSkill,		//ѧϰ����
	};

	//״̬����
	struct stEffectData
	{
		int32_t effecttype;	//״̬���� eEffectState
		int32_t val;				//״ֵ̬������ǳ����ԵĻ�����Ϊÿ�δ���������ֵ���߱���ֵ
		int32_t lasttime;		//����ʱ��
		int32_t interval;		//���ʱ��
		int32_t usetime;		//�Ѿ�����ʱ��

		stEffectData()
		{
			effecttype = eEffectState_Null;
			val = 0;
			lasttime = interval = usetime = 0;
		}
	};

	//����
	struct stRune
	{
		int32_t id;		//����ID
		char name[MAX_NAME_LEN];//��������
		char describe[MAX_DESCRIBE_LEN];//��������
		int32_t icon;			//����ID
		int32_t needlevel;		//�����ȼ�
		int32_t effectid;	//״̬ID

		stRune()
		{
			id = icon = needlevel = effectid = 0;
			memset(name,0,sizeof(name[0])*MAX_NAME_LEN);
			memset(describe,0,sizeof(describe[0])*MAX_DESCRIBE_LEN);
		}
	};

	//��������
	enum eSkillType
	{
		eSkillType_Active = 0,		//��������
		eSkillType_Passive,			//��������
	};

	//����
	struct stSkill
	{
		int32_t id;		//����ID
		char name[MAX_NAME_LEN];//��������
		char describe[MAX_DESCRIBE_LEN];//��������
		int32_t icon;			//ͼ��ID
		int32_t needlevel;		//�����ȼ�
		int32_t skillType;		//�������� eSkillType
		int32_t attackType;	//�˺�����	eCalcAttackType
		int32_t addWeaponDamage;		//���������˺���
		int32_t career;			//ְҵ�޶�
		int32_t effectrate;		//����״̬��Ч��������
		int32_t effectID;		//����״̬ID
		int32_t colddown;		//������ȴʱ��
		int32_t energyCost[eEnergyTypeNum];		//�������ġ�����Ǹ�����ʾ��������
		int32_t runeID;		//��ѡ����ID
		int32_t runeList[MAX_RUNE_NUM];	//��ѡ�����б�

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
	
	//�˺����ؽ��
	enum eAttackResultType
	{
		eAttackResult_Null = 0,		//��Ч����
		eAttackResult_Ignore,		//����
		eAttackResult_Block,			//��

	};

};