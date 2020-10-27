#include "FallState.h"

void FallState::StateHandle()
{
	if (object->velocity.GetY() < 0)
	{
		object->velocity.SetY(0);
	}
}

int FallState::GetAnimation()
{
	return object->direction * STATE_FALL;
}
