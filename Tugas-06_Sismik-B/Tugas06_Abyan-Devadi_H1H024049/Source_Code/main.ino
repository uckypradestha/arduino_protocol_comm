#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ==================== KONFIGURASI ====================
LiquidCrystal_I2C lcd(0x27, 16, 2);

constexpr uint8_t LCD_COLS      = 16;
constexpr uint8_t TITLE_ROW     = 0;
constexpr uint8_t SCROLL_ROW    = 1;
constexpr uint16_t SCROLL_DELAY = 300;
constexpr uint16_t LOOP_PAUSE   = 800;

const String TITLE = "Jujur Janggal";
const String QUOTE = "Kicau Mania";

// Padding spasi di kiri & kanan agar teks masuk/keluar dengan mulus
const String PADDING = "                "; // 16 spasi
const String SCROLL_TEXT = PADDING + QUOTE + PADDING;

// ==================== FUNGSI ====================

/**
 * Cetak teks di tengah baris tertentu.
 * Otomatis menghitung posisi kolom berdasarkan panjang teks.
 */
void printCentered(const String& text, uint8_t row) {
  uint8_t col = (LCD_COLS - text.length()) / 2;
  lcd.setCursor(col, row);
  lcd.print(text);
}

/**
 * Scroll teks dari kanan ke kiri pada baris yang ditentukan.
 * Menggunakan teknik substring: setiap frame mengambil 16 karakter
 * dari posisi offset yang bergeser satu per satu.
 */
void scrollText(const String& text, uint8_t row) {
  int totalFrames = text.length() - LCD_COLS; // Jumlah langkah scroll

  for (int i = 0; i <= totalFrames; i++) {
    lcd.setCursor(0, row);
    lcd.print(text.substring(i, i + LCD_COLS)); // Tampilkan 16 karakter
    delay(SCROLL_DELAY);
  }
}

// ==================== SETUP ====================
void setup() {
  lcd.init();
  lcd.backlight();
  printCentered(TITLE, TITLE_ROW); // Judul statis di baris 0
}

// ==================== LOOP ====================
void loop() {
  scrollText(SCROLL_TEXT, SCROLL_ROW); // Scroll quote di baris 1
  delay(LOOP_PAUSE);
}