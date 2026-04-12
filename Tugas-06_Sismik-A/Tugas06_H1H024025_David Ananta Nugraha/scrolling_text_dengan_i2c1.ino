#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C layar(0x27, 16, 2); 

String judul = "QUOTE"; 
String teks = "Kesuksesan dimulai dari langkah kecil"; 

// Tambah padding kiri & kanan
String teksPanjang = "                " + teks + "                "; 

unsigned long waktuSebelum = 0;
int posisi = 0;
const int delayScroll = 120; 

void setup() {
  layar.init();
  layar.backlight();
  
  // Center otomatis
  layar.setCursor((16 - judul.length()) / 2, 0); 
  layar.print(judul);
}

void loop() {
  unsigned long waktuSekarang = millis();

  if (waktuSekarang - waktuSebelum >= delayScroll) {
    waktuSebelum = waktuSekarang;

    layar.setCursor(0, 1);

    String potongan = teksPanjang.substring(posisi, posisi + 16);
    layar.print(potongan); 

    posisi++;

    if (posisi > teksPanjang.length() - 16) {
      posisi = 0;
    }
  }
}