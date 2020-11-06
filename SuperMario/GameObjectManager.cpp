#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::instance = NULL;

GameObjectManager::GameObjectManager()
{
    AnimationManager* am = AnimationManager::GetInstance();

    GameObject* obj;
#pragma region Ground
    obj = new YellowBrick(0, 176, 0.2f, 623);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10101));
    gameObjects[ID_GROUND_1] = obj;
    
    obj = new YellowBrick(240, 128, 0.2f, 47);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10101));
    gameObjects[ID_GROUND_2] = obj;
    
    obj = new YellowBrick(272, 96, 0.2f, 47);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10101));
    gameObjects[ID_GROUND_3] = obj;
    
    obj = new YellowBrick(352, 128, 47, 31);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10102));
    obj->tag = "pipe";
    gameObjects[ID_GROUND_4] = obj;

    obj = new YellowBrick(400, 128, 0.2f, 79);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10102));
    gameObjects[ID_GROUND_5] = obj;
    
    obj = new YellowBrick(464, 96, 0.2, 63);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10101));
    gameObjects[ID_GROUND_6] = obj;
    
    obj = new YellowBrick(512, 64, 0.2f, 63);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10101));
    gameObjects[ID_GROUND_7] = obj;

    obj = new YellowBrick(512, 144, 0.2f, 95);
    obj->SetSprite(SpriteManager::GetInstance()->GetSprite(10101));
    gameObjects[ID_GROUND_8] = obj;

#pragma endregion

    

    obj = new Mario(0, gameObjects[ID_GROUND_1]->position.GetY() - MARIO_BIG_HEIGHT);
    obj->SetKeyHandler(Game::GetInstance()->keyHandler);
#pragma region Big Mario animations
    obj->AddAnimation(FIGURE_BIG, STATE_IDLE, LEFT, am->GetAnimation(ANI_MARIO_BIG_IDLE_LEFT));
    obj->AddAnimation(FIGURE_BIG, STATE_IDLE, RIGHT, am->GetAnimation(ANI_MARIO_BIG_IDLE_RIGHT));
    obj->AddAnimation(FIGURE_BIG, STATE_RUN, LEFT, am->GetAnimation(ANI_MARIO_BIG_RUN_LEFT));
    obj->AddAnimation(FIGURE_BIG, STATE_RUN, RIGHT, am->GetAnimation(ANI_MARIO_BIG_RUN_RIGHT));
    obj->AddAnimation(FIGURE_BIG, STATE_JUMP, LEFT, am->GetAnimation(ANI_MARIO_BIG_JUMP_LEFT));
    obj->AddAnimation(FIGURE_BIG, STATE_JUMP, RIGHT, am->GetAnimation(ANI_MARIO_BIG_JUMP_RIGHT));
    obj->AddAnimation(FIGURE_BIG, STATE_FALL, LEFT, am->GetAnimation(ANI_MARIO_BIG_FALL_LEFT));
    obj->AddAnimation(FIGURE_BIG, STATE_FALL, RIGHT, am->GetAnimation(ANI_MARIO_BIG_FALL_RIGHT));
    obj->AddAnimation(FIGURE_BIG, SWITCH, LEFT, am->GetAnimation(ANI_MARIO_BIG_SWITCH_LEFT));
    obj->AddAnimation(FIGURE_BIG, SWITCH, RIGHT, am->GetAnimation(ANI_MARIO_BIG_SWITCH_RIGHT));
    obj->AddAnimation(FIGURE_BIG, STATE_SIT, LEFT, am->GetAnimation(ANI_MARIO_BIG_SIT_LEFT));
    obj->AddAnimation(FIGURE_BIG, STATE_SIT, RIGHT, am->GetAnimation(ANI_MARIO_BIG_SIT_RIGHT));
    obj->AddAnimation(FIGURE_BIG, KICK, LEFT, am->GetAnimation(ANI_MARIO_BIG_KICK_LEFT));
    obj->AddAnimation(FIGURE_BIG, KICK, RIGHT, am->GetAnimation(ANI_MARIO_BIG_KICK_RIGHT));
