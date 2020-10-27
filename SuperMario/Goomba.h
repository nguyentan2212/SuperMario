#pragma once
#include "GameObject.h"
#include "State.h"

class Goomba : public GameObject
{
public:
	Goomba(float x, float y, float speed) :GameObject(x, y)
	{
		this->runSpeed = speed;
		this->jumpSpeed = 0;
		TransitionTo(new IdleState());
		direction = -1;
	}
	void Update(float delta);
	void RenderAnimation();
	void SetState(int state);
};

