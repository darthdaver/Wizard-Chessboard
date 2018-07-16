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
         *      - initialBusy  : a boolean representing if the cell is empty or busy
         *      - initialColor : a char representing the color of the piece (if the cell is busy)
         *                       N.B. : 'B' stands for BLACK, 'W' stands for WHITE, 'E' stands for EMPTY
         * 
         * - Return : an initialized instance of the class
         */
        Cell(bool initialBusy, char initialColor);

        /**
         * Getter for busy variable
         *
         * - Return : the busy of the piece in the chessboard
         */
        bool getBusy();

        /**
         * Getter for alive variable
         *
         * - Return : a char representing the color of the piece (if the cell is busy)
         *            N.B. : 'B' stands for BLACK, 'W' stands for WHITE, 'E' stands for EMPTY
         * 
         */
        char getColor();

        /**
         * Setter for busy variable
         * 
         */
        void setBusy();

        /**
         * Getter for alive variable
         *
         * - Parameters : 
         *      - newColor : a char representing the color of the piece (if the cell is busy)
         *                   N.B. : 'B' stands for BLACK, 'W' stands for WHITE, 'E' stands for EMPTY
         * 
         */
        void setColor(char newColor);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         * 
         */
        virtual void toString();

    protected:
        /**
         * Piece variables
         *
         * - Parameters :
         *      -busy : string that represents the coordinates of the busy
         *              of the piece
         */
        bool busy;
        char color;
};

#endif