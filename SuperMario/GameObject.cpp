#include "GameObject.h"

GameObject::GameObject(float x, float y, Vector2D direction)
{
	position.SetVector(x, y);
	state = 0;
	this->direction.SetVector(direction);
}

GameObject::GameObject(Vector2D vec, Vector2D direction)
{
	position.SetVector(vec);
	state = 0;
	this->direction.SetVector(direction);
}
