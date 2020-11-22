#include "Sprite.h"

void Sprite::LoadTexture(std::string imagePath, D3DCOLOR transparentColor)
{
	LPDIRECT3DDEVICE9 d3ddv = DrawDevice::GetInstance()->GetDevice();
	D3DXIMAGE_INFO info;
	std::wstring stemp = StringHelper::s2ws(imagePath);
	LPCWSTR path = stemp.c_str();
	HRESULT result = D3DXGetImageInfoFromFile(path, &info);
	if (result != D3D_OK)
	{
		texture = NULL;
	}

	result = D3DXCreateTextureFromFileEx(
		d3ddv,								// Pointer to Direct3D device object
		path,						// Path to the image to load
		info.Width,							// Texture width
		info.Height,						// Texture height
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		transparentColor,			// Transparent color
		&info,
		NULL,
		&texture);								// Created texture pointer

	if (result != D3D_OK)
	{
		texture = NULL;
	}
}

Sprite::Sprite(D3DCOLOR transparentColor, int w, int h, std::string imagePath)
{
	LoadTexture(imagePath, transparentColor);
	size.SetVector(w, h);
	
}

Sprite::Sprite(D3DCOLOR transparentColor, Vector2D size, std::string imagePath)
{
	LoadTexture(imagePath, transparentColor);
	this->size.SetVector(size);
	
}

void Sprite::Draw(Vector2D drawPosition)
{
	D3DXVECTOR3 drawPos(drawPosition.GetX(), drawPosition.GetY(), 0);
	RECT src;
	src.top = 0;
	src.left = 0;
	src.bottom = size.GetY();
	src.right = size.GetX();
	float x = size.GetX() / 2.0;
	float y = size.GetY() / 2.0;
	D3DXVECTOR3 center(x, y, 0);
	DrawDevice::GetInstance()->Draw(drawPos, texture, src, center);
}
