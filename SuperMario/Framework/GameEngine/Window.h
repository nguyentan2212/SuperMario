#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "../Utilities/Debug.h"
class Window
{
private:
	HWND mainWindow;
	HINSTANCE hInstance;	

	void Init(int nCmdShow, DWORD icon, DWORD iconSm, DWORD height, DWORD width, LPCWSTR title);
public:
	Window(HINSTANCE _hInstance, int nCmdShow, DWORD icon, DWORD iconSm, DWORD height, DWORD width, LPCWSTR title);
	~Window();
	HWND GetWindow() {
		return mainWindow;
	}	
	static LRESULT CALLBACK msgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

typedef Window* LPWINDOW;