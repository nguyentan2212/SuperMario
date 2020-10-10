#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class Sprite
{
public:
	Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture);
	void Draw(float x, float y);
	~Sprite() { delete texture; }
private:
	int id;				// Sprite ID in the sprite database

	int left;
	int top;
	int right;
	int bottom;

	LPDIRECT3DTEXTURE9 texture;
};

typedef Sprite* LPSPRITE;