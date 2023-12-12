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
void Queen::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8])
{
}
