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
    // Auxiliary variable
    String temp;

    // Transform voice in a string in lowercase characters to avoid misunderstanding
    voice.toUpperCase();

    // Split of the first word
    temp = String(strtok(voice.c_str(), " "));

    stack.push(temp);

    //Split the rest of the speech words
    while(temp != NULL){
      temp = String(strtok(NULL," "));

      if(temp != NULL){
        stack.push(temp);
      }
    }

    // Code block for debugging purposes
    //Serial.print("Number of items in the stack:  ");
    //Serial.println(stack.count());
    //Serial.println("List of the items:");

    //while(!stack.isEmpty()){
      //Serial.println(stack.pop());
    //}
  }

  /*
   *  Command interpretation and move execution phase
   *  Analysis of the single words splitted in the previous phase.
   *  If the move is validated, it is performed.
   */
   if(playerMove[0] == "PEDONE"){

    // Auxiliary variables to keep track if the right pawns is found
    boolean pawnsSearch = true;

    if(turn){
      int index = 0;
      while(pawnsSearch && index<8){
        if(pawnFirstMove[index] && (playerMove[2].charAt(1) - chessBoard[index].charAt(1) == 0) && (playerMove[2].charAt(2) - chessBoard[index].charAt(2) == 2)){
          // Check if the route is free and perform move
          if(checkIsFree("PEDONE",chessBoard[index],playerMove[2])){
            performMove(playerMove[2],index);
          }
        } else if (true){

        }
      }
    } else{
      int index = 16;
      while(pawnsSearch && index<24){
        if(pawnFirstMove[index-8] && true){

        }
      }
    }
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


/*
 *  The function activate/deactivate the electromagnet to attract/release the corresponding pawn.
 *  The action is performed giving/removing voltage to the relay connected to the solenoid.
 */
void electromagnet(boolean condition){

  digitalWrite(RELAY,condition);
}


/*
 *  The function check if the destination or an intermediate cell (along the destination route) is free.
 *  Return a boolean value that is true if the path is free, false otherwise.
 */
boolean checkIsFree(String type, String source, String destination){

  int steps_X = int(abs(destination.charAt(1) - source.charAt(1)));
  int steps_Y = int(abs(destination.charAt(2) - source.charAt(2)));
  int dir;

  if(type.equals("PEDONE")){
    dir = angularCoefficient(source,destination);
    walkTheRoute(source,destination,dir);
  } else if(type.equals("TORRE")){

  } else if(type.equals("ALFIERE")){

  } else if(type.equals("CAVALLO")){

  } else if(type.equals("REGINA")){

  } else if(type.equals("RE")){

  }

  return false;
}

/*
 *  The function walk the path from the source to the destination
 *  according to the direction:
 *    - 0 : horizontal
 *    - 1 : vertical
 *    - 2 : oblique
 */
boolean walkTheRoute(String source, String destination, int dir){

  for(int x = )
    for(int x = )
  String intermediateCell = String(playerMove[2].charAt(1));
  intermediateCell.concat(char(playerMove[2].charAt(2)-1));


  int index = 0;

  while(index < 32){
      if(chessBoard[index].equals(destination)){
        return false;
      } else{
        index++;
      }
  }
}


/*
 *  The function activate/deactivate the electromagnet to attract/release the corresponding pawn.
 *  The action is performed giving/removing voltage to the relay connected to the solenoid.
 */
void performMove(String destination, int pieceIndex){
  stepperMovement (false, X_DIR, X_STP, (chessBoard[pieceIndex].charAt(1)-solenoid.charAt(1))*125);
  stepperMovement (true, Y_DIR, Y_STP, (chessBoard[pieceIndex].charAt(2)-solenoid.charAt(2))*125);
  electromagnet(true);
  stepperMovement (false, X_DIR, X_STP, (destination.charAt(1)-solenoid.charAt(1))*125);
}
