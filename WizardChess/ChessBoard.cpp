/*
 * ChessBoard class implementation.
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

// Constructor
ChessBoard::ChessBoard() {

    // Chessoboard state track initialization
    String chessBoard[32] = {"A2","B2","C2","D2","E2","F2","G2","H2",
                             "A1","B1","C1","D1","E1","F1","G1","H1",
                             "A7","B7","C7","D7","E7","F7","G7","H7",
                             "A8","B8","C8","D8","E8","F8","G8","H8"};
    
    // Elements cemetery space track initialization
    boolean cemetery[32] = {true,true,true,true,true,true,true,true,
                            true,true,true,true,true,true,true,true,
                            true,true,true,true,true,true,true,true,
                            true,true,true,true,true,true,true,true};
    
    // Enpass controller initialization
    boolean pawnFirstMove[16] = {true,true,true,true,true,true,true,true,
                                 true,true,true,true,true,true,true,true};
    
    // Promotion controller initialization
    String pawnPromotion[16] = {"PAWN","PAWN","PAWN","PAWN","PAWN","PAWN","PAWN","PAWN",
                                "PAWN","PAWN","PAWN","PAWN","PAWN","PAWN","PAWN","PAWN"};

    // Turn controller inizialization
    boolean turn;

    // Solenoid position initialization
    String solenoid = "A1";
};

// Stepper movement function implementation
void Chessboard::stepperMovement (boolean dir, byte dirPin, byte stepperPin, int steps){
    digitalWrite (dirPin, dir);
    delay (50);
    
    for (int i = 0; i < steps; i++) {
      digitalWrite (stepperPin, HIGH);
      delayMicroseconds (800);
      digitalWrite (stepperPin, LOW);
      delayMicroseconds (800);
    } 
}

// Electromagnet function implementation
void electromagnet(boolean condition){
    digitalWrite(RELAY,condition);
}

// GetTurnPlayer implementation
boolean getTurnPlayer(){
    return turn;
};

// set the starting angle of the robot with respect to the vertical position
void Kalman::setAngle(float angle) {
    this->angle = angle;
};

float Kalman::getBias() {
  return this->bias;
};

float Kalman::getInnovation() {
  return this->e;
};

