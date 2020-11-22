#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "../Utilities/Singleton.h"
class DrawDevice : public Singleton<DrawDevice>
{
	friend class Singleton<DrawDevice>;
private:
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object
	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;
	DrawDevice() {
	}
public:	
	void Init(HWND hWnd);
	void Begin() {
		d3ddv->BeginScene();
	}
	void Draw(D3DXVECTOR3 drawPosition, LPDIRECT3DTEXTURE9 texture, RECT resource, DWORD flag = D3DXSPRITE_ALPHABLEND);
	void End() {
		d3ddv->EndScene();
		d3ddv->Present(NULL, NULL, NULL, NULL);
	}
	LPDIRECT3DDEVICE9 GetDevice() {
		return d3ddv;
	}
};
typedef DrawDevice* LPDRAWDEVICE;