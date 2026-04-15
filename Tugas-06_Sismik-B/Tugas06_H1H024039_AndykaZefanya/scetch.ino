#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String message = "Knowledge is Power - Francis Bacon";
int msgLen;

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
  msgLen = message.length();
}

void loop() {
  for (int i = 15; i >= -msgLen; i--) {
    lcd.setCursor(0, 1);
    lcd.print("                "); 
    
    if (i >= 0) {
      lcd.setCursor(i, 1);
      lcd.print(message);
    } else {
      lcd.setCursor(0, 1);
      lcd.print(message.substring(-i));
    }

    delay(200); 
  }
}