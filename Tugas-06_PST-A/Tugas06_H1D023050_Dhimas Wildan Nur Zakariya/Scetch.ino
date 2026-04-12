#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD pada alamat 0 = Tinkercad I2C
Adafruit_LiquidCrystal lcd(0);

// Kata Mutiara
String pesan = "Habis gelap, Terbitlah terang"; 

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
}

void loop() {
  // 1. Menampilkan "QUOTE" di tengah baris 0 (statis)
  // Total 16 kolom, kata "QUOTE" ada 5 huruf. 
  // posisi kolom ke-5.
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");

  // 2. Logika teks berjalan untuk baris 1 (dinamis)
  // Spasi di depan pesan agar muncul dari paling kanan (kolom 15)
  String tampilan = "               " + pesan + "                ";

  for (int i = 0; i < tampilan.length() - 16; i++) {
    // Tampilkan baris atas agar tidak berkedip
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");

    // Tampilkan potongan teks pada baris 1
    lcd.setCursor(0, 1);
    lcd.print(tampilan.substring(i, i + 16));

    delay(0); // Mengatur kecepatan (semakin kecil semakin cepat)
  }
}
