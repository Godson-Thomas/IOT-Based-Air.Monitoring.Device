#include <Wire.h> // Library for I2C communication
#include <LiquidCrystal_I2C.h> // Library for LCD
#include <SoftwareSerial.h>
#include <SimpleDHT.h>
SoftwareSerial toESP1(0, 1); //Rx, Tx
SoftwareSerial toESP2(12, 13); //Rx, Tx


// for DHT11, 
//      VCC: 5V or 3V
//      GND: GND
//      DATA: 2
int pinDHT11 = 2;
SimpleDHT11 dht11(pinDHT11);

int tonePin = 9;
int fan= 4;
// Wiring: SDA pin is connected to A4 and SCL pin to A5.
// Connect to LCD via I2C, default address 0x27 (A0-A2 not jumpered)
LiquidCrystal_I2C lcd = LiquidCrystal_I2C(0x27, 16, 2); // Change to (0x27,16,2) for 16x2 LCD.

void setup() {
  Serial.begin(9600);
    //MOTOR DECLARATION
    pinMode(fan,OUTPUT);
   // initialize  communication at 9600 bits per second:
   toESP1.begin(9600);
   toESP2.begin(9600);
   
  // Initiate the LCD:
  lcd.init();
  lcd.backlight();
}

void loop() {
  
 // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  delay(1000);

  // read without samples.
  byte temperature = 0;
  byte humidity = 0;
  int err = SimpleDHTErrSuccess;
  if ((err = dht11.read(&temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
    Serial.print("Read DHT11 failed, err="); Serial.println(err);delay(1000);
    return;
  }
  
int temp=(int)temperature;
int humi=(int)humidity;
int tempo=temp;
int humo=humi; 

 toESP1.println(String(tempo));
 Serial.print(tempo);
 Serial.print('\n');
 delay(2000);

 
 lcd.setCursor(0,0);
 lcd.print("TEMP: ");
 lcd.setCursor(5,0);
  lcd.print(String(tempo)+ "*C");
  lcd.setCursor(0,1);
  lcd.print("HUMI: ");
  lcd.print(String(humo)+ "%");


   toESP2.println(String(humo)); 
 Serial.print(humo);
 Serial.print('\n');
 delay(1000);


 
 delay(500);




 //MQ6 Gas Sensor
  
  if (sensorValue>700)
  {
    lcd.setCursor(10,1); //Set the cursor on the third column and the second row (counting starts at 0!).
    lcd.print("SAFE");
    delay(500);
     toESP1.println("LEAK");
     delay(1000);
      Despacito();  
  }
  else{
    lcd.setCursor(10,1); //Set the cursor on the second row (counting starts at 0!).
  lcd.print("SAFE"); 
  delay(500);
  }
  
lcd.clear();

}


void Despacito() {
  
  tone(tonePin, 587, 709.720327982);
  delay(788.578142202);
  digitalWrite(fan, HIGH);
  delay(10.3082110092);
  tone(tonePin, 554, 709.720327982);
  delay(788.578142202);
  digitalWrite(fan, LOW);
  delay(5.15410550459);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, LOW);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, HIGH);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 391, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 391, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 554, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 587, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 440, 412.843850917);
  delay(458.715389908);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, LOW);
  delay(5.15410550459);
  tone(tonePin, 440, 41.7482545872);
  delay(46.3869495413);
  delay(36.0787385321);
  tone(tonePin, 440, 37.109559633);
  delay(41.2328440367);
  digitalWrite(fan, HIGH);
  delay(30.9246330275);
  tone(tonePin, 440, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 587, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  digitalWrite(fan, LOW);
  tone(tonePin, 587, 46.3869495413);
  delay(51.5410550459);
  delay(30.9246330275);
  tone(tonePin, 587, 46.3869495413);
  delay(51.5410550459);
  delay(20.6164220183);
  tone(tonePin, 587, 273.683002294);
  delay(304.092224771);
  digitalWrite(fan, HIGH);
  delay(5.15410550459);
  tone(tonePin, 659, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);

  tone(tonePin, 554, 691.165548165);
  delay(767.961720183);
  delay(314.40043578);
  tone(tonePin, 587, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  tone(tonePin, 554, 552.004699541);
  delay(613.338555046);
  delay(5.15410550459);
  digitalWrite(fan, HIGH);
  tone(tonePin, 493, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 369, 273.683002294);
  delay(304.092224771);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  delay(5.15410550459);
  tone(tonePin, 369, 134.52215367);
  delay(149.469059633);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW);
  digitalWrite(fan, LOW); 
 
}
