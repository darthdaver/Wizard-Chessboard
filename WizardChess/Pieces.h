/*
 * Header file for the classes that implement the corresponding pieces.
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

#ifndef PIECES_H
#define PIECES_H

#include "Piece.h"

class Bishop: public Piece {
    public:
        /**
         * Define the constructor of the class
         *
         * - Return : a not initialized instance of the class
         */
        Bishop();

        /**
         * Define the constructor of the class
         *
         * - Parameters :
         *      - initialPosition : a string that represents the initial coordinates
         *                          of the piece to be instanciated
         *
         * - Return : an initialized instance of the class
         */
        Bishop(const char * initialPosition);

        /**
         * Implement the virtual function with the scope to show a string representation
         * of the object
         *
         * - Return : a string representation of the object
         */
        void toString();
};


class King: public Piece {
    public:
        /**
         * Define the constructor of the class
         *
         * - Return : a not initialized instance of the class
         */
        King();

        /**
         * Define the constructor of the class
         *
         * - Parameters :
         *      - initialPosition : a string that represents the initial coordinates
         *                          of the piece to be instanciated
         *
         * - Return : an initialized instance of the class
         */
        King(const char * initialPosition);

        /**
         * Implement the virtual function with the scope to show a string representation
         * of the object
         *
         * - Returns : a string representation of the object
         */
        void toString();
};


class Knight: public Piece {
    public:
      /**
       * Define the constructor of the class
       *
       * - Return : a not initialized instance of the class
       */
       Knight();

      /**
       * Define the default constructor of the class
       *
       * - Parameters :
       *      - initialPosition : a string that represents the initial coordinates
       *                          of the piece to be instanciated
       *
       * - Return : an initialized instance of the class
       */
      Knight(const char * initialPosition);

      /**
       * Implement the virtual function with the scope to show a string representation
       * of the object
       *
       * - Return : a string representation of the object
       */
      void toString();
};


class Queen: public Piece {
  public:
      /**
       * Define the constructor of the class
       *
       * - Return : a not initialized instance of the class
       */
       Queen();

      /**
       * Define the default constructor of the class
       *
       * - Parameters :
       *      - initialPosition : a string that represents the initial coordinates
       *                          of the piece to be instanciated
       *
       * - Return : an initialized instance of the class
       */
      Queen(const char * initialPosition);

      /**
       * Implement the virtual function with the scope to show a string representation
       * of the object
       *
       * - Return : a string representation of the object
       */
      void toString();
};

class Pawn: public Piece {
    public:
        /**
         * Define the constructor of the class
         *
         * - Return : a not initialized instance of the class
         */
         Pawn();

        /**
         * Define the default constructor of the class
         *
         * - Parameters :
         *      - initialPosition : a string that represents the initial coordinates
         *                          of the piece to be instanciated
         *
         * - Return : an initialized instance of the class
         */
        Pawn(const char * initialPosition);

        /**
         * Getter for promotion variable
         *
         * - Return : keep track if a pawn has been promoted to another type of pawn.
         *            N.B.: "PEDINA" means the pawn has not been promoted yet.
         *            While, for example, "QUEEN" means the corresponding pawn has
         *            been promoted to a queen piece)
         */
        char * getPromotion();

        /**
         * Getter for firstMove variable
         *
         * - Return : a bool value representing if the pawn has just been moved
         *            or not. The scope is relative to a possible en passant
         */
        bool getFirstMove();

        /**
         * Setter for pawnPromotion variable
         *
         * - Parameters :
         *      - newType : string that represents the new type of the piece
         */
        void setPromotion(const char * newType);

        /**
         * Setter for pawnFirstMove variable
         *
         */
        void setFirstMove();

        /**
         * Implement the virtual function with the scope to show a string representation
         * of the object
         *
         * - Return : a string representation of the object
         */
        void toString();

    protected:
        /**
         * Piece variables
         *
         * pawnPromotion : keep track if a pawn has been promoted to another type of pawn.
         *                 Any cell contain the actual state of the corresponding pawn (
         *                 "PEDINA" means the pawn has not been promoted yet. While,
         *                 for example, "QUEEN" means the corresponding pawn has
         *                 been promoted to a queen piece)
         * pawnFirstMove : keep track if a pawn has just been moved or not (the scope
         *                 of this variable is referred to the possibility to
         *                 perform an en passant or a first "two-cells" motion)
         */
        char pawnPromotion[8];
        bool pawnFirstMove;
};


class Rook: public Piece {
    public:
        /**
         * Define the constructor of the class
         *
         * - Return : a not initialized instance of the class
         */
         Rook();

        /**
         * Define the default constructor of the class
         *
         * - Parameters :
         *      - initialPosition : a string that represents the initial coordinates
         *                          of the piece to be instanciated
         *
         * - Return : an initialized instance of the class
         */
        Rook(const char * initialPosition);

        /**
         * Implement the virtual function with the scope to show a string representation
         * of the object
         *
         * - Return : a string representation of the object
         */
        void toString();
};

#endif