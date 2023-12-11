#include "Pawn.h"

Pawn::Pawn()
{

}

Pawn::~Pawn()
{

}
Pawn::Pawn(Colour colour) : Piece(colour)
{
    if (this->m_colour == DARK)
        this->m_image = new wxBitmap(CHESS_BLACK_PAWN, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_PAWN, wxBITMAP_TYPE_PNG);
}
std::vector<Point> Pawn::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8]) const
{
}
