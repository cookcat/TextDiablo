/********************************************************************
	Created Date:	2014/06/08
	Created Time:	22:30
	Last Edit Date:	2014/06/08
	Last Edit Time:	22:30
	Component Name: ��������
	Purpose:	  ��������
*********************************************************************/

#pragma once

#include "Table.h"

#include "Singleton.h"

class CTableManager : public Singleton<CTableManager>
{
public:
	CTableManager(void);
	~CTableManager(void);

	void init();


private:

};
