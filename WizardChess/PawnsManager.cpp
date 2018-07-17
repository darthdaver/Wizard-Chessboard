/*
 * PawnsManager class implementation
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
PawnsManager::PawnsManager(): Manager() {
  pawns[WHITE][0] = Pawn::Pawn("A2");
  pawns[WHITE][1] = Pawn::Pawn("B2");
  pawns[WHITE][2] = Pawn::Pawn("C2");
  pawns[WHITE][3] = Pawn::Pawn("D2");
  pawns[WHITE][4] = Pawn::Pawn("E2");
  pawns[WHITE][5] = Pawn::Pawn("F2");
  pawns[WHITE][6] = Pawn::Pawn("G2");
  pawns[WHITE][7] = Pawn::Pawn("H2");
  pawns[BLACK][0] = Pawn::Pawn("A7");
  pawns[BLACK][1] = Pawn::Pawn("B7");
  pawns[BLACK][2] = Pawn::Pawn("C7");
  pawns[BLACK][3] = Pawn::Pawn("D7");
  pawns[BLACK][4] = Pawn::Pawn("E7");
  pawns[BLACK][5] = Pawn::Pawn("F7");
  pawns[BLACK][6] = Pawn::Pawn("G7");
  pawns[BLACK][7] = Pawn::Pawn("H7");
};

// checkCandidates implementation
char * PawnsManager::checkCandidates(Cell * cbState[][8], bool turn, const char * from, const char * destination){
  // auxiliary variables
  int numCandidates = 0;
  int indexCandidate;
  bool removeEnpassant = false;
  int row;
  int col;
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = destination[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = destination[1] - 49;

  // it is legal to look for candidates only if the destination cell is not already occupied by a piece of the same color
  if((turn && cbState[row][col].getColor() != 'B') || (!turn && cbState[row][col].getColor() != 'W')){
    // control the position of any pawn of the player in order to find a possible candidate
    for(int i = 0; i < 8; i++){
      // check the queen is alive
      if(pawns[turn][i].getAlive()){
        if(from == NULL){     // ordinary cases without ambiguity --> from = NULL
          // consider the parameters from and destination as points (from = (xf,yf), destination = (xd,yd))
          // calculate the vertical difference yd - yf
          vDiff = destination[1] - pawns[turn][i].getPosition()[1];
          // calculate the horizontal difference xd - xf
          hDiff = destination[0] - pawns[turn][i].getPosition()[0];
        } else {               // ambiguous cases --> from ≠ NULL
          // control if actually a pawn of the player occupy the position expressed by the variable from 
          if(checkSource(cbState, turn, from)){
            return NULL;
          }
          // calculate the vertical difference yd - yf
          vDiff = destination[1] - from[1];
          // calculate the horizontal difference xd - xf
          hDiff = destination[0] - from[0];
        }
        if(hDiff) == 0 && abs(vDiff) == 1){   // classical move
          // check direction and path is licit : if yes, add the corresponding pawn to the list of candidates
          if(checkDirection(turn, vDiff) && checkPathIsFree(cbState, vDiff, hDiff, row, col)){
            // a one-step movement eliminate previous eventual en passant
            if(turn){   // if move black
              enPassantBlack = NULL;
            } else{     // if move white
              enPassantWhite = NULL;
            }
            // add candidate
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else {
              return from;
            }
          }
        } else if(pawns[turn][i].getFirstMove() && (hDiff) == 0 && abs(vDiff) == 2){   // double step move
          // check direction and path is licit : if yes, add the corresponding pawn to the list of candidates
          if(checkDirection(turn, vDiff) && checkPathIsFree(cbState[][8], vDiff, hDiff, row, col)){
            // a two-step movement generate the possibility for the opponent player to perform an en passant in the next move
            if(turn){   // if move black
              strcpy(enPassantWhite, destination);
            } else{     // if move white
              strcpy(enPassantBlack, destination);
            }
            // add candidate
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else {
              return from;
            }
            
          }
        } else if(abs(hDiff) == 1 && abs(vDiff == 1){    // eat the opposing piece
          // check direction and path is licit : if yes, add the corresponding pawn to the list of candidates
          if(checkDirection(turn, vDiff) && !checkPathIsFree(cbState, vDiff, hDiff, row, col)){
            // a eat move eliminate previous eventual en passant
            if(turn){   // if move black
              enPassantBlack = NULL;
            } else{     // if move white
              enPassantWhite = NULL;
            }
            // add candidate
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else {
              return from;
            }
          }
        } else if(turn && enPassantBlack != NULL && abs(hDiff) == 1 && vDiff == 0){    // en passant black --> white
          // verify immediatly if the path is correct (the destination must be busy by another pawn in order to perform an en passant)
          if(strcmp(enPassantBlack,destination) == 0){
            enPassantBlack = NULL;
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else {  
              return from;
            }
            
          }
        } else if(!turn && enPassantWhite != NULL && abs(hDiff) == 1 && vDiff == 0){   // en passant white --> black
          // verify immediatly if the path is correct (the destination must be busy by another pawn in order to perform an en passant)
          if(strcmp(enPassantWhite,destination) == 0){
            enPassantWhite = NULL;
            if(from == NULL){
              numCandidates++;
              indexCandidate = i;
            } else {
              return from;
            }
          }
        }
      }
    }
    // in case from = NULL verify that the search of candidates return only one candidate
    if(numCandidates == 1){
      return pawns[turn][indexCandidate].getPosition();
    }
  }
  //move not valid
  return NULL;
};

char * PawnsManager::checkPromotedCandidates(Cell * cbState[][8], bool turn, const char * promoType, const char * from){
  int numCandidates = 0;
  int indexCandidate;

  // unambiguous cases
  for(int i = 0; i < 8; i++){
    // control that a promoted pawn is actually present in the cell indicated by the variable from and that
    // the pawn is actually promoted to the type indicated by the variable promoType
    if(strcmp(promoType, pawns[turn][i].getPromotion()) == 0){
      // no sense move
      if(strcmp(promotype, "PEDINA") == 0){
        return NULL;
      }
      if(from != NULL && checkSource(cbState, turn, from)){
        return from;
      } else {
        numCandidates ++;
        indexCandidate = i;
    }
  }

  if(numCandidates == 1){
    return pawns[turn][indexCandidate].getPosition();
  } else{
    return NULL;
  }
};

bool checkDirection(bool turn, int vDiff){
  if(turn){   // if move black
    if(hDiff) < 0){
      return false;
    }
    return true;
  } else {    // if move white
    if(hDiff) > 0){
      return true;
    }
    return false;
  }
}

virtual bool checkPathIsFree(Cell * cbState[][8], int vDiff, int hDiff, int row, int col){
  // note that the case of en passant is not considered because the control is already performed
  // in the main function through the variable enPassantWhite (or enPassantBlack)

  if(abs(vDiff) <= 1 && abs(hDiff) <= 1){  // one-step forward (ordinary case) or diagonal movement
    // verify if the destination cell is not busy by another piece
    if(!cbState[row][column].getBusy()){
      // if the one-step movement is performed in vertical, the destination cell must be empty
      if(hDiff == 0 && abs(vDiff) == 1){
        return true;
      } else{
        return false;
      }
    } else{   // the destination is busy
      // if the one-step movement is performed in diagonal, the destination cell must be busy
      if((abs(hDiff) == 1 && abs(vDiff) == 1)){
        return true;
      }
      return false;
    }
  } else if((abs(vDiff) == 0 && abs(hDiff) == 2){ //first 2-step forward movement

    int rowForward;
    int colForward;

    if(vDiff == 2){   // if move white the movement is an increment in the row value
      colForward = destination[1] - 49 + 1;
    } else {          // if move black the movement is a decrement in the row value
      colForward = destination[1] - 49 - 1;
    }
    rowForward = destination[0] - 65;

    // if both the next cells are empty the path is free
    if(!cbState[rowForward][colForward].getBusy() && !cbState[row][col].getBusy()){
      return true;
    } else{
      return false;
    }
  }
  return false;
};
