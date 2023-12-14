#ifndef BISHOP_H
#define BISHOP_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Bishop : public Piece
{
public:
    Bishop();
    Bishop(PieceColour colour);
    ~Bishop();
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);
    Piece::PieceColour GetColour();
private:
};

#endif