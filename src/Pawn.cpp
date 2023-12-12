#include "Pawn.h"

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}
Pawn::Pawn(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_PAWN, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_PAWN, wxBITMAP_TYPE_PNG);
}
void Pawn::GetLegalMoves(const Point &point, Piece *chessmatrix[8][8], bool highlight_matrix[8][8])
{
    int x = point.GetX();
    int y = point.GetY();
    /* Highlight piece square */
    highlight_matrix[x][y] = 1;
    if ((((y + 1) < 8)) && (chessmatrix[x + 1][y + 1] == nullptr))
        highlight_matrix[x][y + 1] = 1;

    if ((((x + 1) < 8) && ((y + 1) < 8)) && (chessmatrix[x + 1][y + 1] != nullptr))
        highlight_matrix[x + 1][y + 1] = 1;

    if ((((x - 1) < 8) && ((y + 1) < 8)) && (chessmatrix[x + 1][y + 1] != nullptr))
        highlight_matrix[x - 1][y + 1] = 1;
}
