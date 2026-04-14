#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

String barisAtas = "QUOTE"; 

String pesan = "SEMANGAT YAA -- FINDA W.F -- 55"; 
String fullPesan = "                " + pesan + "                "; 

unsigned long waktuLalu = 0;
int pos = 0;
const int kecepatan = 120; 
void setup() {
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(5, 0); 
  lcd.print(barisAtas);
}

void loop() {
  unsigned long waktuSekarang = millis();

  if (waktuSekarang - waktuLalu >= kecepatan) {
    waktuLalu = waktuSekarang;

   
    String sub = fullPesan.substring(pos, pos + 16);
    
    lcd.setCursor(0, 1);
    lcd.print(sub); 
    pos++;
    
    if (pos >= fullPesan.length() - 16) {
      pos = 0;
    }
  }
}