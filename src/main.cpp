#define TEST 2

#if TEST == 0


#elif TEST == 1


#elif TEST == 2

#include <wx/wx.h>
#include "../include/Board.h"
class MyFrame : public wxFrame
{
public:
    MyFrame() : wxFrame(NULL, wxID_ANY, "Chessboard", wxDefaultPosition, wxSize(800, 800))
    {
        wxPanel *panel = new wxPanel(this, wxID_ANY);
        Board *chessboard = new Board();
        chessboard->init(panel);
    }
};

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame *frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);

#endif