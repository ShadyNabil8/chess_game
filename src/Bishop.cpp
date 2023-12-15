#include "Bishop.h"

Bishop::Bishop()
{
}

Bishop::~Bishop()
{
}

Bishop::Bishop(PieceColour colour) : Piece(colour)
{
    if (this->m_colour == DARK_PIECE)
        this->m_image = new wxBitmap(CHESS_BLACK_BISHOP, wxBITMAP_TYPE_PNG);
    else
        this->m_image = new wxBitmap(CHESS_WHITE_BISHOP, wxBITMAP_TYPE_PNG);
}

void Bishop::GetLegalMoves(const Point &point, Piece *chessmatrix[8][8], bool highlight_matrix[8][8])
{
    int x = point.GetX();
    int y = point.GetY();
    Point otherpoint;
    Piece *other;

    /* If you used i = 0, then it will compare the current location of the selected piece if it is an enemy or not
        and surly it is not an enemy, so it will break the loop without adding ant moves.
    */
    for (int i = 1; i < 8; i++)
    {
        otherpoint.SetXY(x - i, y - i);
        other = chessmatrix[x - i][y - i];
        if (IsInBoard(otherpoint) && IsEmpty(other))
            SetValidMove(otherpoint, highlight_matrix);
        else if (IsInBoard(otherpoint))
        {
            if (IsEnemy(this, other))
                SetValidMove(otherpoint, highlight_matrix);
            break;
        }
        else
            break;
    }

    for (int i = 1; i < 8; i++)
    {
        otherpoint.SetXY(x + i, y + i);
        other = chessmatrix[x + i][y + i];
        if (IsInBoard(otherpoint) && IsEmpty(other))
            SetValidMove(otherpoint, highlight_matrix);
        else if (IsInBoard(otherpoint))
        {
            if (IsEnemy(this, other))
                SetValidMove(otherpoint, highlight_matrix);
            break;
        }
        else
            break;
    }
    for (int i = 1; i < 8; i++)
    {
        otherpoint.SetXY(x + i, y - i);
        other = chessmatrix[x + i][y - i];
        if (IsInBoard(otherpoint) && IsEmpty(other))
            SetValidMove(otherpoint, highlight_matrix);
        else if (IsInBoard(otherpoint))
        {
            if (IsEnemy(this, other))
                SetValidMove(otherpoint, highlight_matrix);
            break;
        }
        else
            break;
    }
    for (int i = 1; i < 8; i++)
    {
        otherpoint.SetXY(x - i, y + i);
        other = chessmatrix[x - i][y + i];
        if (IsInBoard(otherpoint) && IsEmpty(other))
            SetValidMove(otherpoint, highlight_matrix);
        else if (IsInBoard(otherpoint))
        {
            if (IsEnemy(this, other))
                SetValidMove(otherpoint, highlight_matrix);
            break;
        }
        else
            break;
    }
}

Piece::PieceColour Bishop::GetColour()
{
    return this->m_colour;
}
