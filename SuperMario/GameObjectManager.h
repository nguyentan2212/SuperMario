#pragma once
#include "GameDefine.h"
#include "GameObject.h"
#include "Mario.h"
#include "Goomba.h"
#include "Koopa.h"
#include "Camera.h"
#include <unordered_map>

using namespace std;

class GameObjectManager
{
public:
	GameObjectManager();
	void Update(float delta);
	void Render();
	LPGAMEOBJECT GetGameObject(int id);
	LPGAMEOBJECT GetGameObject(string tag);
	static GameObjectManager* GetInstance();

private:
	static GameObjectManager* instance;
	Camera* camera;
	unordered_map<int, LPGAMEOBJECT> gameObjects;
};

