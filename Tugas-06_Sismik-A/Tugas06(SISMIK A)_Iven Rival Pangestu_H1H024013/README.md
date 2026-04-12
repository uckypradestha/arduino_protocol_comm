# Scrolling Text LCD I2C (Arduino)
Proyek ini merupakan implementasi animasi teks berjalan dua arah (**Ping-Pong Scrolling**) pada LCD 16x2 menggunakan antarmuka I2C di lingkungan Arduino.Program ini menampilkan judul statis di baris pertama dan teks kutipan dinamis di baris kedua.

## Identitas Praktikan
* **Nama**: Iven Rival Pangestu 
* **NIM**: H1H024013 
* **Kelas**: A

## Tautan Proyek
* **Simulasi Tinkercad**: https://www.tinkercad.com/things/gk2WOcq2rxR-tugas06sismik-ah1h024013iven-rival-pangestu/editel?returnTo=https%3A%2F%2Fwww.tinkercad.com%2Fdashboard&sharecode=vxeM7BroA3bbGtZzi4XlQbjQghl4oTCupSqZuJnxxkI 

## SKEMA RANGKAIAN
<img width="1494" height="702" alt="Tugas06(SISMIK A)_H1H024013_IVEN RIVAL PANGESTU)" src="https://github.com/user-attachments/assets/840a9cbe-5972-4c3d-a531-e0fe121d70f8" />

## Komponen & Library
* **Mikrokontroler**: Arduino (Simulasi Tinkercad) 
* **LCD**: 16x2 dengan modul I2C 
* **Library**: `Adafruit_LiquidCrystal.h` (digunakan untuk menyederhanakan komunikasi I2C antara mikrokontroler dan modul LCD).

## Konfigurasi Program
Program menggunakan beberapa konstanta utama untuk mengatur jalannya animasi:
* `LCD_COLS (16)`: Jumlah kolom pada LCD.
* `SCROLL_DELAY (280ms)`: Jeda antar frame untuk mengatur kecepatan scroll.
* `PAUSE_END (1200ms)`: Jeda di setiap ujung sebelum arah teks berbalik.


## Penjelasan Logika Program

### 1. Inisialisasi
Objek LCD diinisialisasi dengan alamat `0`. Pada fungsi `setup()`, baris pertama diatur untuk menampilkan teks **"QUOTE"** secara statis di posisi tengah (kolom 5 hingga 10).

### 2. Mekanisme Render Frame
Fungsi `renderFrame()` bertanggung jawab mencetak teks karakter demi karakter berdasarkan nilai `offset`:
* Jika `offset` negatif, teks mulai muncul dari sisi kanan layar.
* Jika `offset` mencapai nilai maksimal, hanya karakter terakhir yang tersisa di sisi kiri layar.
* Sebelum setiap frame baru dirender, fungsi `hapusBaris1()` akan membersihkan baris kedua dengan spasi untuk mencegah teks tumpang tindih.

### 3. Animasi Ping-Pong
Efek "Ping-Pong" dihasilkan oleh fungsi `pingPongScroll()` yang memiliki dua fase utama:
| Fase | Arah Gerak | Perubahan Offset |
| :--- | :--- | :--- |
| **Maju** | Kanan ke Kiri | `offsetMin` ke `offsetMax` (Naik)  |
| **Mundur** | Kiri ke Kanan | `offsetMax` ke `offsetMin` (Turun)  |

## DEMO 
https://github.com/user-attachments/assets/1047654a-fc9d-41de-aba1-32aef2760098
## KodeFULL
```cpp
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
```

## Kesimpulan
Program ini berhasil mengimplementasikan kontrol presisi terhadap posisi teks menggunakan parameter `offset`. Dengan memisahkan logika render dan animasi, parameter seperti kecepatan dan jeda dapat disesuaikan dengan mudah melalui konstanta yang tersedia.
