#include "Piece.h"

Piece::Piece()
{
}
Piece::~Piece()
{
}

Piece::Piece(PieceColour colour) : m_colour(colour), m_image(nullptr)
{
}

wxBitmap *Piece::GetImage()
{
    return this->m_image;
}

Piece::PieceColour Piece::GetColour()
{
    return this->m_colour;
}

void Piece::SetImage(wxBitmap *image)
{
    this->m_image = image;
}

void Piece::InitializeImage(const wxString &darkImage, const wxString &lightImage)
{
    wxBitmap *image = new wxBitmap(m_colour == DARK_PIECE ? darkImage : lightImage, wxBITMAP_TYPE_PNG);
    SetImage(image);
}

bool Piece::IsInBoard(const Point &targetPosition)
{
    int x = targetPosition.GetX();
    int y = targetPosition.GetY();
    if ((x < 8) && (x >= 0) && (y < 8) && (y >= 0))
        return true;
    else
        return false;
}
bool Piece::IsEnemy(const Piece *currentPiece, const Piece *targetPiece)
{
    if (currentPiece->m_colour == targetPiece->m_colour)
        return false;
    else
        return true;
}
bool Piece::IsEmpty(const Piece *targetPiece)
{
    if (targetPiece == nullptr)
        return true;
    else
        return false;
}

void Piece::SetValidMove(const Point &targetPosition, bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE])
{
    int x = targetPosition.GetX();
    int y = targetPosition.GetY();
    validMovesMatrix[x][y] = true;
}

void Piece::Kill()
{
    delete this;
}
