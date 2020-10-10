#pragma once
#include <vector>
#include "GameObject.h"

#define MARIO_STATE_IDLE			0
#define MARIO_STATE_WALKING_RIGHT	100
#define MARIO_STATE_WALKING_LEFT	200
#define MARIO_STATE_JUMP			300
#define MARIO_WALKING_SPEED         10
using namespace std;

class Mario : public GameObject
{
public:
	Mario(float x, float y, float speed = 0, Vector2D direction = Vector2D::Right());
	Mario(const Vector2D& vec, float speed = 0, Vector2D direction = Vector2D::Right());

	void Update(float delta);
	void SetSprite(LPSPRITE sprite);
	void RenderSprite();
	void AddAnimation(LPANIMATION animation);
	void PlayAnimation(int index);
	void RenderAnimation();
	void SetState(int state);

private:
	float speed;
	vector<LPANIMATION> animations;	
	
};

