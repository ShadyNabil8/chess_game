#ifndef _BOARD_H
#define _BOARD_H
#include <wx/wx.h>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Point.h"
class Board : public wxPanel
{
private:
    enum Colour
    {
        DARK,
        LIGHT
    };
    int boardSize;
    int squareSize;
    int selectedSquareRow;
    int selectedSquareCol;

public:
    Piece *pieces[8][8];
    Board();
    Board(wxFrame *parent);
    void DrawSquare(int x, int y, Colour color, Piece *piece);
    void DrawPiece(int x, int y, Piece *piece, wxPaintDC &dc);
    void OnPaint(wxPaintEvent &event);
    void OnLeftClick(wxMouseEvent &event);
    bool IsEmptySquare(int x, int y);
    void CleanSquare(int new_x, int new_y);
    void MovePiece(int old_x, int old_y, int new_x, int new_y);
    void DrawLightSquare(wxPaintDC &dc, int x, int y);
    void DrawDarkSquare(wxPaintDC &dc, int x, int y);
    void HighlightSquare(wxPaintDC &dc, int x, int y);
    ~Board();
};

#endif