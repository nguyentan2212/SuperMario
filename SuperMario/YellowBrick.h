#pragma once
#include "GameObject.h"

using namespace std;

class YellowBrick : public GameObject
{
public:
	YellowBrick(float x, float y) : GameObject(x, y){}
	YellowBrick(Vector2D vec) : GameObject(vec){}

	void Update(float delta){}
	void SetSprite(LPSPRITE sprite){}
	void RenderSprite(){}
	void AddAnimation(LPANIMATION animation){ animations.push_back(animation); }
	void PlayAnimation(int index){ if (index < animations.size()) animations[index]->Render(position); }
	void RenderAnimation() { PlayAnimation(0); }

private:
	vector<LPANIMATION> animations;
};

