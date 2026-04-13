#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String text = "                Ini contoh scrolling text I2C!                ";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  // Baris atas (statis)
  lcd.setCursor(3, 0);
  lcd.print("H1H024010");
}

void loop() {
  for (int i = 0; i < text.length() - 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(text.substring(i, i + 16)); 

    delay(200);
  }
}