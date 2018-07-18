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

    for(int i = 0; i < 8; i++){
        for(int j = 0; i < 8; i++){
            if(j == 0 || j == 1){
                cells[i][j] = new Cell(true,'W');
            } else if(j == 7 || j == 8){
                cells[i][j] = new Cell(true,'B');
            } else{
                cells[i][j] = new Cell(false,'E');
            }
        }
    }
};

// Move function implementation
void ChessBoard::move(Queue <char *> wordsQueue){
    // Auxiliary variables
    bool promotion = false;
    bool errorFlag = false;
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

    // If the piece is a pawn, verify if the move refers to a promoted pawn
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
        // prevents errors if the source is a non valid word
        if(strlen(wordsQueue.front()) == 2){
            from = wordsQueue.dequeue();
        } else {
            errorFlag = true;
        }
        // Superfluous word (preposition)
        wordsQueue.dequeue();
        // prevents errors if the destination is a non valid word
        if(strlen(wordsQueue.front()) == 2){
            destination = wordsQueue.dequeue();
        } else{
            errorFlag = true;
        }
    } else if(wordsQueue.count() == 1){ // ordinary cases
        from = NULL;
        // prevents errors if the destination is a non valid word
        if(strlen(wordsQueue.front()) == 2){
            destination = wordsQueue.dequeue();
        } else{
            errorFlag = true;
        }
    }

    // verify if there is a candidate for the move
    if(strcmp(piece,"PEDINA") == 0 && !errorFlag){
        if(promotion){
            candidate = pawnsManager.checkPromotedCandidates(turn,promoType,from,destination);
            if(candidate != NULL){
                if(promoType == "TORRE"){
                    from = candidate;
                    candidate = rooksManager.checkPromotedCandidates(turn,promoType,from,destination);
                } else if(promoType == "ALFIERE"){
                    from = candidate;
                    candidate = bishopsManager.checkPromotedCandidates(turn,promoType,from,destination);
                } else if(promoType == "CAVALLO"){
                    from = candidate;
                    candidate = knightsManager.checkPromotedCandidates(turn,promoType,from,destination);
                } else if(promoType == "REGINA"){
                    from = candidate;
                    candidate = queensManager.checkPromotedCandidates(turn,promoType,from,destination);
                } else if(promoType == "RE"){
                    from = candidate;
                    candidate = kingsManager.checkPromotedCandidates(turn,promoType,from,destination);
                } 
            }
        } else{
            candidate = pawnsManager.checkCandidates(turn,from,destination);
        }
    } else if(strcmp(piece,"TORRE") == 0 && !errorFlag){
        candidate = rooksManager.checkCandidates(cbState, turn,from,destination);
    } else if(strcmp(piece,"ALFIERE") == && !errorFlag){
        candidate = bishopsManager.checkCandidates(cbState, turn,from,destination);
    } else if(strcmp(piece,"CAVALLO") == && !errorFlag){
        candidate = knightsManager.checkCandidates(cbState, turn,from,destination);
    } else if(strcmp(piece,"REGINA") == && !errorFlag){
        candidate = queensManager.checkCandidates(cbState, turn,from,destination);
    } else if(strcmp(piece,"RE") == && !errorFlag){
        candidate = kingsManager.checkCandidates(cbState, turn,from,destination);
    }

    // if there is a candidate, perform the move
    if(candidate != NULL){
      // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
      int row = destination[0] - 65;
      // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
      int col = destination[1] - 49;
      // verify if a piece must be transported to the cemetery
      if(cbState[row][col].getColor() == 'D'){
        // switch on alert led for 5s

        removeDead(destination, row, col);
      }

      // switch on alert led for 5s
      performMove(piece, candidate, destination);

      // Update state of the game
      updateState(candidate, destination);
    } else{
        Serial.println("Invalid move! Try again!");
    }

    Serial.println();
    Serial.println(piece + " moved from " + candidate + "to " + destination " succesfully executed.");
    Serial.println();
    toString();
};

void ChessBoard::performMove(char type, char * from, char * to) {
  // transport the electromagnet in the cell where is positioned the piece that has to be moved
  direct("A1", from);
  
  // for all the pieces different from the knight
  if(type != 'H'){
        // transport the piece to the destination cell through the navigate function
    if (navigate(from, to) == true) {
        // report the electromagnet to the default position (A1)
        direct(to, "A1");
    } else {
        // executed only in case of error: bring back the electromagnet to the default position (A1)
        direct(from, "A1");
    }
  } else{       // in case of knight move
        //implement all the cases
  }
};

