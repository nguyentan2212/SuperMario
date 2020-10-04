#pragma once
#include <vector>
#include "GameObject.h"

using namespace std;

class Mario : public GameObject
{
public:
	Mario(float x, float y, float speed);
	Mario(const Vector2D& vec, float speed);

	void Update(float delta);
	void SetSprite(LPSPRITE sprite);
	void RenderSprite();
	void AddAnimation(LPANIMATION animation);
	void PlayAnimation(int index);
	void RenderAnimation();

private:
	float speed;
	vector<LPANIMATION> animations;
};

