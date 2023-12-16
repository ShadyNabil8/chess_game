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
    ~Queen() override;
    void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);

private:
    void CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
};

#endif