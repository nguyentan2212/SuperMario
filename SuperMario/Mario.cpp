#include "Mario.h"
#include "Game.h"
#include "Debug.h"

#define MARIO_WIDTH 16

Mario::Mario(float x, float y, float speed, Vector2D direction): GameObject(x, y, direction)
{
	this->speed = speed;
}

Mario::Mario(const Vector2D& vec, float speed, Vector2D direction): GameObject(vec, direction)
{
	this->speed = speed;
}

void Mario::Update(float delta)
{
	int backBufferWidth = Game::GetInstance()->GetBackBufferWidth();
	float dx = speed * delta / 100;
	float x = dx + position.GetX();
	if (x <= 0 || x >= backBufferWidth - MARIO_WIDTH)
	{
		
		speed = 0;
		if (x <= 0)
		{
			x = 0;
		}
		else if (x >= backBufferWidth - MARIO_WIDTH)
		{
			x = (float)(backBufferWidth - MARIO_WIDTH);
		}
	}

	position.SetVector(x, position.GetY());
}

void Mario::SetSprite(LPSPRITE sprite)
{
}

void Mario::RenderSprite()
{
}

void Mario::AddAnimation(LPANIMATION animation)
{
	animations.push_back(animation);
}

void Mario::PlayAnimation(int index)
{
	if (index >= animations.size())
	{
		return;
	}
	animations[index]->Render(position);
}

void Mario::RenderAnimation()
{
	switch (this->state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		PlayAnimation(0);
		break;
	case MARIO_STATE_WALKING_LEFT:
		PlayAnimation(1);
		break;
	case MARIO_STATE_JUMP:
		break;
	case MARIO_STATE_IDLE:
		if (direction.GetX() > 0)
		{
			PlayAnimation(2);
		}
		else
		{
			PlayAnimation(3);
		}
		break;
	}
	
}

void Mario::SetState(int state)
{
	this->state = state;
	switch (state)
	{
	case MARIO_STATE_WALKING_RIGHT:
		speed = MARIO_WALKING_SPEED;
		this->direction.SetVector(Vector2D::Right());		
		break;
	case MARIO_STATE_WALKING_LEFT:
		speed = -MARIO_WALKING_SPEED;
		this->direction.SetVector(Vector2D::Left());		
		break;
	case MARIO_STATE_JUMP:
		break;
	default:
		this->state = MARIO_STATE_IDLE;
		speed = 0;
		break;
	}
	DebugOut(L"[INFO] position x = %f, speed = %f \n", direction.GetX(), speed);
}
