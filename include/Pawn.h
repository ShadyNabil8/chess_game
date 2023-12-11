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
    std::vector<Point> GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],int highlight_matrix[8][8]) const;

private:
};

#endif