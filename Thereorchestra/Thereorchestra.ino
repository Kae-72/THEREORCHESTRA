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
  pinMode(A0, INPUT);
  Serial.begin(9600);

}

void loop() {

  int sensor1value= analogRead(A0);

  Serial.print("sensor1value: ");
  Serial.println(sensor1value);

  delay(100);

}
