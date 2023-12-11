#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

Bishop::Bishop(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_BISHOP, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_BISHOP, wxBITMAP_TYPE_PNG);
}

std::vector<Point> Bishop::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],int highlight_matrix[8][8]) const
{
}
