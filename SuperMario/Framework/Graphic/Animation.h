#pragma once
#include <vector>
#include <cmath>
#include "../Graphic/Sprite.h"

using namespace std;
class Animation
{
private:
	vector<LPSPRITE> frames;
	string name;
	int fps;
	int activeFrame = -1;
	double frameTime = -1;


public:
	Animation(int _fps, string _name) {
		fps = _fps;
		name = _name;
	}
	void AddSprite(LPSPRITE _sprite) {
		frames.push_back(_sprite);
	}
	void Render(Vector2D position);
	void Render(float x, float y) {
		Render(Vector2D(x, y));
	}
};
typedef Animation* LPANIMATION;