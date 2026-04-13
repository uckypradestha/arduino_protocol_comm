#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// Menggunakan library Adafruit 
Adafruit_LiquidCrystal lcd(0);

String pesanQuote = "Ilmu itu bukan yang dihafal, tapi yang memberi manfaat";
String teksBerjalan = "                " + pesanQuote + "                "; 

void setup() {
  lcd.begin(16, 2);      
  lcd.setBacklight(1);   

  // Setting baris 0 (statis di tengah)
  lcd.setCursor(5, 0); 
  lcd.print("QUOTE");
}

void loop() {
  // Setting baris 1 (dinamis berjalan dari kanan) 
  for (int i = 0; i <= teksBerjalan.length() - 16; i++) {
    lcd.setCursor(0, 1); 
    lcd.print(teksBerjalan.substring(i, i + 16));
    delay(50); 
  }
}