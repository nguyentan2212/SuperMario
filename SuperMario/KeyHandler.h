#pragma once
#include <dinput.h>

class KeyHandler
{
public:	
	virtual void OnKeyDown(int KeyCode) = 0;
	virtual void OnKeyUp(int KeyCode) = 0;
	virtual void Update(DIDEVICEOBJECTDATA* keyEvents, DWORD dwElements) = 0;
};

typedef KeyHandler* LPKEYHANDLER;
