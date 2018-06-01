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
       * Implement the virtual function with the scope to found the candidate
       * for which the move can be performed
       *
       * - Parameters:
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the bishop on which the move could be performed.
       *            N.B.: The function return NULL if:
       *              - more than 1 candidate has been found so there is ambiguity on the command expressed
       *                by the player (it is required to specify which of the two bishops the player want to move)
       *              - there is not a candidate.
       */
      char * checkCandidates(boolean turn, const char * from, const char * destination);

  private:
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
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the king on which the move could be performed.
       *            N.B.: The function return NULL if the king cannot be moved to the destination required
       */
      char * checkCandidates(boolean turn, const char * from, const char * destination);

   private:
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
       * Implement the virtual function with the scope to found the candidate
       * for which the move can be performed
       *
       * - Parameters:
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the knight on which the move could be performed.
       *            N.B.: The function return NULL if:
       *              - more than 1 candidate has been found so there is ambiguity on the command expressed
       *                by the player (it is required to specify which of the two knight the player want to move)
       *              - there is not a candidate.
       */
      char * checkCandidates(boolean turn, const char * from, const char * destination);

  private:
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
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the queen on which the move could be performed.
       *            N.B.: The function return NULL if the queen cannot be moved to the destination required
       */
      char * checkCandidates(boolean turn, const char * from, const char * destination);

   private:
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
       * Implement the virtual function with the scope to found the candidate
       * for which the move can be performed
       *
       * - Parameters:
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the pawn on which the move could be performed.
       *            N.B.: The function return NULL if:
       *              - more than 1 candidate has been found so there is ambiguity on the command expressed
       *                by the player (it is required to specify which of the candidate pawns the player want to move)
       *              - there is not candidate.
       */
      char * checkCandidates(boolean turn, const char * from, const char * destination);

      /**
       * Implement the virtual function with the scope to found the candidates
       * for which the move can be performed
       *
       * - Parameters:
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the pawn on which the move could be performed.
       *            N.B.: The function return NULL if:
       *              - more than 1 candidate has been found so there is ambiguity on the command expressed
       *                by the player (it is required to specify which of the candidate pawns the player want to move)
       *              - there is not candidate.
       */
      char * checkPromotedCandidates(boolean turn, const char * promoType, const char * from, const char * destination);

  private:
      /*
       * pawns          : represents the list of pawns.
       *                  Note: the first row refers to the white pawns, while the second
       *                  row refers to the black ones
       * enPassantWhite : indicates which pawn has eventually execute a 2 steps first move
       *                  at the previous white adversary move.
       *                  N.B.: it contains the position of the pawn and it is set to NULL
       *                  if in the previous move the adversary did not perform a 2 steps
       *                  first move
       * enPassantBlack : indicates which pawn has eventually execute a 2 steps first move
       *                  at the previous white adversary move.
       *                  N.B.: it contains the position of the pawn and it is set to NULL
       *                  if in the previous move the adversary did not perform a 2 steps
       *                  first move
       */
      Pawn pawns [2][8];
      char enPassantWhite[3];
      char enPassantBlack[3];
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
       * Implement the virtual function with the scope to found the candidate
       * for which the move can be performed
       *
       * - Parameters:
       *      - turn        : indicates if move the white (true) or the black (false)
       *      - source      : indicates the source cell of the piece that the player wants to move
       *      - destination : indicates the destination cell of the piece that the player wants to move
       *
       * - Returns: a char pointer pointing to the coordinates of the rook on which the move could be performed.
       *            N.B.: The function return NULL if:
       *              - more than 1 candidate has been found so there is ambiguity on the command expressed
       *                by the player (it is required to specify which of the two rook the player want to move)
       *              - there is not a candidate.
       */
      char * checkCandidates(boolean turn, const char * from, const char * destination);

  private:
     /*
      * rooks : represents the list of rooks.
      *         Note: the first row refers to the white rooks, while the second
      *         row refers to the black ones
      */
     Rook rooks [2][2];
};

#endif
