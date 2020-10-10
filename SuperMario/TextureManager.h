#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include <unordered_map>

using namespace std;

class TextureManager
{
public:
	TextureManager() { }
	TextureManager(TextureManager& textureManager) = delete;
	void operator=(const TextureManager& textureManager) = delete;
	static TextureManager* GetInstance();
	void AddTexture(int id, LPDIRECT3DTEXTURE9 texture);
	LPDIRECT3DTEXTURE9 GetTexture(int id);
private:
	static TextureManager* instance;
	unordered_map<int,LPDIRECT3DTEXTURE9> textures;
};

TextureManager* TextureManager::instance = NULL;

TextureManager* TextureManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new TextureManager();
	}
	return instance;
}

void TextureManager::AddTexture(int id,LPDIRECT3DTEXTURE9 texture)
{
	textures[id] = texture;
}

LPDIRECT3DTEXTURE9 TextureManager::GetTexture(int id)
{
	if (textures.empty())
	{
		return NULL;
	}	
	return textures[id];
}