#include "Pawn.h"

Pawn::Pawn()
{

}

Pawn::~Pawn()
{

}
Pawn::Pawn(int x, int y, Color color, wxWindow *square) : Piece(x, y, color, square)
{
    if (m_color == WHITE)
        m_img = CHESS_WHITE_PAWN;
    else
        m_img = CHESS_BLACK_PAWN;
    this->Put(this->m_x, this->m_y);
}