// Navigate funtion implementation
bool ChessBoard::navigate(char * from, char * to) {
  // power up the CNC board
  digitalWrite (POWER_CNC, HIGH);
  //power up the magnet
  digitalWrite (POWER_MAGNET, HIGH);

  // wait the board to power up
  delay(1000);

  // es: navigate from A1 to C3
  bool dirX = to[0] > from[0]; // es: C > A --> true
  bool dirY = to[1] < from[1]; // es: 3 > 1 --> true
  // es: navigate from A1 to C3
  int deltaX = abs(to[0] - from[0]);  // es: C - A = 2
  int deltaY = abs(to[1] - from[1]);  // es: 3 - 1 = 2

  if (deltaX == deltaY) {
    // diagonal
    for (int i = 0; i < deltaX * STEPS/5; i++) {
      step (dirX, X_DIR, X_STP, 5);
      step (dirY, Y_DIR, Y_STP, 5);
    }
  } else {
    if (deltaX * deltaX == 0) {     // horizontal or vertical move
      step (dirX, X_DIR, X_STP, STEPS * deltaX);
      step (dirY, Y_DIR, Y_STP, STEPS * deltaY);
    } else {      // move not valid
      // switch off the electromagnet
      digitalWrite (POWER_MAGNET, LOW);
      return false;
    }
  }

  // wait the CNC to finish
  delay(500);

  //power off the electromagnet
  digitalWrite (POWER_MAGNET, LOW);
  //power off the CNC board
  digitalWrite (POWER_CNC, LOW);

  return true;
};

// Direct function implementation
void ChessBoard::direct(char * from, char * to) {
  // power up the CNC board
  digitalWrite (POWER_CNC, HIGH);

  // wait the board to power up
  delay(1000);

  // es: navigate from A1 to C3
  bool dirX = to[0] > from[0]; // es: C > A --> true
  bool dirY = to[1] < from[1]; // es: 3 > 1 --> true
  // es: navigate from A1 to C3
  int deltaY = abs(to[0] - from[0]);  // es: C - A = 2
  int deltaY = abs(to[1] - from[1]);  // es: 3 - 1 = 2

  step (dirX, X_DIR, X_STP, STEPS * deltaY);
  step (dirY, Y_DIR, Y_STP, STEPS * deltaY);

  // wait the CNC to finish
  delay(500);

  //power off the CNC board
  digitalWrite (POWER_CNC, LOW);
};

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

// Remove dead implementation
void ChessBoard::removeDead(char * destination, int row, int col){
    if(cbState[row][col].getPiece() == 'P'){
      pawnsManager.finAndRemove();
    } else if(cbState[row][col].getPiece() == 'R'){
      rooksManager.finAndRemove();
    } else if(cbState[row][col].getPiece() == 'B'){
      bishopsManager.finAndRemove();
    } else if(cbState[row][col].getPiece() == 'H'){
      knightsManager.finAndRemove();
    } else if(cbState[row][col].getPiece() == 'Q'){
      queensManager.finAndRemove();
    } else if(cbState[row][col].getPiece() == 'K'){
      kingsManager.finAndRemove();
    }

    cbState[row][col].setBusy();
    cbState[row][col].setColor('E');
    cbState[row][col].setPiece('E');

    // implementation of the algorithm to remove the piece

    // led signal to indicate the removal of the piece

};

// Update State function implementation
void ChessBoard::updateState(const char * oldPosition, const char * newPosition) {
  // update position of the piece on the ChessBoard
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int rowOld = oldPosition[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int colOld = oldPosition[1] - 49;
  // 'A' corresponds to 65 - 65 = 0, 'B' to 66 - 65 = 1, 'C' to 67 - 65 = 2, etc.
  int rowNew = newPosition[0] - 65;
  // '1' corresponds to 49 - 49 = 0, '2' to 50 - 49 = 1, etc.
  int colNew = newPosition[1] - 49;

  // set the old position to empty
  cbState[rowOld][colOld].setBusy();
  // set the new position to busy
  cbState[rowNew][colNew].setBusy();
  
  // change the turn of the player
  setTurnPlayer();
};

// SetTurnPlayer function implementation
void ChessBoard::setTurnPlayer(){
    turn = !turn;
};

void toString(){
    Serial.println();
    Serial.println("--- Game State ---");
    Serial.println();
    Serial.print("Turn : ");
    Serial.println(turn);
    Serial.println();
    Serial.println("Chessboard : ");
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Serial.println("Cell   : ");
            Serial.print(char(i + 65));
            Serial.println(char(j + 48));
            Serial.println(cbState[i][j].toString());
        }
    }
    Serial.println();

    pawnsManager.toString();
};