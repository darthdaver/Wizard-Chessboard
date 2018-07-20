/*
 * Header file for the PieceInterface abstract class.
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

#ifndef PIECE_H
#define PIECE_H

#include <Arduino.h>

class Piece {
  public:
        /**
         * Define the constructor of the class
         *
         * - Return : a not initialized instance of the class
         */
        Piece();

        /**
         * Define the constructor of the class
         * - Parameters :
         *      - initialPosition : represents the initial position of the piece on the chessboard
         * 
         * - Return : an initialized instance of the class
         */
        Piece(const char * initialPosition);

        /**
         * Getter for position variable
         *
         * - Return : the position of the piece in the chessboard
         */
        char * getPosition();

        /**
         * Getter for alive variable
         *
         * - Return : the boolean state of the piece (true -> alive , false -> dead)
         */
        bool getAlive();

        /**
         * Setter for position variable
         *
         * - Parameters :
         *      - newCoordinates : string that represents the new newCoordinates
         *                         of the piece
         */
        void setPosition(const char * newCoordinates);

        /**
         * Setter for alive variable
         *
         */
        void setAlive();

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString() = 0;

    protected:
        /**
         * Piece variables
         *  
         * - Parameters :
         *      - position : string that represents the coordinates of the position
         *                   of the piece
         */
        char * position;
        bool alive;
};

#endif
