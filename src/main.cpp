#define TEST 2

#if TEST == 0


#elif TEST == 1


#elif TEST == 2

#include <wx/wx.h>
#include "../include/Board.h" 
#include "../include/Frame.h" 
class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame *frame = new MyFrame();
        Board *chessboard = new Board(frame);
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

#endif