#include "Vector2D.h"

Vector2D Vector2D::operator+(const Vector2D& vec)
{
    Vector2D temp;
    temp.x = this->x + vec.x;
    temp.y = this->y + vec.y;
    return temp;
}

Vector2D Vector2D::operator-(const Vector2D& vec)
{
    Vector2D reVec = Vector2D(-vec.x, -vec.y);
    Vector2D temp = *this + reVec;
    return temp;
}

Vector2D Vector2D::operator*(const float f)
{
    Vector2D temp;
    temp.x = this->x * f;
    temp.y = this->y * f;
    return temp;
}

Vector2D Vector2D::operator/(const float f)
{
    Vector2D temp;
    temp.x = this->x / f;
    temp.y = this->y / f;
    return temp;
}
