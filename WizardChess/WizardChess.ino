/*
 * WizardChess
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

#include <SoftwareSerial.h>
#include "Config.h"
#include "ChessBoard.h"

// Bluetooth: define software serial
SoftwareSerial BT(BT_RX, BT_TX);

ChessBoard chessBoard;
Bishop bishop;

void setup() {

  // Serial setup
  Serial.begin(9600);

  // Software serial setup
  BT.begin(9600);

  // NEMA 17 pins setup
  pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
  pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
  pinMode (EN, OUTPUT);
  digitalWrite (EN, LOW);

  // RELAY pins setup
  pinMode(RELAY, OUTPUT);

  chessBoard = ChessBoard();
  
  delay(1000);
}

void loop(){
  
  Serial.println("Bishop:");
  chessBoard.bishopsManager.bishops[0][0].toString();
  delay(1000);
  chessBoard.bishopsManager.bishops[0][1].toString();
  delay(1000);
  chessBoard.bishopsManager.bishops[1][0].toString();
  delay(1000);
  chessBoard.bishopsManager.bishops[1][1].toString();
  delay(1000);
  Serial.println();
  Serial.println("Rook:");
  chessBoard.rooksManager.rooks[0][0].toString();
  delay(1000);
  chessBoard.rooksManager.rooks[0][1].toString();
  delay(1000);
  chessBoard.rooksManager.rooks[1][0].toString();
  delay(1000);
  chessBoard.rooksManager.rooks[1][1].toString();
  delay(1000);
  Serial.println();
  Serial.println("Knight:");
  chessBoard.knightsManager.knights[0][0].toString();
  delay(1000);
  chessBoard.knightsManager.knights[0][1].toString();
  delay(1000);
  chessBoard.knightsManager.knights[1][0].toString();
  delay(1000);
  chessBoard.knightsManager.knights[1][1].toString();
  delay(1000);
  Serial.println();
  Serial.println("King:");
  chessBoard.kingsManager.kings[0][0].toString();
  delay(1000);
  chessBoard.kingsManager.kings[1][0].toString();
  delay(1000);
  Serial.println();
  Serial.println("Queen:");
  chessBoard.queensManager.queens[0][0].toString();
  delay(1000);
  chessBoard.queensManager.queens[1][0].toString();
  delay(1000);
  Serial.println();
  Serial.println("Pawn:");
  for(int r = 0; r  < 2; r++){
    for(int c = 0; c < 8; c++){
      chessBoard.pawnsManager.pawns[r][c].toString();
      delay(1000);
    }
  }
}
