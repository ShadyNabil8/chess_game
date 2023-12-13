#include "Piece.h"
#include <thread>
#include <chrono>
#include <future>
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

bool Piece::IsInBoard(int x, int y)
{
    if ((x < 8) && (x >= 0) && (y < 8) && (y >= 0))
        return true;
    else
        return false;
}
bool Piece::IsAlly(Piece *piece)
{
    if (this->m_colour == piece->m_colour)
        return true;
    else
        return false;
}