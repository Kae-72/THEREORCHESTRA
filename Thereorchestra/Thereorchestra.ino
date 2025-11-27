
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
int OCTAVER = 0;
int BUZZER = 10;

//BOTONES ESPECIALES
bool DEBUG = false;
int BOTON_D = 9;


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
  pinMode(BOTON_D, INPUT)
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
  if (DEFAULT) {
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.write(0);
    lcd.print("NOTES");
    lcd.write(4);
    lcd.print("OCTAVE");
    lcd.write(0);
    lcd.setCursor(4,1);
    lcd.print(NOTE);
    lcd.setCursor(10,1);
    lcd.print(OCTAVE);
    lcd.setCursor(14,1);
  };
// lcd screen printer

  delay (QUARTER*0.8);

//BOTONES--------------------------------------------------------------------------------------------------------------------------------------------//
//Debug song/songs (D)-------------------------------------------------------------------------------------------------------------------------------//
 if (digitalWrite(BOTON_D) == HIGH) {
  DEBUG = true
 };

 while (DEBUG = true) {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Song of Storms");
  lcd.write(0);
  lcd.
 };
 


}



