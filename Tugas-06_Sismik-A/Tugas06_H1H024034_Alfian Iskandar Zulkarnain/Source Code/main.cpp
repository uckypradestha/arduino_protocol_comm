// Mengimport library
#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD
Adafruit_LiquidCrystal lcd(0);

// Deklarasi variable
String teksDiam = "OWO SAID:"; 
String teksJalan = "                HI AN TECH AN TECH ASHING                ";

void setup() {
  lcd.begin(16, 2);        
  lcd.clear();       
  lcd.setBacklight(HIGH);   

  int posisiTengah = (16 - teksDiam.length()) / 2;
  
  lcd.setCursor(posisiTengah, 0); 
  lcd.print(teksDiam);            
}

void loop() {
  // Loop ini akan mengambil potongan 16 karakter dari string teksJalan dan menggesernya
  for (int i = 0; i <= teksJalan.length() - 16; i++) {
    lcd.setCursor(0, 1);
    
    // Tampilkan 16 karakter mulai dari indeks ke-i
    lcd.print(teksJalan.substring(i, i + 16));
    
    delay(100); 
  }
}