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
	figure = FIGURE_BIG;
}

Mario::Mario(const Vector2D& vec): GameObject(vec)
{	
	TransitionTo(new IdleState());
	runSpeed = MARIO_RUN_SPEED;
	jumpSpeed = MARIO_JUMP_SPEED;
	width = MARIO_BIG_WIDTH;
	height = MARIO_BIG_HEIGHT;
	tag = "Mario";
	figure = FIGURE_BIG;
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

	if (IsGrounded)
	{
		if (keyHandler->OnKeyDown(DIK_SPACE) && !keyHandler->IsStillPressed(DIK_SPACE))
		{
			IsGrounded = false;
			TransitionTo(new JumpState());
		}
		else if (keyHandler->OnKeyDown(DIK_RIGHT))
		{
			direction = 1;
			TransitionTo(new RunState());
		}
		else if (keyHandler->OnKeyDown(DIK_LEFT))
		{
			direction = -1;
			TransitionTo(new RunState());
		}
		else
		{
			TransitionTo(new IdleState());
		}
	}
	else
	{
		if (dynamic_cast<JumpState*>(this->state))
		{
			if (keyHandler->OnKeyDown(DIK_RIGHT))
			{
				direction = 1;
				velocity.SetX(runSpeed);
			}
			if (keyHandler->OnKeyDown(DIK_LEFT))
			{
				direction = -1;
				velocity.SetX(-runSpeed);
			}
			if (velocity.GetY() >= 0.0f || (velocity.GetY() > -15.0f && (keyHandler->OnKeyUp(DIK_SPACE) || keyHandler->IsStillReleased(DIK_SPACE))))
			{
				TransitionTo(new FallState());
			}
		}
		if (position.GetY() >= 150 && dynamic_cast<FallState*>(this->state))
		{
			IsGrounded = true;
			position.SetY(150);
			if (keyHandler->IsStillPressed(DIK_RIGHT) && keyHandler->IsStillPressed(DIK_LEFT))
			{
				TransitionTo(new RunState());
			}
			else if (keyHandler->IsStillPressed(DIK_RIGHT))
			{
				direction = 1;
				TransitionTo(new RunState());
			}
			else if (keyHandler->IsStillPressed(DIK_LEFT))
			{
				direction = -1;
				TransitionTo(new RunState());
			}
			else
			{
				TransitionTo(new IdleState());
			}
		}
	}
	
	LPGAMEOBJECT goomba = GameObjectManager::GetInstance()->GetGameObject("Goomba");
	if (goomba == NULL)
	{
		return;
	}
	LPCOLLISIONEVENT colEvent = new CollisionEvent(this, goomba);
	DebugOut(L"[MARIO.CPP] entry time x = %f\n", colEvent->EntryTime);
	if (colEvent->IsCollided())
	{
		if (colEvent->direction == Vector2D::Down())
			DebugOut(L"[MARIO.CPP] KILL GOOMBA\n");
		else
		{
			DebugOut(L"[MARIO.CPP] MARIO DEATH\n");
			if (figure == FIGURE_BIG)
			{
				figure = FIGURE_SMALL;
			}
			else
			{
				figure = FIGURE_BIG;
			}
		}
	}

}

void Mario::RenderAnimation()
{
	if (!isActivated)
	{
		return;
	}
	PlayAnimation(make_tuple(figure, state->GetId(), direction));
}

