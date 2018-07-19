/*
 * KnightsManager class implementation
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
KnightsManager::KnightsManager(): Manager() {
  knights[WHITE][0] = Knight("B1");
  knights[WHITE][1] = Knight("G1");
  knights[BLACK][0] = Knight("B8");
  knights[BLACK][1] = Knight("G8");
};

// checkCandidates implementation
char * KnightsManager::checkCandidates(Cell * cbState[][8], bool turn, const char* from, const char* destination){
  // auxiliary variables
  char * candidate;
  int numCandidates = 0;
  int indexCandidate;
  int vDiff;
  int hDiff;
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = destination[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = destination[1] - 49;

  // it is legal to look for candidates only if the destination cell is not already occupied by a piece of the same color
  if((turn && cbState[row][col]->getColor() != 'B') || (!turn && cbState[row][col]->getColor() != 'W')){
    // control the position of any knight of the player in order to find a possible candidate
    for(int i = 0; i < 2; i++){
      // check the queen is alive
      if(knights[turn][i].getAlive()){
        // consider the parameters from and destination as points ( from = (xf,yf), destination = (xd,yd))
        if(from == NULL){     // ordinary cases without ambiguity --> from = NULL
          // calculate the vertical difference yd - yf
          vDiff = destination[1] - knights[turn][i].getPosition()[1];
          // calculate the horizontal difference xd - xf
          hDiff = destination[0] - knights[turn][i].getPosition()[0];
        } else{               // ambiguous cases --> from ≠ NULL
          // control if actually a knight of the player occupy the position expressed by the variable from 
          if(checkSource(cbState, turn, from, 'H')){
            return NULL;
          }
          // calculate the vertical difference yd - yf
          vDiff = destination[1] - from[1];
          // calculate the horizontal difference xd - xf
          hDiff = destination[0] - from[0];
        }
      }
      // verify that the move is two-steps in one direction and one-step in the other direction
      if((abs(vDiff) == 2 && abs(hDiff) == 1) || (abs(vDiff) == 1 && abs(hDiff)) == 2){
        // check path is licit
        if(checkPathIsFree(cbState, vDiff, hDiff, row, col)){
          if(from == NULL){
            numCandidates++;
            indexCandidate = i;
          } else {
            if(cbState[row][col]->getBusy()){
              // set a memo to remember that the opponent piece in the destination cell must be removed
              cbState[row][col]->setColor('D');
            }

            setNewPosition(turn, from, destination);
            return from;
          }
        }
      }
    }
    // in case from = NULL verify that the search of candidates return only one candidate
    if(numCandidates == 1){
      if(cbState[row][col]->getBusy()){
        // set a memo to remember that the opponent piece in the destination cell must be removed
        cbState[row][col]->setColor('D');
      }
      candidate = knights[turn][indexCandidate].getPosition();
      knights[turn][indexCandidate].setPosition(destination);
      return candidate;
    }
  }
  // move not valid
  return NULL;
};

bool KnightsManager::checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col){
  // the knights can jump so it is not necessary to verify that the path from the source to the destination is free
  // the only constraint is that the destination cell is not occupied by a piece of the same color, but this
  // is verified as start point in the checkCandidates function
  return true;
};

void KnightsManager::setNewPosition(bool turn, const char * from, const char * destination){
  for(int i = 0; i < 2; i++){
    if(strcmp(knights[turn][i].getPosition(),from) == 0){
      knights[turn][i].setPosition(destination);
    }
  }
};

void KnightsManager::toString(){
  //Serial.println("--- Knights ---");
  //Serial.println();

  for(int i = 0; i < 2; i ++){
    if(i == 0){
      //Serial.println("Black: ");
      //Serial.println();
    } else{
      //Serial.println("White: ");
      //Serial.println();
    }

    for(int j = 0; i < 2; i ++){
      knights[i][j].toString();
    }
  }
};

void KnightsManager::findAndRemove(bool turn, const char * destination){
  for(int i = 0; i < 2; i++){
    if(strcmp(knights[turn][i].getPosition(),destination) == 0){
      knights[turn][i].setAlive();
      knights[turn][i].setPosition("Z9");

      return;
    }
  }
};
