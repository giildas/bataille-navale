#include <Wire.h>
//boussole
#include <CMPS10.h>
CMPS10 compass;

const String str_f("c ");
String str;


void setup()
{
  Serial.begin(115200);
}

void loop()
{
  str = str_f + compass.bearing_byte();
  Serial.println(str);
  delay(200);
}
