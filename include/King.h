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
    void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);

private:
    void CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
};

#endif