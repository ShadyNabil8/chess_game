#include "Frame.h"

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Chess", wxDefaultPosition, wxSize(800, 835), wxDEFAULT_FRAME_STYLE & ~wxRESIZE_BORDER)
{
    m_board = new Board(this);
}
MyFrame::~MyFrame()
{
}