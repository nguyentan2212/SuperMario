#include "Mario.h"
#include "Game.h"
#include "Debug.h"
#include <math.h>

#define MARIO_WIDTH 16
#define GRAVITY 20

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
	int backBufferWidth = Game::GetInstance()->GetBackBufferWidth();
	float vx = velocity.GetX() + 1.0 / 2.0 * acceleration.GetX() * delta * delta;
	float dx = vx * delta;
	float x = dx + position.GetX();
	if (x <= 0)
	{
		position.SetX(0);	
	}
	else if (x >= backBufferWidth - MARIO_WIDTH)
	{
		float tempX = (float)(backBufferWidth - MARIO_WIDTH);
		position.SetX(tempX);		
	}	
	float ay = acceleration.GetY() * delta * delta / 2;
	float vy = velocity.GetY() + acceleration.GetY() * delta * delta / 2;
	float dy = vy * delta;
	float y = dy + position.GetY();
	DebugOut(L"[INFO]vy = %f, dy = %f, ay = %f \n", vy, dy, ay);
	if (y > 200)
	{
		y = 200;
		acceleration.SetY(0);
		DebugOut(L"[INFO] ay = 0");
	}
	velocity.SetVector(vx, vy);
	position.SetVector(x, y);
	
	
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
		if (direction.GetX() > 0)
		{
			PlayAnimation(2);
		}
		else
		{
			PlayAnimation(3);
		}		
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
	default:
		this->state = MARIO_STATE_IDLE;
		velocity.SetX(0);
		break;
	}
	DebugOut(L"[INFO] position x = %f, speed = %f \n", direction.GetX(), velocity.GetY());
}
