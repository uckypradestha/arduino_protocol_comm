#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String quote = "Terbentur, Terbentur, Terbentuk";
int textLen;
int pos;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(5, 0);
  lcd.print("QUOTE");

  textLen = quote.length();
  pos = 0;
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("                ");

  for (int col = 15; col >= 0; col--) {
    int charIndex = pos - (15 - col);
    if (charIndex >= 0 && charIndex < textLen) {
      lcd.setCursor(col, 1);
      lcd.print(quote[charIndex]);
    }
  }

  pos++;

  if (pos >= textLen + 16) {
    pos = 0;
    delay(1000);
  }

  delay(300);
}