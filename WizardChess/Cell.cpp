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

#include "Cell.h"

// Constructor
Cell::Cell(){};

// Constructor
Cell::Cell(bool initialBusy, char initialColor, char initialType) {
  busy  = initialBusy;
  color = initialColor;
  piece = initialType;
};

bool Cell::getBusy(){
  return busy;
};

char Cell::getColor(){
  return color;
};

char Cell::getPiece(){
  return piece;
};

void Cell::setBusy(){
  busy = !busy;
};

void Cell::setColor(char newColor){
  color = newColor;
};

void Cell::setPiece(char newPiece){
  piece = newPiece;
};

void Cell::toString(){
  //Serial.print("Busy  : ");
  //Serial.println(getBusy());
  //Serial.print("Color : ");
  //Serial.println(getColor());
  //Serial.print("Type  : ");
  //Serial.println(getPiece());
};
