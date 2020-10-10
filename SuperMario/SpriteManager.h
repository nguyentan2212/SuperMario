#pragma once
#include "Sprite.h"
#include <unordered_map>
#include "Debug.h"

using namespace std;

class SpriteManager
{
public:
	SpriteManager() { }
	static SpriteManager* GetInstance();
	LPSPRITE GetSprite(int id);
	void AddSprite(int id, LPSPRITE sprite);
	void AddSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture);

private:
	static SpriteManager* instance;
	unordered_map<int, LPSPRITE> sprites;
};

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
