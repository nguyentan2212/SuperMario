#include "DeathState.h"

void DeathState::StateHandle()
{
	stateId = STATE_DEATH;
	object->velocity.SetY(object->jumpSpeed);
	object->acceleration.SetY(GRAVITY);
}

