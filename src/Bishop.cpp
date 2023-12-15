#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

Bishop::Bishop(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_BISHOP, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_BISHOP, wxBITMAP_TYPE_PNG);
}

void Bishop::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    int i = 1;
    CheckAndSetMove(-i, -i, currentPosition, chessBoard, validMovesMatrix); // Top-left
    CheckAndSetMove(i, i, currentPosition, chessBoard, validMovesMatrix);   // Bottom-right
    CheckAndSetMove(i, -i, currentPosition, chessBoard, validMovesMatrix);  // Top-right
    CheckAndSetMove(-i, i, currentPosition, chessBoard, validMovesMatrix);  // Bottom-left
}

Piece::PieceColour Bishop::GetColour()
{
    return this->m_colour;
}

void Bishop::CheckAndSetMove(int xChange, int yChange, const Point &startPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    Point targetPosition = startPosition;
    targetPosition.SetXY(targetPosition.GetX() + xChange, targetPosition.GetY() + yChange);
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
