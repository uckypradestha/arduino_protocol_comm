#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
#include <string.h>

// Inisialisasi LCD I2C dengan address 0
Adafruit_LiquidCrystal lcd(0);

// KONFIGURASI 
const int LCD_COLS  = 16;
const int LCD_ROWS  = 2;
const int SCROLL_DELAY = 200;
const int PAUSE_DELAY  = 800;

// Ganti isi quote sesuai keinginan
const char* quoteText = "Cihuykan Dulu lee";
int textLen;

// Spasi kosong untuk membersihkan baris
const char blankRow[] = "                "; // 16 spasi


// Membersihkan baris ke-2 LCD
void clearRow1() {
  lcd.setCursor(0, 1);
  lcd.print(blankRow);
}

// SETUP
void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.setBacklight(HIGH);

  // Menghitung panjang teks
  textLen = strlen(quoteText);

  // --- BARIS 0: "QUOTE" statis dan berada di tengah ---
  int centerPos = (LCD_COLS - 5) / 2;
  lcd.setCursor(centerPos, 0);
  lcd.print("QUOTE");

  delay(1000); // Jeda awal sebelum animasi dimulai
}

// LOOP 
void loop() {

  // Animasi teks berjalan dari kanan ke kiri
  for (int offset = 0; offset < LCD_COLS + textLen; offset++) {
    clearRow1(); // Bersihkan baris kedua

    // Posisi awal teks
    int startCol = (LCD_COLS - 1) - offset;

    // Cetak karakter satu per satu
    for (int i = 0; i < textLen; i++) {
      int col = startCol + i;

      // Tampilkan hanya jika berada dalam area LCD
      if (col >= 0 && col < LCD_COLS) {
        lcd.setCursor(col, 1);
        lcd.print(quoteText[i]);
      }
    }

    delay(SCROLL_DELAY);
  }

  // Jeda sebelum animasi diulang
  delay(PAUSE_DELAY);
}
