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
		KeyHandling();
		Update(deltaTime);
		Render();
	}
}
