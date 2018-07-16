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
char * RooksManager::checkCandidates(bool cbState[][8], bool turn, const char * from, const char * destination){
  // auxiliary variables
  int numCandidates = 0;
  int indexCandidate;

  // ordinary cases without ambiguity --> from set to NULL
  if(from == NULL){
    // control the position of any rook of the player in order to find a possible candidate
    for(int i = 0; i < 2; i++){
      // check the queen is alive
      if(rooks[turn][i].getAlive()){
        // vertical or horizontal move
        if((destination[0] - rooks[turn][i].getPosition()[0] == 0 &&
            abs(destination[1] - rooks[turn][i].getPosition()[1]) > 0) ||
              (abs(destination[0] - rooks[turn][i].getPosition()[0]) > 0 &&
                destination[1] - rooks[turn][i].getPosition()[1] == 0)){
          // check path is licit
          if(checkPathIsFree(cbState, rooks[turn][i].getPosition(), destination)){
            numCandidates++;
            indexCandidate = i;
          }
        }
    }
    }
  } else{   //manage pawn promotion and ambiguous cases --> from ≠ NULL
    if((destination[0] - from[0] == 0 && abs(destination[1] - from[1]) > 0) ||
          (abs(destination[0] - from[0]) > 0 && destination[1] - from[1] == 0)){
      // check path is licit
      if(checkPathIsFree(cbState, from, destination)){
        return from;
      }
    }
  }
  // move not valid
  return NULL;
};

// checkPathIsFree implementation
virtual bool checkPathIsFree(bool cbState[][8], const char * from, const char * destination){
  // consider the parameters from and destination as points ( from = (xf,yf), destination = (xd,yd))

  // auxiliary variables
  // calculate the vertical difference yd - yf
  int vDiff = destination[1] - from[1];
  // calculate the horizontal difference xd - xf
  int hDiff = destination[0] - from[0];
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = from[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = from[1] - 49;

  if(abs(vDiff) > 0 && hDiff == 0){           // vertical movement
    for(int i = 1; i < abs(vDiff); i++){
      if(vDiff > 0){
        // cell busy
        if(!cbState[row][col + i]){
          return false;
        }
      } else {
        // cell busy
        if(!cbState[row][col - i]){
          return false;
        }
      }
    }
  } else if(vDiff == 0 && abs(hDiff) > 0){    //horizontal movement
    for(int i = 1; i < abs(hDiff); i++){
      if(hDiff > 0){
        // cell busy
        if(!cbState[row + i][col]){
          return false;
        }
      } else {
        // cell busy
        if(!cbState[row - i][col]){
          return false;
        }
      }
    }
  }

  // all constraints, overcome
  return true;
};
