#include "Piece.h"
#include "Globals.h"
#include "Ui.h"
#include <thread>
#include <chrono>
#include <future>
Piece::Piece()
{
}
Piece::~Piece()
{
}
Piece::Piece(int x, int y, Color color, wxWindow *square) : m_x(x), m_y(y), m_color(color), m_square(square)
{
}

void Piece::Put()
{
    Ui::Print(this);
}

void Piece::Delete(wxWindow &square)
{
    Ui::Clean(square);
}

void Piece::Move(wxWindow *square)
{
    this->Delete(*(this->m_square));
    this->m_square = tempSquare;
    this->Put();
}

void Piece::OnPiecePressed(wxMouseEvent &event)
{
    tempPiece = this;
    std::cout << "Piece: " << tempPiece << std::endl;
}