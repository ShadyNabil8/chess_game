#ifndef PIECE_H
#define PIECE_H

#pragma once

#include <wx/wx.h>
#include <iostream>
#include "Point.h"
#include <vector>

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
    enum Colour
    {
        DARK,
        LIGHT
    };
    Piece();
    Piece(Colour colour);
    ~Piece();
    wxBitmap *GetImage();
    void SetImage(wxBitmap *image);

protected:
    wxBitmap *m_image;
    Colour m_colour;
    virtual std::vector<Point> GetLegalMoves(const Point &point) const = 0;
private:
};

#endif