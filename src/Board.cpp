#include "Board.h"
#include <iostream>
#include <unistd.h>

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
            pieces[row][col] = nullptr;
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
    Point point;
    for (int row = 0; row < boardSize; row++)
    {
        point.SetY(row);
        for (int col = 0; col < boardSize; col++)
        {
            point.SetX(col);
            if ((row + col) % 2 == 0)
                DrawSquare(point, LIGHT, pieces[col][row]);
            else
                DrawSquare(point, DARK, pieces[col][row]);
        }
    }
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
        if (!IsEmptySquare(Point(clickedCol, clickedRow)))
        {
            // No square selected yet, highlight the clicked square
            selectedSquareRow = clickedRow;
            selectedSquareCol = clickedCol;
        }
    }
    else
    {
        Point oldpoint = Point(selectedSquareCol, selectedSquareRow);
        Point newpoint = Point(clickedCol, clickedRow);
        MovePiece(oldpoint, newpoint);
        // Reset the selected square
        selectedSquareRow = -1;
        selectedSquareCol = -1;
    }

    Refresh(true); // Request a repaint
}

void Board::DrawSquare(const Point &point, Colour color, Piece *piece)
{
    wxPaintDC dc(this);
    if (point.GetX() == selectedSquareCol && point.GetY() == selectedSquareRow)
    {
        HighlightSquare(dc, point);
    }
    else
    {
        if (color == LIGHT)
            DrawLightSquare(dc, point);
        else
            DrawDarkSquare(dc, point);
    }
    DrawPiece(point, piece, dc);
}

bool Board::IsEmptySquare(const Point &point)
{
    if (pieces[point.GetX()][point.GetY()] == nullptr)
        return true;
    else
        return false;
}

void Board::CleanSquare(const Point &point)
{
    if (IsEmptySquare(point))
    {
        pieces[point.GetX()][point.GetY()] = nullptr;
    }
    else
    {
        delete pieces[point.GetX()][point.GetY()];
        pieces[point.GetX()][point.GetY()] = nullptr;
    }
}
void Board::MovePiece(const Point &oldpoint, const Point &newpoint)
{
    CleanSquare(newpoint);
    pieces[newpoint.GetX()][newpoint.GetY()] = pieces[oldpoint.GetX()][oldpoint.GetY()];
    pieces[oldpoint.GetX()][oldpoint.GetY()] = nullptr;
}

void Board::DrawLightSquare(wxPaintDC &dc, const Point &point)
{
    dc.SetBrush(wxBrush(wxColour(238, 239, 211, 255)));
    dc.SetPen(wxPen(wxColour(238, 239, 211, 255), 0, wxPENSTYLE_TRANSPARENT));
    dc.DrawRectangle(point.GetX() * squareSize, point.GetY() * squareSize, squareSize, squareSize);
}
void Board::DrawDarkSquare(wxPaintDC &dc, const Point &point)
{

    dc.SetBrush(wxBrush(wxColour(119, 150, 87, 255)));
    dc.SetPen(wxPen(wxColour(119, 150, 87, 255), 0, wxPENSTYLE_TRANSPARENT));
    dc.DrawRectangle(point.GetX() * squareSize, point.GetY() * squareSize, squareSize, squareSize);
}

void Board::HighlightSquare(wxPaintDC &dc, const Point &point)
{
    dc.SetBrush(wxBrush(wxColour(30, 129, 176)));
    dc.SetPen(wxPen(wxColour(30, 129, 176), 0, wxPENSTYLE_TRANSPARENT));
    dc.DrawRectangle(point.GetX() * squareSize, point.GetY() * squareSize, squareSize, squareSize);
}

void Board::DrawPiece(const Point &point, Piece *piece, wxPaintDC &dc)
{
    int x = point.GetX() * squareSize;
    int y = point.GetY() * squareSize;
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