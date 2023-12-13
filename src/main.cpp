#include <wx/wx.h>

#include "Frame.h"


class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        ::wxInitAllImageHandlers();
        MyFrame *frame = new MyFrame();
        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
