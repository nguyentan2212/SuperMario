#include "GameObjectManager.h"

GameObjectManager* GameObjectManager::instance = NULL;

GameObjectManager::GameObjectManager()
{
    GameObject* obj = new Mario(200, 150);
    obj->SetKeyHandler(Game::GetInstance()->keyHandler);
    gameObjects[ID_MARIO] = obj;
    obj = new Goomba(224, 161, 0);
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
