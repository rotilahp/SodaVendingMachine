#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 2, 16); 

void setup()
{
    lcd.begin();
    lcd.clear();
    lcd.print("Hello fixduino!");

    // go to row 1 column 0, note that this is indexed at 0
    lcd.setCursor(0,1); 
    lcd.print ("LCD I2C by ESP32");
}

void loop(){}
