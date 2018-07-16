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
char * PawnsManager::checkCandidates(bool turn, const char * from, const char * destination){
  // auxiliary variables
  int numCandidates = 0;
  int indexCandidate;
  bool removeEnpassant = false;

  // ordinary cases without ambiguity --> from set to NULL
  if(from == NULL){
    // control the position of any pawn of the player in order to find a possible candidate
    for(int i = 0; i < 8; i++){
      // check the queen is alive
      if(pawns[turn][i].getAlive()){
        if(destination[0] - pawns[turn][i].getPosition()[0]) == 0 &&
              abs((destination[1] - pawns[turn][i].getPosition()[1])) == 1){   // classical move
          // check direction and path is licit : if yes, add the corresponding pawn to the list of candidates
          if(checkDirection(turn, pawns[turn][i].getPosition(), destination) &&
                checkPathIsFree(cbState, pawns[turn][i].getPosition(), destination)){
            numCandidates++;
            indexCandidate = i;
          }
          // a one-step movement eliminate previous eventual en passant
          if(turn){   // if move black
            enPassantBlack = NULL;
          } else{     // if move white
            enPassantWhite = NULL;
          }
        } else if(pawns[turn][i].getFirstMove() && (destination[0] - pawns[turn][i].getPosition()[0]) == 0 &&
                    abs((destination[1] - pawns[turn][i].getPosition()[1])) == 2){   // double step move
          // check direction and path is licit : if yes, add the corresponding pawn to the list of candidates
          if(checkDirection(turn, pawns[turn][i].getPosition(), destination) &&
                checkPathIsFree(cbState, pawns[turn][i].getPosition(), destination)){
            numCandidates++;
            indexCandidate = i;
            // a two-step movement generate the possibility for the opponent player to perform an en passant in the next move
            if(turn){   // if move black
              strcpy(enPassantWhite, destination);
            } else{     // if move white
              strcpy(enPassantBlack, destination);
            }
          }
        } else if(abs(destination[0] - pawns[turn][i].getPosition()[0]) == 1 &&
                    abs((destination[1] - pawns[turn][i].getPosition()[1])) == 1){    // eat the opposing piece
          // check direction and path is licit : if yes, add the corresponding pawn to the list of candidates
          if(checkDirection(turn, pawns[turn][i].getPosition(), destination) &&
                !checkPathIsFree(cbState, pawns[turn][i].getPosition(), destination)){
            numCandidates++;
            indexCandidate = i;
          }
          // a eat move eliminate previous eventual en passant
          if(turn){   // if move black
            enPassantBlack = NULL;
          } else{     // if move white
            enPassantWhite = NULL;
          }
        } else if(turn && enPassantBlack != NULL && abs(destination[0] - pawns[turn][i].getPosition()[0]) == 1 &&
                (destination[1] - pawns[turn][i].getPosition()[1]) == 0){    // en passant black --> white
          // verify immediatly if the path is correct (the destination must be busy by another pawn in order to perform an en passant)
          if(strcmp(enPassantBlack,destination) == 0){
            numCandidates++;
            indexCandidate = i;
            enPassantBlack = NULL;
          }
        } else if(!turn && enPassantWhite != NULL && abs(destination[0] - pawns[turn][i].getPosition()[0]) == 1 &&
                (destination[1] - pawns[turn][i].getPosition()[1]) == 0){   // en passant white --> black
          // verify immediatly if the path is correct (the destination must be busy by another pawn in order to perform an en passant)
          if(strcmp(enPassantWhite,destination) == 0){
            numCandidates++;
            indexCandidate = i;
            enPassantWhite = NULL;
          }
        }
      }
    }

    // verify there is only one candidate
    if(numCandidates == 1){   // only one candidate
      return pawns[turn][indexCandidate].getPosition();
    } else {    // more than one candidate: ambiguity!
      return NULL;
    }
  } else{   // manage ambiguous cases --> from ≠ NULL
    // control if from is a valid position
    if(checkSource(turn, from)){
      if(destination[0] - from[0]) == 0 &&
            abs((destination[1] - from[1])) == 1){   // classical move
        // check direction and path is licit : if yes, return the candidate
        if(checkDirection(turn, from, destination) &&
              checkPathIsFree(cbState, from,destination)){
          // a one-step movement eliminate previous eventual en passant
          if(turn){   // if move black
            enPassantBlack = NULL;
          } else{     // if move white
            enPassantWhite = NULL;
          }
          return from;
        }
      } else if(((turn && from[1] == '7') ||  (!turn && from[1] == '2') && (destination[0] - from[0]) == 0 &&
            abs((destination[1] - from[1])) == 2){   // double step move at first move
        // note: in the above else if condition '7' and '2' refers to the fact that if it's the first move
        // for the pawn, in the case move the black, the row of the pawn must be 7, while in the case
        // move the white, the row must be 2

        // check direction and path is licit : if yes, return the candidate
        if(checkDirection(turn, from, destination) &&
              checkPathIsFree(cbState, from, destination))){
          // a two-step movement generate the possibility for the opponent player to perform an en passant in the next move
          if(turn){   // if move black
            strcpy(enPassantWhite,destination);
          } else{     // if move white
            strcpy(enPassantBlack,destination);
          }
          return from;
        }
      } else if(abs(destination[0] - from[0]) == 1 &&
                  abs((destination[1] - from[1]) == 1){    // eat the opposing piece
        // check direction and path is licit : if yes, return the candidate
        if(checkDirection(turn, from, destination) &&
              !checkPathIsFree(cbState, from, destination)){
          // a eat move eliminate previous eventual en passant
          if(turn){   // if move black
            enPassantBlack = NULL;
          } else{     // if move white
            enPassantWhite = NULL;
          }
          return from;
        }
      } else if(turn && enPassantBlack != NULL && abs(destination[0] - from[0]) == 1 &&
              (destination[1] - from[1]) == 0){   // en passant black --> white
        if(strcmp(enPassantBlack,destination) == 0){
          enPassantBlack = NULL;
          return from;
        }
      } else if(!turn && enPassantWhite != NULL && abs(destination[0] - from[0]) == 1 &&
              (destination[1] - from[1]) == 0){   // en passant black --> white
        if(strcmp(enPassantWhite,destination) == 0){
          enPassantWhite = NULL;
          return from;
        }
      } else{
        // not valid move
        return NULL;
      }
    }
  }
};

