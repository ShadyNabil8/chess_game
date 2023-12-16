#ifndef PIECEFACTORY_H
#define PIECEFACTORY_H

#pragma once
#include <iostream>
#include <memory>
#include "Piece.h"
class PieceFactory
{
public:
    ~PieceFactory();
    static std::unique_ptr<Piece> CreatePawn(const wxString &image);
    static std::unique_ptr<Piece> CreateKing(const wxString &image);
    static std::unique_ptr<Piece> CreateQueen(const wxString &image);
    static std::unique_ptr<Piece> CreateBishop(const wxString &image);
    static std::unique_ptr<Piece> CreateKnight(const wxString &image);
    static std::unique_ptr<Piece> CreateRook(const wxString &image);
    static void DeletePiece(Piece* piece);
private:
    // Make the constructor private to prevent instantiation
    PieceFactory() = default;
};

#endif