#include "SitState.h"

void SitState::StateHandle()
{
	stateId = STATE_SIT;
	object->acceleration.SetVector(0, 0);
	object->velocity.SetVector(0, 0);
}
