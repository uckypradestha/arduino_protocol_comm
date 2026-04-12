#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

void setup()
{
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);
  lcd.clear();
  
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}

void loop()
{
  String blank = "                "; // space for entering effect
  String quote = "andai saja kita mengerti, saat bertemu pertama kali ";
  String message = blank + quote; // merge with space with the quote
  
  // looping over the entire letters of the text
  for (int i = 1; i < message.length(); i++) { 
    lcd.setCursor(0, 1);
    
    // Print substring for scrolling effect
    if (i < message.length() - 16) { // handle the 16 initial letters
        lcd.print(message.substring(i, i + 16));
    } else { // handle the rest of the letter
        // Handle end of message
        lcd.print(message.substring(i));
    }
  }
}