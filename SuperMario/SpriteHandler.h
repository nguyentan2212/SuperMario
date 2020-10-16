#pragma once
#include <d3dx9.h>
#include "Camera.h"

class SpriteHandler
{
public:
	SpriteHandler();	
	~SpriteHandler();
	void SetTranform(D3DXMATRIX matScale);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT resource);
	static SpriteHandler* GetInstance();
	LPD3DXSPRITE spriteHandler = NULL;

private:
	
	static SpriteHandler* instance;
};

typedef SpriteHandler* LPSPRITEHANDLER;


