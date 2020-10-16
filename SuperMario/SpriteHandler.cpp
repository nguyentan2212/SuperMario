#include "SpriteHandler.h"

SpriteHandler* SpriteHandler::instance = NULL;

SpriteHandler::SpriteHandler()
{
	
}

SpriteHandler::~SpriteHandler()
{
	if (spriteHandler != NULL) spriteHandler->Release();
}

void SpriteHandler::SetTranform(D3DXMATRIX matScale)
{
	spriteHandler->SetTransform(&matScale);
}

void SpriteHandler::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom)
{
	RECT r;
	r.left = left;
	r.top = top;
	r.right = right;
	r.bottom = bottom;

	Draw(x, y, texture, r);
}

void SpriteHandler::Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, RECT resource)
{
	Camera* camera = Camera::GetInstance();
	Vector2D camPosition = camera->position;
	D3DXVECTOR3 p(x - camPosition.GetX(), y - camPosition.GetY(), 0);

	spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);

	spriteHandler->Draw(texture, &resource, NULL, &p, D3DCOLOR_XRGB(255, 255, 255));

	spriteHandler->End();
}

SpriteHandler* SpriteHandler::GetInstance()
{
	if (instance == NULL)
	{
		instance = new SpriteHandler();
	}
	return instance;
}
