#pragma once
#include "Vector2D.h"
#include "Animation.h"
#include "Sprite.h"

class GameObject
{
public:
	GameObject(float x, float y);
	GameObject(Vector2D vec);
	void SetPosition(float x, float y);
	void SetPosition(Vector2D vec);
	Vector2D GetPosition(){ return position; }
	
	virtual void Update(float delta) = 0;
	virtual void SetSprite(LPSPRITE sprite) = 0;
	virtual void RenderSprite() = 0;
	virtual void AddAnimation(LPANIMATION animation) = 0;
	virtual void PlayAnimation(int index) = 0;
	virtual void RenderAnimation() = 0;
protected:
	Vector2D position;
	//LPSPRITE sprite;// Object can have many sprites
	//vector<LPANIMATION> animations;
};

