#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

String quote = "Tidur Dulu Aja";
int posisi = 15;
int indexHuruf = 0;

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);

  // QUOTE di tengah
  lcd_1.setCursor(5, 0);
  lcd_1.print("QUOTE");
}

void loop()
{
  // bersihkan baris kedua
  lcd_1.setCursor(0, 1);
  lcd_1.print("                ");

  // ambil sebagian teks
  String tampil = quote.substring(0, indexHuruf + 1);

  // tampilkan dari kanan
  lcd_1.setCursor(posisi, 1);
  lcd_1.print(tampil);

  delay(300);

  posisi--;
  indexHuruf++;

  // reset jika semua huruf sudah tampil
  if (indexHuruf >= quote.length()) {
    posisi = 15;
    indexHuruf = 0;
  }
}