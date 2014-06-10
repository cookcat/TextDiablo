#include "public.h"
#include "TextureManager.h"

using namespace cocos2d;
using namespace CocosDenshion;


CTextureManager::CTextureManager( void )
{

}

CTextureManager::~CTextureManager( void )
{

}

Texture2D* CTextureManager::GetTexture(const char* resType, int resSubID)
{
	char strFile[255];
	sprintf(strFile,"image/%s/%04d.png",resType,resSubID);
	CCLOG(strFile);
	if (FileUtils::getInstance()->isFileExist(strFile))
	{
		return TextureCache::getInstance()->addImage(strFile);
	}
	else
	{
		return NULL;
	}
}

void CTextureManager::ReleaseTexture(const char* resType, int resSubID)
{
	char strFile[255];
	sprintf(strFile,"image/%s/%04d.png",resType,resSubID);

	TextureCache::getInstance()->removeTextureForKey(strFile);
}

SpriteFrame * CTextureManager::GetSpriteFrame(const char* resType, int resSubID)
{
	Texture2D *pTexture = GetTexture(resType,resSubID);
	if (pTexture)
	{
		SpriteFrame* pSpriteFrame = SpriteFrame::createWithTexture(pTexture,CCRectMake(0,0,pTexture->getContentSize().width,pTexture->getContentSize().height));
		return pSpriteFrame;
	}
	else
	{
		return NULL;
	}
}

Sprite * CTextureManager::GetSprite(const char* resType, int resSubID)
{
	Texture2D *pTexture = GetTexture(resType,resSubID);
	if (pTexture)
	{
		return Sprite::createWithTexture(pTexture);
	}
	else
	{
		return NULL;
	}
}