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
    void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
    Piece::PieceColour GetColour();

private:
    void CheckAndSetMove(int xChange, int yChange, const Point &startPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
};

#endif