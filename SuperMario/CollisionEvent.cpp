#include "CollisionEvent.h"

CollisionEvent::CollisionEvent(const LPGAMEOBJECT& object, const LPGAMEOBJECT& other)
{
	direction = Vector2D::Zero();
	Box objectBox = object->GetBoundingBox();
	Box otherBox = other->GetBoundingBox();
	EntryTime = OnCollision(objectBox, otherBox);
}

bool CollisionEvent::IsCollided()
{
	if (EntryTime < COLLISION_TIME)
	{
		return true;
	}
	return false;
}

bool CollisionEvent::IsColliding(const Box& object, const Box& other)
{
	float left = other.left - object.right;
	float top = other.top - object.bottom;
	float right =  other.right - object.left;
	float bottom = other.bottom - object.top;

	return (left <= 0 && right >= 0 && top <= 0 && bottom >= 0);
}

bool CollisionEvent::IsColliding(const LPGAMEOBJECT& object, const LPGAMEOBJECT& other)
{
	return IsColliding(object->GetBoundingBox(), other->GetBoundingBox());
}

void CollisionEvent::findDistance(Box b1, Box b2, float& xInvEntry, float& yInvEntry, float& xInvExit, float& yInvExit)
{

	if (b1.velocity.GetX() > 0.0f)
	{
		xInvEntry = b2.left - b1.right;
		xInvExit = b2.right - b1.left;
	}
	else
	{
		xInvEntry = b2.right - b1.left;
		xInvExit = b2.left - b1.right;
	}

	if (b1.velocity.GetY() > 0.0f)
	{
		yInvEntry = b2.top - b1.bottom;
		yInvExit = b2.bottom - b1.top;
	}
	else
	{
		yInvEntry = b2.bottom - b1.top;
		yInvExit = b2.top - b1.bottom;
	}
}

Box CollisionEvent::getBroadphaseBox(Box b)
{
	Box broadphasebox;
	broadphasebox.left = b.velocity.GetX() > 0 ? b.left : b.left + b.velocity.GetX();
	broadphasebox.top = b.velocity.GetY() > 0 ? b.top : b.top + b.velocity.GetY();
	broadphasebox.right = b.velocity.GetX() > 0 ? b.right + b.velocity.GetX() : b.right;
	broadphasebox.bottom = b.velocity.GetY() > 0 ? b.bottom + b.velocity.GetY() : b.bottom;

	return broadphasebox;
}

float CollisionEvent::sweptAABB(Box b1, Box b2)
{
	float xInvEntry, yInvEntry;
	float xInvExit, yInvExit;

	// find the distance between the objects on the near and far sides for both x and y 
	findDistance(b1,b2, xInvEntry, yInvEntry, xInvExit, yInvExit);

	// find time of collision and time of leaving for each axis (if statement is to prevent divide by zero) 
	float xEntry, yEntry;
	float xExit, yExit;

	if (b1.velocity.GetX() == 0.0f)
	{
		xEntry = -std::numeric_limits<float>::infinity();
		xExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		xEntry = xInvEntry / b1.velocity.GetX();
		xExit = xInvExit / b1.velocity.GetX();
	}

	if (b1.velocity.GetY() == 0.0f)
	{
		yEntry = -std::numeric_limits<float>::infinity();
		yExit = std::numeric_limits<float>::infinity();
	}
	else
	{
		yEntry = yInvEntry / b1.velocity.GetY();
		yExit = yInvExit / b1.velocity.GetY();
	}

	// find the earliest/latest times of collision float 
	float entryTime = std::max(xEntry, yEntry);
	float exitTime = std::min(xExit, yExit);

	if (entryTime > exitTime || (xEntry < 0.0f && yEntry < 0.0f) || xEntry > 1.0f || yEntry > 1.0f)
	{
		direction.SetVector(0, 0);
		return 1.0f;
	}
	else // if there was a collision 
	{
		// calculate normal of collided surface
		if (xEntry > yEntry)
		{
			if (xInvEntry < 0.0f)
			{
				direction = Vector2D::Right();
			}
			else
			{
				direction = Vector2D::Left();
			}
		}
		else
		{
			if (yInvEntry < 0.0f)
			{
				direction = Vector2D::Down();
			}
			else
			{
				direction = Vector2D::Up();
			}
		} 
		return entryTime;
	}
}

float CollisionEvent::OnCollision(Box object, Box other)
{
	if (other.velocity != Vector2D::Zero())
	{
		object.velocity = object.velocity - other.velocity;
		other.velocity.SetVector(0, 0);	
	}

	Box box = getBroadphaseBox(object);
	if (!IsColliding(box, other))
	{
		direction = Vector2D::Zero();
		return 1.0f;
	}
	else
	{
		return sweptAABB(object, other);
	}
}

