#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
String textBawah = "'Ratu Naurah Calista'";
int scrollPos = 16; 
void setup() {
  lcd.begin(16,2);
  lcd.clear();    
  lcd.setBacklight(HIGH); 
  
  lcd.setCursor(4, 0); 
  lcd.print("Halo");
}
void loop() {
  lcd.setCursor(0, 1);
  
  String buffer = "";
  for (int i = 0; i < 16; i++) {
    int index = i - scrollPos;
    if (index >= 0 && index < textBawah.length()) {
      buffer += textBawah[index];
    } else {
      buffer += " ";
    }
  }
  
  lcd.print(buffer);
  
  scrollPos--;
  if (scrollPos < -(int)textBawah.length()) {
    scrollPos = 16; 
  }
  delay(100); 
}