#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);     
  lcd.clear();      
  lcd.setBacklight(HIGH);   

  lcd.setCursor(2, 0);  
  lcd.print("Hello World!");

  lcd.setCursor(2, 1); 
  lcd.print("NAYLA ZAZKI KIRANI");
}

void loop() {
}
