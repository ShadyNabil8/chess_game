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