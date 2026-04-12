#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

String staticText = "QUOTE";
String dynamicQuote = "Be yourself, everyone else is already taken"; 
int messageLength;
int position = 15;

void setup() {
  lcd.init();
  lcd.backlight();

  lcd.setCursor(5, 0);
  lcd.print(staticText);

  dynamicQuote = dynamicQuote + "      ";
  messageLength = dynamicQuote.length();
}

void loop() {
  lcd.setCursor(0, 1);
  lcd.print("                "); 

  if (position >= 0) {
    lcd.setCursor(position, 1);
    lcd.print(dynamicQuote.substring(0, 16 - position));
  } else {
    lcd.setCursor(0, 1);
    lcd.print(dynamicQuote.substring(abs(position), abs(position) + 16));
  }

  position--;

  if (position < -messageLength) {
    position = 15;
  }

  delay(200);
}