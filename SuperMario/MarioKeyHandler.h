#pragma once
#include "KeyHandler.h"
#include "Debug.h"
#include "Mario.h"
#include "Game.h"

class MarioKeyHandler : public KeyHandler
{
public:
	MarioKeyHandler(Mario* mario) { this->mario = mario; game = Game::GetInstance(); }
	void KeyState(BYTE* state)
	{		
	}
	void OnKeyDown(int KeyCode) 
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
	void OnKeyUp(int KeyCode)
	{
		DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);
		mario->SetState(MARIO_STATE_IDLE);
	}
private:
	Mario* mario;
	Game* game;
};

