#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Setup LCD (alamat 0x27, 16 kolom, 2 baris)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Teks yang akan di-scroll
String quote = "Selamat Berjuang, Sukses.";

// Tambah 16 spasi di awal & akhir untuk efek masuk/keluar dari kanan
String scrollquote = "                " + quote + "                ";

void setup() {
  lcd.init(); // Nyalakan LCD
  lcd.backlight(); // Nyalakan lampu latar
  lcd.setCursor(5, 0); // Kursor di tengah baris 1
  lcd.print("QUOTE"); // Cetak teks statis
}

void loop() {
  // Looping untuk menggeser teks pembacaan
  for (int i = 0; i <= scrollquote.length() - 16; i++) { 
    lcd.setCursor(0, 1); // Kursor selalu di awal baris 2
    String tampilan = scrollquote.substring(i, i + 16); // Ambil 16 karakter saja
    lcd.print(tampilan); // Tampilkan ke LCD
    delay(300); // Kecepatan scroll (0,3 detik)
  }
}
