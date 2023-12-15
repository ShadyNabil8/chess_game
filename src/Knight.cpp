#include "Knight.h"

Knight::Knight()
{
}

Knight::~Knight()
{
}
Knight::Knight(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_KNIGHT, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_KNIGHT, wxBITMAP_TYPE_PNG);
}
void Knight::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    int x = currentPosition.GetX();
    int y = currentPosition.GetY();
    Point targetPoint;
    Piece *other;
    
    for (int i = -2; i <= 2; i += 4)
    {
        targetPoint.SetXY(x + 1, y + i);
        other = chessBoard[x + 1][y + i];
        if (IsInBoard(targetPoint) && (IsEmpty(other) || IsEnemy(this, other)))
            SetValidMove(targetPoint, validMovesMatrix);

        targetPoint.SetXY(x - 1, y + i);
        other = chessBoard[x - 1][y + i];
        if (IsInBoard(targetPoint) && (IsEmpty(other) || IsEnemy(this, other)))
            SetValidMove(targetPoint, validMovesMatrix);
    }
}
Piece::PieceColour Knight::GetColour()
{
    return this->m_colour;
}
