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


 // Default constructor
 Bishop::Bishop(){};

 // Constructor
 Bishop::Bishop(const char * initialPosition): Piece(initialPosition){};

 boolean Bishop::checkPathIsFree(const char * destination){
   return true;
 };

 void Bishop::toString(){
   Serial.println("Type     : Bishop");
   Serial.print("Position : ");
   Serial.println(getPosition());
 };
