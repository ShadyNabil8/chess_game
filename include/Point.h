#ifndef POINT_H
#define POINT_H

#pragma once

class Point
{
public:
    Point();
    Point(int x, int y);
    ~Point();
    int GetX();
    int GetY();

private:
    int m_x;
    int m_y;
};

#endif