#include "Rook.h"

Rook::Rook()
{
}

Rook::~Rook()
{
}

Rook::Rook(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_ROOK, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_ROOK, wxBITMAP_TYPE_PNG);
}
void Rook::GetLegalMoves(const Point &point, Piece *chessmatrix[8][8], bool highlight_matrix[8][8])
{
}
Piece::PieceColour Rook::GetColour()
{
    return this->m_colour;
}