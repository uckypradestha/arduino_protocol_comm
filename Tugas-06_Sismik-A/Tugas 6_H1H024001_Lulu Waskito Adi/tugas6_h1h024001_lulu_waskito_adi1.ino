#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* label    = "QUOTE";
const char* message  = "Pelan Tidak Apa, Yang Penting Maju";
const int   COLS     = 16;
const int   TICK_MS  = 150;

void centerPrint(uint8_t row, const char* text) {
  uint8_t len = strlen(text);
  uint8_t col = (len < COLS) ? (COLS - len) / 2 : 0;
  lcd.setCursor(col, row);
  lcd.print(text);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  centerPrint(0, label);
}

void loop() {
  // Bangun buffer: padding kanan sebesar COLS agar teks keluar bersih
  String ticker = String("                ") + message + "                ";
  uint8_t totalLen = ticker.length();

  for (uint8_t pos = 0; pos + COLS <= totalLen; pos++) {
    lcd.setCursor(0, 1);
    lcd.print(ticker.substring(pos, pos + COLS));
    delay(TICK_MS);
  }
}