#include "../include/Board.h"

//--------------------------------------------------------------//
//                         Constructors                         //
//--------------------------------------------------------------//

Board::Board()
{
}

Board::~Board()
{
}
Board::Board(MyFrame *frame)
{
    /* Create a grid sizer for the chessboard */
    this->chessboardSizer = new wxGridSizer(8, 8, 0, 0);
    /* Set the grid sizer as the sizer for the panel */
    this->panel = new wxPanel(frame, wxID_ANY);
    panel->SetSizer(this->chessboardSizer);
    this->Draw(this->chessboardSizer, this->square_array);
}

//--------------------------------------------------------------//
//                         Move Pawn                            //
//--------------------------------------------------------------//

void Board::MovingChessPawn(int ox, int oy, int nx, int ny, const wxString &imagePath)
{
}
// void Board::PutPawn(wxWindow &square, const wxString &imagePath)
// {
//     /* Create a bitmap for the image */
//     wxBitmap bitmap;
//     /* Load the image file into the bitmap */
//     bitmap.LoadFile(imagePath, wxBITMAP_TYPE_PNG);
//     wxStaticBitmap *staticBitmap = new wxStaticBitmap(
//         &square, wxID_ANY, bitmap, wxDefaultPosition, wxDefaultSize);
//     //staticBitmap->Bind(wxEVT_LEFT_DOWN, &Board::OnPawnPressed, this);
//     wxBoxSizer *squareSizer = new wxBoxSizer(wxHORIZONTAL);
//     squareSizer->Add(staticBitmap, 1, wxALIGN_CENTER);
//     square.SetSizer(squareSizer);
// }

//--------------------------------------------------------------//
//                        Delete Pawn                           //
//--------------------------------------------------------------//

void Board::RemovePawn(wxWindow &square)
{
    // Get the sizer associated with the square
    wxSizer *squareSizer = square.GetSizer();

    if (squareSizer)
    {
        // Remove all items from the sizer
        squareSizer->Clear(true); // true indicates that the items should be deleted
        // Layout the square to reflect the changes
        square.Layout();
    }
}

//--------------------------------------------------------------//
//                       Draw The Board                         //
//--------------------------------------------------------------//

void Board::Draw(wxGridSizer *chessboardSizer, wxWindow *square_array[8][8])
{
    // Populate the chessboard with squares
    for (int y = 0; y < 8; y++)
    {
        for (int x = 0; x < 8; x++)
        {
            // wxWindow *square = new wxWindow(panel, wxID_ANY);
            this->square_array[x][y] = new wxWindow(panel, wxID_ANY);
            if ((x + y) % 2 == 0)
            {
                square_array[x][y]->SetBackgroundColour(wxColour(92, 50, 48, 255)); // Set the background color of the square
            }
            else
            {
                square_array[x][y]->SetBackgroundColour(wxColour(120, 73, 57, 255)); // Set the background color of the square
            }
            // Add the square to the grid sizer
            chessboardSizer->Add(square_array[x][y], 1, wxEXPAND | wxALL, 0);
        }
    }
}


//--------------------------------------------------------------//
//                       Init The Paws                          //
//--------------------------------------------------------------//

void Board::InitPaws()
{
    
}









//--------------------------------------------------------------
//--------------------------------------------------------------

void Board::OnPawnPressed(wxMouseEvent& event)
{
    this->RemovePawn(*(this->square_array[0][0]));
    this->RemovePawn(*(this->square_array[0][5]));
}