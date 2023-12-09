#include "Board.h"

//--------------------------------------------------------------//
//                         Constructors                         //
//--------------------------------------------------------------//

Board::Board()
{
}

Board::~Board()
{
}

Board::Board(wxFrame *parent) : wxPanel(parent)
{
    boardSize = 8;
    squareSize = 100;
    selectedSquareRow = -1;
    selectedSquareCol = -1;
    Bind(wxEVT_PAINT, &Board::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &Board::OnLeftClick, this);
}

void Board ::OnPaint(wxPaintEvent &event)
{
    // wxPaintDC dc(this);

    // Draw the chessboard
    for (int row = 0; row < boardSize; ++row)
    {
        for (int col = 0; col < boardSize; ++col)
        {
            int x = col * squareSize;
            int y = row * squareSize;

            if ((row + col) % 2 == 0)
                DrawSquare(x, y, LIGHT);
            else
                DrawSquare(x, y, DARK);
            // TODO: Draw chess pieces based on board[row][col]
        }
    }

    // Highlight the selected square if any
    // if (selectedSquareRow != -1 && selectedSquareCol != -1)
    // {
    //     dc.SetBrush(wxBrush(wxColour(53, 53, 53))); // Semi-transparent green
    //     dc.DrawRectangle(selectedSquareCol * squareSize, selectedSquareRow * squareSize, squareSize, squareSize);
    // }

    // Ensure the paint event is processed
    event.Skip();
}

void Board::OnLeftClick(wxMouseEvent &event)
{
    int mouseX = event.GetX();
    int mouseY = event.GetY();

    int clickedCol = mouseX / squareSize;
    int clickedRow = mouseY / squareSize;

    if (selectedSquareRow == -1 && selectedSquareCol == -1)
    {
        // No square selected yet, highlight the clicked square
        selectedSquareRow = clickedRow;
        selectedSquareCol = clickedCol;
    }
    else
    {
        // Move the piece or perform other actions as needed
        // You may want to update the board and redraw the chessboard
        // based on the selected and clicked squares
        // ...

        // Reset the selected square
        selectedSquareRow = -1;
        selectedSquareCol = -1;
    }

    Refresh(); // Request a repaint
}

void Board::DrawSquare(int x, int y, Colour color)
{
    wxPaintDC dc(this);
    if (color == LIGHT)
    {
        dc.SetBrush(wxBrush(wxColour(238, 239, 211, 255))); // White square
        dc.SetPen(wxPen(wxColour(238, 239, 211, 255), 0, wxPENSTYLE_TRANSPARENT));
    }
    else
    {
        dc.SetBrush(wxBrush(wxColour(119, 150, 87, 255))); // White square
        dc.SetPen(wxPen(wxColour(119, 150, 87, 255), 0, wxPENSTYLE_TRANSPARENT));
    }
    dc.DrawRectangle(x, y, squareSize, squareSize);
}