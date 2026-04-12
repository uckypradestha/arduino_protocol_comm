#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int jedaWaktu = 300; // ubah angka ini untuk mengatur kecepatan scroll
const int lebarLCD = 16;   // jumlah kolom LCD

// teks quote dinamis
String quote = "tepuk tangannya kurang semangat, Hidup Jokowi!"; 
String paddedQuote;
int scrollIndex = 0;
int batasAkhir = 0;

void setup() {
  lcd.begin(16, 2);        // inisialisasi lcd
  lcd.clear();             // bersihkan layar
  lcd.setBacklight(HIGH);  // nyalakan lampu latar

  // teks statis di tengah
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");

  // persiapan teks scrolling (membuat 16 spasi otomatis)
  String spasi = "                "; 
  paddedQuote = spasi + quote + spasi;

  // hitung batas akhir scroll di sini agar tidak dihitung berulang kali di loop
  batasAkhir = paddedQuote.length() - lebarLCD;
}

void loop() {
  // ambil potongan teks sesuai lebar layar
  String displayText = paddedQuote.substring(scrollIndex, scrollIndex + lebarLCD);

  // tampilkan di baris bawah
  lcd.setCursor(0, 1);
  lcd.print(displayText);

  // geser indeks
  scrollIndex++;

  // reset jika sudah di ujung batas
  if (scrollIndex > batasAkhir) {
    scrollIndex = 0;
  }

  // jeda kecepatan scrolling
  delay(jedaWaktu); 
}