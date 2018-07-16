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
Cell::Cell(){};

// Constructor
Cell::Cell(bool initialBusy, char initialColor) {
  busy  = initialBusy;
  color = initialColor:
};

bool getBusy(){
  return busy;
};

char getColor(){
  return color;
};

void setBusy(){
  busy = !busy;
};

void setColor(char newColor){
  color = newColor;
};

void Cell::toString(){
  Serial.println("Busy   :");
  Serial.println(getBusy());
  Serial.print("Color : ");
  Serial.println(getColor());
};
