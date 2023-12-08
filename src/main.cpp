#include <wx/wx.h>
#include "Chess.h"
#include "Board.h"
#include "Globals.h"

class MyApp : public wxApp
{
public:
    virtual bool OnInit()
    {
        MyFrame *frame = new MyFrame();
        chessboard = new Board(frame);

        Bishop *w_bishop_0 = new Bishop(2, 7, WHITE, chessboard->square_array[2][7]);
        Bishop *w_bishop_1 = new Bishop(5, 7, WHITE, chessboard->square_array[5][7]);
        Rook *w_rook_0 = new Rook(0, 7, WHITE, chessboard->square_array[0][7]);
        Rook *w_rook_1 = new Rook(7, 7, WHITE, chessboard->square_array[7][7]);
        Knight *w_knight_0 = new Knight(1, 7, WHITE, chessboard->square_array[1][7]);
        Knight *w_knight_1 = new Knight(6, 7, WHITE, chessboard->square_array[6][7]);
        Queen *w_queen_0 = new Queen(3, 7, WHITE, chessboard->square_array[3][7]);
        King *w_king_0 = new King(4, 7, WHITE, chessboard->square_array[4][7]);
        Pawn *w_pawn_arr[8];
        for (int i = 0; i < 8; i++)
        {
            w_pawn_arr[i] = new Pawn(i, 6, WHITE, chessboard->square_array[i][6]);
        }

        Bishop *b_bishop_0 = new Bishop(2, 0, BLACK, chessboard->square_array[2][0]);
        Bishop *b_bishop_1 = new Bishop(5, 0, BLACK, chessboard->square_array[5][0]);
        Rook *b_rook_0 = new Rook(0, 0, BLACK, chessboard->square_array[0][0]);
        Rook *b_rook_1 = new Rook(7, 0, BLACK, chessboard->square_array[7][0]);
        Knight *b_knight_0 = new Knight(1, 0, BLACK, chessboard->square_array[1][0]);
        Knight *b_knight_1 = new Knight(6, 0, BLACK, chessboard->square_array[6][0]);
        Queen *b_queen_0 = new Queen(3, 0, BLACK, chessboard->square_array[3][0]);
        King *b_king_0 = new King(4, 0, BLACK, chessboard->square_array[4][0]);
        Pawn *b_pawn_arr[8];
        for (int i = 0; i < 8; i++)
        {
            w_pawn_arr[i] = new Pawn(i, 6, BLACK, chessboard->square_array[i][1]);
        }

        frame->Show(true);
        return true;
    }
};

wxIMPLEMENT_APP(MyApp);
