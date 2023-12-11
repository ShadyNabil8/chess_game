#include "Knight.h"

Knight::Knight()
{

}

Knight::~Knight()
{

}
Knight::Knight(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_KNIGHT, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_KNIGHT, wxBITMAP_TYPE_PNG);
}
std::vector<Point> Knight::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8]) const
{
}

