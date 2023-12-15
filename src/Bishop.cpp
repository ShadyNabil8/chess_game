#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

Bishop::Bishop(PieceColour colour) : Piece(colour)
{
    InitializeImage(CHESS_BLACK_BISHOP, CHESS_WHITE_BISHOP);
}

void Bishop::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    int i = 1;
    CheckAndSetMove(-i, -i, currentPosition, chessBoard, validMovesMatrix); // Top-left
    CheckAndSetMove(i, i, currentPosition, chessBoard, validMovesMatrix);   // Bottom-right
    CheckAndSetMove(i, -i, currentPosition, chessBoard, validMovesMatrix);  // Top-right
    CheckAndSetMove(-i, i, currentPosition, chessBoard, validMovesMatrix);  // Bottom-left
}

void Bishop::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    Point targetPosition(currentPosition.GetX() + xChange, currentPosition.GetY() + yChange);
    Piece *targetPiece;

    while (IsInBoard(targetPosition))
    {
        targetPiece = chessBoard[targetPosition.GetX()][targetPosition.GetY()];

        if (IsEmpty(targetPiece))
            SetValidMove(targetPosition, validMovesMatrix);
        else if (IsEnemy(this, targetPiece))
        {
            SetValidMove(targetPosition, validMovesMatrix);
            break;
        }
        else
            break;

        targetPosition.SetXY(targetPosition.GetX() + xChange, targetPosition.GetY() + yChange);
    }
}
