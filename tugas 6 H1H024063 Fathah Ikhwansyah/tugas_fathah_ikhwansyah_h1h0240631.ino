#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); 

void setup() {
  lcd.init(); 
  lcd.backlight(); 
}

void loop() {
  String quote = " Di balik takdir yang pahit, ada hikmah yang manis";
  
  int len = quote.length();
  
  for (int pos = 15; pos >= -len; pos--) {
    
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");
    
    lcd.setCursor(0, 1);
    lcd.print("  "); 
    
    if (pos >= 0) {
      lcd.setCursor(pos, 1);
      lcd.print(quote.substring(0, 16 - pos));
    } else {
      lcd.setCursor(0, 1);
      lcd.print(quote.substring(-pos, -pos + 16));
    }
    
    delay(300); 
  }
}