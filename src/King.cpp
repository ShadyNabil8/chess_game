#include "King.h"

King::King()
{

}

King::~King()
{

}
King::King(int x, int y, Color color, wxWindow *square) : Piece(x, y, color, square)
{
    if (m_color == WHITE)
        m_img = CHESS_WHITE_KING;
    else
        m_img = CHESS_BLACK_KING;
    this->Put();
}
