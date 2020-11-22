#include "MarioGame.h"

MarioGame::MarioGame()
{
	
}

void MarioGame::GameInit(HINSTANCE _hInstance, int nCmdShow)
{
	DirectXGame::GameInit(_hInstance, nCmdShow);
	
	LoadGameObjects("Resources/animations.json");
}

void MarioGame::SetInfo()
{
	title = L"Mario game";
	icon = IDI_SUPERMARIO;
	iconSm = IDI_SMALL;
	windowHeight = 600;
	windowWidth = 600;
	fps = 60;
	mspf = 1000.0f / 60.0f;
}

void MarioGame::KeyHandling()
{
}

void MarioGame::Update(double dt)
{
}

void MarioGame::Render()
{
	drawDevice->Begin();
	spriteMap["SuperMarioFall"]->Draw(Vector2D(10, 10));
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
			string folder = ani["folder"];
			folder = configFolder + folder;
			json sprites = ani["sprites"];
			for (auto& item : sprites)
			{
				string path = item["fileName"];
				path = folder + path;
				int w = item["w"];
				int h = item["h"];
				LPSPRITE sprite = new Sprite(name, color, w, h, path);
				spriteMap[name] = sprite;
			}
		}	
	}
	
	
}
