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
         * Setter for position variable
         *
         * - Parameters :
         *      - newCoordinates : string that represents the new newCoordinates
         *                         of the piece
         */
        void setPosition(const char * newCoordinates);

        /**
         * Check if the destination path is free and the move can potentially be performed for the piece
         *
         * - Parameters:
         *      - destination : indicates the destination cell of the piece that
         *                      the player wants to move
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(const char * destination) = 0;

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
         * position : string that represents the coordinates of the position
         *            of the piece
         */
        char position[3];
};

#endif
