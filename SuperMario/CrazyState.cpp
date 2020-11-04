#include "CrazyState.h"

void CrazyState::StateHandle()
{
	stateId = STATE_CRAZY;
	object->velocity.SetX(MARIO_SUPER_RUN_SPEED * object->direction);
}
