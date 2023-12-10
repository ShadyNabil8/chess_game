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

    for (int i = 0; i < boardSize; i++)
    {
        pieces[i][1] = new Pawn(Piece::DARK);
        pieces[i][6] = new Pawn(Piece::LIGHT);
    }
}

void Board ::OnPaint(wxPaintEvent &event)
{
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
    // if(selectedSquareCol != -1 && selectedSquareRow != -1)
    // {
    //     DrawSquare(selectedSquareCol, selectedSquareRow, DARK, nullptr);
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
        if (!IsEmptySquare(clickedCol, clickedRow))
        {
            // No square selected yet, highlight the clicked square
            selectedSquareRow = clickedRow;
            selectedSquareCol = clickedCol;
        }
    }
    else
    {
        MovePiece(selectedSquareCol, selectedSquareRow, clickedCol, clickedRow);
        //  Move the piece or perform other actions as needed
        //  You may want to update the board and redraw the chessboard
        //  based on the selected and clicked squares
        //  ...

        // Reset the selected square
        selectedSquareRow = -1;
        selectedSquareCol = -1;
    }

    Refresh(true); // Request a repaint
}

void Board::DrawSquare(int x, int y, Colour color, Piece *piece)
{
    wxPaintDC dc(this);
    if (x == selectedSquareCol && y == selectedSquareRow)
    {

        dc.SetBrush(wxBrush(wxColour(135, 62, 35)));
        dc.SetPen(wxPen(wxColour(135, 62, 35), 0, wxPENSTYLE_TRANSPARENT));
    }
    else
    {

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
    }

    x *= squareSize;
    y *= squareSize;
    dc.DrawRectangle(x, y, squareSize, squareSize);
    
    if (piece != nullptr)
    {
        if (piece->GetImage() != nullptr)
        { /* Add offset */
            x += (squareSize - piece->GetImage()->GetWidth()) / 2;
            y += (squareSize - piece->GetImage()->GetHeight()) / 2;
            dc.DrawBitmap(*(piece->GetImage()), x, y, false);
        }
    }
}

bool Board::IsEmptySquare(int x, int y)
{
    if (pieces[x][y] == nullptr)
        return true;
    else
        return false;
}

void Board::CleanSquare(int new_x, int new_y)
{
    if (IsEmptySquare(new_x, new_y))
    {
        pieces[new_x][new_y] = nullptr;
    }
    else
    {
        delete pieces[new_x][new_y];
        pieces[new_x][new_y] = nullptr;
    }
}
void Board::MovePiece(int old_x, int old_y, int new_x, int new_y)
{
    CleanSquare(new_x, new_y);
    pieces[new_x][new_y] = pieces[old_x][old_y];
    pieces[old_x][old_y] = nullptr;
}

void Board::HighlightPiece(int x, int y)
{
}