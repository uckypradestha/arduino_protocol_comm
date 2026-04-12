#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Isi quote
String teks = "Find what you love and let it kill you -Bukowski.   ";

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();

  // Baris atas
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");
}

void loop() {
  String scrollText = "                " + teks + "                ";

  for (int i = 0; i <= scrollText.length() - 16; i++) {
    // Baris 0 statis
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");

    // Ambil karakter untuk ditampilkan di baris bawah
    lcd.setCursor(0, 1);
    lcd.print(scrollText.substring(i, i + 16));

    delay(200);
  }
}