#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Teks quote yang ingin ditampilkan
String quoteAsli = "Tetap Waspada"; 

// Menambahkan 15 spasi kosong di awal agar huruf pertama muncul di ujung kanan (kolom 15)
// dan 15 spasi di akhir agar teks menghilang perlahan ke kiri
String scrollText = "               " + quoteAsli + "               "; 

int posisiScroll = 0; // Variabel untuk melacak posisi pergeseran teks

void setup() {
  lcd.begin(16, 2);        // Inisialisasi LCD
  lcd.clear();             // Membersihkan tampilan LCD
  lcd.setBacklight(HIGH);  // Menghidupkan lampu latar (backlight)

  // -- Kalimat 1 statis "QUOTE" di tengah --
  // Kata "QUOTE" memiliki 5 huruf. Lebar layar 16. (16 - 5) / 2 = 5.5
  // Jadi posisi paling pas di tengah adalah mulai dari kolom 5.
  lcd.setCursor(5, 0);  
  lcd.print("QUOTE");
}

void loop() {
  // -- Kalimat 2 dinamis muncul dari kanan --
  
  // Mengambil potongan teks sebanyak 16 karakter dari scrollText
  String textTampil = scrollText.substring(posisiScroll, posisiScroll + 16);
  
  // Selalu print dari awal baris 1 (karena teksnya yang kita geser, bukan kursornya)
  lcd.setCursor(0, 1);
  lcd.print(textTampil);

  // Geser posisi pembacaan teks 1 karakter ke kanan
  posisiScroll++;

  // Jika teks sudah selesai digeser sampai ujung, kembalikan ke awal
  if (posisiScroll > scrollText.length() - 16) {
    posisiScroll = 0;
  }

  // Waktu jeda (kecepatan scroll). Semakin kecil nilainya, semakin cepat.
  delay(300);
}
