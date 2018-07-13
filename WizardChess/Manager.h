/*
 * Header file for the Manager abstract class.
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

#ifndef MANAGER_H
#define MANAGER_H

#include <Arduino.h>
#include <QueueArray.h>

class Manager {
    public:
        /**
         * Define the default constructor of the class
         */
         Manager();

        /**
         * Found the candidates for which the move can be performed
         *
         * - Parameters:
         *      - turn        : indicates if move the white (true) or the black (false)
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Returns: an integer representing the index of the piece on which the move could be performed.
         *            N.B.: The function return -1 if:
         *              - more than 1 candidate has been found so there is ambiguity on the command expressed
         *                by the player (it is required to specify which of the candidate piece the player want to move)
         *              - there is not a candidate.
         */
        virtual int checkCandidates(bool turn, const char * from, const char * destination) = 0;

    private:
        /**
         * Check if path from source to destination is free, i.e. there are not opponent's pieces
         * along the way
         *
         * - Parameters:
         *      - from        : indicates the source cell of the piece that the player wants to move
         *      - destination : indicates the destination cell of the piece that the player wants to move
         *
         * - Returns: a boolean representing if the path is free (true) or not (false)
         */
        virtual bool checkPathIsFree(const char * from, const char * destination) = 0;
};

#endif
