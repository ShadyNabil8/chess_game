#include "Board.h"
#include "Globals.h"
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
            square_array[x][y]->Bind(wxEVT_LEFT_DOWN, &Board::OnSquareClicked, this);
        }
    }
}

void Board::OnSquareClicked(wxMouseEvent &event)
{
    tempSquare = static_cast<wxWindow*>(event.GetEventObject());
}