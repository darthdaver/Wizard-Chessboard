/*
 * Header file for the Cell class.
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

#ifndef CELL_H
#define CELL_H

#include <Arduino.h>

class Cell {
  public:
        /**
         * Define the constructor of the class
         *
         * - Return : a not initialized instance of the class
         */
        Cell();

        /**
         * Define the constructor of the class
         *
         * - Parameters :
         *      - initialBusy  : a boolean representing if the cell is empty or busy at the start of the game
         *      - initialColor : a char representing the color of the piece (if the cell is busy) at the start 
         *                       of the game
         *      - initialType  : a char representing the type of the piece (if the cell is busy) at the start
         *                       of the game
         * 
         * - Return : an initialized instance of the class
         */
        Cell(bool initialBusy, char initialColor, char initialType);

        /**
         * Getter for busy variable
         *
         * - Return : the busy of the piece in the chessboard
         */
        bool getBusy();

        /**
         * Getter for color variable
         *
         * - Return : a char representing the color of the piece (if the cell is busy)
         *            N.B. : 'B' stands for BLACK, 'W' stands for WHITE, 'E' stands for EMPTY
         * 
         */
        char getColor();

        /**
         * Getter for piece variable
         *
         * - Return : a char representing the type of the piece (if the cell is busy)
         * 
         */
        char getPiece();

        /**
         * Setter for busy variable
         * 
         */
        void setBusy();

        /**
         * Setter for color variable
         *
         * - Parameters : 
         *      - newColor : a char representing the color of the piece (if the cell is busy)
         *                   N.B. : 'B' stands for BLACK, 'W' stands for WHITE, 'E' stands for EMPTY
         * 
         */
        void setColor(char newColor);

        /**
         * Setter for piece variable
         *
         * - Parameters : 
         *      - newPiece : a char representing the type of the piece (if the cell is busy)
         */
        void setPiece(char newType);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         * 
         */
        void toString();

    protected:
        /**
         * Piece variables
         *
         * - Parameters :
         *      - busy  : a string representing the coordinates of the busy
         *                of the piece
         *      - color : a char representing the color of the piece (if the cell is busy)
         *                N.B. : 'B' stands for BLACK, 'W' stands for WHITE, 'E' stands for EMPTY
         *                       'D' stands dor DEAD (transition phase before to remove a dead piece)
         *      - piece : a char representing the type of piece in the cell
         *                  - 'P' ---> PAWN
         *                  - 'R' ---> ROOK
         *                  - 'B' ---> BISHOP
         *                  - 'H' ---> KNIGHT (HORSE)
         *                  - 'K' ---> KING
         *                  - 'Q' ---> QUEEN
         *                  - 'E' ---> EMPTY
         */
        bool busy;
        char color;
        char piece;
};

#endif