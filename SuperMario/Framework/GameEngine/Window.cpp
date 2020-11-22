#include "Window.h"

void Window::Init(int nCmdShow, DWORD icon, DWORD iconSm, DWORD height, DWORD width, LPCWSTR title)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = msgProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(icon));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"DirectXWindowClass";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(iconSm));

	// register the window
	if (!RegisterClassEx(&wcex))
	{
		DebugOut(L"[ERROR] [WINDOW.CPP] [INIT] Register window failed.\n");
		return;
	}

	mainWindow = CreateWindowW(wcex.lpszClassName, title, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, width, height, nullptr, nullptr, hInstance, nullptr);

	if (!mainWindow)
	{
		return;
		DebugOut(L"[ERROR] [WINDOW.CPP] [INIT] Window created failed.\n");
	}

	ShowWindow(mainWindow, nCmdShow);
	UpdateWindow(mainWindow);

	DebugOut(L"[INFO] [WINDOW.CPP] [INIT] Window created succeed.\n");
	return ;
}

Window::Window(HINSTANCE _hInstance, int nCmdShow, DWORD icon, DWORD iconSm, DWORD height, DWORD width, LPCWSTR title = L"DirectXWindow")
{
	hInstance = _hInstance;
	Init(nCmdShow,icon, iconSm, height, width, title);
}

Window::~Window()
{
	if (mainWindow)
		mainWindow = NULL;
	if (hInstance)
		hInstance = NULL;
}

LRESULT Window::msgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
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
