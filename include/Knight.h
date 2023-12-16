#ifndef KNIGHT_H
#define KNIGHT_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Knight : public Piece
{
public:
    Knight();
    Knight(PieceColour colour);
    ~Knight() override;
    void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);

private:
    void CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
};

#endif