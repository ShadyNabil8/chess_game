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

#ifndef BOARD_SIZE
#define BOARD_SIZE 8
#endif

enum PieceColour
{
    DARK_PIECE = 0,
    LIGHT_PIECE
};

class Piece
{
public:
    Piece();
    Piece(PieceColour colour);
    virtual ~Piece();
    wxBitmap *GetImage();
    PieceColour GetColour();
    virtual void GetLegalMoves(const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]) = 0;

protected:
    void InitializeImage(const wxString &darkImage, const wxString &lightImage);
    wxBitmap *m_image;
    PieceColour m_colour;
    bool IsInBoard(const Point &targetPosition);
    bool IsEnemy(const Piece *currentPiece, const Piece *targetPiece);
    bool IsEmpty(const Piece *targetPiece);
    void SetValidMove(const Point &targetPosition, bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]);
    virtual void CheckAndSetMove(int xChange, int yChange, const Point &currentPosition, Piece *chessBoard[BOARD_SIZE][BOARD_SIZE], bool validMovesMatrix[BOARD_SIZE][BOARD_SIZE]) = 0;
    void SetImage(wxBitmap *image);

private:
};

#endif