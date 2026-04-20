#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD dengan alamat I2C 0x27, ukuran 16 kolom x 2 baris
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Teks yang akan ditampilkan sebagai running text
// Ditambahkan spasi di depan dan belakang agar efek masuk dan keluar lebih halus
String text = "                ~Must Be The Water~                ";

void setup() {
  lcd.init();        // Inisialisasi LCD
  lcd.backlight();   // Menyalakan lampu backlight

  // Menampilkan teks statis "QUOTE:" di tengah baris pertama
  lcd.setCursor(5, 0);
  lcd.print("QUOTE:");
}

void loop() {
  // Perulangan untuk menggeser teks (running text)
  for (int i = 0; i < text.length() - 15; i++) {

    // Set kursor di baris kedua (baris pertama index = 1)
    lcd.setCursor(0, 1);

    // Menampilkan 16 karakter (sesuai lebar LCD)
    // substring digunakan agar teks tetap di satu baris
    lcd.print(text.substring(i, i + 16));

    // Delay untuk mengatur kecepatan pergerakan teks
    delay(150);
  }
}