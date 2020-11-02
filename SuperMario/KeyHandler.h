#pragma once
#include <dinput.h>
#include "GameDefine.h"

class KeyHandler
{
public:	
	KeyHandler();
	bool OnKeyDown(int keyCode);
	bool OnKeyUp(int keyCode);
	void Update(DIDEVICEOBJECTDATA* keyEvents, DWORD dwElements);
	bool IsStillPressed(int keyCode);
	bool IsStillReleased(int keyCode);
private:
	bool* keyEvents = new bool[KEYBOARD_BUFFER_SIZE];
	bool* previousKeyEvents = new bool[KEYBOARD_BUFFER_SIZE];
};

typedef KeyHandler* LPKEYHANDLER;
