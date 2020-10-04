#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Sprite.h"

class AnimationFrame
{
public:	
	AnimationFrame(LPSPRITE sprite, DWORD time) { this->sprite = sprite; this->time = time; }
	DWORD GetTime() { return time; }
	LPSPRITE GetSprite() { return sprite; }
	~AnimationFrame(){ delete sprite; }

private:
	DWORD time; // Time that this animation frame is rendered
	LPSPRITE sprite; // This property can be an array
};

typedef AnimationFrame* LPANIMATIONFRAME;