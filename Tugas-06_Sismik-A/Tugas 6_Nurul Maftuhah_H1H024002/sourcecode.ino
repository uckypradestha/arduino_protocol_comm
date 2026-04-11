#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String teks = "            tetap semangat yaa ";

void setup() {
  lcd.begin(16, 2);

  // QUOTE di tengah
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  for (int i = 0; i < teks.length() - 15; i++) {
    lcd.setCursor(0, 1);

    // tampilkan 16 karakter bergeser
    lcd.print(teks.substring(i, i + 16));

    delay(50);
  }
}