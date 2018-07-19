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
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

// Constructor
KingsManager::KingsManager(): Manager() {
  kings[WHITE][0] = King::King("E1");
  kings[BLACK][0] = King::King("E8");
};

// checkCandidates implementation
char * KingsManager::checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination){
  // auxiliary variables
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = destination[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = destination[1] - 49;
  int vDiff;
  int hDiff;

  // consider the parameters from and destination as points (from = (xf,yf), destination = (xd,yd))
  if(from = NULL){     // ordinary cases without ambiguity --> from = NULL
    // calculate the vertical difference yd - yf
    vDiff = destination[1] - kings[turn][0].getPosition()[1];
    // calculate the horizontal difference xd - xf
    hDiff = destination[0] - kings[turn][0].getPosition()[0];
  } else{               // ambiguous cases --> from ≠ NULL
    // control if actually a king of the player occupy the position expressed by the variable from
    if(!checkSource(cbState, turn, from, 'K')){
      return NULL;
    }
    // calculate the vertical difference yd - yf
    vDiff = destination[1] - from[1];
    // calculate the horizontal difference xd - xf
    hDiff = destination[0] - from[0];
  }

  // it is legal to look for candidates only if the destination cell is not already occupied by a piece of the same color
  if((turn && cbState[row][col]->getColor() != 'B') || (!turn && cbState[row][col]->getColor() != 'W')){
    // the king is unique for any player so the case from = NULL and from ≠ NULL is manageable
    // in a single case (considering from = NULL in any case)

    // check the king is alive
    if(kings[turn][0].getAlive()){
      // check if path is licit
      if(checkPathIsFree(cbState, vDiff, hDiff, row, col)){
        if(cbState[row][col]->getBusy()){
          // set a memo to remember that the opponent piece in the destination cell must be removed
          cbState[row][col]->setColor('D');
        }
        kings[turn][0].setPosition(destination);
        return kings[turn][0].getPosition();
      }
    }
  }
  // move not valid
  return NULL;
};

bool KingsManager::checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col){
  if(abs(vDiff) <= 1 && abs(hDiff) <= 1){
    return true;
  } else{
    return false;
  }
};

void KingsManager::toString(){
  //Serial.println("--- King ---");
  //Serial.println();
  printf("\n\n--- King ---\n\n");
    
  for(int i = 0; i < 2; i ++){
    if(i == 0){
      //Serial.println("Black: ");
      printf("White: \n");
      //Serial.println();
    } else{
      printf("Black: \n");
      //Serial.println("White: ");
      //Serial.println();
    }

    kings[i][0].toString();
  }
};

void KingsManager::setNewPosition(bool turn, const char * from, const char * destination){
  kings[turn][0].setPosition(destination);
};

void KingsManager::findAndRemove(bool turn, const char * destination){
  if(strcmp(kings[turn][0].getPosition(),destination) == 0){
      kings[turn][0].setAlive();
      kings[turn][0].setPosition("Z9");
  }
};
