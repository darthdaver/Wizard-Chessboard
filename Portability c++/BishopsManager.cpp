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
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

// Constructor
BishopsManager::BishopsManager(): Manager(){
  bishops[WHITE][0] = Bishop("C1");
  bishops[WHITE][1] = Bishop("F1");
  bishops[BLACK][0] = Bishop("C8");
  bishops[BLACK][1] = Bishop("F8");
};

// checkCandidates implementation
char * BishopsManager::checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination){
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
  
  // row or column out of chessboard limits
  if(row < 0 || col < 0 || row > 7 || col > 7){
      return NULL;
  }
  
  // it is legal to look for candidates only if the destination cell is not already occupied by a piece of the same color
  if((turn && cbState[row][col]->getColor() != 'B') || (!turn && cbState[row][col]->getColor() != 'W')){
    // control the position of any bishop of the player in order to find a possible candidate
    for(int i = 0; i < 2; i++){
      // check the queen is alive
      if(bishops[turn][i].getAlive()){
        if(from == NULL){     // ordinary cases without ambiguity --> from set to NULL
          // consider the parameters from and destination as points (from = (xf,yf), destination = (xd,yd))
          // calculate the vertical difference yd - yf
          vDiff = destination[1] - bishops[turn][i].getPosition()[1];
          // calculate the horizontal difference xd - xf
          hDiff = destination[0] - bishops[turn][i].getPosition()[0];
        } else {              //manage bishop promotion and ambiguous cases --> from ≠ NULL
          // control if actually a bishop of the player occupy the position expressed by the variable from 
          if(!checkSource(cbState, turn, from, 'B')){
            return NULL;
          }
          // calculate the vertical difference yd - yf
          vDiff = destination[1] - from[1];
          // calculate the horizontal difference xd - xf
          hDiff = destination[0] - from[0];
        }
        
        printf("\n\nvdiff1 %d    hdiff %d\n",vDiff,hDiff);
        // verify that the move is not not vertical or horizontal move, but only diagonal (abs(vDiff) == abs(hDiff))
        if(abs(vDiff) == abs(hDiff)){
          // check path is licit
          if(checkPathIsFree(cbState, vDiff, hDiff, row, col)){
              printf("\n\nvdiff2 %d    hdiff %d\n",vDiff,hDiff);
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else{
              if(cbState[row][col]->getBusy()){
                // set a memo to remember that the opponent piece in the destination cell must be removed
                cbState[row][col]->setColor('D');
              }
              setNewPosition(turn, from, destination);
              candidate = new char[3];
              for(int i = 0; i<strlen(from);i++){
                  candidate[i] = from[i];
              }
              return candidate;
            }
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
      candidate = bishops[turn][indexCandidate].getPosition();
      bishops[turn][indexCandidate].setPosition(destination);
      return candidate;
    }
  }

  // move not valid
  return NULL;
};

bool BishopsManager::checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col){
  // move along the diagonal to search for busy cells (remember that abs(vDiff) == abs(hDiff))
    printf("\n\nvdiff3 %d    hdiff %d\n",vDiff,hDiff);
  for(int i = 1; i < abs(vDiff); i++){
    if(vDiff > 0 && hDiff > 0){         // up - right real chessboard (from white player point of view)
      // cell busy
      if(cbState[row - i][col - i]->getBusy()){
        return false;
      }
    } else if(vDiff > 0 && hDiff < 0){  // up - left real chessboard (from white player point of view)
      // cell busy
      if(cbState[row + i][col - i]->getBusy()){
        return false;
      }
    } else if(vDiff < 0 && hDiff > 0){  // down - right real chessboard (from white player point of view)
      // cell busy
      if(cbState[row - i][col + i]->getBusy()){
        return false;
      }
    } else if(vDiff < 0 && hDiff < 0){  // down - left real chessboard (from white player point of view)
      // cell busy
      if(cbState[row + i][col + i]->getBusy()){
        return false;
      }
    }
  }
  // all constraints, overcome
  return true;
};

void BishopsManager::setNewPosition(bool turn, const char * from, const char * destination){
  for(int i = 0; i < 2; i++){
    if(strcmp(bishops[turn][i].getPosition(),from) == 0){
      bishops[turn][i].setPosition(destination);
    }
  }
};

void BishopsManager::toString(){
  //Serial.println("--- Bishops ---");
  //Serial.println();    
  printf("\n\n--- Bishops ---\n\n");  

  for(int i = 0; i < 2; i ++){
    if(i == 0){
      printf("White: \n");
      //Serial.println("Black: ");
      //Serial.println();
    } else{
      printf("\nBlack: \n");
      //Serial.println("White: ");
      //Serial.println();
    }

    for(int j = 0; j < 2; j ++){
      bishops[i][j].toString();
    }
  }
};

void BishopsManager::findAndRemove(bool turn, const char * destination){
  for(int i = 0; i < 2; i++){
    if(strcmp(bishops[turn][i].getPosition(),destination) == 0){
      bishops[turn][i].setAlive();
      bishops[turn][i].setPosition("Z9");

      return;
    }
  }
};
