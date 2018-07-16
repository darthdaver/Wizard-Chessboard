/*
 * QueensManager class implementation
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
QueensManager::QueensManager(): Manager() {
  queens[WHITE_QUEEN][0] = Queen("D1");
  queens[BLACK_QUEEN][0] = Queen("D8");
};

// checkCandidates implementation
char * QueensManager::checkCandidates(bool cbState[][8], bool turn,bool cbState[][8], const char * from, const char * destination){
  if(from == NULL){
    // check the queen is alive
    if(queens[turn][0].getAlive()){
      // check if path is licit
      if(checkPathIsFree(cbState, queens[turn][i].getPosition(), destination)){
        return queens[turn][i].getPosition();
      }
    }
  } else {    // manage pawn promotion and ambiguous cases --> from ≠ NULL
      // check the path is lecit
      if(checkPathIsFree(cbState, from, destination)){
        return queens[turn][i].getPosition();
      }
    }
  }

  // move not valid
  return NULL;
};

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

  // horizontal or vertical movement
  if(abs(vDiff) != abs(hDiff)){
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
  } else {    // diagonal movement
    // move along the diagonal to search for busy cells (remember that abs(vDiff) == abs(hDiff))
    for(int i = 1; i < abs(vDiff); i++){
      if(vDiff > 0 && hDiff > 0){         // up - right real chessboard (from white player point of view)
        // cell busy
        if(!cbState[row + i][col + i]){
          return false;
        }
      } else if(vDiff > 0 && hDiff < 0){  // up - left real chessboard (from white player point of view)
        // cell busy
        if(!cbState[row + i][col - i]){
          return false;
        }
      } else if(vDiff < 0 && hDiff > 0){  // down - right real chessboard (from white player point of view)
        // cell busy
        if(!cbState[row - i][col + i]){
          return false;
        }
      } else if(vDiff < 0 && hDiff < 0){  // down - left real chessboard (from white player point of view)
        // cell busy
        if(!cbState[row - i][col - i]){
          return false;
        }
      }
    }
  }
  // all constraints, overcome
  return true;
};
