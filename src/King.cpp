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
void King::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
}
Piece::PieceColour King::GetColour()
{
    return this->m_colour;
}
void King::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
}