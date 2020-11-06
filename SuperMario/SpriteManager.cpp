#include "SpriteManager.h"

SpriteManager* SpriteManager::instance = NULL;

SpriteManager* SpriteManager::GetInstance()
{
	if (instance == NULL)
	{
		instance = new SpriteManager();
	}
	return instance;
}

LPSPRITE SpriteManager::GetSprite(int id)
{
	if (sprites.empty())
	{
		return NULL;
	}
	return sprites[id];
}

void SpriteManager::AddSprite(int id, LPSPRITE sprite)
{
	sprites[id] = sprite;

}

void SpriteManager::AddSprite(int id, int left, int top, int right, int bottom, LPDIRECT3DTEXTURE9 texture)
{
	LPSPRITE sprite = new Sprite(id, left, top, right, bottom, texture);
	sprites[id] = sprite;
}

SpriteManager::SpriteManager()
{
	TextureManager * textureManager = TextureManager::GetInstance();
	// Load mario texture
	LPDIRECT3DTEXTURE9 texture = textureManager->GetTexture(100);
#pragma region Big Mario sprites
	// Big Mario run to right
	AddSprite(10001, 245, 153, 260, 181, texture);
	AddSprite(10002, 274, 153, 290, 181, texture);
	AddSprite(10003, 304, 153, 321, 181, texture);
	// Big Mario run to left
	AddSprite(10004, 185, 153, 200, 181, texture);
	AddSprite(10005, 155, 153, 171, 181, texture);
	AddSprite(10006, 124, 153, 141, 181, texture);
	// Big Mario jump right
	AddSprite(10007, 394, 274, 411, 301, texture);
	// Big Mario jump left
	AddSprite(10008, 34, 274, 51, 301, texture);
	// Big Mario switch to right
	AddSprite(10009, 424, 153, 441, 182, texture);
	// Big Mario switch to left
	AddSprite(10010, 4, 153, 22, 182, texture);
#pragma endregion
#pragma region Small Mario sprites
	// Small Mario run to right
	AddSprite(10011, 246, 0, 259, 15, texture);
	AddSprite(10012, 274, 0, 291, 16, texture);
	AddSprite(10013, 305, 0, 321, 16, texture);
	// Small Mario run to left
	AddSprite(10014, 186, 0, 199, 15, texture);
	AddSprite(10015, 154, 0, 171, 16, texture);
	AddSprite(10016, 124, 0, 140, 16, texture);
	// Small Mario jump right
	AddSprite(10017, 394, 39, 411, 56, texture);
	// Small Mario jump left
	AddSprite(10018, 34, 39, 51, 56, texture);
	// Small Mario switch right
	AddSprite(10019, 425, 0, 440, 16, texture);
	// Small Mario switch left
	AddSprite(10020, 5, 0, 20, 16, texture);
#pragma endregion
#pragma region Raccoon Mario sprites
	// Raccoon Mario run to right
	AddSprite(10021, 242, 633, 263, 662, texture);
	AddSprite(10022, 271, 633, 294, 662, texture);
	AddSprite(10023, 302, 633, 324, 661, texture);
	// Raccoon Mario run to left
	AddSprite(10024, 182, 633, 203, 662, texture);
	AddSprite(10025, 151, 633, 174, 661, texture);
	AddSprite(10026, 121, 633, 143, 661, texture);
	// Raccoon Mario jump right
	AddSprite(10027, 391, 753, 415, 781, texture);
	// Raccoon Mario jump left
	AddSprite(10028, 30, 753, 54, 781, texture);
	// Raccoon Mario switch right
	AddSprite(10029, 424, 632, 441, 663, texture);
	// Raccoon Mario switch left
	AddSprite(10030, 4, 632, 21, 663, texture);
#pragma endregion
#pragma region Fire Mario sprites
	// Fire Mario run to right
	AddSprite(10031, 245, 393, 260, 421, texture);
	AddSprite(10032, 274, 393, 291, 421, texture);
	AddSprite(10033, 304, 393, 321, 421, texture);
	// Fire Mario run to left
	AddSprite(10034, 185, 393, 200, 421, texture);
	AddSprite(10035, 154, 393, 171, 421, texture);
	AddSprite(10036, 124, 393, 141, 421, texture);
	// Fire Mario jump right
	AddSprite(10037, 394, 514, 411, 541, texture);
	// Fire Mario jump left
	AddSprite(10038, 34, 514, 51, 541, texture);
	// Fire Mario switch right
	AddSprite(10039, 424, 393, 441, 422, texture);
	// Fire Mario switch left
	AddSprite(10040, 4, 393, 21, 422, texture);
#pragma endregion
#pragma region Additional sprites
	// Big Mario sit right
	AddSprite(10041, 425, 238, 440, 257, texture);
	// Big Mario sit left
	AddSprite(10042, 5, 238, 20, 257, texture);
	// Fire Mario sit right
	AddSprite(10043, 425, 478, 440, 497, texture);
	// Fire Mario sit left
	AddSprite(10044, 5, 478, 440, 497, texture);
	// Raccoon Mario sit right
	AddSprite(10045, 392, 677, 414, 697, texture);
	AddSprite(10046, 391, 718, 414, 737, texture);
	AddSprite(10047, 421, 718, 444, 737, texture);
	// Raccoon Mario sit left
	AddSprite(10048, 31, 677, 53, 697, texture);
	AddSprite(10049, 31, 718, 54, 737, texture);
	AddSprite(10050, 1, 718, 24, 737, texture);
	// Small Mario kick right
	AddSprite(10051, 424, 79, 441, 96, texture);
	// Small Mario kick left
	AddSprite(10052, 4, 79, 21, 96, texture);
	// Big Mario kick right
	AddSprite(10053, 422, 273, 444, 301, texture);
	// Big Mario kick left
	AddSprite(10054, 1, 273, 23, 301, texture);
	// Raccoon Mario kick right
	AddSprite(10055, 421, 753, 444, 782, texture);
	// Raccoon Mario kick left
	AddSprite(10056, 1, 753, 24, 782, texture);
	// Fire Mario kick right
	AddSprite(10057, 422, 513, 444, 541, texture);
	// Fire Mario kick left
	AddSprite(10058, 1, 513, 23, 541, texture);
	// Mario death
	AddSprite(10059, 214, 119, 231, 136, texture);
#pragma endregion

	// Goomba 
	texture = textureManager->GetTexture(103);
	AddSprite(10301, 0, 0, 16, 16, texture);
	AddSprite(10302, 16, 0, 32, 16, texture);
	AddSprite(10303, 33, 0, 48, 16, texture);
	AddSprite(10304, 49, 0, 56, 16, texture);

	// Koopa
	texture = textureManager->GetTexture(104);
	AddSprite(10401, 0, 2, 16, 29, texture);
	AddSprite(10402, 17, 2, 33, 30, texture);
	AddSprite(10403, 0, 35, 16, 62, texture);
	AddSprite(10404, 16, 35, 33, 63, texture);

	AddSprite(10405, 34, 0, 49, 16, texture);
	AddSprite(10406, 51, 0, 66, 16, texture);
	AddSprite(10407, 68, 0, 83, 16, texture);
	AddSprite(10408, 85, 0, 100, 16, texture);

	AddSprite(10409, 34, 17, 50, 33, texture);


	// brick
	texture = textureManager->GetTexture(101);
	AddSprite(10101, 300, 135, 387, 150, texture);
	AddSprite(10102, 300, 135, 315, 150, texture);
	DebugOut(L"[INFO] Sprites loaded Ok.\n");
}