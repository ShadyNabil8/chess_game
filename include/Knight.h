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
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);

private:
};

#endif