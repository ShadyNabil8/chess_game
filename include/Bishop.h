#ifndef BISHOP_H
#define BISHOP_H

#pragma once
#include "Piece.h"
class Bishop : public Piece
{
public:
    Bishop();
    Bishop(int x, int y, Color color, wxWindow *square);
    ~Bishop();

private:
};

#endif