#define solenoidSignal 7
#define SECOND 1000

void setup() {
  pinMode(solenoidSignal, OUTPUT);
}

void loop() {
    digitalWrite(solenoidSignal, HIGH);
    delay(20*SECOND);
    digitalWrite(solenoidSignal, LOW);
    delay(2*SECOND);
}
