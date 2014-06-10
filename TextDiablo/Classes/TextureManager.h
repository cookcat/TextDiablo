/********************************************************************
	Created Date:	2014/06/11
	Created Time:	01:48
	Last Edit Date:	2014/06/11
	Last Edit Time:	01:48
	Component Name: 纹理管理器
	Purpose:	 纹理管理器，用于管理纹理贴图
*********************************************************************/
#include "cocos2d.h"
#include "Singleton.h"

using namespace cocos2d;

class CTextureManager : public Singleton<CTextureManager>
{
public:
	CTextureManager(void);
	~CTextureManager(void);

	//获取纹理
	Texture2D* GetTexture(const char* resType, int resSubID);
	//释放纹理
	void ReleaseTexture(const char* resType, int resSubID);

	//获取帧
	SpriteFrame *GetSpriteFrame(const char* resType, int resSubID);

	//获取精灵
	Sprite *GetSprite(const char* resType, int resSubID);

private:


};