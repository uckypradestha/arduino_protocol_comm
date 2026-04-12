#include <Adafruit_LiquidCrystal.h> 

Adafruit_LiquidCrystal lcd_1(0); 

String atas  = "Quotes:";
String bawah = "Mom is the best supporter";

int posisi = 0;

void setup(){
  lcd_1.begin(16, 2); 

  lcd_1.setBacklight(1); 

  int panjang = atas.length(); 

  int tengah = (16 - panjang) / 2; 

  lcd_1.setCursor(tengah, 0); 

  lcd_1.print(atas); 
}

void loop(){
  lcd_1.setCursor(0, 1); 

  String tampil = bawah.substring(posisi, posisi + 16);

  lcd_1.print(tampil); 

  posisi++; 

  if (posisi > bawah.length() - 16) {
    posisi = 0;
  }

  delay(300); 
}