#include "Queen.h"

Queen::Queen()
{

}

Queen::~Queen()
{

}
Queen::Queen(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_QUEEN, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_QUEEN, wxBITMAP_TYPE_PNG);
}
void Queen::GetLegalMoves(const Point &point,Piece* chessmatrix[8][8],bool highlight_matrix[8][8])
{
}
Piece::PieceColour Queen::GetColour()
{
    return this->m_colour;
}
void Queen::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
}