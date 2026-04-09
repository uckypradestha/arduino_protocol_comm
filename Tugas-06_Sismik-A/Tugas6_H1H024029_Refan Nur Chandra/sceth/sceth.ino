#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);
  
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
   String quote = "                Aku tahu, aku diam.  ";
  
  for (int i = 0; i < quote.length(); i++) {
    lcd.setCursor(0, 1); 
    
    String tampilkan = quote.substring(i, i + 16);
    
    while (tampilkan.length() < 16) {
      tampilkan += " ";
    }
    
    lcd.print(tampilkan);
    delay(100); 
    
  }
}