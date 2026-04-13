#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String judul = "QUOTE";
String quoteText = "JANGAN LUPA MAKAN";

const int scrollDelay = 150;

void printCentered(byte row, String text) {
  int col = (16 - text.length()) / 2;
  if (col < 0) col = 0;
  lcd.setCursor(col, row);
  lcd.print(text);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();

  printCentered(0, judul);
}

void loop() {
  String scrollText = "                " + quoteText + "                ";

  for (int i = 0; i <= scrollText.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(scrollText.substring(i, i + 16));

    delay(scrollDelay);
  }
}
