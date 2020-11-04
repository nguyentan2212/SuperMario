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
#pragma region Big Mario animations
	// Build big Mario run to right animation
	LPANIMATION ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10001));
	ani->Add(spriteManager->GetSprite(10002));
	ani->Add(spriteManager->GetSprite(10003));
	animations[ANI_MARIO_BIG_RUN_RIGHT] = ani;

	// Build big Mario run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10004));
	ani->Add(spriteManager->GetSprite(10005));
	ani->Add(spriteManager->GetSprite(10006));
	animations[ANI_MARIO_BIG_RUN_LEFT] = ani;

	// Build big Mario idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10001));
	animations[ANI_MARIO_BIG_IDLE_RIGHT] = ani;

	//Build big Mario idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10004));
	animations[ANI_MARIO_BIG_IDLE_LEFT] = ani;

	//Build big Mario jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10007));
	animations[ANI_MARIO_BIG_JUMP_RIGHT] = ani;

	//Build big Mario jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10008));
	animations[ANI_MARIO_BIG_JUMP_LEFT] = ani;

	//Build big Mario fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10003));
	animations[ANI_MARIO_BIG_FALL_RIGHT] = ani;

	//Build big Mario fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10006));
	animations[ANI_MARIO_BIG_FALL_LEFT] = ani;

	// Big Mario switch to right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10009));
	animations[ANI_MARIO_BIG_SWITCH_RIGHT] = ani;

	// Big Mario switch to left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10010));
	animations[ANI_MARIO_BIG_SWITCH_LEFT] = ani;

	// kick right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10053));
	animations[ANI_MARIO_BIG_KICK_RIGHT] = ani;

	// kick left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10054));
	animations[ANI_MARIO_BIG_KICK_LEFT] = ani;

	// sit right
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10041));
	animations[ANI_MARIO_BIG_SIT_RIGHT] = ani;

	// sit left
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10042));
	animations[ANI_MARIO_BIG_SIT_LEFT] = ani;
#pragma endregion	
#pragma region Small Mario animations
	// Build small Mario run to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10011));
	ani->Add(spriteManager->GetSprite(10012));
	ani->Add(spriteManager->GetSprite(10013));
	animations[ANI_MARIO_SMALL_RUN_RIGHT] = ani;

	// Build small Mario run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10014));
	ani->Add(spriteManager->GetSprite(10015));
	ani->Add(spriteManager->GetSprite(10016));
	animations[ANI_MARIO_SMALL_RUN_LEFT] = ani;

	// Build small Mario idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10011));
	animations[ANI_MARIO_SMALL_IDLE_RIGHT] = ani;

	//Build small Mario idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10014));
	animations[ANI_MARIO_SMALL_IDLE_LEFT] = ani;

	//Build small Mario jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10017));
	animations[ANI_MARIO_SMALL_JUMP_RIGHT] = ani;

	//Build small Mario jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10018));
	animations[ANI_MARIO_SMALL_JUMP_LEFT] = ani;

	//Build small Mario fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10013));
	animations[ANI_MARIO_SMALL_FALL_RIGHT] = ani;

	//Build small Mario fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10016));
	animations[ANI_MARIO_SMALL_FALL_LEFT] = ani;

	// Small Mario switch to right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10019));
	animations[ANI_MARIO_SMALL_SWITCH_RIGHT] = ani;

	// Small Mario switch to left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10020));
	animations[ANI_MARIO_SMALL_SWITCH_LEFT] = ani;

	// kick right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10051));
	animations[ANI_MARIO_SMALL_KICK_RIGHT] = ani;

	// kick left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10052));
	animations[ANI_MARIO_SMALL_KICK_LEFT] = ani;

	// Mario death
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10059));
	animations[ANI_MARIO_SMALL_DEATH] = ani;
