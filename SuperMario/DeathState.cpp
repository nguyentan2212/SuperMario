#include "DeathState.h"
#include "Goomba.h"
#include "Mario.h"

void DeathState::StateHandle()
{
	stateId = STATE_DEATH;
	if (object == NULL)
	{
		return;
	}
	if (dynamic_cast<Goomba*>(object))
	{
		object->velocity = Vector2D::Zero();
		object->acceleration = Vector2D::Zero();
		object->deathTimer = ANI_LONG_TIME;
	}
	else if (dynamic_cast<Mario*>(object))
	{
		object->deathTimer = ANI_LONG_TIME*5;
		object->velocity.SetY(MARIO_JUMP_SPEED/2);
		object->acceleration.SetY(GRAVITY);
	}
}

