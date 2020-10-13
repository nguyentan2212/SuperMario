#include "TextureManager.h"

TextureManager* TextureManager::instance = NULL;

TextureManager* TextureManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new TextureManager();
	}
	return instance;
}

void TextureManager::AddTexture(int id, LPDIRECT3DTEXTURE9 texture)
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