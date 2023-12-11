#ifndef PAWN_H
#define PAWN_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Pawn : public Piece
{
public:
    Pawn();
    Pawn(Colour colour);
    ~Pawn();
    std::vector<Point> GetLegalMoves(const Point &point) const;

private:
};

#endif