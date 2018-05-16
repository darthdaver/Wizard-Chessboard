
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

// Functions declaration
void stepperMovement (boolean, byte, byte, int);


// Chessoboard state track
String chessBoard[32] = {"A2","B2","C2","D2","E2","F2","G2","H2",
                         "A1","B1","C1","D1","E1","F1","G1","H1",
                         "A7","B7","C7","D7","E7","F7","G7","H7",
                         "A8","B8","C8","D8","E8","F8","G8","H8"};

// Player turn (true means "move white" - false means "move black")
boolean turn = true;

// Bluetooth: define software serial
SoftwareSerial BT(BT_RX, BT_TX);

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
    while (BT.available()){ 
      // Delay added to make thing stable
      delay(10);
      
      // Conduct a serial read
      char c = BT.read();

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
    voice.toUpperCase();

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
   if(playerMove[0] == "PEDINA"){
    
   } else if(playerMove[0] == "TORRE"){
    
   } else if(playerMove[0] == "ALFIERE"){
    
   } else if(playerMove[0] == "CAVALLO"){
    
   } else if(playerMove[0] == "REGINA"){
   
   } else if(playerMove[0] == "RE"){
    
   } else{
      Serial.println("Command not recognized.");
   }
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

