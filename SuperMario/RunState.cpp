#include "RunState.h"


void RunState::StateHandle()
{
	object->velocity.SetVector(object->runSpeed * object->direction,0);
	object->acceleration.SetVector(0, 0);
}

int RunState::GetAnimation()
{
	return object->direction * STATE_RUN;
}
