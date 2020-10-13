#pragma once
#include <vector>
#include "GameObject.h"
#include "GameDefine.h"

using namespace std;

class Mario : public GameObject
{
public:
	Mario(float x, float y, float speed = 0, Vector2D direction = Vector2D::Right());
	Mario(const Vector2D& vec, float speed = 0, Vector2D direction = Vector2D::Right());

	void Update(float delta);		
	void PlayAnimation(int index);
	void RenderAnimation();
	void SetState(int state);

private:

	Vector2D velocity;
	Vector2D acceleration;	
};
