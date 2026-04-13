#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Teks asli
String teksAsli = "Be a person so kind that even the blind can see it";

// Tambahkan 16 spasi di AWAL dan 16 spasi di AKHIR teks
String teksBerjalan = "                " + teksAsli + "                ";

void setup() {
  lcd.init();
  lcd.backlight();
  
  // Tampilkan teks statis di baris atas
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  // Hitung batas pergeseran (panjang total dikurangi lebar layar)
  int batasGeser = teksBerjalan.length() - 16;
  
  // Lakukan pergeseran dari huruf pertama (0) sampai batas akhir
  for (int i = 0; i <= batasGeser; i++) {
    
    // Potong 16 karakter dari teks panjang, dimulai dari posisi 'i'
    String potonganTeks = teksBerjalan.substring(i, i + 16);
    
    // Tampilkan potongan teks tersebut ke baris bawah
    lcd.setCursor(0, 1);
    lcd.print(potonganTeks);
    
    delay(350); // Kecepatan teks berjalan
  }
}