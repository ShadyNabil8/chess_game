#include "PieceFactory.h"

PieceFactory::PieceFactory()
{
}

PieceFactory::~PieceFactory()
{
}

std::unique_ptr<Piece> PieceFactory::CreatePawn(PieceColour color)
{
    return std::make_unique<Pawn>(color);
}
std::unique_ptr<Piece> PieceFactory::CreateKing(PieceColour color)
{
    return std::make_unique<King>(color);
}
std::unique_ptr<Piece> PieceFactory::CreateQueen(PieceColour color)
{
    return std::make_unique<Queen>(color);
}
std::unique_ptr<Piece> PieceFactory::CreateBishop(PieceColour color)
{
    return std::make_unique<Bishop>(color);
}
std::unique_ptr<Piece> PieceFactory::CreateKnight(PieceColour color)
{
    return std::make_unique<Knight>(color);
}
std::unique_ptr<Piece> PieceFactory::CreateRook(PieceColour color)
{
    return std::make_unique<Rook>(color);
}
void PieceFactory ::DeletePiece(std::unique_ptr<Piece> piece)
{
    /* calling reset on a std::unique_ptr sets it to nullptr,
     * causing the associated memory to be released and the destructor of the managed object to be called.
     */
    piece.reset();
}