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
	GameObject::Update(delta);
	if (actionTimer > 0)
	{
		actionTimer -= delta;
	}
	else
	{
		actionTimer = 0.0f;
	}
	DebugOut(L"[MARIO.CPP] actionTimer = %f\n", actionTimer);
	if (position.GetX() <= 0)// Mario goes to left border
	{
		position.SetX(0);
	}
	else if (position.GetX() >= BACKGROUND_TEXTURE_WIDTH - width)// Mario goes to right border
	{
		position.SetX((float)(BACKGROUND_TEXTURE_WIDTH - width));
	}

	if (keyHandler->OnKeyDown(DIK_LSHIFT))
	{
		runSpeed = MARIO_SUPER_RUN_SPEED;
		jumpSpeed = MARIO_SUPER_JUMP_SPEED;
	}
	else
	{
		runSpeed = MARIO_RUN_SPEED;
		jumpSpeed = MARIO_JUMP_SPEED;
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
			if (!keyHandler->IsStillPressed(DIK_LEFT))
			{
				if (direction == LEFT && runningTimer > 0)
				{
					actionTimer = ANI_LONG_TIME * 0.7f;
					direction = 1;
					TransitionTo(new SwitchAction());
				}
				else if (actionTimer <= 0.0f)
				{
					direction = 1;
					runningTimer = MARIO_RUNNING_TIMER;
					TransitionTo(new RunState());
				}
			}
			
		}
		else if (keyHandler->OnKeyDown(DIK_LEFT))
		{
			if (!keyHandler->IsStillPressed(DIK_RIGHT))
			{	
				if (direction == RIGHT && runningTimer > 0)
				{
					direction = -1;
					actionTimer = ANI_LONG_TIME * 0.7f;
					TransitionTo(new SwitchAction());
				}
				else if (actionTimer <= 0.0f)
				{
					direction = -1;
					runningTimer = MARIO_RUNNING_TIMER;
					TransitionTo(new RunState());
				}
			}
		}
		else if (keyHandler->OnKeyDown(DIK_DOWN) && figure != FIGURE_SMALL)
		{		
			renderPosition = position + Vector2D(0, 10);
			TransitionTo(new SitState());
		}
		else if (keyHandler->OnKeyDown(DIK_K))
		{
			actionTimer = ANI_LONG_TIME;
			TransitionTo(new KickAction());
		}
		else
		{
			
			if (runningTimer > 0.0f && dynamic_cast<RunState*>(this->state))
			{
				runningTimer -= delta;
			}
			else if (actionTimer <= 0.0f)
			{
				runningTimer = 0.0f;
				actionTimer = 0.0f;
				TransitionTo(new IdleState());
			}	
		}
	}
	else
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
		if (dynamic_cast<JumpState*>(this->state))
		{
			if (velocity.GetY() >= 0.0f || (velocity.GetY() > -18.0f && (keyHandler->OnKeyUp(DIK_SPACE) || keyHandler->IsStillReleased(DIK_SPACE))))
			{
				TransitionTo(new FallState());
			}
		}
		if (position.GetY() >= 150 && dynamic_cast<FallState*>(this->state))
		{
			IsGrounded = true;
			position.SetY(150);			
			TransitionTo(new IdleState());
		}
	}
	if (keyHandler->OnKeyDown(DIK_B))
	{
		figure = FIGURE_BIG;
	}
	else if (keyHandler->OnKeyDown(DIK_R))
	{
		figure = FIGURE_RACCOON;
	}
	else if (keyHandler->OnKeyDown(DIK_S))
	{
		figure = FIGURE_SMALL;
	}
	else if (keyHandler->OnKeyDown(DIK_F))
	{
		figure = FIGURE_FIRE;
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
		else if (dynamic_cast<KickAction*>(this->state))
		{
			goomba->position.SetVector(150, 160);
			//figure = (figure == FIGURE_FIRE) ? FIGURE_BIG : FIGURE_FIRE;
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

