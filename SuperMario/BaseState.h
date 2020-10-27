#pragma once
#include "GameDefine.h"
#include "GameObject.h"
#include "GameDefine.h"

class GameObject;
class BaseState
{
public:
	virtual void StateHandle() = 0;
	virtual int GetAnimation() = 0;
	void SetObject(GameObject* obj) {
		object = obj;
	}
	virtual ~BaseState(){
	}
protected:
	GameObject* object;
};

