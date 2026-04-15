#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Kalimat utama
String quote = "SHARE OFTEN AND YOU WILL BE LUCKY IN THE FUTURE";

// Fungsi untuk menambahkan spasi di awal & akhir
String buatTeksBerjalan(String teks) {
  String spasi = "                "; // 16 spasi
  return spasi + teks + spasi;
}

String runningText;

void setup() {
  lcd.init();
  lcd.backlight();

  // Inisialisasi teks berjalan
  runningText = buatTeksBerjalan(quote);

  // Judul di atas
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  int panjang = runningText.length();

  // Loop geser teks
  for (int posisi = 0; posisi < panjang - 15; posisi++) {
    
    lcd.setCursor(0, 1);

    // Ambil 16 karakter
    lcd.print(runningText.substring(posisi, posisi + 16));

    delay(350);
  }
}