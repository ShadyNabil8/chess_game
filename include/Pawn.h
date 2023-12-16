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
    ~Pawn() override;
    void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);

private:
    void CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
};

#endif