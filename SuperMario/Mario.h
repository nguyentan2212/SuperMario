#pragma once
#include <vector>
#include "GameObject.h"
#include "GameDefine.h"
#include "Camera.h"
#include "State.h"

using namespace std;

class Mario : public GameObject
{
public:
	Mario(float x, float y);
	Mario(const Vector2D& vec);

	void Update(float delta);		
	void RenderAnimation();
	void SetState(int state);	

	bool IsGrounded = true;	
};
