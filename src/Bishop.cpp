#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}
Bishop::Bishop(int x, int y, Color color, wxWindow *square) : Piece(x, y, color, square)
{
    if (m_color == WHITE)
        m_img = CHESS_WHITE_BISHOP;
    else
        m_img = CHESS_BLACK_BISHOP;
    this->Put();
}
