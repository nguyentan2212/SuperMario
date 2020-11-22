#pragma once
#include <fstream>
#include "../Framework/GameEngine/DirectXGame.h"
#include "../Resource.h"
#include "../Framework/Utilities/json.hpp"
#include "../Framework/Utilities/StringHelper.h"

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
	
public:
	void GameInit(HINSTANCE _hInstance, int nCmdShow);	
};