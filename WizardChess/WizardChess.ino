
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

#include "Config.h"

// Functions declaration
void stepperMovement (boolean, byte, byte, int);

// Chessoboard state track
String chessBoard[32] = {"a2","b2","c2","d2","e2","f2","g2","h2",
                         "a1","b1","c1","d1","e1","f1","g1","h1",
                         "a7","b7","c7","d7","e7","f7","g7","h7",
                         "a8","b8","c8","d8","e8","f8","g8","h8",};

void setup() {

  // Serial setup
  Serial.begin(9600);
  
  // NEMA 17 pins setup
  pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
  pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
  pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT);
  pinMode (EN, OUTPUT);
  digitalWrite (EN, LOW);

  // RELAY pins setup
  pinMode(RELAY, OUTPUT);
}

void loop(){ 
  // Speech to text auxiliary variables
  boolean command = true;
  String voice;
  String playerMove[10];

  /* 
   *  Speech recognition and speech-to-text translation phase 
   *  Reading of the characters coming from the speech source and received 
   *  via bluetooth communication.
   *  The carachters are stored in the voice variable (String type).
  */
  while(command){
    
    // Check if there is an available byte to read
    // Cycle waiting for a communication with the speech source
    while (Serial.available()){ 
      // Delay added to make thing stable
      delay(10);
      
      // Conduct a serial read
      char c = Serial.read();

      // Add the character read to the speech-to-text string
      voice += c;

      // Set command to false in order to exit from the external cycle
      // (communication with the speech source completed)
      command = false;
    }
  }

  /* 
   * Split phase: if the string obtained from the previous recognition phase
   * is not an empty string, it is splitted in order to analyze the words contained on it
   * and perform the player move.
   * Each word of the string is stored inside the playerMove array of words (String).
   */
   if (voice.length() > 0){

    // Transform voice in a string in lowercase characters to avoid misunderstanding
    voice.toLowerCase();

    // Split of the first 
    playerMove[0] = strtok(voice.c_str(), " ");

    for(int i = 1; i <= 9; i++){
      if(playerMove[i-1] != NULL){
        playerMove[i] = strtok(NULL," ");
      }
    }

    
     // Code block for debugging purposes
      for(int i = 0; i <= 9; i++){
        if(playerMove[i] != NULL){
          Serial.println(playerMove[i]);
        }
      }
  }

  /* 
   *  Command interpretation and move execution phase
   *  Analysis of the single words splitted in the previous phase.
   *  If the move is validated, it is performed.
   */
  
}

// Stepper movement function implementation
void stepperMovement (boolean dir, byte dirPin, byte stepperPin, int steps){
  digitalWrite (dirPin, dir);
  delay (50);
  for (int i = 0; i < steps; i++) {
    digitalWrite (stepperPin, HIGH);
    delayMicroseconds (800);
    digitalWrite (stepperPin, LOW);
    delayMicroseconds (800);
  } 
}
