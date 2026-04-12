#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Alamat I2C biasanya 0x27 atau 0x3F
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Text biar muncul dari kanan
String quote = "                Dihina hina saya tetap sigma                ";

void setup() {
  lcd.init();
  lcd.backlight();

  // Menampilkan "QUOTE" di tengah baris 0
  String title = "QUOTE";
  int posisi = (16 - title.length()) / 2;
  lcd.setCursor(posisi, 0);
  lcd.print(title);
}

void loop() {
  for (int i = 0; i < quote.length() + 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print("                "); // clear baris

    lcd.setCursor(0, 1);

    // ambil substring yang tampil di layar
    String tampil = quote.substring(i, i + 16);
    lcd.print(tampil);

    delay(300);
  }
}
