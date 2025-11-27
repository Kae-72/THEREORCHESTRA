
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

#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

byte single[8] = {
  B00000,
  B00110,
  B00100,
  B00100,
  B01100,
  B01100,
  B00000,
};

byte twoquart[8] = {
  B00000,
  B01111,
  B01001,
  B01001,
  B11011,
  B11011,
  B00000,
};

byte andsym[8] = {
  B00100,
  B01010,
  B01010,
  B00100,
  B01010,
  B01010,
  B00101,
};

byte mas[8] = {
  B00000,
  B00000,
  B00100,
  B01110,
  B00100,
  B00000,
  B00000,
};

byte guion[8] = {
  B00000,
  B00000,
  B00000,
  B01110,
  B00000,
  B00000,
  B00000,
};

int CURRENT_NOTE = 0;
int QUARTER = 250;
int SONGQUAR = 400;
int OCTAVER = 0;
int BUZZER = 10;

//BOTONES ESPECIALES
int BOTON_D = 9;
int BOTON_A = 8;

int buttonAfilter = 0;
int buttonBfilter = 0;
int buttonCfilter = 0;
int buttonDfilter = 0;
bool d_toggle = false;
bool songplaying = false;
bool a_toggle = false;
bool SHUT = false;
bool SHUTFILTER = true;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, single);
  lcd.createChar(1, twoquart); 
  lcd.createChar(2, andsym); 
  lcd.createChar(3, mas); 
  lcd.createChar(4, guion);
  pinMode(BUZZER, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(BOTON_D, INPUT_PULLUP);
  pinMode(BOTON_A, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {

//SENSOR 1 (pitch changer)
  int sensor1value = analogRead(A1);
//SENSOR 2 (octave changer)
  int sensor2value = analogRead(A2);

  String OCTAVE = "";
//OCTAVE CHANGER----------------------------------------------------------------------------------------------------------------------------------//
  
  if (sensor2value < 120) {
    OCTAVER = 0;
    OCTAVE = "";
    pinMode(BUZZER, INPUT);
    //CAMBIAR DESPUÉS A VACIO PARA LCD
  } else {
    pinMode(BUZZER, OUTPUT);
    if (sensor2value >= 530) {
    OCTAVER = 1;
    OCTAVE = "04";
    }
    else if (sensor2value >= 330) {
    OCTAVER = 2;
    OCTAVE = "05";
    }
    else if (sensor2value >= 130) {
    OCTAVER = 4;
    OCTAVE = "06";
    }
  } 
// possibly rearrange the values needed

  String NOTE = "";
//PITCH CHANGER------------------------------------------------------------------------------------------------------------------------------------//
  if (sensor1value <= 100) {
    NOTE = "";
    //CAMBIAR DESPUÉS A VACIO PARA LCD
    pinMode(BUZZER, INPUT);
  } else {
    pinMode(BUZZER, OUTPUT);
    if (sensor1value >= 600) {
      CURRENT_NOTE = NOTE_C4 * OCTAVER;
      NOTE = "C";
    } else if (sensor1value >= 500) {
      CURRENT_NOTE = NOTE_D4 * OCTAVER;
      NOTE = "D";
    } else if (sensor1value >= 417) {
      CURRENT_NOTE = NOTE_E4 * OCTAVER;
      NOTE = "E";
    } else if (sensor1value >= 334) {
      CURRENT_NOTE = NOTE_F4 * OCTAVER;
      NOTE = "F";
    } else if (sensor1value >= 251) {
      CURRENT_NOTE = NOTE_G4 * OCTAVER;
      NOTE = "G";
    } else if (sensor1value >= 168) {
      CURRENT_NOTE = NOTE_A4 * OCTAVER;
      NOTE = "A";
    } else if (sensor1value >= 85) {
      CURRENT_NOTE = NOTE_B4 * OCTAVER;
      NOTE = "B";
    }
    tone(BUZZER,CURRENT_NOTE,QUARTER);
  }
// possibly rearrange the values again

//VALUES PRINTER-----------------------------------------------------------------------------------------------------------------------------------//
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
// console to read the values 

//DEFAULT SCREEN REFRESH PRINTER-------------------------------------------------------------------------------------------------------------------//
  
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.write(0);
  lcd.print("NOTES");
  lcd.write(4);
  lcd.print("OCTAVE");
  lcd.write(1);
  lcd.setCursor(4,1);
  lcd.print(NOTE);
  lcd.setCursor(10,1);
  lcd.print(OCTAVE);
  lcd.setCursor(14,1);

// lcd screen printer

  delay (QUARTER*0.8);

//BOTONES--------------------------------------------------------------------------------------------------------------------------------------------//
//SHUTUP button to shut it up(A)----------------------------------------------------------------------------------------------------------------------//
  if (digitalRead(BOTON_A) == LOW) {
    buttonAfilter += 1;
  }

  if (buttonAfilter > 5) {
    a_toggle = !a_toggle;
    buttonAfilter = 0;
  };

  if (buttonAfilter > 5 && SHUTFILTER == true) {
    a_toggle = !a_toggle;
    buttonAfilter = 0;
  };

  if (a_toggle == true){
    SHUT = true;
  };

  if (a_toggle == false){
    SHUT = false;
  };

  while (SHUT == true) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("XXXXX SHUT XXXXX");
    lcd.setCursor(0,1);
    lcd.print("XXXXXX UP XXXXXX");
    pinMode(BUZZER,INPUT);
    delay(200);
    SHUTFILTER = true;
  }

//NEW BUTTON D CODE----------------------------------------------------------------------------------------------//
  if (digitalRead(BOTON_D) == LOW){
    buttonDfilter += 1;
  }

  if (buttonDfilter > 5) {
    d_toggle = !d_toggle;
    buttonDfilter = 0;
  }

  while (d_toggle == true) {
    songplayer();
  }

  Serial.print(buttonDfilter);
  Serial.print(buttonAfilter);
}

//REFERRED FUNCTIONS---------------------------------------------------------------------------------------------------------------------------------//
void songplayer() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DEBUGGING WITH...");
  lcd.setCursor(0,1);
  lcd.print("Song of Storms");
  lcd.write(0);
  tone(BUZZER, NOTE_D4, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4*2, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4*2, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4*2, SONGQUAR*5);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4*2, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4*2, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4*2, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4*2, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_C4*2, SONGQUAR*2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_A4, SONGQUAR*4);
  delay(SONGQUAR*3);
  noTone(BUZZER);
  tone(BUZZER, NOTE_A4, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4, SONGQUAR*3);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_G4, SONGQUAR/2);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_A4, SONGQUAR*4);
  delay(SONGQUAR*3);
  noTone(BUZZER);
  tone(BUZZER, NOTE_A4, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);  
  tone(BUZZER, NOTE_G4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4, SONGQUAR*4);
  delay(SONGQUAR*2);
  noTone(BUZZER);
}



