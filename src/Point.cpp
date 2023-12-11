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
int Point::GetX()
{
    return this->m_x;
}
int Point::GetY()
{
    return this->m_y;
}