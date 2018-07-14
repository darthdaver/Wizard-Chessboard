/*
 * ChessBoard class implementation
 *
 * Copyright (c) 2018 Davide Molinelli.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 *
 * This program is distributed in the   hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ChessBoard.h"
#include "Config.h"

// Constructor
ChessBoard::ChessBoard() {
    // Turn controller inizialization (start the white player - WHITE --> 0)
    turn = false;
};

// Move function implementation
void move(Queue <char *> wordsQueue){
    // Auxiliary variables
    bool promotion = false;
    char * promoType = new char[8];
    char * from = new char[3];
    char * destination = new char[3];
    char * candidate = new char[3];

    /*
     *  Command interpretation and move execution phase
     *  Analysis of the single words splitted in the previous phase.
     *  If the move is validated, it is performed.
     */
    char * piece = wordsQueue.dequeue();

    if(strcmp(piece,"PEDINA") == 0){
        if(wordsQueue.count() == 5 || (wordsQueue.count() == 3 && wordsQueue.front() == "TORRE" ||
                wordsQueue.front() == "CAVALLO" || wordsQueue.front() == "ALFIERE" || wordsQueue.front() == "REGINA")){
            promoType = wordsQueue.dequeue());
            promotion = true;
        } else if(){
            promoType = wordsQueue.dequeue();
            promotion = true;
        }
    }

    // Superfluous word (preposition)
    wordsQueue.dequeue();

    // Analyze the cases
    if (wordsQueue.count() == 3){       // ambiguous cases
        from = wordsQueue.dequeue();
        // Superfluous word (preposition)
        wordsQueue.dequeue();
        destination = wordsQueue.dequeue();
    } else if(wordsQueue.count() == 1){ // ordinary cases
        from = NULL;
        destination = wordsQueue.dequeue();
    }

    if(strcmp(piece,"PEDINA") == 0){
        if(promotion){
            candidate = pawnsManager.checkPromotedCandidates(chessBoard.getTurnPlayer(),promotion,from,destination);
        } else{
            candidate = pawnsManager.checkCandidates(chessBoard.getTurnPlayer(),from,destination);
        }
    } else if(strcmp(piece,"TORRE") == 0){
        candidate = rooksManager.checkCandidates(chessBoard.getTurnPlayer(),from,destination);
    } else if(strcmp(piece,"ALFIERE") == 0){
        candidate = bishopsManager.checkCandidates(chessBoard.getTurnPlayer(),from,destination);
    } else if(strcmp(piece,"CAVALLO") == 0){
        candidate = knightsManager.checkCandidates(chessBoard.getTurnPlayer(),from,destination);
    } else if(strcmp(piece,"REGINA") == 0){
        candidate = queensManager.checkCandidates(chessBoard.getTurnPlayer(),from,destination);
    } else if(strcmp(piece,"RE") == 0){
        candidate = kingsManager.checkCandidates(chessBoard.getTurnPlayer(),from,destination);
    }
}   

// Stepper movement function implementation
void ChessBoard::stepperMovement (bool dir, byte dirPin, byte stepperPin, int steps){
    digitalWrite (dirPin, dir);
    delay (50);

    for (int i = 0; i < steps; i++) {
        digitalWrite (stepperPin, HIGH);
        delayMicroseconds (800);
        digitalWrite (stepperPin, LOW);
        delayMicroseconds (800);
    }
};

// Electromagnet function implementation
void ChessBoard::electromagnet(bool condition){
    digitalWrite(RELAY,condition);
};

// GetTurnPlayer function implementation
bool ChessBoard::getTurnPlayer(){
    return turn;
};

// SetTurnPlayer function implementation
void ChessBoard::setTurnPlayer(){
    turn = !turn;
}