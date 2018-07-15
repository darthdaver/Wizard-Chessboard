/*
 * RooksManager class implementation
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

#include "Manager.h"
#include "Managers.h"
#include "Pieces.h"
#include "Config.h"

// Constructor
RooksManager::RooksManager(): Manager() {
  rooks[WHITE][0] = Rook::Rook("A1");
  rooks[WHITE][1] = Rook::Rook("H1");
  rooks[BLACK][0] = Rook::Rook("A8");
  rooks[BLACK][1] = Rook::Rook("H8");
};

// checkCandidates implementation
char * RooksManager::checkCandidates(const char * from, const char * destination){
  // auxiliary variables
  int numCandidates = 0;
  int indexCandidate;
  char * candidatePosition;

  if(from == NULL){
    for(int i = 0; i < 2; i++){
      // vertical or horizontal move
      if((destination[0] - rooks[turn][i].getPosition()[0]) == 0 &&
          abs(destination[1] - rooks[turn][i].getPosition()[1]) > 0) ||
            (abs(destination[0] - rooks[turn][i].getPosition()[0]) > 0 &&
              destination[1] - rooks[turn][i].getPosition()[1] == 0)){
        // check path is licit
        if(checkPathIsFree(rooks[turn][i].getPosition(), destination)){
          numCandidates++;
          indexCandidate = i;
          candidatePosition = rooks[turn][i].getPosition());
        }
      }
    }
  } else{
    if((destination[0] - from[0]) == 0 && abs(destination[1] - from > 0) ||
          (abs(destination[0] - from[0]) > 0 && destination[1] - from == 0){
      // check path is licit
      if(checkPathIsFree(from, destination)){
        numCandidates++;
        indexCandidate = i;
        candidatePosition = from;
      }  
    }
  }
};

// checkPathIsFree implementation
virtual bool checkPathIsFree(bool * cbState, const char * from, const char * destination){
  // consider the parameters from and destination as points ( from = (xf,yf), destination = (xd,yd))

  // calculate the vertical difference yd - yf
  vDiff = destination[1] - from[1];
  // calculate the horizontal difference xd - xf
  hDiff = destination[0] - from[0];

  if(abs(vDiff) > 0 && hDiff == 0){
    if(vDiff > 0){
      for(int i = 0; i < abs(vdiff); i++){
        for(int j = 0; j < 2; j++){
          for(int k = 0; k < 2; k++){
            //cell occupied by another piece
            if(strcmp(forwardCell,rooks[i][j].getPosition()) == 0 || strcmp(destination, pawns[i][j].getPosition()) == 0){
              return false;
        }
        }
      }
    }
  } else if(){}
};