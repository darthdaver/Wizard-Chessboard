/*
 * Pawn class implementation
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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Constructor
Pawn::Pawn(){};

// Constructor
Pawn::Pawn(const char * initialPosition): Piece(initialPosition) {
  pawnPromotion = "PEDINA";
  pawnFirstMove = true;
};


char * Pawn::getPromotion(){
  // create a copy to return the pointer in a safety way
  char * copy = new char [strlen(pawnPromotion) + 1];
    
  for(int i=0; i<strlen(pawnPromotion); i++){
      copy[i] = pawnPromotion[i];
  }
  copy[strlen(copy) - 1] = '\0';
    
  return copy;
};

bool Pawn::getFirstMove(){
  return pawnFirstMove;
};

void Pawn::setPromotion(const char * newType){
  pawnPromotion = new char [strlen(newType) + 1];
    
  for(int i = 0; i<strlen(newType); i++){
      pawnPromotion[i] = newType[i];
  }
  pawnPromotion[strlen(pawnPromotion) - 1] = '\0';
};

void Pawn::setFirstMove(){
  pawnFirstMove = false;
};

void Pawn::toString(){
  Serial.println("Type       : Pawn");
  Serial.print("Alive      : ");
  Serial.println(alive);
  Serial.print("Position   : ");
  Serial.print(position[0]);
  Serial.println(position[1]);
  Serial.print("Promotion  : ");
  Serial.println(pawnPromotion);
  Serial.print("First Move : ");
  Serial.println(pawnFirstMove);
};
