/*
 * KingsManager class implementation
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
KingsManager::KingsManager(): Manager() {
  kings[WHITE_KING][0] = King::King("E1");
  kings[BLACK_KING][0] = King::King("E8");
};

// checkCandidates implementation
char * KingsManager::checkCandidates(bool cbState[][8], bool turn,bool cbState[][8], const char * from, const char * destination){
  if(from == NULL){
    // check the king is alive
    if(kings[turn][0].getAlive()){
      // check if path is licit
      if(checkPathIsFree(cbState, kings[turn][i].getPosition(), destination)){
        return kings[turn][i].getPosition();
      }
    }
  } else {    // manage pawn promotion and ambiguous cases --> from ≠ NULL
      // check the path is lecit
      if(checkPathIsFree(cbState, from, destination)){
        return kings[turn][i].getPosition();
      }
    }
  }

  // move not valid
  return NULL;
};

virtual bool checkPathIsFree(bool cbState[][8], const char * from, const char * destination){
  // auxiliary variables
  // calculate the vertical difference yd - yf
  int vDiff = destination[1] - from[1];
  // calculate the horizontal difference xd - xf
  int hDiff = destination[0] - from[0];
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = destination[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = destination[1] - 49;

  if(abs(vDiff) == 1 && abs(hDiff) == 1){
    if(!cbState[row][col]){
      
    }
  }
};
