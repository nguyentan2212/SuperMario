// SuperMario.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "SuperMario.h"

#define MAX_LOADSTRING 100
#define GAME_WIDTH 800
#define GAME_HEIGHT 600
#define FRAME_RATE 100
#define BACKGROUND_COLOR D3DCOLOR_XRGB(255, 255, 255)
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
	game->Init(hWnd);
	SetDebugWindow(hWnd);
	// Loads resources
	LoadResource();
	// Runs game
	Run();
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
}

void LoadSprites()
{
	TextureManager* textureManager = TextureManager::GetInstance();
	SpriteManager* spriteManager = SpriteManager::GetInstance();

	// Mario texture
	LPTEXTURE mario = textureManager->GetTexture(100);
	
	// Mario run to right
	spriteManager->AddSprite(10001, 246, 154, 259, 181, mario);
	spriteManager->AddSprite(10002, 275, 154, 290, 181, mario);
	spriteManager->AddSprite(10003, 304, 154, 321, 181, mario);

	// Mario run to left
	spriteManager->AddSprite(10004, 186, 154, 199, 181, mario);
	spriteManager->AddSprite(10005, 155, 154, 170, 181, mario);
	spriteManager->AddSprite(10006, 125, 154, 140, 181, mario);
}

Mario* mario = new Mario(600, 50, 10);
void BuildAnimation(DWORD time)
{
	SpriteManager* spriteManager = SpriteManager::GetInstance();
	
	// Build Mario run to right animation
	LPANIMATION marioRunRight = new Animation(time);
	marioRunRight->Add(spriteManager->GetSprite(10001));
	marioRunRight->Add(spriteManager->GetSprite(10002));
	marioRunRight->Add(spriteManager->GetSprite(10003));
	mario->AddAnimation(marioRunRight);

	// Build Mario run to left animation
	LPANIMATION marioRunLeft = new Animation(time);
	marioRunLeft->Add(spriteManager->GetSprite(10004));
	marioRunLeft->Add(spriteManager->GetSprite(10005));
	marioRunLeft->Add(spriteManager->GetSprite(10006));
	mario->AddAnimation(marioRunLeft);
}

void LoadResource()
{
	
	// Load textures
	LoadTextures();

	// Load sprites
	LoadSprites();

	
}

void Render()
{
	Game* game = Game::GetInstance();
	LPDIRECT3DDEVICE9 d3ddv = game->GetDirect3DDevice();
	LPDIRECT3DSURFACE9 back_buffer = game->GetBackBuffer();
	LPD3DXSPRITE spriteHandler = game->GetSpriteHandler();	

	if (SUCCEEDED(d3ddv->BeginScene()))
	{
		// Clear back buffer with a color
		d3ddv->ColorFill(back_buffer, NULL, BACKGROUND_COLOR);

		spriteHandler->Begin(D3DXSPRITE_ALPHABLEND);
				
		mario->RenderAnimation();

		spriteHandler->End();
		d3ddv->EndScene();
	}
	// Display back buffer content to the screen
	d3ddv->Present(NULL, NULL, NULL, NULL);
}

void Update(DWORD delta)
{
	mario->Update(delta);
}

int Run()
{
	Render();
	MSG msg;
	int done = 0;
	ULONGLONG frame_start = GetTickCount64();;
	DWORD tick_per_frame = 1000 / FRAME_RATE;	
	// Build animation
	BuildAnimation(100);
	while (!done)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) done = 1;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		DWORD now = GetTickCount64();
		float delta = now - frame_start;
		if (delta >= tick_per_frame)
		{
			frame_start = now;
			
			Update(delta);
			Vector2D vec = mario->GetPosition();
			DebugOut(L"[INFO] position x: %f \n", vec.GetX());
			//DebugOut(L"[INFO] position x: %d \n", Game::GetInstance()->GetBackBufferWidth());
			Render();
		}
		else
		{
			Sleep(tick_per_frame - delta);
		}
	}
	return 0;
}
