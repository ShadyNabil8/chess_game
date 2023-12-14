#include "King.h"

King::King()
{

}

King::~King()
{

}
King::King(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_KING, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_KING, wxBITMAP_TYPE_PNG);
}
void King::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8])
{
}
Piece::PieceColour King::GetColour()
{
    return this->m_colour;
}