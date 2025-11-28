
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

//NECESSARY LIBRARIES
#include <LiquidCrystal_I2C.h>
#include <Wire.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

//SPECIAL CHARACTERS
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

byte frec1[8] = {
  B00000,
  B10111,
  B10101,
  B10101,
  B10101,
  B11101,
  B00000,
};

byte frec2[8] = {
  B00000,
  B11011,
  B01010,
  B01010,
  B01010,
  B01110,
  B00000,
};

byte frec3[8] = {
  B00000,
  B11101,
  B10101,
  B10101,
  B10101,
  B10111,
  B00000,
};

byte frec4[8] = {
  B01110,
  B01010,
  B01010,
  B01010,
  B01010,
  B11011,
  B00000,
};

//DEFAULT VARIABLES NEEDED
int CURRENT_NOTE = 0;
int QUARTER = 250;
int SONGQUAR = 400;
int OCTAVER = 0;
int BUZZER = 10;
int NOTE_COUNTER = 0;
int LAST_M_NOTE = 0;
int OCTAVER_COUNTER = 0;
int LAST_M_OCTAVE = 0;

//BOTONES ESPECIALES
int BOTON_D = 9;
int BOTON_A = 8;
int BOTON_C = 7;

int buttonAfilter = 0;
int buttonBfilter = 0;
int buttonCfilter = 0;
int buttonDfilter = 0;
bool d_toggle = false;
bool a_toggle = false;
bool c_toggle = false;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.createChar(0, single);
  lcd.createChar(1, twoquart);
  lcd.createChar(2, andsym);
  lcd.createChar(3, guion);
  lcd.createChar(4, frec1);
  lcd.createChar(5, frec2);
  lcd.createChar(6, frec3);
  lcd.createChar(7, frec4);
  pinMode(BUZZER, OUTPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(BOTON_D, INPUT_PULLUP);
  pinMode(BOTON_A, INPUT_PULLUP);
  pinMode(BOTON_C, INPUT_PULLUP);
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

  // if (sensor2value < 120) {
  //   OCTAVER = 0;
  //   OCTAVE = "";
  //   OCTAVER_COUNTER = 0;
  //   pinMode(BUZZER, INPUT);
  // } else {
  //   int POTENTIAL_OCTAVE = 0;
  //   String POTENTIAL_OCTAVE_NAME = "";
  //   pinMode(BUZZER, OUTPUT);
  //   if (sensor2value >= 530) {
  //   POTENTIAL_OCTAVE = 1;
  //   POTENTIAL_OCTAVE_NAME = "04";
  //   }
  //   else if (sensor2value >= 330) {
  //   POTENTIAL_OCTAVE = 2;
  //   POTENTIAL_OCTAVE_NAME = "05";
  //   }
  //   else if (sensor2value >= 120) {
  //   POTENTIAL_OCTAVE = 4;
  //   POTENTIAL_OCTAVE_NAME = "06";
  //   }

  //   if (POTENTIAL_OCTAVE == LAST_M_OCTAVE){
  //     OCTAVER_COUNTER += 1;
  //   } else {
  //     OCTAVER_COUNTER = 0;
  //     LAST_M_OCTAVE = POTENTIAL_OCTAVE;
  //   }

  //   if (OCTAVER_COUNTER >= 1) {
  //     OCTAVER = POTENTIAL_OCTAVE;
  //     OCTAVE = POTENTIAL_OCTAVE_NAME;
  //   };
  // }
// possibly rearrange the values needed

  String NOTE = "";
//PITCH CHANGER------------------------------------------------------------------------------------------------------------------------------------//
  if (sensor1value <= 100) {
    NOTE = "";
    pinMode(BUZZER, INPUT);
  } else {
    pinMode(BUZZER, OUTPUT);
    if (sensor1value >= 610) {
      CURRENT_NOTE = NOTE_C4 * OCTAVER;
      NOTE = "C";
    } else if (sensor1value >= 525) {
      CURRENT_NOTE = NOTE_D4 * OCTAVER;
      NOTE = "D";
    } else if (sensor1value >= 440) {
      CURRENT_NOTE = NOTE_E4 * OCTAVER;
      NOTE = "E";
    } else if (sensor1value >= 355) {
      CURRENT_NOTE = NOTE_F4 * OCTAVER;
      NOTE = "F";
    } else if (sensor1value >= 270) {
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

  // if (sensor1value <= 100) {
  //   NOTE = "";
  //   pinMode(BUZZER, INPUT);
  //   NOTE_COUNTER = 0;
  // } else {
  //   pinMode(BUZZER, OUTPUT);
  //   int POTENTIAL_NOTE = 0;
  //   String POTENTIAL_NOTE_NAME = "";
  //   if (sensor1value >= 610) {
  //     POTENTIAL_NOTE = NOTE_C4;
  //     POTENTIAL_NOTE_NAME = "C";
  //   } else if (sensor1value >= 525) {
  //     POTENTIAL_NOTE = NOTE_D4;
  //     POTENTIAL_NOTE_NAME = "D";
  //   } else if (sensor1value >= 440) {
  //     POTENTIAL_NOTE = NOTE_E4;
  //     POTENTIAL_NOTE_NAME = "E";
  //   } else if (sensor1value >= 355) {
  //     POTENTIAL_NOTE = NOTE_F4;
  //     POTENTIAL_NOTE_NAME = "F";
  //   } else if (sensor1value >= 270) {
  //     POTENTIAL_NOTE = NOTE_G4;
  //     POTENTIAL_NOTE_NAME = "G";
  //   } else if (sensor1value >= 185) {
  //     POTENTIAL_NOTE = NOTE_A4;
  //     POTENTIAL_NOTE_NAME = "A";
  //   } else if (sensor1value >= 100) {
  //     POTENTIAL_NOTE = NOTE_B4;
  //     POTENTIAL_NOTE_NAME = "B";
  //   };

  //   if (POTENTIAL_NOTE == LAST_M_NOTE) {
  //     NOTE_COUNTER += 1;
  //   } else {
  //     NOTE_COUNTER = 0;
  //     LAST_M_NOTE = POTENTIAL_NOTE;
  //   };

  //   if (NOTE_COUNTER >= 1) {
  //     CURRENT_NOTE = POTENTIAL_NOTE * OCTAVER;
  //     NOTE = POTENTIAL_NOTE_NAME;
  //   };

  //   tone(BUZZER, CURRENT_NOTE, QUARTER);
  // }
// possibly rearrange the values

//DEFAULT SCREEN REFRESH PRINTER-------------------------------------------------------------------------------------------------------------------//
  lcd.clear();
  lcd.setCursor(1,0);
  lcd.write(1);
  lcd.print("NOTES");
  lcd.write(3);
  lcd.print("OCTAVE");
  lcd.write(0);
  lcd.setCursor(4,1);
  lcd.print(NOTE);
  lcd.setCursor(10,1);
  lcd.print(OCTAVE);
  lcd.setCursor(14,1);
// lcd screen printer

//VALUES PRINTER-----------------------------------------------------------------------------------------------------------------------------------//
  Serial.print("sensor1value: ");
  Serial.print(sensor1value);
  Serial.print('\t');
  Serial.println("NOTE: ");
  Serial.print(NOTE);
  Serial.print('\t');
  Serial.println("sensor2value: ");
  Serial.print(sensor2value);
  Serial.print('\t');
  Serial.println("OCTAVE: ");
  Serial.print(OCTAVE);
// console to read the values

  delay (QUARTER*0.8);

//BOTONES--------------------------------------------------------------------------------------------------------------------------------------------//
//THE SHUTUP BUTTON (A)------------------------------------------------------------------------------------------------------------------------------//
  if (digitalRead(BOTON_A) == LOW) {
    buttonAfilter += 1;
  }

  if (buttonAfilter > 2) {
    a_toggle = !a_toggle;
    buttonAfilter = 0;
  }

  while (a_toggle == true) {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("XXXXX SHUT XXXXX");
    lcd.setCursor(0,1);
    lcd.print("XXXXXX UP XXXXXX");
    pinMode(BUZZER,INPUT);
    delay(200);
  }

//THE DEBUG BUTTON (D)-------------------------------------------------------------------------------------------------------------------------------//
  if (digitalRead(BOTON_D) == LOW){
    buttonDfilter += 1;
  }

  if (buttonDfilter > 2) {
    d_toggle = !d_toggle;
    buttonDfilter = 0;
  }

  while (d_toggle == true) {
    songplayer();
  }

//THE FREQ SHOW BUTTON (C)---------------------------------------------------------------------------------------------------------------------------//
  if (digitalRead(BOTON_C) == LOW){
    buttonCfilter += 1;
  }

  if (buttonCfilter >2) {
    c_toggle = !c_toggle;
    buttonCfilter = 0;
  }

  while (c_toggle == true) {
    freqspecial();
  }


}
//END OF LOOP;;;

//REFERRED FUNCTIONS---------------------------------------------------------------------------------------------------------------------------------//
void songplayer() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("DEBUGGING WITH...");
  lcd.setCursor(0,1);
  lcd.print("Song of Storms");
  lcd.write(0);
  tone(BUZZER, NOTE_D4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4*2, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_D4*2, SONGQUAR*4);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4*2, SONGQUAR*5);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4*2, SONGQUAR/2);
  delay(SONGQUAR/2);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4*2, SONGQUAR/2);
  delay(SONGQUAR/2);
  noTone(BUZZER);
  tone(BUZZER, NOTE_F4*2, SONGQUAR/2);
  delay(SONGQUAR/2);
  noTone(BUZZER);
  tone(BUZZER, NOTE_E4*2, SONGQUAR/2);
  delay(SONGQUAR/2);
  noTone(BUZZER);
  tone(BUZZER, NOTE_C4*2, SONGQUAR/2);
  delay(SONGQUAR/2);
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
  tone(BUZZER, NOTE_F4, SONGQUAR);
  delay(SONGQUAR);
  noTone(BUZZER);
  tone(BUZZER, NOTE_G4, SONGQUAR);
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
  return;
}

