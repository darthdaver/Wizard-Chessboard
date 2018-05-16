#include <SoftwareSerial.h>

int rxPin = 3;
int txPin = 2;

SoftwareSerial BT(rxPin, txPin);

String voice;

int greenled = 7; //Connect To Pin #7

int yellowled = 6; //Connect To Pin #6

int redled = 5; //Connect To Pin #5

void allOn(){
  digitalWrite(redled, HIGH);
  digitalWrite(yellowled, HIGH);
  digitalWrite(greenled, HIGH);
}

void allOff(){
  digitalWrite(redled, LOW);
  digitalWrite(yellowled, LOW);
  digitalWrite(greenled, LOW);
}

void setup(){
  Serial.begin(9600);
  BT.begin(9600);
  
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);
}

void loop() {
  //Check if there is an available byte to read
  while (BT.available()){ 
    //Delay added to make thing stable
    delay(10);
    
    //Conduct a serial read
    char c = BT.read();

    //Exit the loop when the # is detected after the word
    if (c == '#'){
      break;
    }
    voice += c;

  }

  if (voice.length() > 0){

    voice.toLowerCase();
    
    Serial.println(voice);

    if(voice == "turn on led"){
      allOn();
    } else if(voice == "turn off led"){
      allOff();
    } else if(voice == "red led on"){
      digitalWrite(redled,HIGH);
    } else if(voice == "yellow led on"){
      digitalWrite(yellowled,HIGH);
    } else if(voice == "green led on"){
      digitalWrite(greenled,HIGH);
    } else if(voice == "red led off"){
      digitalWrite(redled,LOW);
    } else if(voice == "yellow led off"){
      digitalWrite(yellowled,LOW);
    } else if(voice == "green led off"){
      digitalWrite(greenled,LOW);
    }
    //Reset variable
    voice="";
  }
}
