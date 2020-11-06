#pragma once
#include <vector>
#include "GameObject.h"
#include "GameDefine.h"
#include "Camera.h"
#include "State.h"
#include "CollisionEvent.h"

using namespace std;

class Mario : public GameObject
{
public:
	Mario(float x, float y);
	Mario(const Vector2D& vec);

	void Update(float delta);		
	void RenderAnimation();
	void ChangeFigure(int figure);
	bool IsGrounded = true;	
	float runningTimer = 0.0f;
	float actionTimer = 0.0f;

private:
	float untouchableTimer = 0.0f;
	void CollisionCheck();
	LPGAMEOBJECT CheckGrounded();
};
