## Laporan Program Arduino

Program Arduino untuk menampilkan teks statis di tengah baris atas dan teks berjalan (ping-pong scroll) di baris bawah LCD 16x2.

---

## Source Code
```cpp
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);
String quoteText       = "H1H024048 - WENDY VIRTUS";
const int LCD_COLS     = 16;
const int SCROLL_DELAY = 280;
const int PAUSE_END    = 1200;

void printCenter(String teks, int baris) {
  int pos = (LCD_COLS - teks.length()) / 2;
  if (pos < 0) pos = 0;
  lcd_1.setCursor(pos, baris);
  lcd_1.print(teks);
}

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  printCenter("Hello World", 0);
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
  int panjang   = teks.length();
  int offsetMin = 0;
  int offsetMax = panjang - LCD_COLS;

  if (offsetMax < 0) offsetMax = 0;

  // Maju: geser ke kiri
  for (int off = offsetMin; off <= offsetMax; off++) {
    renderFrame(teks, off);
    delay(SCROLL_DELAY);
  }
  delay(PAUSE_END);

  // Mundur: geser ke kanan
  for (int off = offsetMax; off >= offsetMin; off--) {
    renderFrame(teks, off);
    delay(SCROLL_DELAY);
  }
  delay(PAUSE_END);
}

void loop() {
  pingPongScroll(quoteText);
}
```
---

## Library
```cpp
#include <Adafruit_LiquidCrystal.h>
```
Menggunakan library **Adafruit_LiquidCrystal** untuk memudahkan berinteraksi dengan LCD.

---

## Inisialisasi

```cpp
// Global
Adafruit_LiquidCrystal lcd_1(0);          // object untuk mengakses lcd
String quoteText       = "H1H024048 - WENDY VIRTUS"; // teks yang akan di-scroll
const int LCD_COLS     = 16;              // jumlah kolom LCD
const int SCROLL_DELAY = 280;             // delay antar frame (ms)
const int PAUSE_END    = 1200;            // jeda di ujung sebelum berbalik (ms)
```

Pada inisialisasi global, terdapat:
- **lcd_1** — object yang digunakan untuk berinteraksi dengan LCD.
- **quoteText** — string teks yang akan ditampilkan secara scrolling di baris bawah.
- **LCD_COLS** — konstanta jumlah kolom LCD (16).
- **SCROLL_DELAY** — delay antar frame scroll dalam milidetik.
- **PAUSE_END** — jeda setelah teks mencapai ujung sebelum berbalik arah.

<br />

```cpp
// Inisialisasi Arduino
void setup() {
  lcd_1.begin(16, 2);          // menyiapkan lcd
  lcd_1.setBacklight(1);       // menyalakan backlight
  printCenter("Hello World", 0); // menampilkan teks di tengah baris atas
}
```

Pada inisialisasi Arduino, akan melakukan:
- Mempersiapkan LCD dengan `lcd_1.begin(16, 2)` agar siap digunakan.
- Menyalakan backlight (lampu belakang) LCD.
- Menampilkan tulisan `"Hello World"` di tengah baris atas menggunakan fungsi `printCenter()`.

---

## Fungsi Pendukung

### printCenter()
```cpp
void printCenter(String teks, int baris) {
  int pos = (LCD_COLS - teks.length()) / 2;
  if (pos < 0) pos = 0;
  lcd_1.setCursor(pos, baris);
  lcd_1.print(teks);
}
```
Fungsi ini menghitung posisi kolom secara otomatis agar teks tampil **tepat di tengah** layar.
Rumus yang digunakan:
```
posisi = (LCD_COLS - panjang_teks) / 2
       = (16 - 11) / 2
       = kolom ke-2
```

### hapusBaris1()
```cpp
void hapusBaris1() {
  lcd_1.setCursor(0, 1);
  lcd_1.print("                ");
}
```
Fungsi ini membersihkan baris ke-2 LCD dengan mencetak 16 spasi, agar tidak ada sisa karakter dari frame sebelumnya.

### renderFrame()
```cpp
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
```
Fungsi ini menampilkan potongan teks sesuai nilai `offset`. Setiap kolom LCD akan menampilkan karakter dari indeks `offset + col` pada string, sehingga menghasilkan efek geser.

---

## Looping

```cpp
void pingPongScroll(const String& teks) {
  int panjang   = teks.length();
  int offsetMin = 0;
  int offsetMax = panjang - LCD_COLS;

  if (offsetMax < 0) offsetMax = 0;

  // Maju: geser ke kiri
  for (int off = offsetMin; off <= offsetMax; off++) {
    renderFrame(teks, off);
    delay(SCROLL_DELAY);
  }
  delay(PAUSE_END);

  // Mundur: geser ke kanan
  for (int off = offsetMax; off >= offsetMin; off--) {
    renderFrame(teks, off);
    delay(SCROLL_DELAY);
  }
  delay(PAUSE_END);
}

void loop() {
  pingPongScroll(quoteText);
}
```

Pada fungsi looping, akan menjalankan:
- Menghitung panjang teks dan menentukan batas offset minimum (`0`) dan maksimum (`panjang - 16`).
- **Looping maju** — teks bergeser dari kiri ke kanan dengan memanggil `renderFrame()` dari offset `0` hingga `offsetMax`.
- Jeda selama `PAUSE_END` milidetik setelah teks mencapai ujung kanan.
- **Looping mundur** — teks bergeser kembali dari kanan ke kiri (efek ping-pong).
- Proses ini berulang terus-menerus selama Arduino menyala.

---

## Tampilan LCD

<img width="1052" height="683" alt="image" src="https://github.com/user-attachments/assets/37054f64-6880-45e8-8762-6499bd169c12" />
