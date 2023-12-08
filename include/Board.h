#ifndef _BOARD_H
#define _BOARD_H
#include <wx/wx.h>
#include "Frame.h"
class Board
{
private:
    wxGridSizer *chessboardSizer;
    wxPanel *panel;
    void Draw(wxGridSizer *chessboardSizer);
    void OnSquareClicked(wxMouseEvent &event);

public:
    Board();
    Board(MyFrame *frame);
    ~Board();
    wxWindow *square_array[8][8];
};

#endif