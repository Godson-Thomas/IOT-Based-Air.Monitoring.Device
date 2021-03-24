#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
SoftwareSerial fromUNO1(D4, D5); //Rx,Tx
SoftwareSerial fromUNO2(D2, D3); //Rx,TX
 
String tempdata;
String humidata;
String apiKey = "GY7212M4286J1KQE";     //  Enter your Write API key from ThingSpeak
 
const char *ssid =  "I_O";     // replace with your wifi ssid and wpa2 key
const char *pass =  "1.61803399";
const char* server = "api.thingspeak.com";
 

 
WiFiClient client;
 
void setup() 
{
       Serial.begin(9600);
       fromUNO1.begin(9600);
       fromUNO2.begin(9600);
       
       delay(10);
      
 
       Serial.println("Connecting to ");
       Serial.println(ssid);
 
 
       WiFi.begin(ssid, pass);
 
      while (WiFi.status() != WL_CONNECTED) 
     {
            delay(500);
            Serial.print(".");
     }
      Serial.println("");
      Serial.println("WiFi connected");
 
}
 
void loop() 
{
delay(300);
  if (fromUNO1.available() && fromUNO2.available() )
  {
     tempdata = fromUNO1.readStringUntil('\n');
     Serial.print(tempdata);
     Serial.print('\n');
     delay(1000);
     humidata = fromUNO2.readStringUntil('\n');
      Serial.print(humidata);
     Serial.print('\n');
     delay(1000);
delay(1000);
     
    
 
            
 
                         if (client.connect(server,80))   //   "184.106.153.149" or api.thingspeak.com
                      {  
                            
                             String postStr = apiKey;
                             postStr +="&field1=";
                             postStr += tempdata;
                             postStr +="&field2=";
                             postStr += humidata;
                             postStr += "\r\n\r\n";
 
                             client.print("POST /update HTTP/1.1\n");
                             client.print("Host: api.thingspeak.com\n");
                             client.print("Connection: close\n");
                             client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
                             client.print("Content-Type: application/x-www-form-urlencoded\n");
                             client.print("Content-Length: ");
                             client.print(postStr.length());
                             client.print("\n\n");
                             client.print(postStr);
 
                             Serial.print("tempdata: ");
                             Serial.print(tempdata);
                             Serial.print("\nhumidata: ");
                             Serial.print(humidata);
                             
                        }
          client.stop();
 
          Serial.println("\n Senting Data to Thingspeak....");
  
  // thingspeak needs minimum 15 sec delay between updates
  delay(1000);
  }
}
