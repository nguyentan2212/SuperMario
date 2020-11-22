#pragma once
#include <string>
#include "../Graphic/DrawDevice.h"
#include "../Utilities/Vector2D.h"
#include "../Utilities/StringHelper.h"

class Sprite
{
private:
	std::string name;
	LPDIRECT3DTEXTURE9 texture = NULL;	
	Vector2D size;	
	void LoadTexture(std::string imagePath, D3DCOLOR transparentColor);
public:
	Sprite(std::string name, D3DCOLOR transparentColor, int w, int h, std::string imagePath);
	Sprite(std::string name, D3DCOLOR transparentColor, Vector2D size, std::string imagePath);
	~Sprite() {		
		if (texture) texture = NULL;
	}
	LPDIRECT3DTEXTURE9 GetTexture() {
		return texture;
	}	
	Vector2D GetSize() {
		return size;
	}
	void Draw(Vector2D drawPosition);
};
typedef Sprite* LPSPRITE;