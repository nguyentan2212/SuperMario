#include "Koopa.h"

Koopa::Koopa(float x, float y, float speed):GameObject(x,y)
{
	this->runSpeed = speed;
	this->direction = -1;
	TransitionTo(new RunState());
}

void Koopa::Update(float delta)
{
	GameObject::Update(delta);
	DebugOut(L"[Koopa.cpp] state = %d\n", this->state->GetId());
	if (position.GetX() <= 0)
	{
		direction = 1;
	}
	if (position.GetX() >= 224)
	{
		direction = -1;
	}
	if (dynamic_cast<RunState*>(this->state))
	{
		TransitionTo(new RunState());
	}
	else if (dynamic_cast<CrazyState*>(this->state))
	{
		renderPosition = position + Vector2D(0, 13);
		TransitionTo(new CrazyState());
	}
}

void Koopa::RenderAnimation()
{
	if (!this->isActivated)
	{
		return;
	}
	if (dynamic_cast<RunState*>(this->state))
	{
		PlayAnimation(make_tuple(NULL, STATE_RUN, direction));
	}
	else
	{
		PlayAnimation(make_tuple(NULL, this->state->GetId(), NULL));
	}
	
}
