#pragma once
#include "GameObject.h"
#include "State.h"
class Koopa : public GameObject
{
public:
	Koopa(float x, float y, float speed);
	void Update(float delta);
	void RenderAnimation();
};

