#ifndef _BOARD_H
#define _BOARD_H
#include <wx/wx.h>
#include "../include/Frame.h"
class Board
{
private:
    wxWindow *square_array[8][8];
    wxGridSizer *chessboardSizer;
    wxPanel *panel;

public:
    Board();
    Board(MyFrame *frame);
    ~Board();
    void MovingChessPawn(int ox, int oy, int nx, int ny, const wxString &imagePath);
    void PutPawn(wxWindow &square, const wxString &imagePath);
    void RemovePawn(wxWindow &square);
    void Draw(wxGridSizer *chessboardSizer, wxWindow *square_array[8][8]);
};

#endif