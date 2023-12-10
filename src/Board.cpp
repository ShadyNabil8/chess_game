#include "Board.h"
#include <iostream>
#include <unistd.h>
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
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            board[row][col] = 0;
            pieces[row][col] = nullptr;
        }
    }
    Bind(wxEVT_PAINT, &Board::OnPaint, this);
    Bind(wxEVT_LEFT_DOWN, &Board::OnLeftClick, this);

    pieces[0][0] = new Rook(Piece::DARK);
    pieces[1][0] = new Knight(Piece::DARK);
    pieces[2][0] = new Bishop(Piece::DARK);
    pieces[3][0] = new Queen(Piece::DARK);
    pieces[4][0] = new King(Piece::DARK);
    pieces[5][0] = new Bishop(Piece::DARK);
    pieces[6][0] = new Knight(Piece::DARK);
    pieces[7][0] = new Rook(Piece::DARK);

    pieces[0][7] = new Rook(Piece::LIGHT);
    pieces[1][7] = new Knight(Piece::LIGHT);
    pieces[2][7] = new Bishop(Piece::LIGHT);
    pieces[3][7] = new Queen(Piece::LIGHT);
    pieces[4][7] = new King(Piece::LIGHT);
    pieces[5][7] = new Bishop(Piece::LIGHT);
    pieces[6][7] = new Knight(Piece::LIGHT);
    pieces[7][7] = new Rook(Piece::LIGHT);

    for(int i = 0 ; i < boardSize ; i++)
    {
        pieces[i][1] = new Pawn(Piece::DARK);
        pieces[i][6] = new Pawn(Piece::LIGHT);
    }
        
}

void Board ::OnPaint(wxPaintEvent &event)
{
    // sleep(5);
    //  Draw the chessboard
    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            if ((row + col) % 2 == 0)
                DrawSquare(col, row, LIGHT, pieces[col][row]);
            else
                DrawSquare(col, row, DARK, pieces[col][row]);
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

        pieces[clickedCol][clickedRow] = pieces[selectedSquareCol][selectedSquareRow];
        pieces[selectedSquareCol][selectedSquareRow] = nullptr;
        // Move the piece or perform other actions as needed
        // You may want to update the board and redraw the chessboard
        // based on the selected and clicked squares
        // ...

        // Reset the selected square
        selectedSquareRow = -1;
        selectedSquareCol = -1;
    }

    Refresh(true); // Request a repaint
}

void Board::DrawSquare(int x, int y, Colour color, Piece *piece)
{
    x *= squareSize;
    y *= squareSize;
    wxPaintDC dc(this);
    if (color == LIGHT)
    {
        dc.SetBrush(wxBrush(wxColour(238, 239, 211, 255)));
        dc.SetPen(wxPen(wxColour(238, 239, 211, 255), 0, wxPENSTYLE_TRANSPARENT));
    }
    else
    {
        dc.SetBrush(wxBrush(wxColour(119, 150, 87, 255)));
        dc.SetPen(wxPen(wxColour(119, 150, 87, 255), 0, wxPENSTYLE_TRANSPARENT));
    }
    dc.DrawRectangle(x, y, squareSize, squareSize);

    if (piece != nullptr)
    {
        if (piece->GetImage() != nullptr)
        { /* Add offset */
            x += (squareSize - piece->GetImage()->GetWidth()) / 2;
            y += (squareSize - piece->GetImage()->GetHeight()) / 2;
            dc.DrawBitmap(*(piece->GetImage()), x, y, true);
        }
    }
}