#include <Adafruit_LiquidCrystal.h>

// Inisialisasi LCD I2C dengan alamat 0
Adafruit_LiquidCrystal lcd(0);

// ==================== KONFIGURASI ====================
const int LCD_COLS  = 16;
const int LCD_ROWS  = 2;
const int SCROLL_DELAY = 50;

// Kalimat ke-2 (baris [1]) yang akan ditampilkan secara dinamis (scroll)
const char* quoteText = "PST Matkul Menyenangkan Sedunia";
int textLen;

// ==================== FUNGSI ====================

// Membersihkan isi baris ke-2 (baris [1])
void clearRow1() {
  lcd.setCursor(0, 1);
  lcd.print("                "); // 16 spasi untuk menghapus teks sebelumnya
}

// ==================== SETUP ====================
void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.setBacklight(HIGH);

  // --- BARIS [0]: Menampilkan teks "QUOTE" secara statis ---
  // Teks harus berada tepat di tengah LCD (16 kolom)
  int centerPos = (LCD_COLS - 5) / 2; // 5 adalah panjang kata "QUOTE"
  lcd.setCursor(centerPos, 0);
  lcd.print("QUOTE");

  // Menghitung panjang teks quote (untuk kebutuhan scrolling)
  textLen = strlen(quoteText);
}

// ==================== LOOP ====================
void loop() {

  // Perulangan untuk membuat teks berjalan dari kanan ke kiri
  for (int offset = 0; offset < LCD_COLS + textLen; offset++) {
    
    clearRow1(); // Bersihkan baris [1] sebelum menampilkan frame berikutnya

    // Posisi awal teks dimulai dari sisi kanan LCD (kolom 15, baris 1)
    int startCol = (LCD_COLS - 1) - offset;

    // Menampilkan teks secara bertahap (scroll)
    for (int i = 0; i < textLen; i++) {
      int col = startCol + i;

      // Hanya tampilkan karakter yang berada dalam area LCD (kolom 0–15)
      if (col >= 0 && col < LCD_COLS) {
        lcd.setCursor(col, 1); // baris [1]
        lcd.print(quoteText[i]);
      }
    }

    delay(SCROLL_DELAY); // delay untuk efek pergerakan
  }

  // Jeda sebelum animasi diulang dari awal
  delay(800);
}