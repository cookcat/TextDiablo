/********************************************************************
	Created Date:	2014/06/03
	Created Time:	23:53
	Component Name: �������Զ���
	Purpose:	 �������ԵĶ���
*********************************************************************/

#pragma once

#define MAX_NAME_LEN	16
#define MAX_DESCRIBE_LEN			256

typedef char int8_t;
typedef unsigned char uint8_t;
typedef unsigned char BYTE;

typedef short int16_t;
typedef unsigned short uint16_t;

typedef int int32_t;
typedef unsigned int uint32_t;

namespace Cmd{

	//4ά��������
	enum eBasePropertyType
	{
		eBasePropertyType_Str = 0,		//����
		eBasePropertyType_Dex,			//����
		eBasePropertyType_Inte,			//����
		eBasePropertyType_Vit,				//����

		eBasePropertyTypeNum,			//4ά������Ŀ
	};

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
		int32_t expAdd;	//����ӳɡ�
		int32_t npcExpAdd;	//ɱ�־���ֵ�ӳɡ�
		stAdventureProperty()
		{
			luck = movespeed = magicEquipDrop = goldDrop = goldAdd = expAdd = npcExpAdd = 0;
		}
	};


	//�˺�����
	enum eCalcAttackType
	{
		eAttackType_Phy = 0,		//�����˺�
		eAttackType_Ice,					//���˺�
		eAttackType_Fire,					//���˺�
		eAttackType_Flash,				//���˺�
		eAttackType_Poision,			//���˺�
		eAttackType_Arcane,				//�����˺�
		eAttackType_Holy,				//��ʥ�˺�

		eAttackTypeNum,		//�˺�������Ŀ
	};

	//������ʽ
	enum eAttackMode
	{
		eAttackMode_Local = 0,		//��ս
		eAttackMode_Remote,			//Զ��

		eAttackModeNum,					//������ʽ��Ŀ
	};

	//��������
	struct stAttackProperty 
	{
		BYTE attackMode;
		int32_t basePropDamageAdd[eBasePropertyTypeNum];		//4ά�����˺��ӳɡ�

		int32_t attackSpeed;			//�����ٶ�
		int32_t bangRate;				//��������
		int32_t bangDamage;		//�����˺�

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
		int32_t blockRate;			//�񵲸���
		int32_t dodge;				//���ܸ���
		int32_t reduce;				//�˺�����
		int32_t attackTypeResistance[eAttackTypeNum];	//�˺����Ϳ���
		int32_t attackModeReduce[eAttackModeNum];		//������ʽ�˺�����

		stDefenceProperty()
		{
			armor = blockDamage = blockRate = dodge =reduce =0;
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
		stTriValCurMaxRecover sp;			//����
		stTriValCurMaxRecover xp;			//��������
		stTriValCurMaxRecover mp;			//����
		stTriValCurMaxRecover hate;			//����
		stTriValCurMaxRecover sermon;	//����
		stTriValCurMaxRecover anger;		//ŭ��
	};

	
	//NPC����
	struct stNpcData
	{
		int id;//NPC ID
		int perfixid;	//ǰ׺ID
		char name[MAX_NAME_LEN];//NPC����
		char describe[MAX_DESCRIBE_LEN];//NPC����
	
		stBaseProperty baseProperty;					//��������
		stAdventureProperty adventureProperty;	//ð������
		stAttackProperty attackProperty;				//��������
		stDefenceProperty defenceProperty;			//��������
		stHPProperty hpProperty;							//��������
		stEnergyProperty energyProperty;				//��������

		stNpcData()
		{
			id = perfixid = 0;
			memset(name,0,sizeof(name[0])*MAX_NAME_LEN);
			memset(describe,0,sizeof(describe[0])*MAX_DESCRIBE_LEN);
		}
	};

	//ǰ׺����
	struct stPerfixData
	{
		int id;		//ǰ׺ID
	
	};

	
	

};