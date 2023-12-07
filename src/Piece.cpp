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
    this->m_staticBitmap->Bind(wxEVT_LEFT_DOWN, &Piece::OnPiecePressed, this);
    wxBoxSizer *squareSizer = new wxBoxSizer(wxHORIZONTAL);
    squareSizer->Add(this->m_staticBitmap, 1, wxALIGN_CENTER);
    this->m_square->SetSizer(squareSizer);
}

void Piece::Delete(wxWindow &square)
{
    // Get the sizer associated with the square
    wxSizer *squareSizer = square.GetSizer();

    if (squareSizer)
    {
        /* Remove all items from the sizer */
        squareSizer->Clear(true); // true indicates that the items should be deleted
        /* Layout the square to reflect the changes */
        square.Layout();
    }
}

void Piece::OnPiecePressed(wxMouseEvent &event)
{
    this->Delete(*(this->m_square));
}