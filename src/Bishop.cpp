#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

Bishop::Bishop(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_BISHOP, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_BISHOP, wxBITMAP_TYPE_PNG);
}
