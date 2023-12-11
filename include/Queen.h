#ifndef QUEEN_H
#define QUEEN_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Queen : public Piece
{
public:
    Queen();
    Queen(Colour colour);
    ~Queen();
    std::vector<Point> GetLegalMoves(const Point &point) const;

private:
};

#endif