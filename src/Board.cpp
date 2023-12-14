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
    colours[DARK] = wxColour(134, 167, 137);
    colours[LIGHT] = wxColour(235, 243, 232);
    colours[HIGHLIGHT] = wxColour(178, 200, 186);
    player = DARK_PLAYER;

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

    pieces[0][0] = new Rook(Piece::DARK_PIECE);
    pieces[1][0] = new Knight(Piece::DARK_PIECE);
    pieces[2][0] = new Bishop(Piece::DARK_PIECE);
    pieces[3][0] = new Queen(Piece::DARK_PIECE);
    pieces[4][0] = new King(Piece::DARK_PIECE);
    pieces[5][0] = new Bishop(Piece::DARK_PIECE);
    pieces[6][0] = new Knight(Piece::DARK_PIECE);
    pieces[7][0] = new Rook(Piece::DARK_PIECE);

    pieces[0][7] = new Rook(Piece::LIGHT_PIECE);
    pieces[1][7] = new Knight(Piece::LIGHT_PIECE);
    pieces[2][7] = new Bishop(Piece::LIGHT_PIECE);
    pieces[3][7] = new Queen(Piece::LIGHT_PIECE);
    pieces[4][7] = new King(Piece::LIGHT_PIECE);
    pieces[5][7] = new Bishop(Piece::LIGHT_PIECE);
    pieces[6][7] = new Knight(Piece::LIGHT_PIECE);
    pieces[7][7] = new Rook(Piece::LIGHT_PIECE);

    for (int i = 0; i < boardSize; i++)
    {
        pieces[i][1] = new Pawn(Piece::DARK_PIECE);
        pieces[i][6] = new Pawn(Piece::LIGHT_PIECE);
    }
}

void Board ::OnPaint(wxPaintEvent &event)
{
    //  Draw the chessboard
    Point point;
    Colour sqrcolour;
    LegalMovesVector.reserve(INITIAL_VECTOR_SIZE);
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
            DrawSquare(point, sqrcolour, GetPiece(point));
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
    Point newpoint = Point(clickedCol, clickedRow);

    if (selectedSquareRow == -1 && selectedSquareCol == -1)
    {
        if (!IsEmptySquare(newpoint))
        {
            if (IsCorrectPlayerTurn(newpoint))
            {
                GetPiece(newpoint)->GetLegalMoves(newpoint, pieces, highlight_matrix);
                selectedSquareRow = clickedRow;
                selectedSquareCol = clickedCol;
            }
        }
    }
    else
    {
        Point oldpoint = Point(selectedSquareCol, selectedSquareRow);
        /* Ensure that the same piece will not eat itself */
        if (oldpoint != newpoint)
        {
            if (IsLegalMoveSelected(newpoint))
            {
                MovePiece(oldpoint, newpoint);
                RevertTurns();
            }
        }
        // Reset the selected square
        selectedSquareRow = -1;
        selectedSquareCol = -1;

        /* Reset the vector containning legal moves */
        LegalMovesVector.clear();
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
        LegalMovesVector.push_back(point);
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

bool Board::IsLegalMoveSelected(Point &point)
{
    auto it = std::find(LegalMovesVector.begin(), LegalMovesVector.end(), point);

    if (it != LegalMovesVector.end())
        return true;
    else
        return false;
}

bool Board::IsCorrectPlayerTurn(const Point &point)
{
    Piece::PieceColour piececolor = GetPiece(point)->GetColour();
    if (piececolor == Piece::DARK_PIECE && this->player == DARK_PLAYER)
        return true;
    else if (piececolor == Piece::LIGHT_PIECE && this->player == LIGHT_PLAYER)
        return true;
    else
        return false;
}
void Board::RevertTurns()
{
    if (this->player == DARK_PLAYER)
        this->player = LIGHT_PLAYER;
    else
        this->player = DARK_PLAYER;
}