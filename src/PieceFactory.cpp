#include "PieceFactory.h"

PieceFactory::PieceFactory()
{
}

PieceFactory::~PieceFactory()
{
}

static std::unique_ptr<Piece> PieceFactory::CreatePawn(Piece::PieceColour)
{
    return std::make_unique<Pawn>(PieceColour);
}
static std::unique_ptr<Piece> PieceFactory::CreateKing(Piece::PieceColour)
{
    return std::make_unique<King>(PieceColour);
}
static std::unique_ptr<Piece> PieceFactory::CreateQueen(Piece::PieceColour)
{
    return std::make_unique<Queen>(PieceColour);
}
static std::unique_ptr<Piece> PieceFactory::CreateBishop(Piece::PieceColour)
{
    return std::make_unique<Bishop>(PieceColour);
}
static std::unique_ptr<Piece> PieceFactory::CreateKnight(Piece::PieceColour)
{
    return std::make_unique<Knight>(PieceColour);
}
static std::unique_ptr<Piece> PieceFactory::CreateRook(Piece::PieceColour)
{
    return std::make_unique<Rook>(PieceColour);
}
static void PieceFactory : DeletePiece(std::unique_ptr<Piece> piece)
{
    /* calling reset on a std::unique_ptr sets it to nullptr,
     * causing the associated memory to be released and the destructor of the managed object to be called.
     */
    piece.reset();
}