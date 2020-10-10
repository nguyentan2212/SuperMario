#pragma once
#include "Vector2D.h"
#include "Animation.h"
#include "Sprite.h"

class GameObject
{
public:
	GameObject(float x, float y, Vector2D direction = Vector2D::Right());
	GameObject(Vector2D vec, Vector2D direction = Vector2D::Right());	
	virtual void SetState(int state) { this->state = state; }
	int GetState() { return this->state; }
	

	virtual void Update(float delta) = 0;
	virtual void SetSprite(LPSPRITE sprite){}
	virtual void RenderSprite(){}
	virtual void AddAnimation(LPANIMATION animation) = 0;
	virtual void PlayAnimation(int index) = 0;
	virtual void RenderAnimation() = 0;

	Vector2D position;
	Vector2D force;
	Vector2D direction;
protected:
	
	int state;
	
	//Vector2D velocity;
	//Vector2D gravity;
	//LPSPRITE sprite;// Object can have many sprites
	//vector<LPANIMATION> animations;
};

