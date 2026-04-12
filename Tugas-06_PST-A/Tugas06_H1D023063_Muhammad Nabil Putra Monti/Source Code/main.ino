#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD I2C
Adafruit_LiquidCrystal lcd(0);

// Judul statis dan pesan dinamis
const String staticTitle = "QUOTE";
String message = "Disiplin adalah kunci dari kesuksesan. - (Nabil)";

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

  // Menghitung posisi tengah secara otomatis untuk baris [0]
  int center = (16 - staticTitle.length()) / 2;
  lcd.setCursor(center, 0);
  lcd.print(staticTitle);
  
  // Menambahkan 16 spasi di awal agar teks benar-benar muncul dari kanan
  String padding = "                "; 
  message = padding + message + padding;
}

void loop() {
  // Logika sliding window: mengambil potongan string sepanjang 16 karakter
  for (int pos = 0; pos <= message.length() - 16; pos++) {
    lcd.setCursor(0, 1);
    
    // Mengambil "jendela" teks sebanyak 16 karakter dari posisi 'pos'
    String displayPart = message.substring(pos, pos + 16);
    
    lcd.print(displayPart);
    
    delay(250); // Kecepatan scroll
  }
}