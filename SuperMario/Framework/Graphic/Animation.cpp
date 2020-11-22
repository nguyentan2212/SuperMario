#include "Animation.h"

void Animation::Render(Vector2D position)
{
	DWORD now = GetTickCount64();

	if (activeFrame == -1)
	{
		activeFrame = 0;
		frameTime = now;
	}
	else
	{
		DWORD t = 1000 / fps;
		DWORD delta = now - frameTime;

		if (delta > t)
		{
			activeFrame++;
			frameTime = now;
			if (activeFrame == frames.size())
				activeFrame = 0;
		}
	}

	frames[activeFrame]->Draw(position);
}
