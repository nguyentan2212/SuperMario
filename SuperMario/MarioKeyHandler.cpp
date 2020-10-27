#include "MarioKeyHandler.h"

void MarioKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:// Space button is pressed ...
		mario->SetState(STATE_JUMP);
		break;
	case DIK_RIGHT:// Right arrow button is pressed
		mario->direction = 1;
		mario->SetState(STATE_RUN);
		break;
	case DIK_LEFT:
		mario->direction = -1;
		mario->SetState(STATE_RUN);	
		break;
	}
}
void MarioKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);

	switch (KeyCode)
	{
	case DIK_SPACE: // Space button is released
		mario->SetState(STATE_FALL);
		break;
	case DIK_RIGHT:// Right arrow button is pressed
		mario->SetState(STATE_IDLE);
		break;
	case DIK_LEFT:
		mario->SetState(STATE_IDLE);
		break;
	}	
}

// Update key events 
void MarioKeyHandler::Update(DIDEVICEOBJECTDATA* keyEvents, DWORD dwElements)
{
	for (DWORD i = 0; i < dwElements; i++)
	{
		int KeyCode = keyEvents[i].dwOfs;
		int KeyState = keyEvents[i].dwData;
		if ((KeyState & 0x80) > 0)
			OnKeyDown(KeyCode);
		else
			OnKeyUp(KeyCode);
	}
}
