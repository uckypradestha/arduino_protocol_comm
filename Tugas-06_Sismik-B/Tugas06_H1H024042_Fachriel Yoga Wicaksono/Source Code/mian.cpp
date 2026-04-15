#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0); //membuat objek LCD dengan alamat I2C 0
String quote = "Jatuh 7 kali bangkit 8 kali"; //teks yang ditampilkan
void setup() {
  lcd.begin(16, 2); //menyiapkan lcd 16x2
  lcd.setBacklight(1); //menyalakan backlight
  lcd.setCursor(5, 0); //posisikan di tengah secara manual
  lcd.print("QUOTE"); //tampilkan "QUOTE" di posisi (5,0)
}

void loop() {
  int panjang = quote.length(); //panjang teks
  // perulangan untuk efek teks berjalan (kanan → kiri)
  for (int i = 15; i >= -panjang; i--) {
    lcd.setCursor(i, 1); //geser posisi teks
    lcd.print(quote); //ini teks yang akan ditampilkan
  }
}
