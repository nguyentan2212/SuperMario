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
	DebugOut(L"[Mario.cpp] state = %d\n", this->state->GetId());
	if (dynamic_cast<DeathState*>(this->state))
	{
		return;
	}
	if (figure == FIGURE_SMALL)
	{
		renderPosition = position + Vector2D(0, 14);
	}
	if (actionTimer > 0)
	{
		actionTimer -= delta;
	}
	else
	{
		actionTimer = 0.0f;
	}

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
		LPGAMEOBJECT obj = CheckGrounded();
		if (obj == NULL)
		{
			IsGrounded = false;
			TransitionTo(new FallState());
			DebugOut(L"[Mario.cpp] mario fall from ground\n");
		}
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
		else if (keyHandler->OnKeyUp(DIK_DOWN)&& dynamic_cast<SitState*>(this->state))
		{
			renderPosition = position;
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
		LPGAMEOBJECT obj = CheckGrounded();
		if (obj != NULL && dynamic_cast<FallState*>(this->state))
		{
			IsGrounded = true;
			position.SetY(obj->position.GetY() - height);
			TransitionTo(new IdleState());
		}
		else if (!dynamic_cast<FallState*>(this->state))
		{
			if (velocity.GetY() >= 0.0f)
			{
				TransitionTo(new FallState());
			}
			else if (velocity.GetY() > -20.0f && keyHandler->IsStillReleased(DIK_SPACE))
			{
				TransitionTo(new FallState());
			}
		}

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
	}
	if (keyHandler->OnKeyDown(DIK_B))
	{
		ChangeFigure(FIGURE_BIG);
	}
	else if (keyHandler->OnKeyDown(DIK_R))
	{
		ChangeFigure(FIGURE_RACCOON);
	}
	else if (keyHandler->OnKeyDown(DIK_S))
	{
		ChangeFigure(FIGURE_SMALL);
	}
	else if (keyHandler->OnKeyDown(DIK_F))
	{
		ChangeFigure(FIGURE_FIRE);
	}
	if (untouchableTimer > 0.0f)
	{
		untouchableTimer -= delta;
		return;
	}
	CollisionCheck();

}

void Mario::RenderAnimation()
{
	if (!isActivated)
	{
		return;
	}
	if (dynamic_cast<DeathState*>(this->state))
	{
		PlayAnimation(make_tuple(FIGURE_SMALL, STATE_DEATH, NULL));
	}
	else
	{
		PlayAnimation(make_tuple(figure, state->GetId(), direction));
	}
	
}

void Mario::ChangeFigure(int figure)
{
	if (figure == FIGURE_SMALL)
	{
		renderPosition = position + Vector2D(0, 14);
	}
	else
	{
		renderPosition = position;
	}
	untouchableTimer = ANI_LONG_TIME;
	this->figure = figure;
}

void Mario::CollisionCheck()
{
	// check with goomba
	LPGAMEOBJECT object = GameObjectManager::GetInstance()->GetGameObject(ID_GOOMBA_1);
	LPCOLLISIONEVENT colEvent = new CollisionEvent(this, object);

	if (colEvent->IsCollided() && object->isActivated)
	{
		if (colEvent->direction == Vector2D::Down())
		{
			object->TransitionTo(new DeathState());
			TransitionTo(new JumpState());
		}
		else
		{
			if (figure != FIGURE_SMALL)
			{
				ChangeFigure(FIGURE_SMALL);
			}
			else
			{
				IsGrounded = true;
				TransitionTo(new DeathState());
			}
		}
	}

	// check with koopa
	object = GameObjectManager::GetInstance()->GetGameObject(ID_KOOPA_1);
	colEvent = new CollisionEvent(this, object);
	if (colEvent->IsCollided() && object->isActivated)
	{
		if (colEvent->direction == Vector2D::Down())
		{
			if (dynamic_cast<RunState*>(object->state))
			{
				object->TransitionTo(new IdleState());
				TransitionTo(new JumpState());
			}
		}
		else if (dynamic_cast<IdleState*>(object->state))
		{
			object->TransitionTo(new CrazyState());
		}
		else
		{
			if (figure != FIGURE_SMALL)
			{
				ChangeFigure(FIGURE_SMALL);
			}
			else
			{
				IsGrounded = true;
				TransitionTo(new DeathState());
			}
		}
	}
	object = GameObjectManager::GetInstance()->GetGameObject(ID_GROUND_4);
	colEvent = new CollisionEvent(this, object);
	if (colEvent->IsColliding(this, object) && position.GetY() > object->position.GetY())
	{
		if (position.GetX() <= object->position.GetX())
		{
			position.SetX(object->position.GetX() - width);
		}
		else
		{
			position.SetX(object->position.GetX() + object->width);
		}

	}
}

LPGAMEOBJECT Mario::CheckGrounded()
{
	vector<LPGAMEOBJECT> list = GameObjectManager::GetInstance()->GetGameObject("Ground");
	list.push_back(GameObjectManager::GetInstance()->GetGameObject(ID_GROUND_4));
	for (auto obj : list)
	{
		LPCOLLISIONEVENT colEvent = new CollisionEvent(this, obj);
		if (obj->position.GetY() - position.GetY() >= height)
		{
			if (colEvent->IsCollided() && dynamic_cast<FallState*>(this->state))
			{
				if (colEvent->direction == Vector2D::Down())
				{
					return obj;
				}
			}
			else if (colEvent->IsColliding(this, obj))
			{
				return obj;
			}
		}
	}
	return NULL;
}