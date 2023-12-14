#ifndef PAWN_H
#define PAWN_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Pawn : public Piece
{
public:
    Pawn();
    Pawn(PieceColour colour);
    ~Pawn();
    void GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8]);
    Piece::PieceColour GetColour();
private:
};

#endif