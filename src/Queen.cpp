#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"

Queen::Queen()
{
}

Queen::~Queen()
{
}
Queen::Queen(PieceColour colour) : Piece(colour)
{
    InitializeImage(CHESS_BLACK_QUEEN, CHESS_WHITE_QUEEN);
}
void Queen::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    const int POSITIVE_STEP = 1;
    const int NIGATIVE_STEP = -1;
    CheckAndSetMove(NIGATIVE_STEP, 0, currentPosition, chessBoard, validMovesMatrix);             // Left
    CheckAndSetMove(POSITIVE_STEP, 0, currentPosition, chessBoard, validMovesMatrix);             // Right
    CheckAndSetMove(0, NIGATIVE_STEP, currentPosition, chessBoard, validMovesMatrix);             // Up
    CheckAndSetMove(0, POSITIVE_STEP, currentPosition, chessBoard, validMovesMatrix);             // Down
    CheckAndSetMove(NIGATIVE_STEP, NIGATIVE_STEP, currentPosition, chessBoard, validMovesMatrix); // Top-left
    CheckAndSetMove(POSITIVE_STEP, POSITIVE_STEP, currentPosition, chessBoard, validMovesMatrix); // Bottom-right
    CheckAndSetMove(POSITIVE_STEP, NIGATIVE_STEP, currentPosition, chessBoard, validMovesMatrix); // Top-right
    CheckAndSetMove(NIGATIVE_STEP, POSITIVE_STEP, currentPosition, chessBoard, validMovesMatrix); // Bottom-left
}

void Queen::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
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