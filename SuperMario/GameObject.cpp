#include "GameObject.h"

GameObject::GameObject(float x, float y)
{
	position.SetVector(x, y);
}

GameObject::GameObject(Vector2D vec)
{
	position.SetVector(vec);
}

void GameObject::SetPosition(float x, float y)
{
	position.SetVector(x, y);
}

void GameObject::SetPosition(Vector2D vec)
{
	position.SetVector(vec);
}
