/*
 * BishopsManager class implementation
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
BishopsManager::BishopsManager(): Manager(){
  bishops[WHITE_BISHOP][0] = Bishop("C1");
  bishops[WHITE_BISHOP][1] = Bishop("F1");
  bishops[BLACK_BISHOP][0] = Bishop("C8");
  bishops[BLACK_BISHOP][1] = Bishop("F8");
};

// checkCandidates implementation
char * BishopsManager::checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination){
  // auxiliary variables
  int numCandidates = 0;
  int indexCandidate;
  int vDiff;
  int hDiff;
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = destination[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = destination[1] - 49;

  // it is legal to look for candidates only if the destination cell is not already occupied by a piece of the same color
  if((turn && cbState[row][col].getColor() != 'B') || (!turn && cbState[row][col].getColor() != 'W')){
    // control the position of any bishop of the player in order to find a possible candidate
    for(int i = 0; i < 2; i++){
      // check the queen is alive
      if(bishops[turn][i].getAlive()){
        if(from == NULL){     // ordinary cases without ambiguity --> from set to NULL
          // consider the parameters from and destination as points (from = (xf,yf), destination = (xd,yd))
          // calculate the vertical difference yd - yf
          int vDiff = destination[1] - bishops[turn][i].getPosition()[1];
          // calculate the horizontal difference xd - xf
          int hDiff = destination[0] - bishops[turn][i].getPosition()[0];
        } else {              //manage pawn promotion and ambiguous cases --> from ≠ NULL
          // calculate the vertical difference yd - yf
          int vDiff = destination[1] - from[1];
          // calculate the horizontal difference xd - xf
          int hDiff = destination[0] - from[0];
        }
        // verify that the move is not not vertical or horizontal move, but only diagonal (abs(vDiff) == abs(hDiff))
        if(abs(vDiff) == abs(hDiff)){
          // check path is licit
          if(checkPathIsFree(cbState, vDiff, hDiff, row, col)){
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else{
              return from;
            }
          }
        }
      }
    }
    // in case from = NULL verify that the search of candidates return only one candidate
    if(numCandidates == 1){
      return bishops[turn][i].getPosition();
    }
  }
  // move not valid
  return NULL;
};

virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col){
  // move along the diagonal to search for busy cells (remember that abs(vDiff) == abs(hDiff))
  for(int i = 1; i < abs(vDiff); i++){
    if(vDiff > 0 && hDiff > 0){         // up - right real chessboard (from white player point of view)
      // cell busy
      if(cbState[row + i][col + i].getBusy()){
        return false;
      }
    } else if(vDiff > 0 && hDiff < 0){  // up - left real chessboard (from white player point of view)
      // cell busy
      if(cbState[row + i][col - i].getBusy()){
        return false;
      }
    } else if(vDiff < 0 && hDiff > 0){  // down - right real chessboard (from white player point of view)
      // cell busy
      if(cbState[row - i][col + i].getBusy()){
        return false;
      }
    } else if(vDiff < 0 && hDiff < 0){  // down - left real chessboard (from white player point of view)
      // cell busy
      if(cbState[row - i][col - i].getBusy()){
        return false;
      }
    }
  }
  // all constraints, overcome
  return true;
};