#pragma endregion
#pragma region Small Mario animations
    obj->AddAnimation(FIGURE_SMALL, STATE_IDLE, LEFT, am->GetAnimation(ANI_MARIO_SMALL_IDLE_LEFT));
    obj->AddAnimation(FIGURE_SMALL, STATE_IDLE, RIGHT, am->GetAnimation(ANI_MARIO_SMALL_IDLE_RIGHT));
    obj->AddAnimation(FIGURE_SMALL, STATE_RUN, LEFT, am->GetAnimation(ANI_MARIO_SMALL_RUN_LEFT));
    obj->AddAnimation(FIGURE_SMALL, STATE_RUN, RIGHT, am->GetAnimation(ANI_MARIO_SMALL_RUN_RIGHT));
    obj->AddAnimation(FIGURE_SMALL, STATE_JUMP, LEFT, am->GetAnimation(ANI_MARIO_SMALL_JUMP_LEFT));
    obj->AddAnimation(FIGURE_SMALL, STATE_JUMP, RIGHT, am->GetAnimation(ANI_MARIO_SMALL_JUMP_RIGHT));
    obj->AddAnimation(FIGURE_SMALL, STATE_FALL, LEFT, am->GetAnimation(ANI_MARIO_SMALL_FALL_LEFT));
    obj->AddAnimation(FIGURE_SMALL, STATE_FALL, RIGHT, am->GetAnimation(ANI_MARIO_SMALL_FALL_RIGHT));
    obj->AddAnimation(FIGURE_SMALL, SWITCH, LEFT, am->GetAnimation(ANI_MARIO_SMALL_SWITCH_LEFT));
    obj->AddAnimation(FIGURE_SMALL, SWITCH, RIGHT, am->GetAnimation(ANI_MARIO_SMALL_SWITCH_RIGHT));
    obj->AddAnimation(FIGURE_SMALL, KICK, LEFT, am->GetAnimation(ANI_MARIO_SMALL_KICK_LEFT));
    obj->AddAnimation(FIGURE_SMALL, KICK, RIGHT, am->GetAnimation(ANI_MARIO_SMALL_KICK_RIGHT));
    obj->AddAnimation(FIGURE_SMALL, STATE_DEATH, NULL, am->GetAnimation(ANI_MARIO_SMALL_DEATH));
#pragma endregion
#pragma region Raccoon Mario animations
    obj->AddAnimation(FIGURE_RACCOON, STATE_IDLE, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_IDLE_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_IDLE, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_IDLE_RIGHT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_RUN, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_RUN_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_RUN, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_RUN_RIGHT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_JUMP, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_JUMP_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_JUMP, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_JUMP_RIGHT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_FALL, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_FALL_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_FALL, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_FALL_RIGHT));
    obj->AddAnimation(FIGURE_RACCOON, SWITCH, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_SWITCH_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, SWITCH, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_SWITCH_RIGHT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_SIT, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_SIT_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, STATE_SIT, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_SIT_RIGHT));
    obj->AddAnimation(FIGURE_RACCOON, KICK, LEFT, am->GetAnimation(ANI_MARIO_RACCOON_KICK_LEFT));
    obj->AddAnimation(FIGURE_RACCOON, KICK, RIGHT, am->GetAnimation(ANI_MARIO_RACCOON_KICK_RIGHT));
