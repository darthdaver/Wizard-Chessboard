#include <SoftwareSerial.h>
#include <QueueArray.h>

boolean command = true;

int rxPin = 3;
int txPin = 2;
SoftwareSerial BT(rxPin, txPin);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BT.begin(9600);
}

void loop(){
  // Speech to text auxiliary variables
  boolean command = true;
  int index = 0;
  char voice[256]="";
  QueueArray <char *> queue;

  /* Speech recognition phase */
  while(command){

    // Check if there is an available byte to read
    // Cycle waiting for a communication with the speech source
    while (BT.available()){
      // Delay added to make thing stable
      delay(10);

      // Conduct a serial read
      char c = tolower(BT.read());

      // Add the character read to the speech-to-text string
      voice[index]=c;

      // Set command to false in order to exit from the external cycle
      // (communication with the speech source completed)
      command = false;

      index++;
    }

    /* Split phase: if the string obtained from the previous recognition phase
    * is not a empty string, it is splitted in order to analyze the words contained in it
    * and perform the player move.
    * Each word of the string is stored inside the playerMove array of words (String).
    */
    if (strlen(voice) > 0){
      char * temp = strtok(voice, " ");
      queue.enqueue(temp);

      while(temp != NULL){
        temp = strtok(NULL," ");

        if(temp != NULL){
          queue.enqueue(temp);
        }
      }

      Serial.print("Number of items in the queue:  ");
      Serial.println(queue.count());
      Serial.println("List of the items:");

      while(!queue.isEmpty()){
        Serial.println(String(stack.dequeue()));
      }
    }
  }
}
