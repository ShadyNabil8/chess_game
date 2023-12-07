#include "Piece.h"

Piece::Piece()
{
}
Piece::~Piece()
{
}
Piece::Piece(int x, int y, Color color, wxWindow *square) : m_x(x), m_y(y), m_color(color), m_square(square)
{
}
void Piece::Put(int x, int y)
{
    /* Create a bitmap for the image */
    wxBitmap bitmap;
    /* Load the image file into the bitmap */
    bitmap.LoadFile(this->m_img, wxBITMAP_TYPE_PNG);
    this->m_staticBitmap = new wxStaticBitmap(this->m_square, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize);
    wxBoxSizer *squareSizer = new wxBoxSizer(wxHORIZONTAL);
    squareSizer->Add(this->m_staticBitmap, 1, wxALIGN_CENTER);
    this->m_square->SetSizer(squareSizer);
}