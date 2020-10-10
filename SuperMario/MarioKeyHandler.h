#pragma once
#include "KeyHandler.h"
#include "Debug.h"
#include "Mario.h"

class MarioKeyHandler : public KeyHandler
{
public:
	MarioKeyHandler(Mario* mario) { this->mario = mario;}
	void OnKeyDown(int KeyCode);	
	void OnKeyUp(int KeyCode);
	void Update(DIDEVICEOBJECTDATA* keyEvents, DWORD dwElements);
private:
	Mario* mario;
};

