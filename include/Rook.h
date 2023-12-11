#ifndef ROOK_H
#define ROOK_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Rook : public Piece
{
public:
    Rook();
    Rook(Colour colour);
    ~Rook();
    std::vector<Point> GetLegalMoves(const Point &point) const;

private:
};

#endif