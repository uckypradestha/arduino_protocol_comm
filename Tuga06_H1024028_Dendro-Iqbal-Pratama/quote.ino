#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

// teks quote
String quoteText = "Hidup jadi terasa mudah jika pernah merasakan susah ";
int textLen;

#define LCD_COLS 16
#define LCD_ROWS 2
#define SCROLL_DELAY 300

void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(HIGH);

  // tulisan atas
  lcd.setCursor(5, 0);
  lcd.print("QUOTE");

  textLen = quoteText.length();
}

void loop() {
  for (int offset = 0; offset < textLen + LCD_COLS; offset++) {
    
    // bersihin baris kedua
    lcd.setCursor(0, 1);
    lcd.print("                "); // 16 spasi

    int startCol = LCD_COLS - 1 - offset;

    for (int i = 0; i < textLen; i++) {
      int col = startCol + i;

      if (col >= 0 && col < LCD_COLS) {
        lcd.setCursor(col, 1);
        lcd.print(quoteText[i]);
      }
    }

    delay(SCROLL_DELAY);
  }
}
