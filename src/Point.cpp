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
bool Point::operator==(const Point &point) const
{
    if (this->m_x == point.GetX() && this->m_y == point.GetY())
        return true;
    else
        return false;
}
bool Point::operator!=(const Point &point) const
{
    if (this->m_x == point.GetX() && this->m_y == point.GetY())
        return false;
    else
        return true;
}

void Point::SetXY(int x, int y)
{
    this->m_x = x;
    this->m_y = y;
}