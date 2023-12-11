#ifndef KNIGHT_H
#define KNIGHT_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Knight : public Piece
{
public:
    Knight();
    Knight(Colour colour);
    ~Knight();
    std::vector<Point> GetLegalMoves(const Point &point) const;

private:
};

#endif