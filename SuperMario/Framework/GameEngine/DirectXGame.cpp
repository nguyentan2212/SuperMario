#include "DirectXGame.h"

void DirectXGame::GameInit(HINSTANCE _hInstance, int nCmdShow)
{
	hInstance = _hInstance;
	SetInfo();
	mainWindow = new Window(hInstance, nCmdShow, icon, iconSm, windowHeight, windowWidth, title);
	drawDevice = DrawDevice::GetInstance();
	drawDevice->Init(mainWindow->GetWindow());
}


void DirectXGame::Run()
{
	MSG msg;
	bool continueRunning = true;
	ULONG64 start = GetTickCount64();
	while (continueRunning)
	{
		// peek for messages
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);

			if (msg.message == WM_QUIT)
				continueRunning = false;
		}
		// run the game logic
		ULONG64 now = GetTickCount64();
		double delta = ((double)now - (double)start)/1000;
		ULONG64 mlspf = (ULONG64)((double)1.0 / fps * 1000);
		if (delta >= (double)1.0 / fps)
		{
			start = now;
			DebugOut(L"[INFO] delta time = %f, mlspf = %lld\n", delta, mlspf);
			KeyHandling();
			Update(delta);
			Render();
		}
		else
		{
			//Sleep(mlspf - (ULONG64)delta);
		}
	}
}
