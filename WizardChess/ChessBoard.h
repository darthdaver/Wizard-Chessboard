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
       * Identify the element on which the player move must be performed
       *
       * - Parameters :
       *      - command : the char * obtained from the speech to text conversion, that represents the command expressed by a player
       *
       * - Return : a pointer to a char * of characters that represents the type of the pawn to move
       *      - PEDINA (PAWN)
       *      - TORRE (ROOK)
       *      - CAVALLO (KNIGHT)
       *      - ALFIERE (BISHOP)
       *      - REGINA (QUEEN)
       *      - RE (KING)
       */
      float identifyElement(char * command); //?????????????????????

      /**
       * Getter of the turn variable
       *
       * - Return : a bool representing the player who has the right to move
       *      - true  : move the black
       *      - false : move the white
       *
       */
      bool getTurnPlayer();

      /**
       * Verifies if it is possible to make the move expressed by the player and, in that case, executes it
       * 
       * - Parameters :
       *      - wordsQueue : a queue containing the words relative to the move that the player want to perform
       */
      void move(QueueArray <char *> wordsQueue);

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
       * Activate (deactivate) the electromagnet in order to attract (release) the pawn.
       * The action is performed giving/removing voltage to the relay connected to the solenoid
       *
       * - Parameters :
       *      - condition : if true activate the cathing, if false release the catching
       */
      void electromagnet(bool condition);

      /**
       * Change the player turn
       * 
       */
      void setTurnPlayer();

      /**
       * Public Chessboard variables
       * 
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
      bool cemetery[2][16]={{true,true,true,true,true,true,true,true,
                   true,true,true,true,true,true,true,true},
                  {true,true,true,true,true,true,true,true,
                   true,true,true,true,true,true,true,true}};
      bool turn;
      char * solenoid = "A1";
      BishopsManager bishopsManager;
      KingsManager kingsManager;
      KnightsManager knightsManager;
      QueensManager queensManager;
      RooksManager rooksManager;
      PawnsManager pawnsManager;
};

#endif
