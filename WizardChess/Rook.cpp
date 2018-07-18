/*
 * Rook class implementation
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
Rook::Rook(){};

// Constructor
Rook::Rook(const char * initialPosition): Piece(initialPosition) {};

bool Rook::checkPathIsFree(const char * destination){
  return true;
};

void Rook::toString(){
  Serial.println("Type     : Rook");
  Serial.print("Alive    : ");
  Serial.println(getAlive());
  Serial.print("Position : ");
  Serial.println(getPosition());
};
