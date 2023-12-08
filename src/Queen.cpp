#include "Queen.h"

Queen::Queen()
{

}

Queen::~Queen()
{

}
Queen::Queen(int x, int y, Color color, wxWindow *square) : Piece(x, y, color, square)
{
    if (m_color == WHITE)
        m_img = CHESS_WHITE_QUEEN;
    else
        m_img = CHESS_BLACK_QUEEN;
    this->Put();
}