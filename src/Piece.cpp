#include "Piece.h"
#include "Globals.h"
#include "Ui.h"
Piece::Piece()
{
}
Piece::~Piece()
{
}
Piece::Piece(int x, int y, Color color, wxWindow *square) : m_x(x), m_y(y), m_color(color), m_square(square)
{
}

void Piece::Put(int x, int y)
{
    Ui::Print(this, x, y);
}

void Piece::Delete(wxWindow &square)
{
    Ui::Clean(square);
}

void Piece::Move(int fromX, int fromY, int toX, int toY)
{
}

void Piece::OnPiecePressed(wxMouseEvent &event)
{
     this->Delete(*(this->m_square));
    // tempPiece = this;
    // while (tempSquare == nullptr)
    //     ;
    // std::cout << "Hello" << std::endl;
}