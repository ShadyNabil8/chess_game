#ifndef KING_H
#define KING_H

#pragma once
#include "Piece.h"
class King : public Piece
{
public:
    King();
    King(int x, int y, Color color, wxWindow *square);
    ~King();

private:
};

#endif