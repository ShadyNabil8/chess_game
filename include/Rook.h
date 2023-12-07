#ifndef ROOK_H
#define ROOK_H

#pragma once
#include "Piece.h"
class Rook : public Piece
{
public:
    Rook();
    Rook(int x, int y, Color color, wxWindow *square);
    ~Rook();

private:
};

#endif