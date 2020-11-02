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
	AddSprite(10001, 245, 153, 260, 181, texture);
	AddSprite(10002, 274, 153, 290, 181, texture);
	AddSprite(10003, 304, 153, 321, 181, texture);
	// Big Mario run to left
	AddSprite(10004, 185, 153, 200, 181, texture);
	AddSprite(10005, 155, 153, 171, 181, texture);
	AddSprite(10006, 124, 153, 141, 181, texture);
	// Big Mario jump right
	AddSprite(10007, 394, 274, 411, 301, texture);
	// Big Mario jump left
	AddSprite(10008, 34, 274, 51, 301, texture);
	// Big Mario switch to right
	AddSprite(10009, 424, 153, 441, 182, texture);
	// Big Mario switch to left
	AddSprite(10010, 4, 153, 22, 182, texture);
	// Small Mario run to right
	AddSprite(10011, 246, 0, 259, 15, texture);
	AddSprite(10012, 274, 0, 291, 16, texture);
	AddSprite(10013, 305, 0, 321, 16, texture);
	// Small Mario run to left
	AddSprite(10014, 186, 0, 199, 15, texture);
	AddSprite(10015, 154, 0, 171, 16, texture);
	AddSprite(10016, 124, 0, 140, 16, texture);
	// Small Mario jump right
	AddSprite(10017, 394, 39, 411, 56, texture);
	// Small Mario jump left
	AddSprite(10018, 34, 39, 51, 56, texture);
	// Small Mario switch right
	AddSprite(10019, 425, 0, 440, 16, texture);
	// Small Mario switch left
	AddSprite(10020, 5, 0, 20, 16, texture);
	// Goomba 
	texture = textureManager->GetTexture(103);
	AddSprite(10301, 0, 0, 16, 16, texture);
	AddSprite(10302, 16, 0, 32, 16, texture);
	AddSprite(10303, 33, 0, 48, 16, texture);
	AddSprite(10304, 49, 0, 56, 16, texture);

	DebugOut(L"[INFO] Sprites loaded Ok.\n");
}