#include "RoleSelectScene.h"
#include "TextureManager.h"

CRoleSelectScene::CRoleSelectScene()
{
}

bool CRoleSelectScene::init()
{
	Size winSize = Director::sharedDirector()->getWinSize();

	//±³¾°²ã
	Layer *pLayerBack = Layer::create();
	this->addChild(pLayerBack,eLayer_Back,eLayer_Back);
	
	Sprite *pSpriteBackGround = CTextureManager::instance().GetSprite("ui",1);
	if (pSpriteBackGround)
	{
		pLayerBack->addChild(pSpriteBackGround);
		pSpriteBackGround->setPosition(winSize.width / 2, winSize.height / 2);

	}
	

	return true;
} 