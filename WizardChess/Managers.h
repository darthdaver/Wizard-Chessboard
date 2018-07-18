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
         * - Return : an initialized instance of the class
         */
        BishopsManager();

        /**
         * Implement the virtual function with the scope to find the candidate
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the bishop on which the move could be performed.
         *            N.B.: The function return NULL if:
         *              - more than 1 candidate has been found so there is ambiguity on the command expressed
         *                by the player (it is required to specify which of the two bishops the player want to move)
         *              - there is not a candidate.
         */
        char * checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination);

        /**
         * Find the bishop to be remove and set it as dead
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - destination : the coordinates of the cell in where there is the bishop to be removed
         */
        void findAndRemove(bool turn, const char * destination);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString();

    private:
        /**
         * Implement the virtual function with the scope to check if the destination path is
         * free and the move can potentially be performed for the piece
         *
         * - Parameters :
         *      - cbState : indicates the position of all the pieces on the chessboard
         *      - vDiff   : indicates how many vertical steps there are from source to destination of a move
         *      - hDiff   : indicates how many horizontal steps there are from source to destination of a move
         *      - row     : indicates the destination row in the cbState matrix
         *      - col     : indicates the destination col in the cbState matrix
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col);

        /* Set the new position of the unique candidate
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : the coordinates of the old position
         *      - destination : the coordinates of the new position
         */
        void setNewPosition(bool turn, const char * from, const char * destination);

        /**
         * Private variables
         *
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
          * - Return : an initialized instance of the class
          */
        KingsManager();

        /**
         * Implement the virtual function with the scope to find the candidates
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the king on which the move could be performed.
         *            N.B.: The function return NULL if the king cannot be moved to the destination required
         */
        char * checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination);

        /**
         * Find the king to be remove and set it as dead
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - destination : the coordinates of the cell in where there is the king to be removed
         */
        void findAndRemove(bool turn, const char * destination);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString();

    private:
        /**
         * Implement the virtual function with the scope to check if the destination path is
         * free and the move can potentially be performed for the piece
         *
         * - Parameters :
         *      - cbState : indicates the position of all the pieces on the chessboard
         *      - vDiff   : indicates how many vertical steps there are from source to destination of a move
         *      - hDiff   : indicates how many horizontal steps there are from source to destination of a move
         *      - row     : indicates the destination row in the cbState matrix
         *      - col     : indicates the destination col in the cbState matrix
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col);

        /* Set the new position of the unique candidate
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : the coordinates of the old position
         *      - destination : the coordinates of the new position
         */
        void setNewPosition(bool turn, const char * from, const char * destination);

        /**
         * Private variables
         *
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
         * - Return : an initialized instance of the class
         */
        KnightsManager();

        /**
         * Implement the virtual function with the scope to find the candidate
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the knight on which the move could be performed.
         *            N.B.: The function return NULL if:
         *              - more than 1 candidate has been found so there is ambiguity on the command expressed
         *                by the player (it is required to specify which of the two knight the player want to move)
         *              - there is not a candidate.
         */
        char * checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination);

        /**
         * Find the knight to be remove and set it as dead
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - destination : the coordinates of the cell in where there is the knight to be removed
         */
        void findAndRemove(bool turn, const char * destination);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString();

    private:
        /**
         * Implement the virtual function with the scope to check if the destination path is
         * free and the move can potentially be performed for the piece
         *
         * - Parameters :
         *      - cbState : indicates the position of all the pieces on the chessboard
         *      - vDiff   : indicates how many vertical steps there are from source to destination of a move
         *      - hDiff   : indicates how many horizontal steps there are from source to destination of a move
         *      - row     : indicates the destination row in the cbState matrix
         *      - col     : indicates the destination col in the cbState matrix
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col);

        /* Set the new position of the unique candidate
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : the coordinates of the old position
         *      - destination : the coordinates of the new position
         */
        void setNewPosition(bool turn, const char * from, const char * destination);

        /**
         * Private variables
         *
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
         * - Return : an initialized instance of the class
         */
        QueensManager();

        /**
         * Implement the virtual function with the scope to find the candidates
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the queen on which the move could be performed.
         *            N.B.: The function return NULL if the queen cannot be moved to the destination required
         */
        char * checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination);

        /**
         * Find the queen to be remove and set it as dead
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - destination : the coordinates of the cell in where there is the queen to be removed
         */
        void findAndRemove(bool turn, const char * destination);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString();

   private:
        /**
         * Implement the virtual function with the scope to check if the destination path is
         * free and the move can potentially be performed for the piece
         *
         * - Parameters :
         *      - cbState : indicates the position of all the pieces on the chessboard
         *      - vDiff   : indicates how many vertical steps there are from source to destination of a move
         *      - hDiff   : indicates how many horizontal steps there are from source to destination of a move
         *      - row     : indicates the destination row in the cbState matrix
         *      - col     : indicates the destination col in the cbState matrix
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col);

        /* Set the new position of the unique candidate
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : the coordinates of the old position
         *      - destination : the coordinates of the new position
         */
        void setNewPosition(bool turn, const char * from, const char * destination);

        /**
         * Private variables
         *
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
         * - Return : an initialized instance of the class
         */
        PawnsManager();

        /**
         * Implement the virtual function with the scope to find the candidate
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the pawn on which the move could be performed.
         *            N.B.: The function return NULL if:
         *              - more than 1 candidate has been found so there is ambiguity on the command expressed
         *                by the player (it is required to specify which of the candidate pawns the player want to move)
         *              - there is not candidate.
         */
        char * checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination);

        /**
         * Implement the virtual function with the scope to find the promoted candidates
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - promotype   : indicates the promotion type of the pawn
         *      - from        : indicates the source cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the promoted pawn on which the move could be performed.
         *            N.B.: The function return NULL if:
         *              - more than 1 candidate has been found so there is ambiguity on the command expressed
         *                by the player (it is required to specify which of the candidate pawns the player want to move)
         *              - there is not candidate.

         *            N.B.: The function, differently from the checkCandidates function, verifies only if exists a promoted
         *                  pawn of type equal to the specified promoType parameter and if the from parameter is ≠ NULL
         *                  the function check if in that position really exists that type of mromoted pawn.
         *                  The other checks (path is correct and free, etc.) will be performed by the maneger of the
         *                  promoType (the class PawnManager has not control on other type of pieces different from Pawn).
         */
        char * checkPromotedCandidates(Cell * cbState[][8], bool turn, const char * promoType, const char * from);

        /**
         * Find the pawn to be remove and set it as dead
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - destination : the coordinates of the cell in where there is the pawn to be removed
         */
        void findAndRemove(bool turn, const char * destination);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString();

    private:
        /**
         * Implement the virtual function with the scope to check if the destination path is
         * free and the move can potentially be performed for the piece
         *
         * - Parameters :
         *      - cbState : indicates the position of all the pieces on the chessboard
         *      - vDiff   : indicates how many vertical steps there are from source to destination of a move
         *      - hDiff   : indicates how many horizontal steps there are from source to destination of a move
         *      - row     : indicates the destination row in the cbState matrix
         *      - col     : indicates the destination col in the cbState matrix
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col);

        /**
         * Verify that a pawn move always forward
         *
         * - Parameters :
         *      - turn  : indicates if move the white (false) or the black (true)
         *      - vDiff : indicates how many vertical steps there are from source to destination of a move
         *
         * - Return : a bool indicating if (or not) the pawn move forward
         */
        bool checkDirection(bool turn, int vDiff);

        /* Set the new position of the unique candidate
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : the coordinates of the old position
         *      - destination : the coordinates of the new position
         */
        void setNewPosition(bool turn, const char * from, const char * destination);

        /**
         * Private variables
         *
         * pawns          : represents the list of pawns.
         *                  Note: the first row refers to the white pawns, while the second
         *                  row refers to the black ones
         * enPassantWhite : indicates which pawn has eventually execute a 2 steps first move
         *                  at the previous black adversary move.
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
         * - Return : an initialized instance of the class
         */
        RooksManager();

        /**
         * Implement the virtual function with the scope to find the candidate
         * for which the move can be performed
         *
         * - Parameters :
         *      - cbState     : indicates the position of all the pieces on the chessboard
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Return : a char pointer pointing to the coordinates of the rook on which the move could be performed.
         *            N.B.: The function return NULL if:
         *              - more than 1 candidate has been found so there is ambiguity on the command expressed
         *                by the player (it is required to specify which of the two rook the player want to move)
         *              - there is not a candidate.
         */
        char * checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination);

        /**
         * Find the rook to be remove and set it as dead
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - destination : the coordinates of the cell in where there is the rook to be removed
         */
        void findAndRemove(bool turn, const char * destination);

        /**
         * Show a string representation of the object
         *
         * - Return : a string representation of the object
         */
        virtual void toString();

    private:
        /**
         * Implement the virtual function with the scope to check if the destination path is
         * free and the move can potentially be performed for the piece
         *
         * - Parameters :
         *      - cbState : indicates the position of all the pieces on the chessboard
         *      - vDiff   : indicates how many vertical steps there are from source to destination of a move
         *      - hDiff   : indicates how many horizontal steps there are from source to destination of a move
         *      - row     : indicates the destination row in the cbState matrix
         *      - col     : indicates the destination col in the cbState matrix
         *
         * - Return : a bool value indicating if the path is feasible (true)
         *            for the piece or not (false)
         */
        virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col);

        /* Set the new position of the unique candidate
         *
         * - Parameters :
         *      - turn        : indicates if move the white (false) or the black (true)
         *      - from        : the coordinates of the old position
         *      - destination : the coordinates of the new position
         */
        void setNewPosition(bool turn, const char * from, const char * destination);

        /**
         * Private variables
         *
         * rooks : represents the list of rooks.
         *         Note: the first row refers to the white rooks, while the second
         *         row refers to the black ones
         */
        Rook rooks [2][2];
};

#endif
