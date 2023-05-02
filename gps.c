#include <TinyGPS++.h>           
#include <SoftwareSerial.h>      

TinyGPSPlus gps;

#define S_RX    7               
#define S_TX    6                

SoftwareSerial SoftSerial(S_RX, S_TX);    

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

float data[4];


void setup() 
{
  Serial.begin(9600);
  SoftSerial.begin(9600);
  
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}
          
void loop()
{
 while (SoftSerial.available() > 0)
 {
    if (gps.encode(SoftSerial.read()))
    {
      if (gps.location.isValid())
      {
          data[0] = 7;
          data[2] = gps.location.lat();
          data[3] = gps.location.lng();
          radio.write(&data, sizeof(data));
        
          break;
      }
      else
      {
        Serial.println("Location Invalid");
			}
    }
 }
}
