#ifndef UI_H
#define UI_H

#pragma once
#include "Piece.h"
#include <wx/wx.h>
class Ui
{
public:
    Ui();
    ~Ui();
    static void Print(Piece *piece, int x, int y);
    static void Clean(wxWindow &square);
    

private:
};

#endif