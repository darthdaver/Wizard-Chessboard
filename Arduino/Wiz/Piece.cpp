/*
 * PieceInterface abstract class implementation.
 *
 * Copyright (c) 2018 Davide Molinelli.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the   hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Piece.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Piece::Piece(){};

Piece::Piece(const char * initialPosition){
  ////Serial.println(initialPosition);
  position = new char[3];
  position[0] = initialPosition[0];
  position[1] = initialPosition[1];
  alive = true;
};

char * Piece::getPosition(){
  // get position in a safety way
  char * copy = new char [strlen(position)];
    
  for(int i=0; i<strlen(position); i++){
      copy[i] = position[i];
  }
  
  return copy;
};

bool Piece::getAlive(){
  return alive;
};

void Piece::setPosition(const char * newCoordinates){
  // set position in a safety way
  position[0] = newCoordinates[0];
  position[1] = newCoordinates[1];
};

void Piece::setAlive(){
  alive = !alive;
};
