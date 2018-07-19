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

// Constructor
Pawn::Pawn(){};

// Constructor
Pawn::Pawn(const char * initialPosition): Piece(initialPosition) {
  pawnPromotion = "PEDINA";
  pawnFirstMove = true;
};


char * Pawn::getPromotion(){
  // create a copy to return the pointer in a safety way
  char * copy = new char [strlen(pawnPromotion)];
    
  for(int i=0; i<strlen(pawnPromotion); i++){
      copy[i] = pawnPromotion[i];
  }
    
  return copy;
};

bool Pawn::getFirstMove(){
  return pawnFirstMove;
};

void Pawn::setPromotion(const char * newType){
  pawnPromotion = new char [strlen(newType)];
    
  for(int i = 0; i<strlen(newType); i++){
      pawnPromotion[i] = newType[i];
  }
};

void Pawn::setFirstMove(){
  pawnFirstMove = false;
};

void Pawn::toString(){
  Serial.println("Type     : Pawn");
  Serial.print("Alive    : ");
  Serial.println(getAlive());
  Serial.print("Position : ");
  Serial.println(getPosition());
};
