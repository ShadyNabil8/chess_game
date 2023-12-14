#ifndef ROOK_H
#define ROOK_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Rook : public Piece
{
public:
    Rook();
    Rook(PieceColour colour);
    ~Rook();
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);
    Piece::PieceColour GetColour();
private:
};

#endif