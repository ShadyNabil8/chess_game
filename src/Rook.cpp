#include "Rook.h"

Rook::Rook()
{
}

Rook::~Rook()
{
}

Rook::Rook(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_ROOK, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_ROOK, wxBITMAP_TYPE_PNG);
}
std::vector<Point> Rook::GetLegalMoves(const Point &point, Piece *chessmatrix[8][8],int highlight_matrix[8][8]) const
{
}
