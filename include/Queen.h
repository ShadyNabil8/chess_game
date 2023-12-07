#ifndef QUEEN_H
#define QUEEN_H

#pragma once
#include "Piece.h"
class Queen : public Piece
{
public:
    Queen();
    Queen(int x, int y, Color color, wxWindow *square);
    ~Queen();

private:
};

#endif