#include "King.h"

King::King()
{
}

King::~King()
{
}
King::King(PieceColour colour) : Piece(colour)
{
    InitializeImage(CHESS_BLACK_KING, CHESS_WHITE_KING);
}
void King::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
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

void King::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    Point targetPosition(currentPosition.GetX() + xChange, currentPosition.GetY() + yChange);
    Piece *targetPiece = chessBoard[targetPosition.GetX()][targetPosition.GetY()];
    if (IsInBoard(targetPosition))
    {
        if (IsEmpty(targetPiece))
            SetValidMove(targetPosition, validMovesMatrix);
        else if (IsEnemy(this, targetPiece))
            SetValidMove(targetPosition, validMovesMatrix);
    }
}