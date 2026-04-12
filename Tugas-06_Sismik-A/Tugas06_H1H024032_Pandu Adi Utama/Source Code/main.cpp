// Menambahkan library untuk mengontrol LCD I2C
#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD I2C
Adafruit_LiquidCrystal lcd(0);

// Deklarasi teks
String teksStatis = "QUOTE"; // Teks statis
String teksDinamis = "                Bapak Mulyono Raja Tipu-Tipu                "; // Teks dinamis

void setup() {
  lcd.begin(16, 2); // Mengatur LCD ukuran 16 kolom x 2 baris
  lcd.clear(); // Mengosongkan tampilan LCD saat dinyalakan
  lcd.setBacklight(HIGH); // Menyalakan lampu backlight LCD

// Mengatur posisi tengah untuk teks "QUOTE"
  int posisiTengah = (16 - teksStatis.length()) / 2;
  
  lcd.setCursor(posisiTengah, 0); // Mengatur teks agar muncul di tengah baris pertama
  lcd.print(teksStatis);  // Menampilkan teks statis
}

void loop() {
  
  // Looping animasi berjalan dari kanan ke kiri
  for (int i = 0; i <= teksDinamis.length() - 16; i++) {
    lcd.setCursor(0, 1);  // Mengatur teks agar muncul di awal baris kedua
    lcd.print(teksDinamis.substring(i, i + 16)); // Menampilkan teks mulai dari indeks ke-i
    delay(300); // Delay untuk mengatur kecepatan animasi
  }
}
