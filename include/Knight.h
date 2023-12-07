#ifndef KNIGHT_H
#define KNIGHT_H

#pragma once
#include "Piece.h"
class Knight : public Piece
{
public:
    Knight();
    Knight(int x, int y, Color color, wxWindow *square);
    ~Knight();

private:
};

#endif