#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD I2C dengan address 0
Adafruit_LiquidCrystal lcd(0);

// ==================== KONFIGURASI ====================
const int LCD_COLS  = 16;
const int LCD_ROWS  = 2;
const int SCROLL_DELAY = 200;

// Ganti isi quote sesuai keinginan
const char* quoteText = "Senin-Jumat Nganggur, Sabtu Minggu Libur. ~Jaim";
int textLen;

// ==================== FUNGSI ====================

// Hapus konten baris 1 (tulis 16 spasi)
void clearRow1() {
  lcd.setCursor(0, 1);
  lcd.print("                "); // 16 spasi
}

// ==================== SETUP ====================
void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.setBacklight(HIGH);

  // --- BARIS 0: "QUOTE" statis, tepat di tengah ---
  int centerPos = (LCD_COLS - 5) / 2;
  lcd.setCursor(centerPos, 0);
  lcd.print("QUOTE");

  textLen = strlen(quoteText);
}

// ==================== LOOP ====================
void loop() {

  for (int offset = 0; offset < LCD_COLS + textLen; offset++) {
    clearRow1(); // Bersihkan baris 1

    // startCol: kolom LCD tempat karakter pertama teks dicetak
    int startCol = (LCD_COLS - 1) - offset; // Mulai dari kolom 15

    for (int i = 0; i < textLen; i++) {
      int col = startCol + i;

      // Cetak hanya karakter yang berada dalam area LCD (0 ~ 15)
      if (col >= 0 && col < LCD_COLS) {
        lcd.setCursor(col, 1);
        lcd.print(quoteText[i]);
      }
    }

    delay(SCROLL_DELAY);
  }

  // Jeda sebentar sebelum scroll diulang dari awal
  delay(800);
}
