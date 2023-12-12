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
void King::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8])
{
}
