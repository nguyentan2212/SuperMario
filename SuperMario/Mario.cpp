#include "Mario.h"
#include "Game.h"
#include "Debug.h"
#include <math.h>

Mario::Mario(float x, float y, float speed, Vector2D direction): GameObject(x, y, direction)
{	
	this->velocity.SetVector(speed, 0);
	this->acceleration.SetVector(0, 0);
}

Mario::Mario(const Vector2D& vec, float speed, Vector2D direction): GameObject(vec, direction)
{	
	this->velocity.SetVector(speed, 0);
	this->acceleration.SetVector(0, 0);
}

void Mario::Update(float delta)
{
	delta /= 100;	
	int gameWidth = Game::GetInstance()->GetBackBufferWidth()/3 + 3;
	float vx = velocity.GetX() + 1.0 / 2.0 * acceleration.GetX() * delta * delta;
	float dx = vx * delta;
	float x = dx + position.GetX();
	if (x <= 0)
	{
		x = 0;
	}
	else if (x >= 2816 - MARIO_WIDTH)
	{
		float tempX = (float)(2816 - MARIO_WIDTH);
		x = tempX;
	}	
	float ay = acceleration.GetY() * delta * delta / 2;
	float vy = velocity.GetY() + acceleration.GetY() * delta * delta / 2;
	velocity.SetVector(vx, vy);
	if (vy >= 0 && this->state == MARIO_STATE_JUMP)
	{
		SetState(MARIO_STATE_FALL);
	}
	float dy = vy * delta;
	float y = dy + position.GetY();
	//DebugOut(L"[INFO] Mario position x = %f, y = %f \n", x, y);
	if (y > 150 && this->state == MARIO_STATE_FALL)
	{
		y = 150;
		SetState(MARIO_STATE_IDLE);
		DebugOut(L"[INFO] grounded 0 \n");
	}
	position.SetVector(x, y);

	LPCAMERA camera = Camera::GetInstance();
	float cx = x - gameWidth/2.0f;
	if (cx < 0)
	{
		cx = 0;
	}
	else if (cx > 2816 - gameWidth)
	{
		cx = 2816 - gameWidth;
	}
	camera->position.SetX(cx);
	DebugOut(L"[INFO] Camera x = %f, Mario = %f \n", cx, x);
}

void Mario::RenderAnimation()
{
	
	switch (this->state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		PlayAnimation(ANI_MARIO_BIG_RUN_RIGHT);
		break;
	case MARIO_STATE_WALKING_LEFT:
		PlayAnimation(ANI_MARIO_BIG_RUN_LEFT);
		break;
	case MARIO_STATE_JUMP:
		if (direction.GetX() > 0)
		{
			PlayAnimation(ANI_MARIO_BIG_JUMP_RIGHT);
		}
		else
		{
			PlayAnimation(ANI_MARIO_BIG_JUMP_LEFT);
		}		
		break;
	case MARIO_STATE_FALL:
		if (direction.GetX() > 0)
		{
			PlayAnimation(ANI_MARIO_BIG_FALL_RIGHT);
		}
		else
		{
			PlayAnimation(ANI_MARIO_BIG_FALL_LEFT);
		}
		break;
	case MARIO_STATE_IDLE:
		if (direction.GetX() > 0)
		{
			PlayAnimation(ANI_MARIO_BIG_IDLE_RIGHT);
		}
		else
		{
			PlayAnimation(ANI_MARIO_BIG_IDLE_LEFT);
		}
		break;
	}
	
}

void Mario::SetState(int state)
{
	DebugOut(L"[INFO] old state = %d, new state = %d \n", this->state, state);
	this->state = state;
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		velocity.SetX(MARIO_WALKING_SPEED);
		direction.SetVector(Vector2D::Right());		
		break;
	case MARIO_STATE_WALKING_LEFT:
		velocity.SetX(-MARIO_WALKING_SPEED);
		direction.SetVector(Vector2D::Left());		
		break;
	case MARIO_STATE_JUMP:
		acceleration.SetY(GRAVITY);
		velocity.SetY(MARIO_JUMP_SPEED);
		break;
	case MARIO_STATE_FALL:
		velocity.SetY(0);
		break;
	default:
		this->state = MARIO_STATE_IDLE;
		velocity.SetVector(0, 0);
		acceleration.SetY(0);
		break;
	}
}
