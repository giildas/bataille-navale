#include <Wire.h>

#include <CMPS10.h>

CMPS10 compass;
int b;

void setup(){
  Serial.begin(9600);
}

void loop() {
  Serial.print("b1 ");
  Serial.print( (int)compass.bearing() );
  Serial.print(" p1 ");
  Serial.print( compass.pitch() );
  Serial.print(" r1 ");
  Serial.println( compass.roll() );
  delay(100);
}


  
