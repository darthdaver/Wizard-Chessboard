/**
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

#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <Arduino.h>
#include <QueueArray.h>
#include "Cell.h"
#include "Managers.h"

class ChessBoard {
    public:
      /**
       * Define the default constructor of the class
       *
       * - Return : an initialized instance of the class
       */
      ChessBoard();

      /**
       * Verifies if it is possible to make the move expressed by the player and, in that case, executes it
       *
       * - Parameters :
       *      - wordsQueue : a queue containing the words relative to the move that the player want to perform
       */
      void move(QueueArray <char *> wordsQueue);

      /**
       * Show a string representation of the object
       *
       * - Return : a string representation of the object
       */
      void toString();

      /**
       * Public Chessboard variables
       *
       * cbState    : keep track of the state of the white and black pieces in the chessboard cells
       *              Matrix:
       *                                  1  2  3  4  5  6  7  8
       *                               A                          A
       *                               B                          B
       *                               C                          C
       *                               D                          D
       *                               E                          E
       *                               F                          F
       *                               G                          G
       *                               H                          H
       *                                  1  2  3  4  5  6  7  8
       *
       *                                    white ------->
       *                                        <------- black
       *
       * cemetery : keep track of the state of the white and black cemetery spaces where the eliminated
       *            pawns are positioned (true = free space, false = busy space)
       * turn     : keep track if moves the white (false) or the black (true)
       */
      Cell * cbState[8][8];
      bool cemetery[2][16]    = {{true,true,true,true,true,true,true,true,
                                  true,true,true,true,true,true,true,true},
                                 {true,true,true,true,true,true,true,true,
                                  true,true,true,true,true,true,true,true}};
      bool turn;

    private:
      /**
       * Generate the stepper motor movement in order to transport the piece from the source cell to the destination cell,
       * performing a player move. The function move the solenoid (that catches the piece) along a single axis (X or Y) so to
       * perform a movement from (xa,ya) to (xb,yb) the function must be called twice:
       * 1. (xa,ya) --> (xb,ya)
       * 2. (xb,ya) --> (xb,yb))
       *
       * - Parameters :
       *      - dir        : defines the direction of rotation of the stepper motor (true = counterclockwise, false = clockwise)
       *      - dirPin     : define the stepper motor on which to act (X_DIR act on the stepper motor predisposed to move
       *                     the solenoid on the X axis while Y_DIR act on the stepper motor predisposed to move the solenoid
       *                     on the Y axis)
       *      - stepperPin : define the stepper pin of the stepper motor on which perform the step movements (X_STP indicates
       *                     the stepper pin of the stepper motor predisposed to move the solenoid on the X axis, while Y_STP
       *                     indicates the stepper pin of the stepper motor predisposed to move the solenoid on the Y axis)
       *      -steps       : define the number of the steps necessary to move from xa --> xb (if the movement is performed along
       *                     the X axis) or from ya --> yb (if the movement is performed along the Y axis)
       */
      void stepperMovement (bool dir, byte dirPin, byte stepperPin, int steps);

      /**
       * Transport a piece from a source cell to a destination cell with the electromagnet switched on
       *
       * - Parameters :
       *      - from : represents the coordinates of the source cell
       *      - to   : represents the coordinates of the destination cell
       *
       * - Return : a boolean value indicating if the move has been succesfully performed
       */
      bool navigate(const char * from, const char * to);

      /**
       * Transport the electromagnet switched off from a source cell to a destination cell
       *
       * - Parameters :
       *      - from : represents the coordinates of the source cell
       *      - to   : represents the coordinates of the destination cell
       */
      void direct(const char * from, const char * to);

      /**
       * Execute the move in three phases :
       *  1. Transport the electromagnet switched off from A1 (default position of the magnet) to the cell
       *     in which is positioned the pieced that has to be moved
       *  2. Trasport the piece to the destination with the electromagnet switched on
       *  3. Trasport the electromagnet switched off to the default position (A1)
       *
       * Parameters :
       *      - type : represents the type of piece that must be moved
       *      - from : represents the coordinates of the source cell
       *      - to   : represents the coordinates of the destination cell
       */
      void performMove(const char type, const char * from, const char * to);

      /**
       * Execute the process to remove a dead piece
       * 
       * - Parameters :
       *      - destination : the coordiantes of the cell occupied by the piece that has to be removed
       *      - row         : the row index indicating the position in the cbState of the piece that 
       *                      must be removed
       *      - col         : the column index indicating the position in the cbStateof the piece that
       *                      must be removed
       * 
       */
      void removeDead(const char * destination, int row, int col);

      /**
       * Update the state of the ChessBoard after a move has been performed
       * 
       * - Parameters :
       *      - oldPosition : represents the old position of the moved piece
       *      - newPosition : represents the new position of the moved piece
       */
      void updateState(const char * oldPosition, const char * newPosition);

      /**
       * Change the player turn
       *
       */
      void setTurnPlayer();

      /**
       * Private Chessboard variables
       *
       * cellsOccupied  : keep track of the state of the white and black pieces in the chessboard cells
       * cemetery       : keep track of the state of the white and black cemetery spaces where the eliminated
       *                  pawns are positioned (true = free space, false = busy space)
       * solenoid       : keep track the position of the solenoid
       * turn           : keep track if moves the white (false) or the black (true)
       * bishopsManager : keep track the position of any bishop in the chessboard and manage any phase of a move
       *                  which involve a bishop
       * kingsManager   : keep track the position of any king in the chessboard and manage any phase of a move
       *                  which involve a king
       * knightsManager : keep track the position of any knight in the chessboard and manage any phase of a move
       *                  which involve a knight
       * queensManager  : keep track the position of any queen in the chessboard and manage any phase of a move
       *                  which involve a queen
       * rooksManager   : keep track the position of any rook in the chessboard and manage any phase of a move
       *                  which involve a rook
       * pawnsManager   : keep track the position of any pawn in the chessboard and manage any phase of a move
       *                  which involve a pawn
       */
      char * solenoid;
      BishopsManager bishopsManager;
      KingsManager kingsManager;
      KnightsManager knightsManager;
      QueensManager queensManager;
      RooksManager rooksManager;
      PawnsManager pawnsManager;
};

#endif
