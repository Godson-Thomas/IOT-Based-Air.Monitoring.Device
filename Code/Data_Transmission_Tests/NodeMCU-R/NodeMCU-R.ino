#include <SoftwareSerial.h>
SoftwareSerial fromUNO1(D4, D5); //Rx, Tx
SoftwareSerial fromUNO2(D2, D3); //Rx, Tx
String data1;
String data2;
void setup()

{
  Serial.begin(9600);
  fromUNO1.begin(9600);
  fromUNO2.begin(9600);
}


void loop()
{
  if (fromUNO1.available())
  {
     data1 = fromUNO1.readStringUntil('\n');
    Serial.print(data1);
    Serial.print('\n');
    Serial.print("ok");
    Serial.print('\n');
    if (data1=="7"){
      Serial.print("1st");
      Serial.print('\n');
   }

if (fromUNO2.available())
  {
     data2 = fromUNO2.readStringUntil('\n');
    Serial.print(data2);
    Serial.print('\n');
    Serial.print("Bling");
    Serial.print('\n');
    if (data2=="7"){
      Serial.print("2nd");
      Serial.print('\n');
   }
  }

   
  }

  
}
