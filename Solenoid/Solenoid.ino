#define solenoidSignal 7
#define SECOND 1000

void setup() {
  Serial.begin(9600);
  pinMode(solenoidSignal, OUTPUT);
}

void loop() {
    Serial.println("Accendi");
    digitalWrite(solenoidSignal, HIGH);
    delay(20*SECOND);
    Serial.println("Spegni");
    digitalWrite(solenoidSignal, LOW);
    delay(2*SECOND);
}
