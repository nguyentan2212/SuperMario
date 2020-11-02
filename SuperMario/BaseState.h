#pragma once
#include "GameDefine.h"
#include "GameObject.h"

class GameObject;
class BaseState
{
public:
	virtual void StateHandle() = 0;
	int GetId() { return stateId; }
	void SetObject(GameObject* obj) {
		object = obj;
	}
	virtual ~BaseState(){
	}
protected:
	int stateId;
	GameObject* object;
};

