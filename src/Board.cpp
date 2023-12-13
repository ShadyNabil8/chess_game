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
    colours[DARK] = wxColour(209, 134, 88, 255);
    colours[LIGHT] = wxColour(245, 227, 207, 255);
    colours[HIGHLIGHT] = wxColour(158, 90, 78);

    for (int row = 0; row < boardSize; row++)
    {
        for (int col = 0; col < boardSize; col++)
        {
            pieces[row][col] = nullptr;
            highlight_matrix[row][col] = 0;
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
    Point point;
    Colour sqrcolour;
    for (int row = 0; row < boardSize; row++)
    {
        point.SetY(row);
        for (int col = 0; col < boardSize; col++)
        {
            point.SetX(col);
            if (IsLegalMove(point))
                sqrcolour = HIGHLIGHT;
            else
            {
                if ((row + col) % 2 == 0)
                    sqrcolour = LIGHT;
                else
                    sqrcolour = DARK;
            }
            DrawSquare(point, sqrcolour, pieces[col][row]);
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
            Point point(clickedCol, clickedRow);
            GetPiece(point)->GetLegalMoves(point, pieces, highlight_matrix);
            // No square selected yet, highlight the clicked square
            selectedSquareRow = clickedRow;
            selectedSquareCol = clickedCol;
        }
    }
    else
    {
        Point oldpoint = Point(selectedSquareCol, selectedSquareRow);
        Point newpoint = Point(clickedCol, clickedRow);
        /* Ensure that the same piece will not eat itself :) */
        if (oldpoint != newpoint)
            MovePiece(oldpoint, newpoint);

        // Reset the selected square
        selectedSquareRow = -1;
        selectedSquareCol = -1;
    }

    Refresh(true); // Request a repaint
}

void Board::DrawSquare(const Point &point, Colour &color, Piece *piece)
{
    int mouseX = point.GetX() * squareSize;
    int mouseY = point.GetY() * squareSize;
    wxPaintDC dc(this);
    Point selected = Point(selectedSquareCol, selectedSquareRow);
    dc.SetBrush(wxBrush(colours[color]));
    dc.SetPen(wxPen(colours[color], 0, wxPENSTYLE_TRANSPARENT));
    dc.DrawRectangle(mouseX, mouseY, squareSize, squareSize);
    DrawPiece(point, piece, dc);
}

bool Board::IsEmptySquare(const Point &point)
{
    if (GetPiece(point) == nullptr)
        return true;
    else
        return false;
}

void Board::CleanSquare(const Point &point)
{
    if (!IsEmptySquare(point))
    {
        delete GetPiece(point);
        SetPiece(point, nullptr);
    }
}
void Board::MovePiece(const Point &oldpoint, const Point &newpoint)
{
    CleanSquare(newpoint);
    Piece *oldpiece = GetPiece(oldpoint);
    SetPiece(newpoint, oldpiece);
    SetPiece(oldpoint, nullptr);
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

bool Board::IsLegalMove(const Point &point)
{
    int x = point.GetX();
    int y = point.GetY();
    if (highlight_matrix[x][y] == true)
    {
        highlight_matrix[x][y] = false;
        return true;
    }
    return false;
}

Piece *Board::GetPiece(const Point &point)
{
    return this->pieces[point.GetX()][point.GetY()];
}

void Board::SetPiece(const Point &point, Piece *piece)
{
    pieces[point.GetX()][point.GetY()] = piece;
}