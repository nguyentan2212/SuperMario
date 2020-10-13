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

void SpriteManager::AddSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture)
{
	LPSPRITE sprite = new Sprite(id, left, top, right, bottom, texture);
	sprites[id] = sprite;
}

SpriteManager::SpriteManager()
{
	TextureManager * textureManager = TextureManager::GetInstance();
	// Load mario texture
	LPDIRECT3DTEXTURE9 texture = textureManager->GetTexture(100);
	
	// Big Mario run to right
	AddSprite(10001, 246, 154, 260, 181, texture);
	AddSprite(10002, 275, 154, 290, 181, texture);
	AddSprite(10003, 304, 154, 321, 181, texture);
	// Big Mario run to left
	AddSprite(10004, 186, 154, 200, 181, texture);
	AddSprite(10005, 155, 154, 170, 181, texture);
	AddSprite(10006, 125, 154, 140, 181, texture);
	// Big Mario jump right
	AddSprite(10007, 394, 275, 412, 303, texture);
	// Big Mario jump left
	AddSprite(10008, 34, 275, 52, 303, texture);
	// Big Mario switch right
	AddSprite(10009, 4, 154, 22, 181, texture);
	// Big Mario switch left
	AddSprite(10010, 424, 154, 442, 181, texture);
	// background
	texture = textureManager->GetTexture(102);
	AddSprite(10201, 0, 240, 255, 432, texture);
}