char * PawnsManager::checkPromotedCandidates(bool cbState[][8], bool turn, const char * promoType, const char * from){
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
      if(from != NULL && checkSource(from)){
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

bool checkDirection(bool turn, const char * from, const char * destination){
  if(turn){   // if move black
    if(destination[1] - pawns[turn][i].getPosition()[1])) < 0){
      return false;
    }
    return true;
  } else {    // if move white
    if(destination[1] - pawns[turn][i].getPosition()[1])) > 0){
      return true;
    }
    return false;
  }
}

bool checkSource(bool turn, const * from){
  // control if actually a pawn of the player occupy the position expressed by the variable from
  for(int i = 0; i < 8; i++){
    if(strcmp(from,pawns[turn][i].getPosition()) == 0){
      return true;
    }
  }
  return false;
}

virtual bool checkPathIsFree(bool cbState[][8], const char * from, const char * destination){
  // consider the parameters from and destination as points (from = (xf,yf), destination = (xd,yd))
  // note that the case of en passant is not considered because the control is already performed
  // in the main function through the variable enPassantWhite (or enPassantBlack)

  // auxiliary variables
  // calculate the vertical difference yd - yf
  int vDiff = destination[1] - from[1];
  // calculate the horizontal difference xd - xf
  int hDiff = destination[0] - from[0];
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int row = destination[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int col = destination[1] - 49;

  if(abs(vDiff) <= 1 && abs(hDiff) <= 1){  // one-step forward (ordinary case) or diagonal movement
    // verify if the destination cell busy by another piece
    if(cbState[row][column]){
      // if the one-step movement is performed in vertical, the destination cell must be empty
      if(hDiff == 0 && abs(vDiff) == 1){
        return true;
      } else{
        return false;
      }
    } else{
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
    if(cbState[rowForward][colForward] && cbState[row][col]){
      return true;
    } else{
      return false;
    }
  }
  return false;
};
