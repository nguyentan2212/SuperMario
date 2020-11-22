#pragma once
#include <fstream>
#include "../Framework/GameEngine/DirectXGame.h"
#include "../Resource.h"
#include "../Framework/Utilities/json.hpp"

using json = nlohmann::json;
using namespace std;

class MarioGame : public DirectXGame, public Singleton<MarioGame>
{
	friend class Singleton<MarioGame>;
private:
	void SetInfo();
	void KeyHandling();
	void Update(double dt);
	void Render();
	void LoadGameObjects(string jsonPath);
	MarioGame();
	float t = 0;
public:
	void GameInit(HINSTANCE _hInstance, int nCmdShow);	
};