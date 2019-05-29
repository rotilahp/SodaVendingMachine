/*********
  Address of LCD Screen is 0x27
*********/

#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns =16;
int lcdRows =2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  

void LCDSetup(){
  // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
}

void updateLCD(char x){

  String mystring(x);
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  // print message
  lcd.print("Press # to buy:");
  lcd.setCursor(0,1);
  lcd.print(mystring);
}

void defaultLCDDisplay(){

  String defaultMessage1 = "Daniel's Soda Machine!";
  String defaultMessage2 = "Get yourself a soda today!";
  
  scrollText(0, defaultMessage1, 400, 0);
  scrollText(0, defaultMessage2, 400, 1);
  
}

void scrollText(int row, String message, int delayTime, int lcdColumns) {
  for (int i=0; i < lcdColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int pos = 0; pos < message.length(); pos++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(pos, pos + lcdColumns));
    delay(delayTime);
  }
}

void clearLCD(){
  lcd.clear();
}

void successLCD(){
  // set cursor to first column, first row
  lcd.setCursor(0, 0);
  lcd.print("Thank you for");
  lcd.setCursor(2,1);
  lcd.print("your purchase!");
  delay(2000);
  lcd.clear();

}
