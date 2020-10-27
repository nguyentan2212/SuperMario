#include "IdleState.h"


void IdleState::StateHandle()
{
	object->acceleration.SetVector(0, 0);
	object->velocity.SetVector(0, 0);

}

int IdleState::GetAnimation()
{
	return object->direction * STATE_IDLE;
}
