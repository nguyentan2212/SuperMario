#pragma once
class Vector2D
{
public:
	Vector2D() { this->x = 0; this->y = 0; }
	Vector2D(float x, float y) { this->x = x; this->y = y; }
	void SetVector(float x, float y) { this->x = x; this->y = y; }
	void SetVector(Vector2D vec) { this->x = vec.x; this->y = vec.y; }	
	float GetX() { return x; }
	float GetY() { return y; }

	static Vector2D Up() { return Vector2D(0, -1); }
	static Vector2D Down() { return Vector2D(0, 1); }
	static Vector2D Left() { return Vector2D(-1, 0); }
	static Vector2D Right() { return Vector2D(1, 0); }

private:
	float x;
	float y;
};

typedef Vector2D* LPVECTOR2D;

