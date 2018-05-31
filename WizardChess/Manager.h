/*
 * Header file for the ManagerInterface abstract class.
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
#include <StackList.h>

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
     *      - source      : indicates the source cell of the piece that the player wants to move
     *      - destination : indicates the destination cell of the piece that the player wants to move
     *
     * - Returns: a boolean value indicating if the path is feasible (true) or not (false)
     */
    virtual StackList <int> checkCandidates(const char * from, const char * destination) = 0;
};

#endif
