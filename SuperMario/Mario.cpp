#include "Mario.h"
#include "Game.h"
#include "Debug.h"
#include <math.h>
#include <typeinfo>

Mario::Mario(float x, float y): GameObject(x, y)
{	
	TransitionTo(new IdleState());
	runSpeed = MARIO_RUN_SPEED;
	jumpSpeed = MARIO_JUMP_SPEED;
	width = MARIO_BIG_WIDTH;
	height = MARIO_BIG_HEIGHT;
	tag = "Mario";
}

Mario::Mario(const Vector2D& vec): GameObject(vec)
{	
	TransitionTo(new IdleState());
	runSpeed = MARIO_RUN_SPEED;
	jumpSpeed = MARIO_JUMP_SPEED;
	width = MARIO_BIG_WIDTH;
	height = MARIO_BIG_HEIGHT;
	tag = "Mario";
}

void Mario::Update(float delta)
{
	delta /= 100; // Convert delta from millisecond to 1/10 second
	GameObject::Update(delta);
	//DebugOut(L"[MARIO.CPP] velocity x= %f, y=%f\n", velocity.GetX(), velocity.GetY());

	
	if (position.GetX() <= 0)// Mario goes to left border
	{
		position.SetX(0);
	}
	else if (position.GetX() >= BACKGROUND_TEXTURE_WIDTH - width)// Mario goes to right border
	{
		position.SetX((float)(BACKGROUND_TEXTURE_WIDTH - width));
	}
	
	if (position.GetY() >= 150 && !IsGrounded)
	{
		IsGrounded = true;
		position.SetY(150);
		
		if (velocity.GetX() != 0)
		{
			TransitionTo(new RunState());
		}
		else
		{
			TransitionTo(new IdleState());
		}
	}

	
		LPGAMEOBJECT goomba = GameObjectManager::GetInstance()->GetGameObject("Goomba");
		if (goomba == NULL)
		{
			return;
		}
		LPCOLLISIONEVENT colEvent = new CollisionEvent(this, goomba);
		if (colEvent->IsCollided()) DebugOut(L"[MARIO.CPP] time = %f\n", colEvent->EntryTime);
	
}

void Mario::RenderAnimation()
{
	if (!isActivated)
	{
		return;
	}
	PlayAnimation(this->state->GetAnimation());
}

void Mario::SetState(int state)
{
	switch (state)
	{
	case STATE_IDLE:
		if (IsGrounded)
		{
			TransitionTo(new IdleState());
		}
		else if (!IsGrounded)
		{
			velocity.SetX(0);
		}
		break;
	case STATE_RUN:
			if (IsGrounded)
			{
				TransitionTo(new RunState());
			}
			else if (velocity.GetX() == 0 && velocity.GetY() < 0)
			{
				velocity.SetX(MARIO_RUN_SPEED * direction);
			}
		break;
	case STATE_JUMP:
		if (IsGrounded)
		{
			IsGrounded = false;
			TransitionTo(new JumpState());
		}
		break;
	case STATE_FALL:
		if (!IsGrounded)
			TransitionTo(new FallState());
		break;
	}
}

