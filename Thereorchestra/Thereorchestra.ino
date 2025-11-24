
//TAKEN FROM THE PITCHES.H
int NOTE_C4 = 262;
int NOTE_D4 = 294;
int NOTE_E4 = 330;
int NOTE_F4 = 349;
int NOTE_G4 = 392;
int NOTE_A4 = 440;
int NOTE_B4 = 494;
int NOTE_C5 = 523;
//NOTES


const int N = 400;
int buffer[N];
int indexBuffer = 0;
long addup = 0;
bool full = false;

int buzzer = 10;

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT)
  Serial.begin(9600);

}

void loop() {

  //SENSOR 1 (pitch changer)
  int sensor1valueAVG = analogRead(A0);

  // if (full) {
  //   addup -= buffer[indexBuffer];
  // }

  // buffer[indexBuffer] = sensor1valueAVG;

  // addup += sensor1valueAVG;

  // indexBuffer = (indexBuffer + 1) % N;

  // if (indexBuffer == 0) {
  //   full = true;
  // }

  // if (full) {
  //   float promedio = addup / (float)N;


  Serial.print("sensor1value average: ");
  Serial.println(sensor1valueAVG);
  //}
  //SENSOR 1 (pitch changer)

  //SENSOR 2 (octave changer)
  int sensor2value = analogRead(A1)

  Serial.print("sensor2value average: ");
  Serial.printIn(sensor2value);
  //SENSOR 2 (octave changer)

  delay(200);

//OCTAVE CHANGER----------------------------------------------------------------------------------------------------------------------------------//
  if (sensor2value >= 500) {
    OCTAVER = 1
    pinMode(buzzer, OUTPUT);
  }
  else if (sensor2value >= 300) {
    OCTAVER = 2
    pinMode(buzzer, OUTPUT);
  }
  else if (sensor2value >= 100) {
    OCTAVER = 4
    pinMode(buzzer, OUTPUT);
  }
  else {
    OCTAVER = 0
    pinMode(buzzer, INPUT);
  } 
// possibly rearrange the values needed

//PITCH CHANGER----------------------------------------------------------------------------------------------------------------------------------//
  if (sensor1valueAVG >= 600) {
    int CURRENT_NOTE = NOTE_C4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else if (sensor1valueAVG >= 517) {
    int CURRENT_NOTE = NOTE_D4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else if (sensor1valueAVG >= 434) {
    int CURRENT_NOTE = NOTE_E4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else if (sensor1valueAVG >= 351) {
    int CURRENT_NOTE = NOTE_F4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else if (sensor1valueAVG >= 268) {
    int CURRENT_NOTE = NOTE_G4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else if (sensor1valueAVG >= 185) {
    int CURRENT_NOTE = NOTE_A4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else if (sensor1valueAVG >= 100) {
    int CURRENT_NOTE = NOTE_B4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  } else {
    noTone(buzzer)
  }

  

}



