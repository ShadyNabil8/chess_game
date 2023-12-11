#include "Point.h"

Point::Point()
{
}
Point::Point(int x, int y) : m_x(x), m_y(y)
{
}
Point::~Point()
{
}
int Point::GetX() const
{
    return this->m_x;
}
int Point::GetY() const
{
    return this->m_y;
}

void Point::SetX(int x)
{
    this->m_x = x;
}
void Point::SetY(int y)
{
    this->m_y = y;
}