#include "Knight.h"

Knight::Knight()
{
}

Knight::~Knight()
{
}
Knight::Knight(PieceColour colour) : Piece(colour)
{
    InitializeImage(CHESS_BLACK_KNIGHT, CHESS_WHITE_KNIGHT);
}
void Knight::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    const int L_SHAPE_DELTA = 2;
    const int KNIGHT_MOVE_DELTA = 1;

    for (int i = -L_SHAPE_DELTA; i <= L_SHAPE_DELTA; i += 2 * L_SHAPE_DELTA)
    {
        CheckAndSetMove(KNIGHT_MOVE_DELTA, i, currentPosition, chessBoard, validMovesMatrix);
        CheckAndSetMove(-KNIGHT_MOVE_DELTA, i, currentPosition, chessBoard, validMovesMatrix);
    }
}

void Knight::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    Point targetPosition(currentPosition.GetX() + xChange, currentPosition.GetY() + yChange);
    Piece *targetPiece = chessBoard[targetPosition.GetX()][targetPosition.GetY()];

    if (IsInBoard(targetPosition) && (IsEmpty(targetPiece) || IsEnemy(this, targetPiece)))
        SetValidMove(targetPosition, validMovesMatrix);
}
