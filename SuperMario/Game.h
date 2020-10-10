#pragma once
#include <Windows.h>
#include <d3d9.h>
#include <d3dx9.h>
#include "Debug.h"
#include "KeyHandler.h"

#define DIRECTINPUT_VERSION 0x0800
#define KEYBOARD_BUFFER_SIZE 1024

class Game
{
public:
	Game(){}
	Game(Game& game) = delete;
	void operator=(const Game& game) = delete;
	static Game* GetInstance();
	~Game();

	void Init(HWND hWnd, HINSTANCE hInstance);
	void Draw(float x, float y, LPDIRECT3DTEXTURE9 texture, int left, int top, int right, int bottom);
	LPDIRECT3DTEXTURE9 LoadTexture(LPCWSTR texturePath, D3DCOLOR transparentColor);

	LPDIRECT3DDEVICE9 GetDirect3DDevice() { return this->d3ddv; }
	LPDIRECT3DSURFACE9 GetBackBuffer() { return backBuffer; }
	LPD3DXSPRITE GetSpriteHandler() { return this->spriteHandler; }

	int GetBackBufferWidth() { return backBufferWidth; }
	int GetBackBufferHeight() { return backBufferHeight; }

	void InitKeyboard(LPKEYHANDLER handler);
	int IsKeyDown(int KeyCode);
	void ProcessKeyboard();

private:
	static Game* instance;

	HWND hWnd;							// Window handle
	HINSTANCE hInstance;

	LPDIRECT3D9 d3d = NULL;						// Direct3D handle
	LPDIRECT3DDEVICE9 d3ddv = NULL;				// Direct3D device object

	LPDIRECT3DSURFACE9 backBuffer = NULL;
	LPD3DXSPRITE spriteHandler = NULL;			// Sprite helper library to help us draw 2D image on the screen

	int backBufferWidth = 0;
	int backBufferHeight = 0;

	LPDIRECTINPUT8       di;		// The DirectInput object         
	LPDIRECTINPUTDEVICE8 didv;		// The keyboard device 

	BYTE  keyStates[256];			// DirectInput keyboard state buffer 
	DIDEVICEOBJECTDATA keyEvents[KEYBOARD_BUFFER_SIZE];		// Buffered keyboard data

	LPKEYHANDLER keyHandler;
};
