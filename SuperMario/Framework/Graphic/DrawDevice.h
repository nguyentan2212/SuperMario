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
		d3ddv->ColorFill(backBuffer, NULL, D3DCOLOR_XRGB(255, 255, 255));
	}
	void Draw(D3DXVECTOR3 drawPosition, LPDIRECT3DTEXTURE9 texture, RECT resource, D3DXVECTOR3 center = D3DXVECTOR3(0, 0, 0), DWORD flag = D3DXSPRITE_ALPHABLEND);
	void End() {
		d3ddv->EndScene();
		d3ddv->Present(NULL, NULL, NULL, NULL);
	}
	LPDIRECT3DDEVICE9 GetDevice() {
		return d3ddv;
	}
	void Flip() {
		D3DXMATRIX matScale;
		D3DXMatrixScaling(&matScale, -1.0f, 1.0f, 0.0f);
		spriteHandler->SetTransform(&matScale);
		isFlip = !isFlip;
	}
	bool isFlip = false;
};
typedef DrawDevice* LPDRAWDEVICE;