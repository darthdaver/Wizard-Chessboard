/*
 * Header file for the Manager classes.
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

#ifndef MANAGERS_H
#define MANAGERS_H

#include "Manager.h"
#include "Pieces.h"

class BishopsManager: public Manager{
  public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      BishopsManager();

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
       */
      StackList <int> checkCandidates(const char * from, const char * destination);

  public:
      /*
       * bishops : represents the list of pawns.
       *           Note: the first row refers to the white pawns, while the second
       *           row refers to the black ones
       */
      Bishop bishops [2][2];
};

class KingsManager: public Manager{
  public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      KingsManager();

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
       */
      StackList <int> checkCandidates(const char * from, const char * destination);

   public:
     /*
      * kings : represents the list of pawns.
      *         Note: the first row refers to the white pawns, while the second
      *         row refers to the black ones
      */
     King kings [2][1];
};

class KnightsManager: public Manager{
  public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      KnightsManager();

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
       */
      StackList <int> checkCandidates(const char * from, const char * destination);

  public:
    /*
     * knights : represents the list of pawns.
     *           Note: the first row refers to the white pawns, while the second
     *           row refers to the black ones
     */
    Knight knights [2][2];
};

class QueensManager: public Manager{
  public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      QueensManager();

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
       */
      StackList <int> checkCandidates(const char * from, const char * destination);

   public:
      /*
       * queens : represents the list of pawns.
       *          Note: the first row refers to the white pawns, while the second
       *          row refers to the black ones
       */
      Queen queens [2][1];
};

class PawnsManager: public Manager{
  public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      PawnsManager();

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
       */
      StackList <int> checkCandidates(const char * from, const char * destination);

  public:
      /*
       * pawns : represents the list of pawns.
       *         Note: the first row refers to the white pawns, while the second
       *         row refers to the black ones
       */
      Pawn pawns [2][8];
};

class RooksManager: public Manager{
  public:
      /**
       * Define the default constructor of the class
       *
       * - Return: an initialized instance of the class
       */
      RooksManager();

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
       */
      StackList <int> checkCandidates(const char * from, const char * destination);

  public:
     /*
      * rooks : represents the list of rooks.
      *         Note: the first row refers to the white rooks, while the second
      *         row refers to the black ones
      */
     Rook rooks [2][2];
};

#endif
