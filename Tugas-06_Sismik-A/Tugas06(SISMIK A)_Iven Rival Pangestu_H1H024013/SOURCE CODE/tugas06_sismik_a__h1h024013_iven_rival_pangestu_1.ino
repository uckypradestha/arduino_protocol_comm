#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

String quoteText = "Hi antek antek ASINGGG, TAPIII DISINII Saya akan lawanNNNN";
const int LCD_COLS = 16;
const int SCROLL_DELAY = 280;
const int PAUSE_END = 1200;

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  lcd_1.setCursor(5, 0);
  lcd_1.print("QUOTE");
}

void hapusBaris1() {
  lcd_1.setCursor(0, 1);
  lcd_1.print("                "); 
}

void renderFrame(const String& teks, int offset) {
  hapusBaris1();
  int panjang = teks.length();
  for (int col = 0; col < LCD_COLS; col++) {
    int idx = offset + col;
    if (idx >= 0 && idx < panjang) {
      lcd_1.setCursor(col, 1);
      lcd_1.print(teks[idx]);
    }
  }
}

void pingPongScroll(const String& teks) {
  int panjang = teks.length();
  int offsetMin = -(LCD_COLS - 1);
  int offsetMax = panjang - 1;

  // Maju: kanan -> kiri
  for (int off = offsetMin; off <= offsetMax; off++) {
    renderFrame(teks, off);
    delay(SCROLL_DELAY);
  }
  delay(PAUSE_END);

  // Mundur: kiri -> kanan
  for (int off = offsetMax; off >= offsetMin; off--) {
    renderFrame(teks, off);
    delay(SCROLL_DELAY);
  }
  delay(PAUSE_END);
}

void loop() {
  pingPongScroll(quoteText);
}