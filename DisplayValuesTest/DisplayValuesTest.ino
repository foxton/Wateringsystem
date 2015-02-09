#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int loadCell = A0;
int loadcellValue;
int delayTime = 5000;
void setup() 
{
pinMode(loadCell,INPUT);
  // set up the LCD's number of columns and rows: 
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.clear(); 
 Serial.begin(9600); 
}

void loop() 
{
  loadcellValue = analogRead(loadCell);
   lcd.setCursor(0,0);
  lcd.print("load cell:");
  lcd.println(loadcellValue);
  Serial.println(loadcellValue);
 delay(500);
 lcd.clear();
}

