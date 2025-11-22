//MAKE A FLOAT FOR EVERY SINGLE NOTE AS A REFERENCE
float C4 =262;
float D4 =294;
float E4 =330;
float F4 =349;
float G4 =392;
float AA4 = 440.0;
float B4 =494;
float C5 = 524;
float D5 =588;
float E5 =659;
float F5 =698;

int buzzer = 10;

int quatern = 500;


void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {

  // papapaaa papapaaa aahh section 

  tone(buzzer,D4, quatern);
  delay(400);
  noTone(buzzer);
  tone(buzzer,F4, quatern);
  delay(400);
  noTone(buzzer);
  tone(buzzer,D5, quatern*4);
  delay(400);
  noTone(buzzer); 
  
  tone(buzzer,D4,quatern);
  delay(400);
  noTone(buzzer);
  tone(buzzer,F4,quatern);
  delay(400);
  noTone(buzzer);
  tone(buzzer,D5,quatern*4);
  delay(400);
  noTone(buzzer);

  //pipipipi section

  tone(buzzer,E5, quatern*2);
  delay(500);
  noTone(buzzer);
  tone(buzzer,F5,quatern);
  delay(250);
  noTone(buzzer);
  tone(buzzer,E5, quatern);
  delay(250);
  noTone(buzzer);
  tone(buzzer,F5, quatern);
  delay(250);
  noTone(buzzer);

  //bajada section

  tone(buzzer,E5, quatern);
  delay(400);
  noTone(buzzer);
  tone(buzzer,C5, quatern);
  delay(400);
  noTone(buzzer);
  tone(buzzer,A4, quatern*4);
  delay(400);

 //relief section

}
