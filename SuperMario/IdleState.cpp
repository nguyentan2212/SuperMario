#include "IdleState.h"


void IdleState::StateHandle()
{
	stateId = STATE_IDLE;
	object->acceleration.SetVector(0, 0);
	object->velocity.SetVector(0, 0);
}

