#pragma once
#include <d3d9.h>
#include <d3dx9.h>
class Texture
{
private:
	inline static LPDIRECT3DDEVICE9 d3ddv = nullptr;
	LPDIRECT3DTEXTURE9 texture;

public:
	static void SetDevice(LPDIRECT3DDEVICE9 _d3ddv) {
		d3ddv = _d3ddv;
	}
	Texture(LPCWSTR texturePath, D3DCOLOR transparentColor);
	LPDIRECT3DTEXTURE9 GetTexture() {
		return texture;
	}
};
typedef Texture* LPTEXTURE;