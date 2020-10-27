#include "JumpState.h"

void JumpState::StateHandle()
{
	object->velocity.SetY(object->jumpSpeed);
	object->acceleration.SetY(GRAVITY);
}

int JumpState::GetAnimation()
{
	return object->direction * STATE_JUMP;
}
