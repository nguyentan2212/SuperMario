#include "MarioGame.h"

MarioGame::MarioGame()
{
	
}

void MarioGame::GameInit(HINSTANCE _hInstance, int nCmdShow)
{
	DirectXGame::GameInit(_hInstance, nCmdShow);
	Texture::SetDevice(drawDevice->GetDevice());
	char path[] = "Resources/XmlFiles/MarioGameTextures.xml";
	LoadTexture(path);
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
	LPTEXTURE tex = textureMap["mario"];
	drawDevice->Begin();
	RECT r;
	r.left = 0;
	r.top = 0;
	r.right = 16;
	r.bottom = 16;
	drawDevice->Draw(0, 0, tex->GetTexture(), r);
	drawDevice->End();
}

void MarioGame::LoadTexture(char* textureXmlPath)
{
    tinyxml2::XMLDocument doc;
	doc.LoadFile(textureXmlPath);

	tinyxml2::XMLElement* root = doc.RootElement();
	tinyxml2::XMLElement* textureNode = nullptr;
	for (textureNode = root->FirstChildElement(); textureNode != NULL; textureNode = textureNode->NextSiblingElement())
	{
		const char* value = textureNode->FirstAttribute()->Value();
		std::string key(value);

		tinyxml2::XMLElement* pathNode = textureNode->FirstChildElement();
		value = pathNode->GetText();
		wchar_t wtext[20];
		size_t outSize;
		mbstowcs_s(&outSize, wtext, value, strlen(value) + 1);//Plus null
		LPWSTR path = wtext;
		
		tinyxml2::XMLElement* colorNode = pathNode->NextSiblingElement();

		colorNode = colorNode->FirstChildElement();
		int r = pathNode->IntText();
		

		colorNode = colorNode->NextSiblingElement();
		int g = pathNode->IntText();
		
		colorNode = colorNode->NextSiblingElement();
		int b = pathNode->IntText();
		
		LPTEXTURE texture = new Texture(path, D3DCOLOR_XRGB(r, g, b));
		textureMap[key] = texture;
	}
}
