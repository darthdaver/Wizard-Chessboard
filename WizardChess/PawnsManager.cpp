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
  int numCandidates = 0;
  int indexCandidate;
  char candidatePosition[3];
  bool removeEnpassant = false;

  // ordinary cases without ambiguity
  if(from == NULL){
    for(int i = 0; i < 8; i++){
      if(destination[0] - pawns[turn][i].getPosition()[0]) == 0 &&
            abs((destination[1] - pawns[turn][i].getPosition()[1])) == 1){   // classical move
              // check direction and path is licit
              if(checkDirection(turn, pawns[turn][i].getPosition(), destination) && 
                    checkPathIsFree(pawns[turn][i].getPosition(), destination)){
                numCandidates++;
                indexCandidate = i;
                strcpy(candidatePosition,pawns[turn][i].getPosition());
              }
              if(turn){   // if move white
                strcpy(enPassantBlack, NULL);
              } else{     // if move black
                strcpy(enPassantWhite, NULL);
              }
      } else if(pawns[turn][i].getFirstMove() && (destination[0] - pawns[turn][i].getPosition()[0]) == 0 &&
            abs((destination[1] - pawns[turn][i].getPosition()[1])) == 2){   // double step move
              if(checkDirection(turn, pawns[turn][i].getPosition(), destination) && 
                    checkPathIsFree(pawns[turn][i].getPosition(), destination)){
                numCandidates++;
                indexCandidate = i;
                strcpy(candidatePosition,pawns[turn][i].getPosition());
                if(turn){
                  strcpy(enPassantWhite, destination);
                } else{
                  strcpy(enPassantBlack, destination);
                }
              }
      } else if(pawns[turn][i].getFirstMove() && abs(destination[0] - pawns[turn][i].getPosition()[0]) == 1 &&
            abs((destination[1] - pawns[turn][i].getPosition()[1])) == 1){    // eat the opposing piece
              if(checkDirection(turn, pawns[turn][i].getPosition(), destination) && 
                    !checkPathIsFree(pawns[turn][i].getPosition(), destination)){
                numCandidates++;
                indexCandidate = i;
                strcpy(candidatePosition,pawns[turn][i].getPosition());
              }
              if(turn){
                strcpy(enPassantBlack, NULL);
              } else{
                strcpy(enPassantWhite, NULL);
              }
      } else if(turn && enPassantBlack != NULL && abs(destination[0] - pawns[turn][i].getPosition()[0]) == 1 &&
              (destination[1] - pawns[turn][i].getPosition()[1]) == 0){    // en passant black --> white
        if(strcmp(enPassantBlack,destination) == 0){
          numCandidates++;
          indexCandidate = i;
          strcpy(candidatePosition,pawns[turn][i].getPosition());
          removeEnpassant = true;
        }
      } else if(!turn && enPassantWhite != NULL && abs(destination[0] - pawns[turn][i].getPosition()[0]) == 1 &&
              (destination[1] - pawns[turn][i].getPosition()[1]) == 0){   // en passant white --> black
        if(strcmp(enPassantWhite,destination) == 0){
          numCandidates++;
          indexCandidate = i;
          strcpy(candidatePosition,pawns[turn][i].getPosition());
          removeEnpassant = true;
        }
      }
    }

    if(numCandidates == 1){   // only one candidate
      pawns[turn][indexCandidate].setFirstMove();
      pawns[turn][indexCandidate].setPosition(destination);

      if (turn && removeEnpassant) {
        enPassantBlack = NULL;
      } else if (!turn && removeEnpassant){
        enPassantWhite = NULL;
      }

      return candidatePosition;
    } else {    // more than one candidate: ambiguity!
      return NULL;
    }
  } else{   // manage ambiguous cases
    if(checkSource(turn, from)){
      if(destination[0] - from[0]) == 0 &&
            abs((destination[1] - from[1])) == 1){   // classical move
        if(checkDirection(turn, from, destination) &&
              checkPathIsFree(from,destination)){
          strcpy(candidatePosition, from);
          return candidatePosition;
        }
      } else if(((turn && from[1] == "7") ||  (!turn && from[1] == "2") && (destination[0] - from[0]) == 0 &&
            abs((destination[1] - from[1])) == 2){   // double step move at first move
        if(checkDirection(turn, from, destination) && 
              checkPathIsFree(from, destination))){
          strcpy(candidatePosition, from);
          return candidatePosition;
        }
      } else if(turn && enPassantBlack != NULL && abs(destination[0] - from[0]) == 1 &&
              (destination[1] - from[1]) == 0){   // en passant black --> white
        if(strcmp(enPassantBlack,destination) == 0){
          strcpy(candidatePosition, from);
          return candidatePosition;
        }
      } else if(!turn && enPassantWhite != NULL && abs(destination[0] - from[0]) == 1 &&
              (destination[1] - from[1]) == 0){   // en passant black --> white
        if(strcmp(enPassantWhite,destination) == 0){
          strcpy(candidatePosition, from);
          return candidatePosition;
        }
    } else{
      // not valid move
      return NULL;
    }
  }
};

char * PawnsManager::checkPromotedCandidates(bool turn, const char * promoType, const char * from){
  int numCandidates = 0;
  int indexCandidate;
  char candidatePosition[3];

  // unambiguous cases
  for(int i = 0; i < 8; i++){
    if(strcmp(promoType, pawns[turn][i].getPromotion()) == 0){
      if(from != NULL){
        return from;
      }
      numCandidates ++;
      indexCandidate = i;
    }
  }

  if(numCandidates == 1){
    strcpy(candidatePosition,pawns[turn][indexCandidate].getPosition());
    return candidatePosition;
  } else{
    return NULL;
  }
};

bool checkDirection(bool turn, const char * from, const char * destination){
  if(turn){   // if move black
    if(destination[1] - pawns[turn][i].getPosition()[1])) > 0){
      return false;
    }
    return true;
  } else {    // if move right
    if(destination[1] - pawns[turn][i].getPosition()[1])) > 0){
      return true;
    }
    return false;
  }
}

bool checkSource(bool turn, const * from){
  for(int i = 0; i < 8; i++){
    if(strcmp(from,pawns[turn][i].getPosition()) == 0){
      return true;
    }
  }
  return false;
}

virtual bool checkPathIsFree(const char * from, const char * destination){
  // consider the parameters from and destination as points ( from = (xf,yf), destination = (xd,yd))

  // calculate the vertical difference yd - yf
  vDiff = destination[1] - from[1];
  // calculate the horizontal difference xd - xf
  hDiff = destination[0] - from[0];

  // move the Black player
  if(vDiff == -1 && hDiff == 0){  // one step forward (ordinary case)
    char cell[3] = 
  }
};