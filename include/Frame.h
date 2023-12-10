#ifndef _FRAME_H_
#define _FRAME_H_

#include <wx/wx.h>
#include "Board.h"

class MyFrame : public wxFrame
{
public:
    MyFrame();
    ~MyFrame();

private:
    Board *m_board;

};
#endif