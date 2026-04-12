#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup() {
  lcd.begin(16, 4);
  
  // Menyalakan lampu latar belakang
  lcd.setBacklight(1);
  lcd.print("Selamat menikmati MBG");
  delay(1000);
}

void loop() {
  // Jalan ke kiri bertahap
  lcd.scrollDisplayLeft();
  delay(300);
}