#pragma once
#include "BaseState.h"
class IdleState : public BaseState
{
public:
	void StateHandle();
	int GetAnimation();
};

