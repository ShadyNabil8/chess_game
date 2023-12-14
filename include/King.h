#ifndef KING_H
#define KING_H

#pragma once
#include "Piece.h"
#include "Point.h"
class King : public Piece
{
public:
    King();
    King(PieceColour colour);
    ~King();
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);
    Piece::PieceColour GetColour();
private:
};

#endif