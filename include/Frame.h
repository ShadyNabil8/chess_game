#ifndef _FRAME_H_
#define _FRAME_H_

#include <wx/wx.h>
#include <wx/imaglist.h>
#include "Board.h"
// #define str std::string
// #define CHESS_IMAGES_DIR str("/home/shady/chess_game/images/")
// #define CHESS_WHITE_BISHOP CHESS_IMAGES_DIR + str("w_bishop.png")
// #define CHESS_BLACK_BISHOP (CHESS_IMAGES_DIR + str("b_bishop.png"))
// #define CHESS_WHITE_KING (CHESS_IMAGES_DIR + str("w_king.png"))
// #define CHESS_BLACK_KING (CHESS_IMAGES_DIR + str("b_king.png"))
// #define CHESS_WHITE_KNIGHT (CHESS_IMAGES_DIR + str("w_knight.png"))
// #define CHESS_BLACK_KNIGHT (CHESS_IMAGES_DIR + str("b_knight.png"))
// #define CHESS_WHITE_PAWN (CHESS_IMAGES_DIR + str("w_pawn.png"))
// #define CHESS_BLACK_PAWN (CHESS_IMAGES_DIR + str("b_pawn.png"))
// #define CHESS_WHITE_QUEEN (CHESS_IMAGES_DIR + str("w_queen.png"))
// #define CHESS_BLACK_QUEEN (CHESS_IMAGES_DIR + str("b_queen.png"))
// #define CHESS_WHITE_ROOK (CHESS_IMAGES_DIR + str("w_rook.png"))
// #define CHESS_BLACK_ROOK (CHESS_IMAGES_DIR + str("b_rook.png"))

class MyFrame : public wxFrame
{
public:
    MyFrame();
    ~MyFrame();

private:
    Board *board = new Board(this);
    // wxBitmap m_blackRook;
    // wxBitmap m_blackKnight;
    // wxBitmap m_blackBishop;
    // wxBitmap m_blackQueen;
    // wxBitmap m_blackKing;
    // wxBitmap m_blackPawn;
    // wxBitmap m_whiteRook;
    // wxBitmap m_whiteKnight;
    // wxBitmap m_whiteBishop;
    // wxBitmap m_whiteQueen;
    // wxBitmap m_whiteKing;
    // wxBitmap m_whitePawn;
    // enum ChessPieceID
    // {
    //     BKING,
    //     BQUEEN,
    //     BBISHOP,
    //     BKNIGHT,
    //     BROOK,
    //     BPAWN,
    //     WKING,
    //     WQUEEN,
    //     WBISHOP,
    //     WKNIGHT,
    //     WROOK,
    //     WPAWN
    // };
};
#endif