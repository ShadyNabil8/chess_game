#ifndef _BOARD_H
#define _BOARD_H
#include <wx/wx.h>
#include "Piece.h"
#include "King.h"
#include "Queen.h"
#include "Bishop.h"
#include "Knight.h"
#include "Rook.h"
#include "Pawn.h"
#include "Point.h"
#include <vector>

#define INITIAL_VECTOR_SIZE 4

class Board : public wxPanel
{
private:
    enum Colour
    {
        DARK = 0,
        LIGHT,
        HIGHLIGHT
    };
    enum Player
    {
        DARK_PLAYER = 0,
        LIGHT_PLAYER,
    };
    int boardSize;
    int squareSize;
    int selectedSquareRow;
    int selectedSquareCol;
    Player player;
    wxColour colours[3];
    std::vector<Point> LegalMovesVector;

    /* I am using this array to check for the existance for certain piece on a certan square*/
    Piece *pieces[8][8];

    /* I am using this array to determine the legal movements that a certain piece on a certain square can move*/
    bool highlight_matrix[8][8];

    /**
     * @brief
     * Used to draw a light, dark and highlighted square
     * @param point The X and Y that the square will be printed.
     * @param color Square color.
     * @param piece Pointer to the piece that will be printed on this square or null in cade of empty square.
     * @return
     */
    void DrawSquare(const Point &point, Colour &color, Piece *piece);

    /**
     * @brief
     * Used to draw chess pieces.
     * @param point The X and Y that the piece will be printed.
     * @param piece Pointer to the piece that will be printed.
     * @param dc The printer.
     * @return
     */
    void DrawPiece(const Point &point, Piece *piece, wxPaintDC &dc);

    /**
     * @brief
     * This is the event handler that is executed whenever a player chose a piece.
     * This handler reprint the board each time a certain piece is pressed.
     */
    void OnPaint(wxPaintEvent &event);

    /**
     * @brief This is the event handler that is executed the mouse is clicked. it causes the board to be reprinted.
     */
    void OnLeftClick(wxMouseEvent &event);

    /**
     * @brief
     * Check if a square has a chess piece or not.
     * @param point The X and Y that defines the square.
     * @return true in case lf empty and false in case of not empty.
     */
    bool IsEmptySquare(const Point &point);

    /**
     * @brief
     * Check for a certain square can be a legel movement for a piece in a square.
     * And then uses the ansqer to highlight a square or not.
     * It uses the hightlight_matrix array for checking.
     * @param point The X and Y that defines the chosen square.
     * @return true in case lf legal move and false in case of illegal.
     */
    bool IsLegalMove(const Point &point);

    /**
     * @brief
     * Delete a piece on a certain square.
     * @param point The X and Y that defines the chosen square.
     * @return
     */
    void CleanSquare(const Point &point);

    /**
     * @brief
     * Move a piece form a square to another.
     * @param oldpoint The X and Y that defines the chosen square(old location).
     * @param newpoint The X and Y that defines the chosen square(new location).
     * @return
     */
    void MovePiece(const Point &oldpoint, const Point &newpoint);

    /**
     * @brief
     * Get a pointer to a piece on a square.
     * @param point The X and Y that defines the chosen square having the piece.
     * @return Pointer to the piece.
     */
    Piece *GetPiece(const Point &point);

    /**
     * @brief
     * Assign a pointer for a piece to the array carring all pieces.
     * @param point The X and Y that defines the location of the piece on the board.
     * @param piece Pointer to the piece.
     * @return
     */
    void SetPiece(const Point &point, Piece *piece);

    /**
     * @brief
     * When a certain piece is chosen, all legal moves are highlighted.
     * This function check if the player choses one of these highlighted squares or not.
     * @param point The X and Y that defines the location chosen square.
     * @param piece Pointer to the piece.
     * @return true in case lf legal move and false in case of illegal.
     */
    bool IsLegalMoveSelected(Point &point);

    bool IsCorrectPlayerTurn(const Point &point);
    void RevertTurns();

public:
    Board();
    Board(wxFrame *parent);
    ~Board();
};

#endif