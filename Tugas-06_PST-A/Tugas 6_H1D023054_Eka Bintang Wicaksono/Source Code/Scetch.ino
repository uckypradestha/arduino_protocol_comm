#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  lcd.init();
  lcd.clear();
  lcd.backlight();

  // Screen 1
  lcd.setCursor(2, 0);
  lcd.print("Tugas 6 PST");
  lcd.setCursor(1, 1);
  lcd.print("Eka Bintang W");
  delay(3000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(5, 0);
  lcd.print("QUOTE:");

  String text = "Cape Boleh Nyerah Jangan";
  int x = text.length();

  for (int i = 15; i >= -x; i--) {
    lcd.setCursor(0, 1);
    lcd.print("                "); // clear baris

    if (i >= 0) {
      lcd.setCursor(i, 1);
      lcd.print(text);
    } else {
      lcd.setCursor(0, 1);
      lcd.print(text.substring(-i));
    }

    delay(200);
  }
}