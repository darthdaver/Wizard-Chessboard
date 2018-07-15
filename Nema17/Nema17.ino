#define EN 8 // stepper motor enable , active low
#define X_DIR 5 // X -axis stepper motor direction control
#define Y_DIR 6 // y -axis stepper motor direction control
#define Z_DIR 7 // z axis stepper motor direction control
#define X_STP 2 // x -axis stepper control
#define Y_STP 3 // y -axis stepper control
#define Z_STP 4 // z -axis stepper control

/*
 * numero step necessari, fai qualche prova, 130 forse sono troppi, 
 * ma le pedine non escono dalle celle e sono comunque distanziate, 
 * quindi lascerei cosi
 */
#define STEPS 130


/*
 * a questo piedino devi connettere il relè che comanda l'accensione
 * della board a 12V
 */
#define POWER_CNC 9

/*
 * a questo piedino devi connettere il relè che comanda l'accessione
 * dell'elettromagnete a 5V
 */
#define POWER_MAGNET 13

/*
// Function : step . function: to control the direction of the stepper motor , the number of steps .
// Parameters : dir direction control , dirPin corresponding stepper motor DIR pin , stepperPin corresponding stepper motor " step " pin , Step number of step of no return value.
*/
void step (boolean dir, byte dirPin, byte stepperPin, int steps)
{
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
 * NB: i segni > e < nel calcolo delle direzioni
 * se un giorno decidi di cambiare il riferimento degli assi
 * devi cambiare anche i segni
 */
bool navigate (char * from, char * to) {

  // power up the CNC board
  digitalWrite (POWER_CNC, HIGH);

  //power up the magnet
  digitalWrite (POWER_MAGNET, HIGH);
  
  // wait the board to power up
  delay(1000);
  
  // es: navigate from A1 to C3
  bool dir_x = to[0] > from[0]; // es: C > A --> true
  bool dir_y = to[1] < from[1]; // es: 3 > 1 --> true

  // es: navigate from A1 to C3
  int delta_x = abs(to[0] - from[0]);  // es: C - A = 2
  int delta_y = abs(to[1] - from[1]);  // es: 3 - 1 = 2

  if (delta_x == delta_y) {
    // diagonal
    for (int i = 0; i < delta_x*STEPS/5; i++) {
      step (dir_x, X_DIR, X_STP, 5);
      step (dir_y, Y_DIR, Y_STP, 5);
    } 
  } else {
    if (delta_x * delta_y == 0) {
      // only one will be executed
      step (dir_x, X_DIR, X_STP, STEPS * delta_x);
      step (dir_y, Y_DIR, Y_STP, STEPS * delta_y);
    } else {
      digitalWrite (POWER_MAGNET, LOW);
      return false;
    }
  }

  // wait the CNC to finish
  delay(500);

  //power off the magnet
  digitalWrite (POWER_MAGNET, LOW);
  
  //power off the CNC board
  digitalWrite (POWER_CNC, LOW);

  return true;
}

/*
 * questa funzione serve per muoversi quando il magnete è spento
 * perchè evita di fare le diagonali e non fa controlli riguardo
 * delta_x e delta_y
 */
void direct  (char * from, char * to) {

  // power up the CNC board
  digitalWrite (POWER_CNC, HIGH);

  // wait the board to power up
  delay(1000);
  
  // es: navigate from A1 to C3
  bool dir_x = to[0] > from[0]; // es: C > A --> true
  bool dir_y = to[1] < from[1]; // es: 3 > 1 --> true

  // es: navigate from A1 to C3
  int delta_x = abs(to[0] - from[0]);  // es: C - A = 2
  int delta_y = abs(to[1] - from[1]);  // es: 3 - 1 = 2

  step (dir_x, X_DIR, X_STP, STEPS * delta_x);
  step (dir_y, Y_DIR, Y_STP, STEPS * delta_y);

  // wait the CNC to finish
  delay(500);

  //power off the CNC board
  digitalWrite (POWER_CNC, LOW);
}


/*
 * questa è la funzione che fa tutto:
 * - manda il magnete in posizione
 * - lo accende
 * - sposta la pendina a destinazione
 * - spegne il magnete
 * - riporta il magnete al punto di partenza
 * 
 * NB: si muove solo in orizzontale/verticale/diagonale
 * la mossa del cavallo non è ancora stata implementata
 */
void move (char * from, char * to) {
  direct("A1", from);
  if (navigate(from, to) == true) {
    direct(to, "A1");
  } else {
    direct(from, "A1");
  }
}

void setup () {
  // used to power the CNC only when needed
  pinMode (POWER_CNC, OUTPUT);
  digitalWrite (POWER_CNC, LOW);

  // used to power the magnet only when needed
  pinMode (POWER_MAGNET, OUTPUT);
  digitalWrite (POWER_MAGNET, LOW);

  // The stepper motor used in the IO pin is set to output
  pinMode (X_DIR, OUTPUT); pinMode (X_STP, OUTPUT);
  pinMode (Y_DIR, OUTPUT); pinMode (Y_STP, OUTPUT);
  pinMode (Z_DIR, OUTPUT); pinMode (Z_STP, OUTPUT);
  pinMode (EN, OUTPUT);
  digitalWrite (EN, LOW);
  
  delay(1000);

  // esempio che muove il pezzo da C3 a E5
  move("C3","E5");
}
void loop () {

  /*
//step (false, X_DIR, X_STP, 3200); // X axis motor reverse 1 ring, the 200 step is a circle.
//delay(1000);
for (int i = 0; i < 1; i++) {
    step (true, Y_DIR, Y_STP,125); // y axis motor reverse 1 ring, the 200 step is a circle.
    step (true, X_DIR, X_STP, 125); // X axis motor reverse 1 ring, the 200 step is a circle.
    delay(500);
} 
delay(1000);
//step (true, X_DIR, X_STP, 3200); // X axis motor forward 1 laps, the 200 step is a circle.
//delay(1000);
for (int i = 0; i < 1; i++) {
    step (false, Y_DIR, Y_STP, 125); // y axis motor forward 1 laps, the 200 step is a circle.
    step (false, X_DIR, X_STP, 125); // X axis motor reverse 1 ring, the 200 step is a circle.
    delay(500);
}
delay(1000);
*/
} 
