#include "Sprite.h"
#include "SpriteHandler.h"
#include "GameDefine.h"

Sprite::Sprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture, int flipX)
{
	this->id = id;
	this->left = left;
	this->top = top;
	this->right = right;
	this->bottom = bottom;
	this->flipX = flipX;
	this->texture = texture;
}

void Sprite::Draw(float x, float y)
{
	if (this == NULL)
	{
		return;
	}

	SpriteHandler::GetInstance()->Draw(x, y, texture, left, top, right, bottom);
}
