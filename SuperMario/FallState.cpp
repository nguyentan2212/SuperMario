#include "FallState.h"

void FallState::StateHandle()
{
	stateId = STATE_FALL;
	object->acceleration.SetY(GRAVITY);
	if (object->velocity.GetY() < 0)
	{
		object->velocity.SetY(0);
	}
}

