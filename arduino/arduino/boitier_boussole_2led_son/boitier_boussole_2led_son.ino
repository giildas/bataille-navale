#include <Wire.h>
#define ADDRESS 0x60                                          // Defines address of CMPS10

void setup(){
  Serial.begin(9600);                                   
  Wire.begin();
  while(Serial.available()==0);
  pinMode(13, OUTPUT);
  digitalWrite(13, HIGH);
  pinMode(12, OUTPUT);
  digitalWrite(12, HIGH);
}

void loop(){
  
  allumer_led();
  
  byte highByte, lowByte;              // highByte and lowByte store high and low bytes of the bearing and fine stores decimal place of bearing
  char pitch, roll;                          // Stores pitch and roll values of CMPS10, chars are used because they support signed value
  int bearing;                               // Stores full 
   
  int sound;
   
   Wire.beginTransmission(ADDRESS);           //starts communication with CMPS10
   Wire.write(2);                              //Sends the register we wish to start reading from
   Wire.endTransmission();
  
   Wire.requestFrom(ADDRESS, 4);              // Request 4 bytes from CMPS10
   while(Wire.available() < 4);               // Wait for bytes to become available
   highByte = Wire.read();     
   lowByte = Wire.read();    
   pitch = Wire.read();              
   roll = Wire.read();    
   
   bearing = ((highByte<<8)+lowByte)/10;      // Calculate full bearing
  
   sound=analogRead(0);   
  
   display_data(bearing, sound);  // Display data to the LCD03
   
   delay(100);
}

void display_data(int b, int s){    // pitch and roll (p, r) are recieved as ints instead oif bytes so that they will display corectly as signed values.
  
  
  Serial.print("b ");
  Serial.print(b);
  Serial.print(" s ");
  Serial.println(s,DEC);
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
      case '2':
      digitalWrite(12, HIGH);
      delay(10);
      break;
      case '3':
      digitalWrite(12, LOW);
      delay(10);
      break;
    }
  }
}

