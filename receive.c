#include <LiquidCrystal.h>
const int rs = 2, en = 3, d4 = 7, d5 = 6, d6 = 5, d7 = 4;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
RF24 radio(9, 10); // CE, CSN
const byte address[6] = "00001";

int buzzer = 14;

void setup() 
{
    Serial.begin(9600);

    radio.begin();
    radio.openReadingPipe(0, address);
    radio.setPALevel(RF24_PA_MIN);
    radio.startListening();

    lcd.begin(16, 2);
    lcd.print("Welcome");
}

void loop()
{

    if (radio.available()) 
    {
	float buf[4];
	radio.read(&buf, sizeof(buf));

	int a = buf[0];
	int b = buf[1];
	float c = buf[2];
	float d = buf[3];

	if (a == 1)
	{
	    Serial.print("Temperature");  
	    Serial.println(b); 
	    lcd.clear();
	    lcd.setCursor(0, 0);//col,row
	    lcd.print("  Temperature");
	    lcd.setCursor(6, 1);
	    lcd.print(b);
	    lcd.print("C");      
	    if (b > 35){
		digitalWrite(buzzer, HIGH);
	    }        
	}   
	else if (a == 2)
	{
	    Serial.print("Fire Status :");  
	    Serial.println(b); 
	    lcd.clear();
	    lcd.setCursor(0, 0);
	    lcd.print("  Fire Status");
	    lcd.setCursor(0, 1);

	    if (b == LOW){
		lcd.print("     Normal     ");
	    }
	    else{
		lcd.print("    Activate    ");
		digitalWrite(buzzer, HIGH);
	    }
	}  
	else if (a == 3)
	{
	    Serial.print("Sound Status :");  
	    Serial.println(b);
	    lcd.clear();
	    lcd.setCursor(0, 0);
	    lcd.print("  Sound Status  ");
	    lcd.setCursor(0, 1);

	    if (b == LOW){
		lcd.print("     Normal     ");
	    }
	    else{
		lcd.print("    Activate    ");
		digitalWrite(buzzer, HIGH);
	    }
	}  
	else if (a == 4)
	{
	    Serial.print("Motion Status:");  
	    Serial.println(b);
	    lcd.clear();
	    lcd.setCursor(0, 0);
	    lcd.print(" Motion Status ");
	    lcd.setCursor(0, 1);

	    if (b == LOW){
		lcd.print("     Normal     ");
	    }
	    else{
		lcd.print("    Activate    ");
		digitalWrite(buzzer, HIGH);
	    } 
	}
	else if (a == 7)
	{
	    Serial.println("GPS location:");
	    Serial.print("Latitude ");
	    Serial.println(d,4);
	    Serial.print("Longitude ");
	    Serial.println(c,4);

	    lcd.clear();
	    lcd.setCursor(0, 0);
	    lcd.print("Lon : ");
	    lcd.print(d,4);
	    lcd.setCursor(0, 1);
	    lcd.print("Lat : ");
	    lcd.print(c,4);
	}
    }
}
