#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inisialisasi LCD
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Teks dinamis yang ingin ditampilkan
String quote = "Tugas Sistem Mikrokontroler.";

String scrollText = "                " + quote + "                ";

void setup() {
  lcd.init();
  lcd.backlight();
  // Agar posisinya tepat di tengah LCD 
  lcd.setCursor(5, 0);
  lcd.print("TUGAS");
}

void loop() {
  // Looping sebanyak jumlah karakter pada scrollText dikurangi 16
  for (int i = 0; i <= scrollText.length() - 16; i++) {
    
    // Selalu set kursor ke awal baris kedua sebelum mencetak
    lcd.setCursor(0, 1);
    
    // Potong String sepanjang 16 karakter dimulai dari indeks i
    String tampilan = scrollText.substring(i, i + 16);
    
    // Tampilkan potongan teks tersebut ke LCD
    lcd.print(tampilan);
    
    // Kecepatan scrolling
    delay(200);
  }
}