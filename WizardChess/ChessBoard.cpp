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
#include <StackList.h>

// Constructor
ChessBoard::ChessBoard() {

    // Turn controller inizialization
    turn = true;

    // Solenoid position initialization
    solenoid = "A1";
};

// Stepper movement function implementation
void ChessBoard::stepperMovement (boolean dir, byte dirPin, byte stepperPin, int steps){
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
void ChessBoard::electromagnet(boolean condition){
    digitalWrite(RELAY,condition);
};

// GetTurnPlayer implementation
boolean ChessBoard::getTurnPlayer(){
    return turn;
};
