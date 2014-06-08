/********************************************************************
	Created Date:	2014/06/08
	Created Time:	22:30
	Last Edit Date:	2014/06/08
	Last Edit Time:	22:30
	Component Name: ���
	Purpose:	  ���
*********************************************************************/

#pragma once

#include "common/BaseDataCmd.h"
#include "common/ItemUserCmd.h"
#include "common/MagicUserDataCmd.h"
#include "common/MapUserDataCmd.h"


// ��Ʒ������
typedef struct _MakeEquipBase
{
	int32_t ID;	//��ƷID
	char name[MAX_NAME_LEN];		//��Ʒ����
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

}ObjectBase_t;
