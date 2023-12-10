#include "Frame.h"

MyFrame::MyFrame()
    : wxFrame(NULL, wxID_ANY, "Chess", wxDefaultPosition, wxSize(800, 835))
{
    m_board = new Board(this);
}
MyFrame::~MyFrame()
{
}