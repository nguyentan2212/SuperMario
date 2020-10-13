#include "AnimationManager.h"

AnimationManager* AnimationManager::instance = NULL;

AnimationManager* AnimationManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new AnimationManager();
	}
	return instance;
}

void AnimationManager::RenderAnimation(int id, float x, float y)
{
	animations[id]->Render(x, y);
}

void AnimationManager::RenderAnimation(int id, Vector2D vec)
{
	animations[id]->Render(vec);
}

AnimationManager::AnimationManager()
{
	SpriteManager* spriteManager = SpriteManager::GetInstance();

	// Build Mario run to right animation
	LPANIMATION ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10001));
	ani->Add(spriteManager->GetSprite(10002));
	ani->Add(spriteManager->GetSprite(10003));
	animations[ANI_MARIO_BIG_RUN_RIGHT] = ani;

	// Build Mario run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10004));
	ani->Add(spriteManager->GetSprite(10005));
	ani->Add(spriteManager->GetSprite(10006));
	animations[ANI_MARIO_BIG_RUN_LEFT] = ani;

	// Build Mario idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10001));
	animations[ANI_MARIO_BIG_IDLE_RIGHT] = ani;

	//Build Mario idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10004));
	animations[ANI_MARIO_BIG_IDLE_LEFT] = ani;

	//Build Mario jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10007));
	animations[ANI_MARIO_BIG_JUMP_RIGHT] = ani;

	//Build Mario jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10008));
	animations[ANI_MARIO_BIG_JUMP_LEFT] = ani;

	//Build Mario fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10003));
	animations[ANI_MARIO_BIG_FALL_RIGHT] = ani;

	//Build Mario fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10006));
	animations[ANI_MARIO_BIG_FALL_LEFT] = ani;
}
