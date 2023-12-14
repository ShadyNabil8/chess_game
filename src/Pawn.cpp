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
void Pawn::GetLegalMoves(const Point &point, Piece *chessmatrix[8][8], bool highlight_matrix[8][8])
{
    int x = point.GetX();
    int y = point.GetY();
    int step = 0;
    if (this->m_colour == DARK_PIECE)
        step = 1;
    else
        step = -1;
    Piece *other;
    Point otherpoint;

    other = chessmatrix[x][y + step];
    otherpoint.SetXY(x, y + step);
    if ((IsInBoard(otherpoint)) && IsEmpty(other))
        SetValidMove(otherpoint, highlight_matrix);

    other = chessmatrix[x + step][y + step];
    otherpoint.SetXY(x + step, y + step);
    if (IsInBoard(otherpoint) && !IsEmpty(other) && (IsEnemy(this, other)))
        SetValidMove(otherpoint, highlight_matrix);

    other = chessmatrix[x - step][y + step];
    otherpoint.SetXY(x - step, y + step);
    if (IsInBoard(otherpoint) && !IsEmpty(other) && (IsEnemy(this, other)))
        SetValidMove(otherpoint, highlight_matrix);
}

Piece::PieceColour Pawn::GetColour()
{
    return this->m_colour;
}