// SuperMario.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "SuperMario.h"

#define MAX_LOADSTRING 100
#define GAME_WIDTH 700
#define GAME_HEIGHT 700
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:

// Game object

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);
	
	LPDIRECTXGAME game = MarioGame::GetInstance();
	game->GameInit(hInstance, nCmdShow);
	game->Run();
	return TRUE;
}

//void LoadTextures()
//{
//	Game* game = Game::GetInstance();
//	TextureManager* textureManager = TextureManager::GetInstance();
//
//	textureManager->AddTexture(100, game->LoadTexture(L"mario.png", D3DCOLOR_XRGB(0, 136, 255)));
//	textureManager->AddTexture(101, game->LoadTexture(L"misc.png", D3DCOLOR_XRGB(176, 224, 248)));
//	textureManager->AddTexture(102, game->LoadTexture(L"background.png", BLACK_BRUSH));
//	textureManager->AddTexture(103, game->LoadTexture(L"goomba.png", D3DCOLOR_XRGB(68, 145, 190)));
//	textureManager->AddTexture(104, game->LoadTexture(L"Koopa.png", D3DCOLOR_XRGB(68, 145, 190)));
//}

//void LoadSprites()
//{
//	SpriteManager* spriteManager = SpriteManager::GetInstance();
//}
//
//void BuildAnimation()
//{
//	AnimationManager* anmationManager = AnimationManager::GetInstance();
//}

//void LoadResource()
//{
//	// Load textures
//	LoadTextures();
//	// Load sprites
//	LoadSprites();
//	// Build animations
//	BuildAnimation();
//
//}

//void Render()
//{
//	Game* game = Game::GetInstance();
//	
//	GameObjectManager* gom = GameObjectManager::GetInstance();
//	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
//	LPDIRECT3DSURFACE9 back_buffer = game->GetBackBuffer();
//
//	AnimationManager* animationManager = AnimationManager::GetInstance();
//	if (SUCCEEDED(d3ddv->BeginScene()))
//	{
//		// Clear back buffer with a color
//		d3ddv->ColorFill(back_buffer, NULL, BACKGROUND_COLOR);
//		gom->Render();
//		d3ddv->EndScene();
//	}
//	// Display back buffer content to the screen
//	d3ddv->Present(NULL, NULL, NULL, NULL);
//}


int Run()
{
	
	MSG msg;
	int done = 0;
	ULONGLONG frame_start = GetTickCount64();;
	//DWORD tick_per_frame = TICK_PER_FRAME;	

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		//GameObjectManager* gom = GameObjectManager::GetInstance();

		//ULONGLONG now = GetTickCount64();
		//float delta = (float)now - (float)frame_start;
		//if (delta >= tick_per_frame)
		//{
		//	frame_start = now;
		//	
		//	game->ProcessKeyboard();

		//	gom->Update(delta);
		//	//DebugOut(L"[INFO] position x: %f %f \n", vec.GetX(), vec.GetY());
		//	//DebugOut(L"[INFO] position x: %d \n", Game::GetInstance()->GetBackBufferWidth());
		//	Render();
		//}
		//else
		//{
		//	Sleep(tick_per_frame - (DWORD)delta);
		//}
	}
	return 0;
}
