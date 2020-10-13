#include "MarioKeyHandler.h"

void MarioKeyHandler::OnKeyDown(int KeyCode)
{
	DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	switch (KeyCode)
	{
	case DIK_SPACE:
		mario->SetState(MARIO_STATE_JUMP);
		break;
	case DIK_RIGHT:
		mario->SetState(MARIO_STATE_WALKING_RIGHT);
		break;
	case DIK_LEFT:
		mario->SetState(MARIO_STATE_WALKING_LEFT);
		break;
	}
}
void MarioKeyHandler::OnKeyUp(int KeyCode)
{
	DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
	if (mario->GetState() == MARIO_STATE_JUMP)
	{
		mario->SetState(MARIO_STATE_FALL);
	}
	else if (mario->GetState() != MARIO_STATE_FALL)
	{
		mario->SetState(MARIO_STATE_IDLE);
	}
	
}

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
