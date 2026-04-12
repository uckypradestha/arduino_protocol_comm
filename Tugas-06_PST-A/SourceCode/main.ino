#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String top = "QUOTE:";
String bottom = "Tidak perlu kata kata yang penting bukti nyata!";

void setup() {
  // menginisialisasi LCD I2C
  // dan menyalakan backlight
  lcd.init();
  lcd.backlight();

  // menampilkan kata QUOTE: pada tengah lcd
  // panjang 16 = 5 + 6 (text) + 5
  lcd.setCursor(5, 0);
  lcd.print(top);

  // Memberikan 15 spasi di awal agar teks mulai muncul dari kolom paling kanan (indeks 15)
  // Dan 16 spasi di akhir agar teks hilang sepenuhnya ke kiri sebelum mengulang
  bottom = "               " + bottom + "                ";
}

void loop() {
  // melakukan perulangan manual untuk menggerakan text bottom
  // bisa menggunakan fungsi lcd.autoscroll() tetapi akan scrol baris ke [0] dan [1]
  // jadinya menggunakan perulangan manual
  for (int i = 0; i < (bottom.length() - 16); i++) {
    lcd.setCursor(0, 1);

    // Mengambil potongan 16 karakter secara progresif
    lcd.print(bottom.substring(i, i + 16));

    // delay pergeseran text
    delay(250);
  }
}