#pragma endregion
#pragma region Fire Mario animations
    obj->AddAnimation(FIGURE_FIRE, STATE_IDLE, LEFT, am->GetAnimation(ANI_MARIO_FIRE_IDLE_LEFT));
    obj->AddAnimation(FIGURE_FIRE, STATE_IDLE, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_IDLE_RIGHT));
    obj->AddAnimation(FIGURE_FIRE, STATE_RUN, LEFT, am->GetAnimation(ANI_MARIO_FIRE_RUN_LEFT));
    obj->AddAnimation(FIGURE_FIRE, STATE_RUN, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_RUN_RIGHT));
    obj->AddAnimation(FIGURE_FIRE, STATE_JUMP, LEFT, am->GetAnimation(ANI_MARIO_FIRE_JUMP_LEFT));
    obj->AddAnimation(FIGURE_FIRE, STATE_JUMP, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_JUMP_RIGHT));
    obj->AddAnimation(FIGURE_FIRE, STATE_FALL, LEFT, am->GetAnimation(ANI_MARIO_FIRE_FALL_LEFT));
    obj->AddAnimation(FIGURE_FIRE, STATE_FALL, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_FALL_RIGHT));
    obj->AddAnimation(FIGURE_FIRE, SWITCH, LEFT, am->GetAnimation(ANI_MARIO_FIRE_SWITCH_LEFT));
    obj->AddAnimation(FIGURE_FIRE, SWITCH, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_SWITCH_RIGHT));
    obj->AddAnimation(FIGURE_FIRE, STATE_SIT, LEFT, am->GetAnimation(ANI_MARIO_FIRE_SIT_LEFT));
    obj->AddAnimation(FIGURE_FIRE, STATE_SIT, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_SIT_RIGHT));
    obj->AddAnimation(FIGURE_FIRE, KICK, LEFT, am->GetAnimation(ANI_MARIO_FIRE_KICK_LEFT));
    obj->AddAnimation(FIGURE_FIRE, KICK, RIGHT, am->GetAnimation(ANI_MARIO_FIRE_KICK_RIGHT));
#pragma endregion
    gameObjects[ID_MARIO] = obj;

    obj = new Goomba(224, 161, 2);
    obj->AddAnimation(NULL, STATE_RUN, NULL, am->GetAnimation(ANI_GOOMBA_RUN));
    obj->AddAnimation(NULL, STATE_DEATH, NULL, am->GetAnimation(ANI_GOOMBA_DEATH));
    gameObjects[ID_GOOMBA_1] = obj;
    
    obj = new Koopa(200, 149, 4);
    obj->AddAnimation(NULL, STATE_RUN, RIGHT, am->GetAnimation(ANI_KOOPA_RUN_RIGHT));
    obj->AddAnimation(NULL, STATE_RUN, LEFT, am->GetAnimation(ANI_KOOPA_RUN_LEFT));
    obj->AddAnimation(NULL, STATE_IDLE, NULL, am->GetAnimation(ANI_KOOPA_IDLE));
    obj->AddAnimation(NULL, STATE_CRAZY, NULL, am->GetAnimation(ANI_KOOPA_CRAZY));
    gameObjects[ID_KOOPA_1] = obj;

    
    camera = Camera::GetInstance();
}

void GameObjectManager::Update(float delta)
{
    camera->Follow(gameObjects[ID_MARIO]->position);
    for (auto obj : gameObjects)
    {
        if (obj.second->isActivated)
        {
            obj.second->Update(delta);
        }
    }
}

void GameObjectManager::Render()
{
    camera->DrawBackGround();
    for (auto obj : gameObjects)
    {
        if (obj.second->isActivated)
        {
            obj.second->RenderAnimation();
        }
    }
}

LPGAMEOBJECT GameObjectManager::GetGameObject(int id)
{
    return gameObjects[id];
}

vector<LPGAMEOBJECT> GameObjectManager::GetGameObject(string tag)
{
    vector<LPGAMEOBJECT> list;
    for (auto it : gameObjects)
    {
        if (it.second->tag == tag)
        {
            list.push_back(it.second);
        }
    }
    return list;
}

GameObjectManager* GameObjectManager::GetInstance()
{
    if (instance == NULL)
    {
        instance = new GameObjectManager();
    }
    return instance;
}
