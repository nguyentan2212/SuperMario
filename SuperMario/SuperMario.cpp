// SuperMario.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "SuperMario.h"


#define MAX_LOADSTRING 100
#define LPTEXTURE LPDIRECT3DTEXTURE9
// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
HWND                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
void LoadResource();
int Run();

// Game object

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_SUPERMARIO, szWindowClass, MAX_LOADSTRING);
	// Registers the window class
	MyRegisterClass(hInstance);

	// Creates main window
	HWND hWnd = InitInstance(hInstance, nCmdShow);

	if (hWnd == NULL)
	{
		return FALSE;
	}

	// Creates game instance
	Game* game = Game::GetInstance();
	game->Init(hWnd, hInstance);

	// Create Key handler
	game->InitKeyboard();

	SetDebugWindow(hWnd);
	// Loads resources
	LoadResource();
	// Runs game
	Run();
	return TRUE;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SUPERMARIO));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

HWND InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, GAME_WIDTH, GAME_HEIGHT, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return NULL;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return hWnd;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

void LoadTextures()
{
	Game* game = Game::GetInstance();
	TextureManager* textureManager = TextureManager::GetInstance();

	textureManager->AddTexture(100, game->LoadTexture(L"mario.png", D3DCOLOR_XRGB(0, 136, 255)));
	textureManager->AddTexture(101, game->LoadTexture(L"misc.png", D3DCOLOR_XRGB(176, 224, 248)));
	textureManager->AddTexture(102, game->LoadTexture(L"background.png", BLACK_BRUSH));
	textureManager->AddTexture(103, game->LoadTexture(L"goomba.png", D3DCOLOR_XRGB(68, 145, 190)));
}

void LoadSprites()
{
	SpriteManager* spriteManager = SpriteManager::GetInstance();
}

void BuildAnimation()
{
	AnimationManager* anmationManager = AnimationManager::GetInstance();
}

void LoadResource()
{
	// Load textures
	LoadTextures();
	// Load sprites
	LoadSprites();
	// Build animations
	BuildAnimation();

}

void Render()
{
	Game* game = Game::GetInstance();
	
	GameObjectManager* gom = GameObjectManager::GetInstance();
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 back_buffer = game->GetBackBuffer();

	AnimationManager* animationManager = AnimationManager::GetInstance();
	if (SUCCEEDED(d3ddv->BeginScene()))
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(back_buffer, NULL, BACKGROUND_COLOR);
		gom->Render();
		d3ddv->EndScene();
	}
	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}


int Run()
{
	Render();
	Game* game = Game::GetInstance();
	MSG msg;
	int done = 0;
	ULONGLONG frame_start = GetTickCount64();;
	DWORD tick_per_frame = TICK_PER_FRAME;	

	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		GameObjectManager* gom = GameObjectManager::GetInstance();

		ULONGLONG now = GetTickCount64();
		float delta = (float)now - (float)frame_start;
		if (delta >= tick_per_frame)
		{
			frame_start = now;
			
			game->ProcessKeyboard();

			gom->Update(delta);
			//DebugOut(L"[INFO] position x: %f %f \n", vec.GetX(), vec.GetY());
			//DebugOut(L"[INFO] position x: %d \n", Game::GetInstance()->GetBackBufferWidth());
			Render();
		}
		else
		{
			Sleep(tick_per_frame - (DWORD)delta);
		}
	}
	return 0;
}
