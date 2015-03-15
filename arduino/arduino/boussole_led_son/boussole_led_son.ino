#include <Wire.h>
//boussole
#include <CMPS10.h>
CMPS10 compass;

void setup(){

  Serial.begin(9600);

  //LED
  while(Serial.available()==0);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);

  
}

void loop() {
  Serial.print("b ");
  
  //son
  int sound;
  sound=analogRead(0);   
  
  allumer_led();
  
  Serial.println((int)compass.bearing());
  delay(100);
}

void allumer_led() {
  if (Serial.available()){
    char input = Serial.read();
    switch (input){
      case '1':
        digitalWrite(13, HIGH);
        delay(10);
        break;
      case '0':
        digitalWrite(13, LOW);
        delay(10);
        break;
    }
  }
}
