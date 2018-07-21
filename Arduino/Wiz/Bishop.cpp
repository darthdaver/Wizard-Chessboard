/*
 * Bishop class implementation
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

#include "Piece.h"
#include "Pieces.h"
#include <stdio.h>

using namespace std;

// Default constructor
Bishop::Bishop(){};
// Constructor
Bishop::Bishop(const char * initialPosition): Piece(initialPosition){};

void Bishop::toString(){
  //Serial.println("Type     : Bishop");
  //Serial.print("Alive    : ");
  //Serial.println(alive);
  //Serial.print("Position : ");
  //Serial.print(position[0]);
  //Serial.println(position[1]);
  //printf("\nType     : Bishop\n");
  //printf("Alive    : %d\n",getAlive());
  //printf("Position : %s\n",getPosition());
};
