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

void GameObject::Update(float delta)
{
	velocity = velocity + acceleration * delta * delta / 2;
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
