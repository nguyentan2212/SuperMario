#include "Animation.h"

void Animation::Add(LPSPRITE sprite, DWORD time)
{
	DWORD t = time;
	if (t == 0)
	{
		t = this->defaultTime;
	}

	LPANIMATIONFRAME frame = new AnimationFrame(sprite, t);
	frames.push_back(frame);
}

void Animation::Render(float x, float y)
{
	DWORD now = GetTickCount64();

	if (currentFrame == -1)
	{
		currentFrame = 0;
		lastFrameTime = now;
	}
	else
	{
		DWORD t = frames[currentFrame]->GetTime();
		DWORD delta = now - lastFrameTime;

		if (delta > t)
		{
			currentFrame++;
			lastFrameTime = now;
			if (currentFrame == frames.size())
				currentFrame = 0;
		}
	}

	frames[currentFrame]->GetSprite()->Draw(x, y);
}



