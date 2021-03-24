#include <SoftwareSerial.h>

SoftwareSerial toESP1(0, 1); //Rx, Tx
SoftwareSerial toESP2(12, 13); //Rx, Tx

void setup()
{
Serial.begin(9600);
  toESP1.begin(9600);
   toESP2.begin(9600);
}

void loop()
{
  int  i = (random(0,10));
  int  j=(random(10,20));
  
  toESP1.println(String(i));
  Serial.print(i);
  Serial.print('\n');
toESP2.println(String(j));
  Serial.print(j);
  delay(1000);
  }
   
