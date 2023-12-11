#ifndef POINT_H
#define POINT_H

#pragma once

class Point
{
public:
    Point();
    Point(int x, int y);
    ~Point();
    int GetX() const;
    int GetY() const;
    void SetX(int x);
    void SetY(int y);

private:
    int m_x;
    int m_y;
};

#endif