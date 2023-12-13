#include "Piece.h"

Piece::Piece()
{
}
Piece::~Piece()
{
}

Piece::Piece(Colour colour) : m_colour(colour), m_image(nullptr)
{
}

wxBitmap *Piece::GetImage()
{
    return this->m_image;
}

void Piece::SetImage(wxBitmap *image)
{
    this->m_image = image;
}

bool Piece::IsInBoard(const Point &point)
{
    int x = point.GetX();
    int y = point.GetY();
    if ((x < 8) && (x >= 0) && (y < 8) && (y >= 0))
        return true;
    else
        return false;
}
bool Piece::IsEnemy(const Piece *current, const Piece *other)
{
    if (current->m_colour == other->m_colour)
        return false;
    else
        return true;
}
bool Piece::IsEmpty(const Piece *piece)
{
    if (piece == nullptr)
        return true;
    else
        return false;
}

void Piece::SetValidMove(const Point &point, bool highlight_matrix[8][8])
{
    int x = point.GetX();
    int y = point.GetY();
    highlight_matrix[x][y] = true;
}

// Colour Piece::GetColour()
// {
//     return this->m_colour;
// }