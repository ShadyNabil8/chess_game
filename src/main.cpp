#define TEST 2

#if TEST == 0

#elif TEST == 1

#elif TEST == 2

#include <wx/wx.h>
#include "../include/Chess.h"
class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame *frame = new MyFrame();
        Board *chessboard = new Board(frame);
        Bishop *p = new Bishop(0, 0, WHITE, chessboard->square_array[0][0]);
        Bishop *p2 = new Bishop(1, 0, BLACK, chessboard->square_array[1][0]);

        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

#endif