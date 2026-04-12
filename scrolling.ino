#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const char* quote = "Kadang prosesnya terasa sulit dan sakit, tapi rencana Allah selalu yang terbaik";
const int DELAY_TIME = 300;

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);

  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  int len = strlen(quote);

  for (int offset = 0; offset < 16 + len; offset++) {

    // kosongkan baris ke-2
    lcd.setCursor(0, 1);
    for (int i = 0; i < 16; i++) {
      lcd.print(" ");
    }

    int startCol = 15 - offset;

    for (int i = 0; i < len; i++) {
      int col = startCol + i;

      if (col >= 0 && col < 16) {
        lcd.setCursor(col, 1);
        lcd.print(quote[i]);
      }
    }

    delay(DELAY_TIME);
  }

  delay(800);
}