#pragma endregion
#pragma region Raccoon Mario animations
	//run to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10021));
	ani->Add(spriteManager->GetSprite(10022));
	ani->Add(spriteManager->GetSprite(10023));
	animations[ANI_MARIO_RACCOON_RUN_RIGHT] = ani;

	//run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10024));
	ani->Add(spriteManager->GetSprite(10025));
	ani->Add(spriteManager->GetSprite(10026));
	animations[ANI_MARIO_RACCOON_RUN_LEFT] = ani;

	//idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10021));
	animations[ANI_MARIO_RACCOON_IDLE_RIGHT] = ani;

	//idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10024));
	animations[ANI_MARIO_RACCOON_IDLE_LEFT] = ani;

	//jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10027));
	animations[ANI_MARIO_RACCOON_JUMP_RIGHT] = ani;

	//jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10028));
	animations[ANI_MARIO_RACCOON_JUMP_LEFT] = ani;

	//fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10023));
	animations[ANI_MARIO_RACCOON_FALL_RIGHT] = ani;

	//fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10026));
	animations[ANI_MARIO_RACCOON_FALL_LEFT] = ani;

	//switch to right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10029));
	animations[ANI_MARIO_RACCOON_SWITCH_RIGHT] = ani;

	//switch to left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10030));
	animations[ANI_MARIO_RACCOON_SWITCH_LEFT] = ani;

	// kick right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10055));
	animations[ANI_MARIO_RACCOON_KICK_RIGHT] = ani;

	// kick left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10056));
	animations[ANI_MARIO_RACCOON_KICK_LEFT] = ani;

	// sit right
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10045));
	ani->Add(spriteManager->GetSprite(10046));
	ani->Add(spriteManager->GetSprite(10047));
	animations[ANI_MARIO_RACCOON_SIT_RIGHT] = ani;

	// sit left
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10048));
	ani->Add(spriteManager->GetSprite(10049));
	ani->Add(spriteManager->GetSprite(10050));
	animations[ANI_MARIO_RACCOON_SIT_LEFT] = ani;
#pragma endregion
#pragma region Fire Mario animations
	//run to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10031));
	ani->Add(spriteManager->GetSprite(10032));
	ani->Add(spriteManager->GetSprite(10033));
	animations[ANI_MARIO_FIRE_RUN_RIGHT] = ani;

	//run to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10034));
	ani->Add(spriteManager->GetSprite(10035));
	ani->Add(spriteManager->GetSprite(10036));
	animations[ANI_MARIO_FIRE_RUN_LEFT] = ani;

	//idle to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10031));
	animations[ANI_MARIO_FIRE_IDLE_RIGHT] = ani;

	//idle to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10034));
	animations[ANI_MARIO_FIRE_IDLE_LEFT] = ani;

	//jump to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10037));
	animations[ANI_MARIO_FIRE_JUMP_RIGHT] = ani;

	//jump to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10038));
	animations[ANI_MARIO_FIRE_JUMP_LEFT] = ani;

	//fall to right animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10033));
	animations[ANI_MARIO_FIRE_FALL_RIGHT] = ani;

	//fall to left animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10036));
	animations[ANI_MARIO_FIRE_FALL_LEFT] = ani;

	//switch to right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10039));
	animations[ANI_MARIO_FIRE_SWITCH_RIGHT] = ani;

	//switch to left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10030));
	animations[ANI_MARIO_FIRE_SWITCH_LEFT] = ani;

	// kick right
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10057));
	animations[ANI_MARIO_FIRE_KICK_RIGHT] = ani;

	// kick left
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10058));
	animations[ANI_MARIO_FIRE_KICK_LEFT] = ani;

	// sit right
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10043));
	animations[ANI_MARIO_FIRE_SIT_RIGHT] = ani;

	// sit left
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10044));
	animations[ANI_MARIO_FIRE_SIT_LEFT] = ani;
#pragma endregion

	
	//Build background animation
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10201));
	animations[ANI_BACKGROUND] = ani;
#pragma region Goomba animations
	//Build Goomba animation run
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10301));
	ani->Add(spriteManager->GetSprite(10302));
	animations[ANI_GOOMBA_RUN] = ani;

	// Goomba death animation
	ani = new Animation(ANI_LONG_TIME);
	ani->Add(spriteManager->GetSprite(10303));
	animations[ANI_GOOMBA_DEATH] = ani;
#pragma endregion
#pragma region Koopa animations
	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10401));
	ani->Add(spriteManager->GetSprite(10402));
	animations[ANI_KOOPA_RUN_LEFT] = ani;

	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10403));
	ani->Add(spriteManager->GetSprite(10404));
	animations[ANI_KOOPA_RUN_RIGHT] = ani;

	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10405));
	ani->Add(spriteManager->GetSprite(10406));
	ani->Add(spriteManager->GetSprite(10407));
	ani->Add(spriteManager->GetSprite(10408));
	animations[ANI_KOOPA_CRAZY] = ani;

	ani = new Animation(ANI_DEFAULT_TIME);
	ani->Add(spriteManager->GetSprite(10409));
	animations[ANI_KOOPA_STUN] = ani;
#pragma endregion

	

	DebugOut(L"[INFO] Animations loaded Ok.\n");
}
