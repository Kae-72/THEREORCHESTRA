//MAKE A FLOAT FOR EVERY SINGLE NOTE AS A REFERENCE
float C4 =262;
float D4 =294;
float E4 =330;
float F4 =349;
float G4 =392;
float AA4 = 440.0;
float B4 =494;
float D5 =588;
float E5 =659;
float F5 =698;

int buzzer = 11;


void setup() {
  pinMode(buzzer, OUTPUT);
}

void loop() {
  tone(buzzer,D4,1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,F4,1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,D5,4000);
  delay(500);
  noTone(buzzer); 
  
  tone(buzzer,D4,1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,F4,1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,D5,4000);
  delay(500);
  noTone(buzzer);

  tone(buzzer,E5, 3000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,F5,1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,E5, 1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,F5, 1000);
  delay(500);
  noTone(buzzer);

  tone(buzzer,E5, 1000);
  delay(500);
  noTone(buzzer);
  tone(buzzer,E5, 1000);
  delay(500);
  noTone(buzzer);

}
