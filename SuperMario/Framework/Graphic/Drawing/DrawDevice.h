#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class DrawDevice
{
private:
	LPDIRECT3DDEVICE9 d3ddv;				// Direct3D device object
	LPDIRECT3DSURFACE9 backBuffer;
	LPD3DXSPRITE spriteHandler = NULL;

public:
	DrawDevice(HWND hWnd);
	void Begin() {
		d3ddv->BeginScene();
	}
	void Draw(double x, double y, LPDIRECT3DTEXTURE9 texture, RECT resource);
	void End() {
		d3ddv->EndScene();
		d3ddv->Present(NULL, NULL, NULL, NULL);
	}
	LPDIRECT3DDEVICE9 GetDevice() {
		return d3ddv;
	}
};

typedef DrawDevice* LPDRAWDEVICE;