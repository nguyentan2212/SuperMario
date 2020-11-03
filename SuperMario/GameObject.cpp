#include "GameObject.h"

GameObject::GameObject(float x, float y):state(nullptr)
{
	this->velocity.SetVector(0, 0);
	this->acceleration.SetVector(0, 0);
	position.SetVector(x, y);
	renderPosition = position;
	height = 0;
	width = 0;
	keyHandler = NULL;
}

GameObject::GameObject(Vector2D vec) :state(nullptr)
{
	this->velocity.SetVector(0, 0);
	this->acceleration.SetVector(0, 0);
	position.SetVector(vec);
	renderPosition = position;
	height = 0;
	width = 0;
	keyHandler = NULL;
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
	delta /= 100;
	velocity = velocity + acceleration * delta / 2;
	position = position + velocity * delta;
	renderPosition = position;
}

void GameObject::PlayAnimation(ANITUPLE index)
{
	animations[index]->Render(renderPosition);
}

// figure, state or action, direction, animation's pointer
void GameObject::AddAnimation(int figure, int state, int direction, LPANIMATION ani)
{
	ANITUPLE key = make_tuple(figure, state, direction);
	animations[key] = ani;
}

void GameObject::TransitionTo(BaseState* state)
{
	if (this->state != nullptr)
		delete this->state;
	this->state = state;
	this->state->SetObject(this);
	this->state->StateHandle();
}
