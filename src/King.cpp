#include "King.h"

King::King()
{

}

King::~King()
{

}
King::King(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_KING, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_KING, wxBITMAP_TYPE_PNG);
}
std::vector<Point> King::GetLegalMoves(const Point &point) const
{
}
