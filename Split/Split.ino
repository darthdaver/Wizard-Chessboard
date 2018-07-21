#include <SoftwareSerial.h>

boolean command = true;

int rxPin = 3;
int txPin = 2;
SoftwareSerial BT(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Inizializzazione completata!");
  Serial.println();
}

void loop(){ 
  // Speech to text auxiliary variables
  boolean command = true;
  String voice;
  String playerMove[10];

  /* Speech recognition phase */
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
    delay(1000);
  }

  /* Split phase: if the string obtained from the previous recognition phase
   * is not a empty string, it is splitted in order to analyze the words contained in it
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
  delay(1000);
}
