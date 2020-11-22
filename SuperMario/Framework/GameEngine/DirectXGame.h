#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>
#include "../Utilities/Singleton.h"
#include "Window.h"
#include "../Graphic/DrawDevice.h"
#include "../Graphic/Sprite.h"

class DirectXGame 
{
protected:
	HINSTANCE hInstance;                    // handle to an instance of the application
	int fps;								// frames per second
	double mspf;							// milliseconds per frame
	double deltaTime;						// game update rate
	bool isPaused;							// true if the game is paused

	LPWINDOW mainWindow;                    // the application window
	DWORD icon;                             // icon of application
	DWORD iconSm;                           // small icon of application
	DWORD windowHeight;                     // window's height
	DWORD windowWidth;                      // window's width
	LPCWSTR title;                          // window's title

	LPDRAWDEVICE drawDevice;
	
	std::unordered_map<std::string, LPSPRITE> spriteMap;

	virtual void SetInfo() = 0;
	virtual void KeyHandling() = 0;
	virtual void Update(double dt) = 0;
	virtual void Render() = 0;
	virtual void LoadGameObjects(std::string jsonPath) = 0;
public:
	virtual void GameInit(HINSTANCE _hInstance, int nCmdShow);
	virtual void Run();
};
typedef DirectXGame* LPDIRECTXGAME;
