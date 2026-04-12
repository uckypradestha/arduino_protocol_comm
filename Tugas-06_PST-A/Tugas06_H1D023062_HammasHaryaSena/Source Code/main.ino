#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd(0);

const int LCD_COLS  = 16;
const int LCD_ROWS  = 2;
const int SCROLL_DELAY = 100;

const char* quoteText = "Ya Ndak Tau Kok Tanya Saya";
int textLen;


void clearRow1() {
  lcd.setCursor(0, 1);
  lcd.print("                ");
}

void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.setBacklight(HIGH);

  int centerPos = (LCD_COLS - 5) / 2;
  lcd.setCursor(centerPos, 0);
  lcd.print("QUOTE");

  textLen = strlen(quoteText);
}

void loop() {

  for (int offset = 0; offset < LCD_COLS + textLen; offset++) {
    clearRow1();

    int startCol = (LCD_COLS - 1) - offset;

    for (int i = 0; i < textLen; i++) {
      int col = startCol + i;

      if (col >= 0 && col < LCD_COLS) {
        lcd.setCursor(col, 1);
        lcd.print(quoteText[i]);
      }
    }

    delay(SCROLL_DELAY);
  }

  delay(400);
}