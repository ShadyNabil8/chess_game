#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#pragma once
#include <iostream>
#include <memory>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
class PieceFactory
{
public:
    ~PieceFactory();
    PieceFactory();
    static std::unique_ptr<Piece> CreatePawn(PieceColour color);
    static std::unique_ptr<Piece> CreateKing(PieceColour color);
    static std::unique_ptr<Piece> CreateQueen(PieceColour color);
    static std::unique_ptr<Piece> CreateBishop(PieceColour color);
    static std::unique_ptr<Piece> CreateKnight(PieceColour color);
    static std::unique_ptr<Piece> CreateRook(PieceColour color);
    static void DeletePiece(std::unique_ptr<Piece> piece);

private:
    // Make the constructor private to prevent instantiation
    // PieceFactory() = default;
};

#endif