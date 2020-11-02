#include "KeyHandler.h"
#include "Debug.h"

KeyHandler::KeyHandler()
{
	for (int i = 0; i < KEYBOARD_BUFFER_SIZE; i++)
	{
		this->previousKeyEvents[i] = false;
		this->keyEvents[i] = false;
	}
}

bool KeyHandler::OnKeyDown(int keyCode)
{
	return keyEvents[keyCode];
}

bool KeyHandler::OnKeyUp(int keyCode)
{
	return !keyEvents[keyCode];
}

void KeyHandler::Update(DIDEVICEOBJECTDATA* keyEvents, DWORD dwElements)
{
	for (int i = 0; i < KEYBOARD_BUFFER_SIZE; i++)
	{
		this->previousKeyEvents[i] = this->keyEvents[i];
	}
	
	for (int i = 0; i < dwElements; i++)
	{
		this->keyEvents[keyEvents[i].dwOfs] = (keyEvents[i].dwData & 0x80) > 0;
	}
	
	DebugOut(L"[MARIO.CPP] code = %d\n", keyEvents[0].dwOfs);

}

bool KeyHandler::IsStillPressed(int keyCode)
{
	return keyEvents[keyCode] && previousKeyEvents[keyCode];
}

bool KeyHandler::IsStillReleased(int keyCode)
{
	return !keyEvents[keyCode] && !previousKeyEvents[keyCode];
}