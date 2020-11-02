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

AnimationManager::AnimationManager()
{
	SpriteManager* spriteManager = SpriteManager::GetInstance();

	// Build big Mario run to right animation
	LPANIMATION ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10001));
	ani->Add(spriteManager->GetSprite(10002));
	ani->Add(spriteManager->GetSprite(10003));
	animations[ANI_MARIO_BIG_RUN_RIGHT] = ani;

	// Build small Mario run to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10011));
	ani->Add(spriteManager->GetSprite(10012));
	ani->Add(spriteManager->GetSprite(10013));
	animations[ANI_MARIO_SMALL_RUN_RIGHT] = ani;

	// Build big Mario run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10004));
	ani->Add(spriteManager->GetSprite(10005));
	ani->Add(spriteManager->GetSprite(10006));
	animations[ANI_MARIO_BIG_RUN_LEFT] = ani;

	// Build small Mario run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10014));
	ani->Add(spriteManager->GetSprite(10015));
	ani->Add(spriteManager->GetSprite(10016));
	animations[ANI_MARIO_SMALL_RUN_LEFT] = ani;

	// Build big Mario idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10001));
	animations[ANI_MARIO_BIG_IDLE_RIGHT] = ani;

	// Build small Mario idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10011));
	animations[ANI_MARIO_SMALL_IDLE_RIGHT] = ani;

	//Build big Mario idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10004));
	animations[ANI_MARIO_BIG_IDLE_LEFT] = ani;

	//Build small Mario idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10014));
	animations[ANI_MARIO_SMALL_IDLE_LEFT] = ani;

	//Build big Mario jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10007));
	animations[ANI_MARIO_BIG_JUMP_RIGHT] = ani;

	//Build small Mario jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10017));
	animations[ANI_MARIO_SMALL_JUMP_RIGHT] = ani;

	//Build big Mario jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10008));
	animations[ANI_MARIO_BIG_JUMP_LEFT] = ani;

	//Build small Mario jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10018));
	animations[ANI_MARIO_SMALL_JUMP_LEFT] = ani;

	//Build big Mario fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10003));
	animations[ANI_MARIO_BIG_FALL_RIGHT] = ani;

	//Build small Mario fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10013));
	animations[ANI_MARIO_SMALL_FALL_RIGHT] = ani;

	//Build big Mario fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10006));
	animations[ANI_MARIO_BIG_FALL_LEFT] = ani;

	//Build small Mario fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10016));
	animations[ANI_MARIO_SMALL_FALL_LEFT] = ani;

	// Big Mario switch to right
	ani = new Animation(300);
	ani->Add(spriteManager->GetSprite(10009));
	animations[ANI_MARIO_BIG_SWITCH_RIGHT] = ani;

	// Small Mario switch to right
	ani = new Animation(300);
	ani->Add(spriteManager->GetSprite(10019));
	animations[ANI_MARIO_SMALL_SWITCH_RIGHT] = ani;

	// Big Mario switch to right
	ani = new Animation(300);
	ani->Add(spriteManager->GetSprite(10010));
	animations[ANI_MARIO_BIG_SWITCH_LEFT] = ani;

	// Small Mario switch to right
	ani = new Animation(300);
	ani->Add(spriteManager->GetSprite(10020));
	animations[ANI_MARIO_SMALL_SWITCH_LEFT] = ani;

	//Build background animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10201));
	animations[ANI_BACKGROUND] = ani;

	//Build Goomba animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10301));
	ani->Add(spriteManager->GetSprite(10302));
	animations[ANI_GOOMBA_RUN] = ani;

	DebugOut(L"[INFO] Animations loaded Ok.\n");
}
