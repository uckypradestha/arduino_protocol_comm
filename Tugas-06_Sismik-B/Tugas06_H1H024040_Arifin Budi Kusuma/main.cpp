#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

String teksDiam = "QUOTE:"; 
String teksJalan = "               POKOKNYA ADA DEH              ";

void setup() {
  lcd.begin(16, 2);        
  lcd.clear();       
  lcd.setBacklight(HIGH);   

  int posisiTengah = (16 - teksDiam.length()) / 2;
  
  lcd.setCursor(posisiTengah, 0); 
  lcd.print(teksDiam);            
}

void loop() {
  for (int i = 0; i <= teksJalan.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(teksJalan.substring(i, i + 16));
    
    delay(100); 
  }
}
