#ifndef POINT_H
#define POINT_H

#pragma once
#include "Piece.h"
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
    bool operator==(const Point &point) const;
    bool operator!=(const Point &point) const;

private:
    int m_x;
    int m_y;
};

#endif