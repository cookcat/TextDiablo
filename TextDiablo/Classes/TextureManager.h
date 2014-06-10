/********************************************************************
	Created Date:	2014/06/11
	Created Time:	01:48
	Last Edit Date:	2014/06/11
	Last Edit Time:	01:48
	Component Name: ���������
	Purpose:	 ��������������ڹ���������ͼ
*********************************************************************/
#include "cocos2d.h"
#include "Singleton.h"

using namespace cocos2d;

class CTextureManager : public Singleton<CTextureManager>
{
public:
	CTextureManager(void);
	~CTextureManager(void);

	//��ȡ����
	Texture2D* GetTexture(const char* resType, int resSubID);
	//�ͷ�����
	void ReleaseTexture(const char* resType, int resSubID);

	//��ȡ֡
	SpriteFrame *GetSpriteFrame(const char* resType, int resSubID);

	//��ȡ����
	Sprite *GetSprite(const char* resType, int resSubID);

private:


};