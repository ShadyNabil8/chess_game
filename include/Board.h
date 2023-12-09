#ifndef _BOARD_H
#define _BOARD_H
#include <wx/wx.h>
class Board : public wxPanel
{
private:
    int boardSize;
    int squareSize;
    int selectedSquareRow;
    int selectedSquareCol;
    int board[8][8];
    enum Colour
    {
        DARK,
        LIGHT
    };

public:
    Board();
    Board(wxFrame *parent);
    void DrawSquare(int x, int y, Colour color);
    void OnPaint(wxPaintEvent &event);
    void OnLeftClick(wxMouseEvent &event);
    ~Board();
};

#endif