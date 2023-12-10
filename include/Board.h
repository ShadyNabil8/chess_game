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
    int board[8][8];

public:
    Piece *pieces[8][8];
    Board();
    Board(wxFrame *parent);
    void DrawSquare(int x, int y, Colour color, Piece *piece);
    void OnPaint(wxPaintEvent &event);
    void OnLeftClick(wxMouseEvent &event);
    bool IsEmptySquare(int x, int y);
    void CleanSquare(int old_x, int old_y, int new_x, int new_y);
    void MovePiece(int old_x, int old_y, int new_x, int new_y);
    ~Board();
};

#endif