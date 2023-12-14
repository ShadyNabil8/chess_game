#ifndef QUEEN_H
#define QUEEN_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Queen : public Piece
{
public:
    Queen();
    Queen(PieceColour colour);
    ~Queen();
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);
    Piece::PieceColour GetColour();
private:
};

#endif