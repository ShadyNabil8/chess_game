#include "Knight.h"

Knight::Knight()
{
}

Knight::~Knight()
{
}
Knight::Knight(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_KNIGHT, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_KNIGHT, wxBITMAP_TYPE_PNG);
}
void Knight::GetLegalMoves(const Point &point, Piece *chessmatrix[8][8], bool highlight_matrix[8][8])
{
    int x = point.GetX();
    int y = point.GetY();
    Point otherpoint;
    Piece *other;
    
    for (int i = -2; i <= 2; i += 4)
    {
        otherpoint.SetXY(x + 1, y + i);
        other = chessmatrix[x + 1][y + i];
        if (IsInBoard(otherpoint) && (IsEmpty(other) || IsEnemy(this, other)))
            SetValidMove(otherpoint, highlight_matrix);

        otherpoint.SetXY(x - 1, y + i);
        other = chessmatrix[x - 1][y + i];
        if (IsInBoard(otherpoint) && (IsEmpty(other) || IsEnemy(this, other)))
            SetValidMove(otherpoint, highlight_matrix);
    }
}
Piece::PieceColour Knight::GetColour()
{
    return this->m_colour;
}
