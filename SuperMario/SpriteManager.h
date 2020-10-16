#pragma once
#include "Sprite.h"
#include <unordered_map>
#include "Debug.h"
#include "TextureManager.h"

using namespace std;

class SpriteManager
{
public:
	SpriteManager();
	static SpriteManager* GetInstance();
	LPSPRITE GetSprite(int id);
	void AddSprite(int id, LPSPRITE sprite);
	void AddSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture, int flipX = 1);

private:
	static SpriteManager* instance;
	unordered_map<int, LPSPRITE> sprites;
};