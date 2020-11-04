#include "Goomba.h"

Goomba::Goomba(float x, float y, float speed):GameObject(x,y)
{
	this->runSpeed = speed;
	this->jumpSpeed = 0;
	TransitionTo(new RunState());
	direction = -1;
	width = GOOMBA_WIDTH;
	height = GOOMBA_HEIGHT;
	tag = "Goomba";

}

void Goomba::Update(float delta)
{
	GameObject::Update(delta);
	if (position.GetX() <= 0)
	{
		direction = 1;
		TransitionTo(new RunState());
	}
	if (position.GetX() >= 224)
	{
		direction = -1;
		TransitionTo(new RunState());
	}
}

void Goomba::RenderAnimation()
{
	if (!isActivated)
	{
		return;
	}	
	PlayAnimation(make_tuple(NULL, state->GetId(), NULL));
}
