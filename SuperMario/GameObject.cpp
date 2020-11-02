#include "GameObject.h"

GameObject::GameObject(float x, float y):state(nullptr)
{
	position.SetVector(x, y);
	this->velocity.SetVector(0, 0);
	this->acceleration.SetVector(0, 0);
}

GameObject::GameObject(Vector2D vec) :state(nullptr)
{
	position.SetVector(vec);
	this->velocity.SetVector(0, 0);
	this->acceleration.SetVector(0, 0);
}

Box GameObject::GetBoundingBox()
{
	Box rect;
	rect.left = position.GetX();
	rect.top = position.GetY();
	rect.right = rect.left + width;
	rect.bottom = rect.top + height;
	rect.velocity.SetVector(velocity);
	return rect;
}

void GameObject::Update(float delta)
{
	velocity = velocity + acceleration * delta / 2;
	position = position + velocity * delta;
}

void GameObject::PlayAnimation(int index)
{
	AnimationManager* anis = AnimationManager::GetInstance();
	anis->RenderAnimation(index, position);
}

void GameObject::TransitionTo(BaseState* state)
{
	if (this->state != nullptr)
		delete this->state;
	this->state = state;
	this->state->SetObject(this);
	this->state->StateHandle();
}
