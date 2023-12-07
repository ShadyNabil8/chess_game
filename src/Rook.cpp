#include "Rook.h"

Rook::Rook()
{

}

Rook::~Rook()
{

}

Rook::Rook(int x, int y, Color color, wxWindow *square) : Piece(x, y, color, square)
{
    if (m_color == WHITE)
        m_img = CHESS_WHITE_ROOK;
    else
        m_img = CHESS_BLACK_ROOK;
    this->Put(this->m_x, this->m_y);
}