void freqspecial() {
  int FREQ = 0;
  int sensor1value = analogRead(A1);


  if (sensor1value <= 100) {
    pinMode(BUZZER, INPUT);
  } else {
    pinMode(BUZZER, OUTPUT);
    if (sensor1value >= 630) {
      CURRENT_NOTE = NOTE_C4;
    } else if (sensor1value >= 545) {
      CURRENT_NOTE = NOTE_D4;
    } else if (sensor1value >= 460) {
      CURRENT_NOTE = NOTE_E4;
    } else if (sensor1value >= 375) {
      CURRENT_NOTE = NOTE_F4;
    } else if (sensor1value >= 290) {
      CURRENT_NOTE = NOTE_G4;
    } else if (sensor1value >= 205) {
      CURRENT_NOTE = NOTE_A4;
    } else if (sensor1value >= 120) {
      CURRENT_NOTE = NOTE_B4;
    }
    tone(BUZZER,CURRENT_NOTE,QUARTER);
  };

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.write(4);
  lcd.print(" FREQ ");
  lcd.write(2);
  lcd.print(" S.NUM ");
  lcd.setCursor(15,0);
  lcd.write(7);
  lcd.setCursor(0,1);
  lcd.print("   ");
  lcd.print(CURRENT_NOTE);
  lcd.print("    ");
  lcd.print(sensor1value);
  delay(200);
}



