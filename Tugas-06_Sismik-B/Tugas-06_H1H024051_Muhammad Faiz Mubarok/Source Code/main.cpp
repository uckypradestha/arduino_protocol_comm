#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* quote = "Selamat Berjuang";
const int DELAY = 50;

void setup() {
  lcd.init();
  lcd.backlight();
  delay(500);
  
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}
void loop() {
  int len = strlen(quote);
  
  
  for (int offset = 16; offset >= -len; offset--) {
    lcd.setCursor(0, 1);
    
    lcd.print("                "); 
    
    if (offset >= 0) {
      lcd.setCursor(offset, 1);
      lcd.print(quote);
    } else {
      
      lcd.setCursor(0, 1);
      lcd.print(quote + abs(offset)); 
    }
    delay(200); 
  }
}