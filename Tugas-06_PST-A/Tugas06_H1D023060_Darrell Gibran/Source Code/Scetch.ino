#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String header = "QUOTE";
String quote = "setelah gelap terbit terang";

// spasi depan (utk efek masuk)dan spasi blkg (utk efek keluar)
String scrollText = "                " + quote + "                ";

void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  lcd.setCursor(5, 0);
  lcd.print(header);
}

void loop() {
  for (int i = 0; i <= scrollText.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(scrollText.substring(i, i + 16));
  }
}