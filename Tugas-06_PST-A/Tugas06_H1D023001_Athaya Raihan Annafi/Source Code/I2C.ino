#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String text = "Tetaplah Hidup";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  lcd.setCursor(5, 0);  
  lcd.print("QUOTES");
}

void loop() {

  int totalLength = text.length() + 32; // 16 kiri + text + 16 kanan

  for (int i = 0; i <= totalLength - 16; i++) {

    lcd.setCursor(0, 1);

    for (int j = 0; j < 16; j++) {

      int index = i + j - 16;

      if (index < 0 || index >= text.length()) {
        lcd.print(" ");
      } else {
        lcd.print(text[index]);
      }
    }

    delay(250);
  }
}