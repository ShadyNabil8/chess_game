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
    void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
private:
    void CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
};

#endif