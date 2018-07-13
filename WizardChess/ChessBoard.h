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
#include "Managers.h"

class ChessBoard {
    public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      ChessBoard();

      /**
       * Identify the element on which the player move must be performed
       *
       * - Parameters:
       *      - command : the char * obtained from the speech to text conversion, that represents the command expressed by a player
       *
       * - Return: a pointer to a char * of characters that represents the type of the pawn to move
       *      - PEDINA (PAWN)
       *      - TORRE (ROOK)
       *      - CAVALLO (KNIGHT)
       *      - ALFIERE (BISHOP)
       *      - REGINA (QUEEN)
       *      - RE (KING)
       */
      float identifyElement(char * command); //?????????????????????

      /**
       * Generate the stepper motor movement in order to transport the piece from the source cell to the destination cell,
       * performing a player move. The function move the solenoid (that catches the piece) along a single axis (X or Y) so to
       * perform a movement from (xa,ya) to (xb,yb) the function must be called twice:
       * 1. (xa,ya) --> (xb,ya)
       * 2. (xb,ya) --> (xb,yb))
       *
       * - Parameters:
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
       * - Parameters:
       *      - condition : if true activate the cathing, if false release the catching
       */
      void electromagnet(bool condition);

      /**
       * Getter of the turn variable
       *
       * - Return: a bool representing the player who has the right to move
       *      - true  : move the black
       *      - false : move the white
       *
       */
      bool getTurnPlayer();

    public:
      /**
       * Chessboard variables
       *
       * chessBoard    : keep track of the state of the chessboard (any cell of the array contains
       *                 the coordinates of the position of the corresponding pawn).
       *                 Note: the first 16 elements refer to the white pawns, while the second eight
       *                 refer to the black pawns (the elements are ordered in the array as reported in the
       *                 Config.h file)
       * cemetery      : keep track of the state of the white and black cemetery spaces where the eliminated
       *                 pawns are positioned (true = free space, false = busy space)
       * pawnFirstMove : keep track if a pawn has been just moved or not (the scope of this variable is
       *                 referred to the possibility to perform an en passant or a first "two-cells" motion).
       *                 Note: the first eight elements refer to the white pawns, while the second eight
       *                 refer to the black pawns
       * pawnPromotion : keep track if a pawn has been promoted to another type of pawn
       *                 Note: the first eight elements refer to the white pawns, while the second eight
       *                 refer to the black pawns
       * turn          : keep track if moves the white (false) or the black (true)
       * solenoid      : keep track the position of the solenoid
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
