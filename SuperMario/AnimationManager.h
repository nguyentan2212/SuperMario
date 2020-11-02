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
	LPANIMATION GetAnimation(int index) { return animations[index]; }
	static AnimationManager* GetInstance();
private:
	static AnimationManager* instance;
	unordered_map<int, LPANIMATION> animations;
};
