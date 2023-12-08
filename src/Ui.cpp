#include "Ui.h"

Ui::Ui()
{
}

Ui::~Ui()
{
}

void Ui::Print(Piece *piece)
{
    /* Create a bitmap for the image */
    wxBitmap bitmap;
    /* Load the image file into the bitmap */
    bitmap.LoadFile(piece->m_img, wxBITMAP_TYPE_PNG);
    piece->m_staticBitmap = new wxStaticBitmap(piece->m_square, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize);
    piece->m_staticBitmap->Bind(wxEVT_LEFT_DOWN, &Piece::OnPiecePressed, piece);
    wxBoxSizer *squareSizer = new wxBoxSizer(wxHORIZONTAL);
    squareSizer->Add(piece->m_staticBitmap, 1, wxALIGN_CENTER);
    piece->m_square->SetSizer(squareSizer);
}

void Ui::Clean(wxWindow &square)
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
    //delete squareSizer;
}