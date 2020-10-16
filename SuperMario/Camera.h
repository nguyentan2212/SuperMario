#pragma once
#include "GameObject.h"
#include "SpriteHandler.h"
#include "TextureManager.h"

class Camera : public GameObject
{
public:
	Camera(float x, float y) :GameObject(x, y) {}
	void DrawBackGround();

	static Camera* GetInstance();

private:
	static Camera* instance;
};

typedef Camera* LPCAMERA;

