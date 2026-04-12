#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD I2C (alamat bisa berbeda tergantung device)
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  lcd.init();        // Mengaktifkan LCD
  lcd.backlight();   // Menyalakan lampu latar
}

void loop() {

  // Teks yang akan ditampilkan berjalan
  String text = "Never give up on your dreams, keep going";

  int panjang = text.length();
   // Perulangan untuk menggeser teks dari kanan ke kiri
  for (int posisi = 15; posisi >= -(panjang - 16); posisi--) {

    // Menampilkan judul di tengah (baris pertama)
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");

    // Membersihkan baris kedua sebelum update teks
    lcd.setCursor(0, 1);
    lcd.print("                ");

    // Menentukan bagian teks yang ditampilkan
    if (posisi >= 0) {
      lcd.setCursor(posisi, 1);
      lcd.print(text.substring(0, 16 - posisi));
    } else {
      lcd.setCursor(0, 1);
      lcd.print(text.substring(-posisi, -posisi + 16));
    }

    delay(100); // Mengatur kecepatan pergeseran teks
  }
}