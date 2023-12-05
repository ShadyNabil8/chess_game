#include "../include/Board.h"
Board::Board()
{
}

Board::~Board()
{
}
void Board::init(wxPanel *panel)
{
    // Create a grid sizer for the chessboard
    wxGridSizer *chessboardSizer = new wxGridSizer(8, 8, 0, 0);

    // Populate the chessboard with squares
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            wxWindow *square = new wxWindow(panel, wxID_ANY);
            if ((x + y) % 2 == 0)
            {
                square->SetBackgroundColour(wxColour(209, 139, 71)); // Set the background color of the square
            }
            else
            {
                square->SetBackgroundColour(wxColour(255, 206, 158)); // Set the background color of the square
            }
            chessboardSizer->Add(square, 1, wxEXPAND | wxALL, 0); // Add the square to the grid sizer
        }
    }
    panel->SetSizer(chessboardSizer); // Set the grid sizer as the sizer for the panel
}