#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = NULL;

SpriteManager* SpriteManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new SpriteManager();
	}
	return instance;
}

LPSPRITE SpriteManager::GetSprite(int id)
{
	if (sprites.empty())
	{
		return NULL;
	}
	return sprites[id];
}

void SpriteManager::AddSprite(int id, LPSPRITE sprite)
{
	sprites[id] = sprite;

}

void SpriteManager::AddSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture, int flipX)
{
	LPSPRITE sprite = new Sprite(id, left, top, right, bottom, texture, flipX);
	sprites[id] = sprite;
}

SpriteManager::SpriteManager()
{
	TextureManager * textureManager = TextureManager::GetInstance();
	// Load mario texture
	LPDIRECT3DTEXTURE9 texture = textureManager->GetTexture(100);
	
	// Big Mario run to right
	AddSprite(10001, 246, 154, 260, 181, texture, 1);
	AddSprite(10002, 275, 154, 290, 181, texture, 1);
	AddSprite(10003, 304, 154, 321, 181, texture, 1);
	// Big Mario run to left
	AddSprite(10001, 246, 154, 260, 181, texture, -1);
	AddSprite(10002, 275, 154, 290, 181, texture, -1);
	AddSprite(10003, 304, 154, 321, 181, texture, -1);
	// Big Mario jump right
	AddSprite(10007, 394, 275, 412, 303, texture, 1);
	// Big Mario jump left
	AddSprite(10007, 394, 275, 412, 303, texture, -1);
	// Big Mario switch right
	AddSprite(10009, 4, 154, 22, 181, texture, 1);
	// Big Mario switch left
	AddSprite(10009, 4, 154, 22, 181, texture, -1);
	// background
	/*texture = textureManager->GetTexture(102);
	AddSprite(10201, 0, 240, 255, 432, texture);*/
}