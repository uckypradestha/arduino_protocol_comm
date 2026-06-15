# Laporan Tugas 6 Sistem Mikrokontroler

Nama : Abyan Devadi <br>
NIM : H1H024049 <br>
Kelas: B <br>
Mata Kuliah : Sistem Mikrokontroler

# Deskripsi Program

Program ini mendemonstrasikan penggunaan LCD 16x2 berbasis I2C untuk menampilkan: <br>
Teks statis (judul) pada baris pertama <br>
Teks dinamis (scrolling) pada baris kedua <br>
Teks berjalan ditampilkan secara halus dari kanan ke kiri dengan tambahan padding spasi.

# Librarynya

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
```

<Wire.h> = Library bawaan Arduino untuk komunikasi I2C <br>
<LiquidCrystal_I2C.h> = Library untuk mengontrol LCD melalui modul I2C

# Konfigurasi Sistem

```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);

constexpr uint8_t LCD_COLS      = 16;
constexpr uint8_t TITLE_ROW     = 0;
constexpr uint8_t SCROLL_ROW    = 1;
constexpr uint16_t SCROLL_DELAY = 300;
constexpr uint16_t LOOP_PAUSE   = 800;

const String TITLE = "Jujur Janggal";
const String QUOTE = "Kicau Mania";
```

# Penjelasan:

lcd(0x27, 16, 2) → Alamat I2C dan ukuran LCD <br>
LCD_COLS → Jumlah kolom LCD <br>
TITLE_ROW & SCROLL_ROW → Penempatan baris teks <br>
SCROLL_DELAY → Kecepatan scrolling <br>
LOOP_PAUSE → Jeda setelah satu siklus selesai <br>
TITLE → Judul statis <br>
QUOTE → Teks berjalan <br>

# Mekanisme Scrolling

```cpp
const String PADDING = "                ";
const String SCROLL_TEXT = PADDING + QUOTE + PADDING;
```

PADDING = 16 spasi untuk efek masuk/keluar layar <br>
SCROLL_TEXT = Gabungan teks dengan padding

# Fungsinya 

1. Menampilkan Teks di Tengah

```cpp
void printCentered(const String& text, uint8_t row) {
  uint8_t col = (LCD_COLS - text.length()) / 2;
  lcd.setCursor(col, row);
  lcd.print(text);
}
```
Fungsi ini digunakan untuk menampilkan teks agar berada di tengah layar.

2. Fungsi Scrolling Teks

```cpp
void scrollText(const String& text, uint8_t row) {
  int totalFrames = text.length() - LCD_COLS;

  for (int i = 0; i <= totalFrames; i++) {
    lcd.setCursor(0, row);
    lcd.print(text.substring(i, i + LCD_COLS));
    delay(SCROLL_DELAY);
  }
}
```

Penjelasan:

Menggeser teks per frame sepanjang 16 karakter <br>
substring(i, i + 16) → Menampilkan sebagian teks <br>
delay() → Mengatur kecepatan scroll

---
Setup Program
---

```cpp
void setup() {
  lcd.init();
  lcd.backlight();
  printCentered(TITLE, TITLE_ROW);
}
lcd.init() → Inisialisasi LCD
lcd.backlight() → Menyalakan backlight
printCentered() → Menampilkan judul di tengah
```
---
Loop Program
---

```cpp
void loop() {
  scrollText(SCROLL_TEXT, SCROLL_ROW);
  delay(LOOP_PAUSE);
}
```

Menjalankan animasi scrolling secara berulang <br>
Memberikan jeda sebelum mengulang

---
Hasil Program
---

Baris 1 → Menampilkan teks statis (judul) di tengah <br>
Baris 2 → Menampilkan teks berjalan (scrolling quote) <br>

# 🔗 Link Simulasi Tinkercad

https://www.tinkercad.com/things/fGfdQFFIZSp-punyaabyan?sharecode=zQxqDa3vI3OI6-7tXhZyS0xo_rcryMUNXqUroNLruvM
