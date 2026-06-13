#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// Quote
String quote = "Alon alon asal klakson.";

void setup() {
  // Inisialisasi LCD 16x2
  lcd.begin(16, 2);
  
  lcd.setCursor(5, 0); // Kolom 5, Baris 0
  lcd.print("QUOTE");
}

void loop() {
  // Membuat awalan spasi agar teks muncul dari paling kanan (Kolom 15)
  String padding = "               "; 
  String fullText = padding + quote + padding;

  for (int i = 0; i < fullText.length() - 16; i++) {
    // Set kursor di baris 1
    lcd.setCursor(0, 1);
    
    // Mengambil potongan string sepanjang 16 karakter
    String displayPart = fullText.substring(i, i + 16);
    lcd.print(displayPart);
    
    // Memastikan baris 0 tetap diam
    lcd.setCursor(5, 0);
    lcd.print("QUOTE");
  }
}