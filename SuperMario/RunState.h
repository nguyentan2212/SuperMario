#pragma once
#include "BaseState.h"
class RunState :public BaseState
{ 
public:
	void StateHandle();
	int GetAnimation();
};

