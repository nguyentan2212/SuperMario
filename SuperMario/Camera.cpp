#include "Camera.h"

Camera* Camera::instance = NULL;


void Camera::DrawBackGround()
{
    
    LPSPRITEHANDLER spriteHandler = SpriteHandler::GetInstance();
    TextureManager* textureManager = TextureManager::GetInstance();
    LPDIRECT3DTEXTURE9 background = textureManager->GetTexture(102);
    RECT r;
    r.left = 0 + position.GetX();
    r.top = 240 + position.GetY();
    r.right = 255 + position.GetX();
    r.bottom = 432 + position.GetY();
    spriteHandler->Draw(position.GetX(), position.GetY(), background, r);
}

Camera* Camera::GetInstance()
{
    if (instance == NULL)
    {
        instance = new Camera(0, 0);
    }
    return instance;
}
