#pragma once
#define NOMINMAX
#include "GameObjectManager.h"
#include <limits> 

class CollisionEvent
{
public:
	CollisionEvent(const LPGAMEOBJECT& object, const LPGAMEOBJECT& other);
	bool IsCollided();
	bool IsColliding(const LPGAMEOBJECT& object, const LPGAMEOBJECT& other);
	bool IsColliding(const Box& object, const Box& other);
	Vector2D direction;
	float EntryTime;

private:
	float OnCollision(Box object, Box other);
	void findDistance(Box b1, Box b2, float& xInvEntry, float& yInvEntry, float& xInvExit, float& yInvExit);
	float sweptAABB(Box b1, Box b2);
	Box getBroadphaseBox(Box b);

};
typedef CollisionEvent* LPCOLLISIONEVENT;
