#pragma once
#include <unordered_map>
#include "GameDefine.h"
#include "Animation.h"
#include "SpriteManager.h"

using namespace std;

class AnimationManager
{
public:
	AnimationManager();
	static AnimationManager* GetInstance();
	void RenderAnimation(int id, Vector2D vec);
	void RenderAnimation(int id, float x, float y);
private:
	static AnimationManager* instance;
	unordered_map<int, LPANIMATION> animations;
};
