#pragma once
#include "Vector2D.h"
#include "Animation.h"
#include "AnimationManager.h"
#include "BaseState.h"
#include "KeyHandler.h"

class BaseState;

struct Box
{
	float left, top, right, bottom;
	Vector2D velocity;
};

class GameObject
{
public:
	GameObject(float x, float y);
	GameObject(Vector2D vec);	
	~GameObject() {
		delete state;
	}

	Box GetBoundingBox();
	void SetKeyHandler(LPKEYHANDLER keyHandler) {
		this->keyHandler = keyHandler;
	}
	virtual void Update(float delta);
	virtual void PlayAnimation(int index);
	virtual void RenderAnimation(){}
	virtual void TransitionTo(BaseState* state);

	Vector2D position;
	int direction = 1;
	Vector2D velocity = Vector2D();
	Vector2D acceleration = Vector2D();
	float runSpeed = 0;
	float jumpSpeed = 0;
	bool isActivated = true;
	string tag = "";
protected:
	BaseState* state;
	int height;
	int width;
	LPKEYHANDLER keyHandler;
};

typedef GameObject* LPGAMEOBJECT;

