#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Debug.h"
#include "KeyHandler.h"
#include "Vector2D.h"
#include "Camera.h"
#include "GameDefine.h"


class Game
{
public:
	Game();
	Game(Game& game) = delete;
	void operator=(const Game& game) = delete;
	static Game* GetInstance();
	~Game();

	void Init(HWND hWnd, HINSTANCE hInstance);
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath, D3DCOLOR transparentColor);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }

	int GetBackBufferWidth() { return backBufferWidth; }
	int GetBackBufferHeight() { return backBufferHeight; }

	void InitKeyboard();
	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();

	LPKEYHANDLER keyHandler;
private:
	static Game* instance;

	HWND hWnd;							// Window handle
	HINSTANCE hInstance;

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;

	int backBufferWidth = 0;
	int backBufferHeight = 0;

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data

};
