#ifndef PIECE_H
#define PIECE_H

#pragma once

#include <wx/wx.h>
#include <iostream>
#include "Point.h"

#define str std::string
#define CHESS_IMAGES_DIR str("/home/shady/chess_game/images/")
#define CHESS_WHITE_BISHOP CHESS_IMAGES_DIR + str("w_bishop.png")
#define CHESS_BLACK_BISHOP (CHESS_IMAGES_DIR + str("b_bishop.png"))
#define CHESS_WHITE_KING (CHESS_IMAGES_DIR + str("w_king.png"))
#define CHESS_BLACK_KING (CHESS_IMAGES_DIR + str("b_king.png"))
#define CHESS_WHITE_KNIGHT (CHESS_IMAGES_DIR + str("w_knight.png"))
#define CHESS_BLACK_KNIGHT (CHESS_IMAGES_DIR + str("b_knight.png"))
#define CHESS_WHITE_PAWN (CHESS_IMAGES_DIR + str("w_pawn.png"))
#define CHESS_BLACK_PAWN (CHESS_IMAGES_DIR + str("b_pawn.png"))
#define CHESS_WHITE_QUEEN (CHESS_IMAGES_DIR + str("w_queen.png"))
#define CHESS_BLACK_QUEEN (CHESS_IMAGES_DIR + str("b_queen.png"))
#define CHESS_WHITE_ROOK (CHESS_IMAGES_DIR + str("w_rook.png"))
#define CHESS_BLACK_ROOK (CHESS_IMAGES_DIR + str("b_rook.png"))

class Piece
{
public:
    enum PieceColour
    {
        DARK_PIECE = 0,
        LIGHT_PIECE
    };
    Piece();
    Piece(PieceColour colour);
    ~Piece();
    wxBitmap *GetImage();
    virtual PieceColour GetColour() = 0;
    void SetImage(wxBitmap *image);
    virtual void GetLegalMoves(const Point &point, Piece *chessmatrix[8][8], bool highlight_matrix[8][8]) = 0;

protected:
    wxBitmap *m_image;
    PieceColour m_colour;
    bool IsInBoard(const Point &point);
    bool IsEnemy(const Piece *current, const Piece *other);
    bool IsEmpty(const Piece *piece);
    void SetValidMove(const Point &point, bool highlight_matrix[8][8]);

private:
};

#endif