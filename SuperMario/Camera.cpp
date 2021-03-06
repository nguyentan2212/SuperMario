#include "Camera.h"

Camera* Camera::instance = NULL;


void Camera::DrawBackGround()
{
    
    LPSPRITEHANDLER spriteHandler = SpriteHandler::GetInstance();
    TextureManager* textureManager = TextureManager::GetInstance();
    LPDIRECT3DTEXTURE9 background = textureManager->GetTexture(102);
    RECT r;
    r.left = 0 + (long)position.GetX();
    r.top = 240 + (long)position.GetY();
    r.right = 255 + (long)position.GetX();
    r.bottom = 432 + (long)position.GetY();
    spriteHandler->Draw(position.GetX(), position.GetY(), background, r);
}

void Camera::Follow(Vector2D pos)
{
    int gameWidth = Game::GetInstance()->GetBackBufferWidth() / 3 + 3;// Get game screen
    float cx = pos.GetX() - gameWidth / 2.0f;
    if (cx < 0)
    {
        cx = 0;
    }
    else if (cx > 2816.0f - gameWidth)
    {
        cx = 2816.0f - gameWidth;
    }
    position.SetX(cx);
}

Camera* Camera::GetInstance()
{
    if (instance == NULL)
    {
        instance = new Camera(0, 0);
    }
    return instance;
}
