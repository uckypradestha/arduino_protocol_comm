#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);

  String text = "QUOTE";
  int pos = (16 - text.length()) / 2;
  lcd.setCursor(pos, 0);
  lcd.print(text);
}

void loop() {
  String quote = "                One Dream, Tomorrow by Together!                ";

  for (int i = 0; i <= quote.length() - 16; i++) {
    lcd.setCursor(0, 1);

    String tampil = quote.substring(i, i + 16);
    lcd.print(tampil);

    delay(50);
  }
}