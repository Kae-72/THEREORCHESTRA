
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

// const int N = 100;
// int buffer[N];
// int indexBuffer = 0;
// long addup = 0;
// bool full = false;

int CURRENT_NOTE = 0;
int QUARTER = 250;
int OCTAVER = 0;
int BUZZER = 10;

void setup() {

  pinMode(BUZZER, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  Serial.begin(115200);

}

void loop() {

//start of the buffer
  // if (full) {
  //   addup -= buffer[indexBuffer];
  // }

  // buffer[indexBuffer] = sensor1value;

  // addup += sensor1value;

  // indexBuffer = (indexBuffer + 1) % N;

  // if (indexBuffer == 0) {
  //   full = true;
  // }

  // if (full) {
  //   float promedio = addup / (float)N;

  //}
//end of the buffer

  //SENSOR 1 (pitch changer)
  int sensor1value = analogRead(A0);
  //SENSOR 2 (octave changer)
  int sensor2value = analogRead(A1);

  String OCTAVE = "";
//OCTAVE CHANGER----------------------------------------------------------------------------------------------------------------------------------//
  if (sensor2value >= 500) {
    OCTAVER = 1;
    OCTAVE = "4";
  }
  else if (sensor2value >= 300) {
    OCTAVER = 2;
    OCTAVE = "5";
  }
  else if (sensor2value >= 100) {
    OCTAVER = 4;
    OCTAVE = "6";
  }
  else {
    OCTAVER = 0;
    OCTAVE = "NO OCTAVE";
    //CAMBIAR DESPUÉS A VACIO PARA LCD
  } 
// possibly rearrange the values needed

  String NOTE = "";
//PITCH CHANGER----------------------------------------------------------------------------------------------------------------------------------//
  if (sensor1value <= 100) {
    NOTE = "NO NOTE";
    //CAMBIAR DESPUÉS A VACIO PARA LCD
    pinMode(BUZZER, INPUT);
  } else {
    pinMode(BUZZER, OUTPUT);
    if (sensor1value >= 600) {
      CURRENT_NOTE = NOTE_C4 * OCTAVER;
      NOTE = "C";
    } else if (sensor1value >= 517) {
      CURRENT_NOTE = NOTE_D4 * OCTAVER;
      NOTE = "D";
    } else if (sensor1value >= 434) {
      CURRENT_NOTE = NOTE_E4 * OCTAVER;
      NOTE = "E";
    } else if (sensor1value >= 351) {
      CURRENT_NOTE = NOTE_F4 * OCTAVER;
      NOTE = "F";
    } else if (sensor1value >= 268) {
      CURRENT_NOTE = NOTE_G4 * OCTAVER;
      NOTE = "G";
    } else if (sensor1value >= 185) {
      CURRENT_NOTE = NOTE_A4 * OCTAVER;
      NOTE = "A";
    } else if (sensor1value >= 100) {
      CURRENT_NOTE = NOTE_B4 * OCTAVER;
      NOTE = "B";
    }
    tone(BUZZER,CURRENT_NOTE,QUARTER);
  }
// possibly rearrange the values again

  Serial.print("sensor1value: ");
  Serial.println(sensor1value);
  Serial.print('\t');
  Serial.print(NOTE);
  Serial.print('\t');
  Serial.print("sensor2value: ");
  Serial.println(sensor2value);
  Serial.print('\t');
  Serial.print("OCTAVE: ");
  Serial.println(OCTAVE);

  delay (QUARTER*0.8);
}



