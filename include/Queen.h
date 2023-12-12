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
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);

private:
};

#endif