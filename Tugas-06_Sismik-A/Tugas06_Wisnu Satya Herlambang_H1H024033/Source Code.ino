#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// deklarasi alamat I2C LCD (Biasanya 0x27 atau 0x20 di Tinkercad)
LiquidCrystal_I2C lcd(0x27, 16, 2); 

// 16 spasi kosong agar teks seolah-olah mulai dari luar layar kanan
String spasi = "                "; 
String isiQuote = "FACE YOUR SINS"; // Silakan ganti kalimatnya

// menggabungkan spasi, quote, dan spasi lagi agar gulungannya mulus
String teksBerjalan = spasi + isiQuote + spasi; 

int posisiScroll = 0; // Penanda urutan huruf

void setup() {
  lcd.init();       // menyalakan LCD
  lcd.backlight();  // menyalakan lampu latar LCD

  // layar memiliki 16 kolom (0-15). kata "QUOTE" ada 5 huruf.
  // agar ke tengah: (16 - 5) / 2 = 5. jadi kita mulai dari kolom 5.
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");
}

void loop() {
  // BARIS 1 (DINAMIS/SCROLLING) ---
  lcd.setCursor(0, 1); 
  
  // mengambil 16 karakter dari teksBerjalan, dimulai dari 'posisiScroll'
  String teksTampil = teksBerjalan.substring(posisiScroll, posisiScroll + 16);
  lcd.print(teksTampil);

  posisiScroll++; // geser ke huruf berikutnya
  
  // jika posisi scroll sudah mencapai ujung teks, ulangi dari awal
  if (posisiScroll > teksBerjalan.length() - 16) {
    posisiScroll = 0;
  }

  delay(300); // kecepatan teks berjalan (semakin kecil semakin cepat)
}