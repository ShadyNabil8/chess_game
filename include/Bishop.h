#ifndef BISHOP_H
#define BISHOP_H

#pragma once
#include "Piece.h"
#include "Point.h"
class Bishop : public Piece
{
public:
    Bishop();
    Bishop(Colour colour);
    ~Bishop();
    std::vector<Point> GetLegalMoves(const Point &point) const;

private:
};

#endif