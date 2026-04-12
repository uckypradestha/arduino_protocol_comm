#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String quote = "nekat dulu aja, ntar juga sampai. ~~azekkk";

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  int pos = (16 - 5) / 2;
  lcd.setCursor(pos, 0);
  lcd.print("QUOTE");
}

void loop() {
  scrollText(quote);
}

void scrollText(String text) {
  String displayText = "                " + text + "                ";

  for (int i = 0; i <= displayText.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(displayText.substring(i, i + 16));

    delay(100); 
  }

  delay(300);
}