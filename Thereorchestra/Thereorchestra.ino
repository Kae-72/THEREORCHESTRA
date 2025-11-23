
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


int buzzer = 10;

void setup() {

  pinMode(buzzer, OUTPUT);
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {

  int sensor1value= analogRead(A0);
  delay(200)

  Serial.print("sensor1value: ");
  Serial.println(sensor1value);

  int OCTAVER = 1;

  if (sensor1value >= 600){
    int CURRENT_NOTE = NOTE_C4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }
  else if (600 > sensor1value >= 517){
    int CURRENT_NOTE = NOTE_D4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }
  else if (517 > sensor1value >= 434){
    int CURRENT_NOTE = NOTE_E4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }

  if (434 > sensor1value >= 351){
    int CURRENT_NOTE = NOTE_F4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }

  if (351 > sensor1value >= 268){
    int CURRENT_NOTE = NOTE_G4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }

  if (268 > sensor1value >= 185){
    int CURRENT_NOTE = NOTE_A4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }

  if (185 > sensor1value >= 102){
    int CURRENT_NOTE = NOTE_B4 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }

  if (102 > sensor1value){
    int CURRENT_NOTE = NOTE_C5 * OCTAVER;
    tone(buzzer, CURRENT_NOTE);
  }

}
