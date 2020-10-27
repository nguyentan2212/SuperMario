#include "Goomba.h"

void Goomba::Update(float delta)
{
	delta /= 100; // Convert delta from millisecond to 1/10 second
	GameObject::Update(delta);
	if (position.GetX() <= 0)
	{
		direction = 1;
		SetState(STATE_RUN);
	}
	if (position.GetX() >= 224)
	{
		direction = -1;
		SetState(STATE_RUN);
	}
}

void Goomba::RenderAnimation()
{
	if (!isActivated)
	{
		return;
	}
	PlayAnimation(ANI_GOOMBA_RUN);
}

void Goomba::SetState(int state)
{
	if (state == STATE_RUN)
	{
		TransitionTo(new RunState());
	}
}
