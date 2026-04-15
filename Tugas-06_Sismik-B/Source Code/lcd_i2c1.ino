// Memuat library yang diperlukan
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Inisialisasi LCD dengan alamat I2C 0x27, 16 kolom, dan 2 baris.
// Mendeklarasikan kedua baris berisikan teks
String teksAtas = "^_^ ᗢ";
String teksBawah = "                Caroline Polachek - Billions                ";
// Mendeklarasikan variable untuk melacak posisi karakter
int posisi = 0;
void setup()
{
lcd.init(); // Memulai LCD
lcd.backlight(); // Menyalakan backlight LCD
lcd.setCursor(4, 0); // Memposisikan cursor teksAtas berada di kolom atas dan di tengah layar
lcd.print(teksAtas); // Mencetak teksAtas yang sudah dideklarasikan
}

void loop()
{
lcd.setCursor(0, 1); // Memposisikan cursor teksBawah berada di kolom bawah
  lcd.print(teksBawah.substring(posisi, posisi + 16)); // Mencetak teksBawah yang sudah dideklarasikan
  posisi++; // Geser posisi ke karakter berikutnya
  if (posisi > teksBawah.length() - 16) {
    posisi = 0;
  } // Loop jika teks berada di posisi terakhir, akan dikembalikan ke 0 untuk mengulang
  delay(200); // Kecepatan teksBawah berjalan
}