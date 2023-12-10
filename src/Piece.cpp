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