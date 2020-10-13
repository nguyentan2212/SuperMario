#pragma once
#include "AnimationFrame.h"
#include "Vector2D.h"
#include <vector>

class Animation
{
public:
	Animation(int defaultTime) { this->defaultTime = defaultTime; lastFrameTime = -1; currentFrame = -1; if (!frames.empty()) frames.clear(); }
	void Add(LPSPRITE sprite, DWORD time = 0);
	void Render(float x, float y);
	void Render(Vector2D vec) { Render(vec.GetX(), vec.GetY()); }
	
private:
	std::vector<LPANIMATIONFRAME> frames;
	DWORD lastFrameTime;
	DWORD defaultTime;
	int currentFrame;
};

typedef Animation* LPANIMATION;

