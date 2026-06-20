#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD (MCP23008 default Tinkercad)
Adafruit_LiquidCrystal lcd(0);

// Konfigurasi Teks
const String staticText  = "QUOTE";
const String scrollText  = "Belajarlah dari kesalahan, karena di sana tersembunyi kebijaksanaan.";
const int LCD_COLS = 16;
const int SCROLL_DELAY = 200;

// Variabel Scrolling 
int scrollPos = 0;

// Fungsi Tengah 
int centerColumn(String text) {
  int len = text.length();
  if (len >= LCD_COLS) return 0;
  return (LCD_COLS - len) / 2;
}

// Header 
void displayStaticHeader() {
  lcd.setCursor(centerColumn(staticText), 0);
  lcd.print(staticText);
}

// Scroll 
void scrollFrame() {
  lcd.setCursor(0, 1);
  lcd.print("                ");

  for (int i = 0; i < scrollText.length(); i++) {
    int col = (LCD_COLS - 1 - scrollPos) + i;
    if (col >= 0 && col < LCD_COLS) {
      lcd.setCursor(col, 1);
      lcd.print(scrollText[i]);
    }
  }

  scrollPos++;

  int totalScroll = LCD_COLS + scrollText.length();
  if (scrollPos >= totalScroll) {
    scrollPos = 0;
  }
}

// Setup 
void setup() {
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.setBacklight(255);

  displayStaticHeader();
}

// Loop 
void loop() {
  scrollFrame();
  delay(SCROLL_DELAY);
}