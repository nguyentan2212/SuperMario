#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::instance = NULL;

GameObjectManager::GameObjectManager()
{
    AnimationManager* am = AnimationManager::GetInstance();

    GameObject* obj = new Mario(0, 150);
    obj->SetKeyHandler(Game::GetInstance()->keyHandler);
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
    gameObjects[ID_MARIO] = obj;

    obj = new Goomba(224, 161, 5);
    obj->AddAnimation(NULL, STATE_RUN, NULL, am->GetAnimation(ANI_GOOMBA_RUN));
    gameObjects[ID_GOOMBA_1] = obj;
    
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

LPGAMEOBJECT GameObjectManager::GetGameObject(string tag)
{
    for (auto it : gameObjects)
    {
        if (it.second->tag == tag)
        {
            return it.second;
        }
    }
    return NULL;
}

GameObjectManager* GameObjectManager::GetInstance()
{
    if (instance == NULL)
    {
        instance = new GameObjectManager();
    }
    return instance;
}
