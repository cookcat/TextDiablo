/********************************************************************
	Created Date:	2014/06/03
	Created Time:	23:53
	Last Edit Date:	2014/06/08
	Last Edit Time:	11:35
	Component Name: �������Զ���
	Purpose:	 �������ԵĶ���
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

	//4ά��������
	enum eBasePropertyType
	{
		eBasePropertyType_Str = 0,		//����
		eBasePropertyType_Dex,			//����
		eBasePropertyType_Inte,			//����
		eBasePropertyType_Vit,				//����

		eBasePropertyTypeNum,			//4ά������Ŀ
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
	enum eEnergyType
	{
		eEnergyType_SP = 0,		//����
		eEnergyType_XP,				//��������
		eEnergyType_MP,				//����
		eEnergyType_Hate,			//����
		eEnergyType_Sermon,		//����
		eEnergyType_Anger,			//ŭ��

		eEnergyTypeNum,		//����������Ŀ
	};


	//ְҵ����
	enum eCareerType
	{
		eCareerType_DemonHunter = 1,		//��ħ��
		eCareerType_Crusader  = 1<<1,		//ʥ�̾�
		eCareerType_Wizard = 1<<2,			//ħ��ʦ
	};

	//ħ����������
	enum eMagicPropertyType
	{
		eMagicPropertyType_Null = 0,	//������
		eMagicPropertyType_Str,			//��������ֵ
		eMagicPropertyType_Dex,			//��������ֵ
		eMagicPropertyType_Inte,			//��������ֵ
		eMagicPropertyType_Vit,			//��������ֵ
		eMagicPropertyType_BangRate,		//������������ֵ
		eMagicPropertyType_BangDamage,		//�����˺�����ֵ
	};

	//ħ����������
	struct stMagicProperty
	{
		int32_t type;		//ħ����������	eMagicPropertyType
		int32_t val;		//����ֵ
		BYTE ismain;		//�Ƿ�����Ҫ����

		stMagicProperty()
		{
			type = val = ismain = 0;
		}
	};


};