#pragma once
#include "../Framework/GameEngine/DirectXGame.h"
#include "../Resource.h"
#include "../Framework/Utilities/TinyXml2/tinyxml2.h"

class MarioGame : public DirectXGame, public Singleton<MarioGame>
{
	friend class Singleton<MarioGame>;
private:
	void SetInfo();
	void KeyHandling();
	void Update(double dt);
	void Render();
	void LoadTexture(char* textureXmlPath);
	MarioGame();
	
public:
	void GameInit(HINSTANCE _hInstance, int nCmdShow);	
};