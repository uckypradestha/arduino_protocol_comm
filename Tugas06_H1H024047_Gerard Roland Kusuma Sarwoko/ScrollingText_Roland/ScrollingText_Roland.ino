#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String text = "                Kerja keras tidak akan mengkhianati hasil!                ";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  // Baris 0: "QUOTE" statis di tengah
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  for (int i = 0; i < text.length() - 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(i, i + 16));
    delay(10);
  }
}