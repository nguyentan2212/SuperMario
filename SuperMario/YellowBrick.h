#pragma once
#include "GameObject.h"

using namespace std;

class YellowBrick : public GameObject
{
public:
	YellowBrick(float x, float y, float height, float width) : GameObject(x, y) { 
		this->height = height; 
		this->width = width; 
		this->tag = "Ground";
	}
	YellowBrick(Vector2D vec) : GameObject(vec) {
		this->height = height;
		this->width = width;
		this->tag = "Ground";
	}

	void Update(float delta){}
	void SetSprite(LPSPRITE sprite) {
		this->sprite = sprite;
	}
	void RenderAnimation() {
		//this->sprite->Draw(position);
	}

private:
	LPSPRITE sprite = NULL;
};

