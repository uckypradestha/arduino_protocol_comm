#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* quote = "Da moram živjeti deset tisuća života, uvijek bih izabrala tebe,";
const int DELAY = 300;

void setup() {
  lcd.init();
  lcd.backlight();
  delay(500);
  
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  int len = strlen(quote);
  
  for (int offset = 0; offset < 16 + len; offset++) {
    lcd.setCursor(0, 1);
    for (int i = 0; i < 16; i++) lcd.write(' ');
    
    int startCol = 15 - offset;
    for (int i = 0; i < len; i++) {
      int col = startCol + i;
      if (col >= 0 && col < 16) {
        lcd.setCursor(col, 1);
        lcd.write(quote[i]);
      }
    }
    delay(DELAY);
  }
  delay(800);
}