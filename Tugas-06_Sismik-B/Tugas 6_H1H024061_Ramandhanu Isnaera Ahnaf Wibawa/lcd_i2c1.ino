#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String teksAsli = "Kita punya harapan, tapi dunia punya kenyataan";

String teksBerjalan = "                " + teksAsli + "                ";

void setup() {
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop() {
  int batasGeser = teksBerjalan.length() - 16;
  
  for (int i = 0; i <= batasGeser; i++) {
    
    String potonganTeks = teksBerjalan.substring(i, i + 16);
    
    lcd.setCursor(0, 1);
    lcd.print(potonganTeks);
    
    delay(350);
  }
}