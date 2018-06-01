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

  pawns[WHITE_PAWN][0] = Pawn::Pawn("A2");
  pawns[WHITE_PAWN][1] = Pawn::Pawn("B2");
  pawns[WHITE_PAWN][2] = Pawn::Pawn("C2");
  pawns[WHITE_PAWN][3] = Pawn::Pawn("D2");
  pawns[WHITE_PAWN][4] = Pawn::Pawn("E2");
  pawns[WHITE_PAWN][5] = Pawn::Pawn("F2");
  pawns[WHITE_PAWN][6] = Pawn::Pawn("G2");
  pawns[WHITE_PAWN][7] = Pawn::Pawn("H2");
  pawns[BLACK_PAWN][0] = Pawn::Pawn("A7");
  pawns[BLACK_PAWN][1] = Pawn::Pawn("B7");
  pawns[BLACK_PAWN][2] = Pawn::Pawn("C7");
  pawns[BLACK_PAWN][3] = Pawn::Pawn("D7");
  pawns[BLACK_PAWN][4] = Pawn::Pawn("E7");
  pawns[BLACK_PAWN][5] = Pawn::Pawn("F7");
  pawns[BLACK_PAWN][6] = Pawn::Pawn("G7");
  pawns[BLACK_PAWN][7] = Pawn::Pawn("H7");
};

// checkCandidates implementation
char * PawnsManager::checkCandidates(boolean turn, const char * from, const char * destination){
  int numCandidates = 0;
  int indexCandidate;
  char * candidatePosition[3];
  boolean removeEnpassant = false;

  if(from == NULL){
    for(int i = 0; i < 8; i++){
      if(destination[0] - pawns[abs(turn - 1)][i].getPosition()[0]) == 0 &&
            (destination[1] - pawns[abs(turn - 1)][i].getPosition()[1]) == 1){
              if(/*check path is free*/){
                numCandidates++;
                indexCandidate = i;
                strcpy(candidatePosition,pawns[abs(turn - 1)][i].getPosition());
              }
              if(turn){
                strcpy(enPassantBlack, NULL);
              } else{
                strcpy(enPassantWhite, NULL);
              }
      } else if(pawns[abs(turn - 1)][i].getFirstMove() && (destination[0] - pawns[abs(turn - 1)][i].getPosition()[0]) == 0 &&
            (destination[1] - pawns[abs(turn - 1)][i].getPosition()[1]) == 2){
              if(/*check path is free*/){
                numCandidates++;
                indexCandidate = i;
                strcpy(candidatePosition,pawns[abs(turn - 1)][i].getPosition());
                if(turn){
                  strcpy(enPassantWhite, destination);
                } else{
                  strcpy(enPassantBlack, destination);
                }
              }
      } else if(pawns[abs(turn - 1)][i].getFirstMove() && abs(destination[0] - pawns[abs(turn - 1)][i].getPosition()[0]) == 1 &&
            (destination[1] - pawns[abs(turn - 1)][i].getPosition()[1]) == 1){
              if(/* NOT check path is free*/){
                numCandidates++;
                indexCandidate = i;
                strcpy(candidatePosition,pawns[abs(turn - 1)][i].getPosition());
              }
              if(turn){
                strcpy(enPassantBlack, NULL);
              } else{
                strcpy(enPassantWhite, NULL);
              }
      } else if(turn && enPassantBlack != NULL && abs(destination[0] - pawns[abs(turn - 1)][i].getPosition()[0]) == 1 &&
              (destination[1] - pawns[abs(turn - 1)][i].getPosition()[1]) == 0){

        if(strcmp(enPassantBlack,destination) == 0){
          numCandidates++;
          indexCandidate = i;
          strcpy(candidatePosition,pawns[abs(turn - 1)][i].getPosition());
          removeEnpassant = true;
        }
      } else if(!turn && enPassantWhite != NULL && abs(destination[0] - pawns[abs(turn - 1)][i].getPosition()[0]) == 1 &&
              (destination[1] - pawns[abs(turn - 1)][i].getPosition()[1]) == 0){

        if(strcmp(enPassantWhite,destination) == 0){
          numCandidates++;
          indexCandidate = i;
          strcpy(candidatePosition,pawns[abs(turn - 1)][i].getPosition());
          removeEnpassant = true;
        }
      }
    }

    if(numCandidates == 1){
      pawns[abs(turn - 1)][indexCandidate].setFirstMove();
      pawns[abs(turn - 1)][indexCandidate].setPosition(destination);

      if (turn && removeEnpassant) {
        enPassantBlack = NULL;
      } else if (!turn && removeEnpassant){
        enPassantWhite = NULL;
      }

      return candidatePosition;
    } else {
      return NULL;
    }
  }
};

char * PawnsManager::checkPromotedCandidates(boolean turn, const char * promotion, const char * from, const char * destination){

  QueueArray <int> queue;
  queue.push(0);

  return queue;
};
