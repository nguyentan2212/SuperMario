#include "RunState.h"


void RunState::StateHandle()
{
	stateId = STATE_RUN;
	object->velocity.SetVector(object->runSpeed * object->direction,0);
	object->acceleration.SetVector(0, 0);
}

