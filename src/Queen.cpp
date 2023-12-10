#include "Queen.h"

Queen::Queen()
{

}

Queen::~Queen()
{

}
Queen::Queen(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_QUEEN, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_QUEEN, wxBITMAP_TYPE_PNG);
}