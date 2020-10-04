#include "Mario.h"
#include "Game.h"
#include "Debug.h"

#define MARIO_WIDTH 16

Mario::Mario(float x, float y, float speed): GameObject(x, y)
{
	this->speed = speed;
}

Mario::Mario(const Vector2D& vec, float speed): GameObject(vec)
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
		
		speed = -speed;
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
	if (speed > 0)
	{
		PlayAnimation(0);
	}
	else
	{
		PlayAnimation(1);
	}
}
