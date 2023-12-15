#include "Rook.h"

Rook::Rook()
{
}

Rook::~Rook()
{
}

Rook::Rook(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_ROOK, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_ROOK, wxBITMAP_TYPE_PNG);
}
void Rook::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    const int POSITIVE_STEP = 1;                                                      // Down and right
    const int NIGATIVE_STEP = -1;                                                     // Up and left
    CheckAndSetMove(NIGATIVE_STEP, 0, currentPosition, chessBoard, validMovesMatrix); // Left
    CheckAndSetMove(POSITIVE_STEP, 0, currentPosition, chessBoard, validMovesMatrix); // Right
    CheckAndSetMove(0, NIGATIVE_STEP, currentPosition, chessBoard, validMovesMatrix); // Up
    CheckAndSetMove(0, POSITIVE_STEP, currentPosition, chessBoard, validMovesMatrix); // Down
}

void Rook::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    const int FORWARD_STEP = 1;
    const int BACKWARD_STEP = -1;
    Point targetPosition(currentPosition.GetX() + xChange, currentPosition.GetY() + yChange);
    Piece *targetPiece;
    while (IsInBoard(targetPosition))
    {
        targetPiece = chessBoard[targetPosition.GetX()][targetPosition.GetY()];
        if (IsEmpty(targetPiece))
            SetValidMove(targetPosition, validMovesMatrix);
        else if (IsEnemy(this, targetPiece))
        {
            SetValidMove(targetPosition, validMovesMatrix);
            break;
        }
        else
            break;
            
        targetPosition.SetXY(targetPosition.GetX() + xChange, targetPosition.GetY() + yChange);
    }
}