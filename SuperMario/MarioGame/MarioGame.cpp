#include "MarioGame.h"

MarioGame::MarioGame()
{
	
}

void MarioGame::GameInit(HINSTANCE _hInstance, int nCmdShow)
{
	DirectXGame::GameInit(_hInstance, nCmdShow);
	
	LoadGameObjects("Resources/GameObjects.json");
}

void MarioGame::SetInfo()
{
	title = L"Mario game";
	icon = IDI_SUPERMARIO;
	iconSm = IDI_SMALL;
	windowHeight = 600;
	windowWidth = 600;
	fps = 7;
	mspf = 1000.0f / 60.0f;
}

void MarioGame::KeyHandling()
{
}

void MarioGame::Update(double dt)
{
	deltaTime = dt;
	LPANIMATION animation = animationsMap["SuperMarioWalk"];
}

void MarioGame::Render()
{	
	drawDevice->Begin();
	t += 10;
	animationsMap["SuperMarioWalk"]->Render(Vector2D(100, 100));	
	drawDevice->End();
}

void MarioGame::LoadGameObjects(string jsonPath)
{
	fstream f(jsonPath, ios::in);
	json j;
	f >> j;
	json objects = j["objects"];
	for (auto& obj : objects)
	{
		string configFolder = obj["configFolder"];
		configFolder = "Resources/" + configFolder;
		json animations = obj["animations"];
		D3DCOLOR color = D3DCOLOR_XRGB(68, 145, 190);
		for (auto& ani : animations)
		{
			string name = ani["name"];
			LPANIMATION animation = new Animation(fps, name);
			string folder = ani["folder"];
			folder = configFolder + folder;
			json sprites = ani["sprites"];
			for (auto& item : sprites)
			{
				string path = item["fileName"];
				path = folder + path;
				int w = item["w"];
				int h = item["h"];
				LPSPRITE sprite = new Sprite(color, w, h, path);
				animation->AddSprite(sprite);
			}
			animationsMap[name] = animation;
		}	
	}
	//drawDevice->Flip();
}
