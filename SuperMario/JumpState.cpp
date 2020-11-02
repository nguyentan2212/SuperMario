#include "JumpState.h"

void JumpState::StateHandle()
{
	stateId = STATE_JUMP;
	object->velocity.SetY(object->jumpSpeed);
	object->acceleration.SetY(GRAVITY);
}

