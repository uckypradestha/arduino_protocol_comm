#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);
String kata = "Jawa adlh kunci";

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
  lcd.setCursor(3, 0);
  lcd.print("Kata-Kata");
}

void loop() {
  int panjang = kata.length();

  for (int i = 15; i >= -panjang; i--) {
    lcd.setCursor(0, 1);

    String baris = "";
    for (int j = 0; j < 16; j++) {
      int idx = j - i;
      if (idx >= 0 && idx < panjang) {
        baris += kata[idx];
      } else {
        baris += " ";
      }
    }

    lcd.print(baris);
  }
}