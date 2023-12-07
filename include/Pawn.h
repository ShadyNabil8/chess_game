#ifndef PAWN_H
#define PAWN_H

#pragma once
#include "Piece.h"
class Pawn : public Piece
{
public:
    Pawn();
    Pawn(int x, int y, Color color, wxWindow *square);
    ~Pawn();

private:
};

#endif