#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD pada alamat 0
Adafruit_LiquidCrystal lcd_1(0);

//TEKS QUOTE
String quote = "2,3 Bangtan! Annyeonghaseyo BTS imnida";

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setCursor(5, 0);
  lcd_1.print("QUOTE");
}

void loop() {
  String fullText = "                " + quote + "                ";
  for (int i = 0; i < fullText.length() - 16; i++) {
    lcd_1.setCursor(0, 1);
    lcd_1.print(fullText.substring(i, i + 16));
    delay(15); 
  }
}