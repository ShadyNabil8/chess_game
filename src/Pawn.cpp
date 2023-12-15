#include "Pawn.h"

Pawn::Pawn()
{
}

Pawn::~Pawn()
{
}
Pawn::Pawn(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_PAWN, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_PAWN, wxBITMAP_TYPE_PNG);
}


void Pawn::GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    int x = currentPosition.GetX();
    int y = currentPosition.GetY();
    const int PAWN_FORWARD_STEP = 1;
    int step = (this->m_colour == DARK_PIECE) ? PAWN_FORWARD_STEP : -PAWN_FORWARD_STEP;

    CheckAndSetMove(0, step, currentPosition, chessBoard, validMovesMatrix);     // Move forward
    CheckAndSetMove(step, step, currentPosition, chessBoard, validMovesMatrix);  // Diagonal right
    CheckAndSetMove(-step, step, currentPosition, chessBoard, validMovesMatrix); // Diagonal left
}


void Pawn::CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    Point targetPosition(currentPosition.GetX() + xChange, currentPosition.GetY() + yChange);
    Piece *targetPiece = chessBoard[targetPosition.GetX()][targetPosition.GetY()];
    if ((IsInBoard(targetPosition)) && IsEmpty(targetPiece) && xChange == 0) // xChange == 0: Ignore Diagonal
        SetValidMove(targetPosition, validMovesMatrix);
    else if (IsInBoard(targetPosition) && !IsEmpty(targetPiece) && IsEnemy(this, targetPiece) && xChange != 0) // xChange == 0 Ignore forward
        SetValidMove(targetPosition, validMovesMatrix);
}
