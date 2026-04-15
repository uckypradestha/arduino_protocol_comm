#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);

String isiQuote = "Dihina tidak tumbang, dipuji makasih mas"; 

void setup() {
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(5, 0);
  lcd.print("Hidup");
}

void loop() {
  
  String teksJalan = "               " + isiQuote + "                ";

  for (int i = 0; i <= teksJalan.length() - 16; i++) {
    lcd.setCursor(0, 1);
    
    lcd.print(teksJalan.substring(i, i + 16));
    
  
    delay(250); 
  }
}