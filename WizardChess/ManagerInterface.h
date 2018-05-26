/*
 * Header file for the ChessBoard class.
 *
 * Copyright (c) 2018 Davide Molinelli.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MANAGERINTERFACE_H
#define MANAGERINTERFACE_H

class ManagerInterface {

public:

    /**
     * Check if the destination path is free and the move can potentially be performed
     *
     * - Parameters:
     *      - source      : indicates the source cell of the piece that the player wants to move
     *      - destination : indicates the destination cell of the piece that the player wants to move
     * - Returns: a boolean value indicating if the path is feasible (true) or not (false).
     */
    virtual boolean checkIsFree(String source, String destination);

    /**
     * 
     */
    
    
public:
    /** 
     * Chessboard variables
     * 
     * chessBoard    : keep track of the state of the chessboard (any cell of the array contains 
     *                 the coordinates of the position of the corresponding pawn).
     * cemetery      : keep track of the state of the white and black cemeteries where the eliminated
     *                 pawns are positioned.
     * pawnFirstMove : keep track if a pawn has been just moved or not (the scope of this variable is
     *                 referred to the possibility to perform an en passant or a first "two-cells" motion)
     * pawnPromotion : keep track if a pawn has been promoted to another type of pawn.
     * turn          : keep track if moves the white (true) or the black (false)
     * solenoid      : keep track the position of the solenoid.
     */
    String chessBoard[6][32];
    boolean cemetery[32];
    boolean pawnFirstMove[16];
    String pawnPromotion[2][8];
    boolean turn;
    String solenoid;
};

#endif
