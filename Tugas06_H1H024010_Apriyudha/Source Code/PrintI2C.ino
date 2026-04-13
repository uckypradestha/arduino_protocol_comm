#include <Adafruit_LiquidCrystal.h>


Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 2);        // Inisialisasi LCD
  lcd.clear();       // Membersihkan tampilan LCD
  lcd.setBacklight(HIGH);   // Menghidupkan lampu latar (backlight)

  // Menampilkan pesan pada LCD
  lcd.setCursor(3, 0);  // Posisi kolom ke-3, baris ke-0
  lcd.print("Apriyudha");

  lcd.setCursor(3, 1);  // Posisi kolom ke-3, baris ke-1
  lcd.print("H1H024010");
}

void loop() {
  
}