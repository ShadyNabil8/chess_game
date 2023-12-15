#include "Pawn.h"

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}
Pawn::Pawn(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_PAWN, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_PAWN, wxBITMAP_TYPE_PNG);
}
void Pawn::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    int x = currentPosition.GetX();
    int y = currentPosition.GetY();
    int step = 0;
    if (this->m_colour == DARK_PIECE)
        step = 1;
    else
        step = -1;
    Piece *other;
    Point otherpoint;

    other = chessBoard[x][y + step];
    otherpoint.SetXY(x, y + step);
    if ((IsInBoard(otherpoint)) && IsEmpty(other))
        SetValidMove(otherpoint, validMovesMatrix);

    other = chessBoard[x + step][y + step];
    otherpoint.SetXY(x + step, y + step);
    if (IsInBoard(otherpoint) && !IsEmpty(other) && (IsEnemy(this, other)))
        SetValidMove(otherpoint, validMovesMatrix);

    other = chessBoard[x - step][y + step];
    otherpoint.SetXY(x - step, y + step);
    if (IsInBoard(otherpoint) && !IsEmpty(other) && (IsEnemy(this, other)))
        SetValidMove(otherpoint, validMovesMatrix);
}

Piece::PieceColour Pawn::GetColour()
{
    return this->m_colour;
}

void Pawn::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
}