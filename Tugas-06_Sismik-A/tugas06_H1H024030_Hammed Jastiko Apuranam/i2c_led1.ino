#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String quoteText = "alon alon asal kelakon"; 
String paddedText;

void setup() {
  lcd.init();       
  lcd.backlight();  

  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
  paddedText = "                " + quoteText + "                ";
}

void loop() {
  for (int i = 0; i <= paddedText.length() - 16; i++) {
    lcd.setCursor(0, 1); 
    lcd.print(paddedText.substring(i, i + 16));
    
    delay(200); 
  }
}