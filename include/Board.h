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
    bool highlight_matrix[8][8];
    Board();
    Board(wxFrame *parent);
    void DrawSquare(const Point &point, Colour color, Piece *piece);
    void DrawPiece(const Point &point, Piece *piece, wxPaintDC &dc);
    void OnPaint(wxPaintEvent &event);
    void OnLeftClick(wxMouseEvent &event);
    bool IsEmptySquare(const Point &point);
    bool IsLegalMove(const Point &point);
    void CleanSquare(const Point &point);
    void MovePiece(const Point &oldpoint, const Point &newpoint);
    void DrawLightSquare(wxPaintDC &dc, const Point &point);
    void DrawDarkSquare(wxPaintDC &dc, const Point &point);
    void HighlightSquare(wxPaintDC &dc, const Point &point);
    ~Board();
};

#endif