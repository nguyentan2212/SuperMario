#pragma once
#include "GameObject.h"
#include "State.h"

class Goomba : public GameObject
{
public:
	Goomba(float x, float y, float speed);

	void Update(float delta);
	void RenderAnimation();
};

