#ifndef POINT_H
#define POINT_H

#pragma once

class Point
{
public:
    Point();
    ~Point();
    int GetX();
    int GetY();

private:
    int x;
    int y;
};

#endif