#ifndef KING_H
#define KING_H

#pragma once
#include "Piece.h"
#include "Point.h"
class King : public Piece
{
public:
    King();
    King(Colour colour);
    ~King();
    std::vector<Point> GetLegalMoves(const Point &point,Piece* chessmatrix[8][8]) const;

private:
};

#endif