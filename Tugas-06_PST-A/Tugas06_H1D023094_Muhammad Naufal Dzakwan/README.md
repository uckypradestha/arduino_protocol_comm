# Scrolling Text dengan I2C

## Identitas

Nama : Muhammad Naufal Dzakwan<br>
NIM  : H1D023094<br>
Mata Kuliah : Pemrograman Sistem Tertanam

---

## Deskripsi Proyek

Proyek ini bertujuan untuk menampilkan teks berjalan (*scrolling text*) pada layar LCD 16x2 yang terhubung menggunakan protokol komunikasi I2C. Teks pada baris pertama menampilkan kata **"QUOTE"** secara statis dan tepat di tengah layar, sementara baris kedua menampilkan isi quote yang bergerak dari kanan ke kiri secara berulang.

### Spesifikasi Sistem

- Terdiri dari 2 kalimat pada layar LCD.
- **Baris [0]**: Menampilkan teks `"QUOTE"` yang bersifat **statis**, posisinya berada tepat di tengah layar.
- **Baris [1]**: Menampilkan isi quote yang bersifat **dinamis** (scrolling), muncul dari sisi kanan layar (cursor kolom 15, baris 1) dan bergerak ke kiri.

---

## Alat dan Bahan

| No | Komponen         | Jumlah |
|----|------------------|--------|
| 1  | Arduino Uno      | 1      |
| 2  | LCD 16x2 + Modul I2C | 1  |
| 3  | Kabel Jumper     | Secukupnya |

---

## Skema Wiring (Koneksi I2C)

| Pin LCD I2C | Pin Arduino Uno |
|-------------|-----------------|
| VCC         | 5V              |
| GND         | GND             |
| SDA         | SDA             |
| SCL         | SCL             |

---

## Penjelasan Kode

### 1. Library yang Digunakan

```cpp
#include <Adafruit_LiquidCrystal.h>
```

Library `Adafruit_LiquidCrystal` digunakan untuk mengontrol LCD yang terhubung melalui I2C. Library ini menyederhanakan komunikasi antara Arduino dan LCD I2C dengan menyediakan fungsi-fungsi seperti `begin()`, `setCursor()`, `print()`, dan `setBacklight()`.

---

### 2. Inisialisasi LCD

```cpp
Adafruit_LiquidCrystal lcd(0);
```

Membuat objek LCD dengan alamat I2C = `0`. Pada Tinkercad, alamat ini sudah disesuaikan secara default.

---

### 3. Konfigurasi dan Variabel Global

```cpp
const int LCD_COLS   = 16;
const int LCD_ROWS   = 2;
const int SCROLL_DELAY = 200;

const char* quoteText = "be yourself and never surender";
int textLen;
```

- `LCD_COLS` dan `LCD_ROWS` mendefinisikan ukuran layar LCD (16 kolom, 2 baris).
- `SCROLL_DELAY` mengatur kecepatan scrolling dalam milidetik.
- `quoteText` berisi teks `"be yourself and never surender"` yang akan berjalan di baris kedua LCD.
- `textLen` akan menyimpan panjang karakter `quoteText` untuk kalkulasi scrolling.

---

### 4. Fungsi `setup()`

```cpp
void setup() {
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.setBacklight(HIGH);

  int centerPos = (LCD_COLS - 5) / 2;
  lcd.setCursor(centerPos, 0);
  lcd.print("QUOTE");

  textLen = strlen(quoteText);
}
```

- `lcd.begin(16, 2)` menginisialisasi LCD dengan ukuran 16 kolom dan 2 baris.
- `lcd.setBacklight(HIGH)` menyalakan lampu latar LCD.
- Perhitungan `(LCD_COLS - 5) / 2` menghasilkan posisi **5** agar teks `"QUOTE"` (5 karakter) tepat berada di tengah layar.
- `textLen` dihitung sekali saja di `setup()` agar tidak dihitung ulang setiap iterasi `loop()`.

---

### 5. Fungsi `loop()` — Logika Scrolling

```cpp
void loop() {
  for (int offset = 0; offset < LCD_COLS + textLen; offset++) {
    char rowBuffer[LCD_COLS + 1];
    memset(rowBuffer, ' ', LCD_COLS);
    rowBuffer[LCD_COLS] = '\0';
    int startCol = (LCD_COLS - 1) - offset;
    for (int i = 0; i < textLen; i++) {
      int col = startCol + i;
      if (col >= 0 && col < LCD_COLS) {
        rowBuffer[col] = quoteText[i];
      }
    }
    lcd.setCursor(0, 1);
    lcd.print(rowBuffer);
    delay(SCROLL_DELAY);
  }
  delay(800);
}
```

Logika scrolling menggunakan **row buffer** — seluruh isi baris dirakit terlebih dahulu ke dalam array `rowBuffer[16]`, baru dikirim ke LCD dalam satu kali `lcd.print()`. Pendekatan ini menghindari efek karakter muncul satu per satu yang disebabkan oleh lambatnya komunikasi I2C jika menulis karakter secara individual.

Cara kerjanya:

- `rowBuffer` diisi spasi terlebih dahulu (`memset`) agar karakter yang tidak terisi tetap kosong.
- `startCol = 15 - offset` → posisi kolom tempat karakter pertama teks ditempatkan.
- Setiap iterasi `offset` bertambah 1, sehingga `startCol` berkurang 1 → teks tampak bergerak ke kiri.
- Karakter hanya dimasukkan ke buffer jika `col >= 0 && col < 16` (masih dalam area layar).
- Setelah buffer siap, `lcd.setCursor(0, 1)` + `lcd.print(rowBuffer)` menulis seluruh baris sekaligus dalam satu operasi I2C → teks muncul langsung utuh tanpa efek bertahap.

Ilustrasi per frame:

| offset | startCol | Tampilan Baris 1 (contoh teks "be yourself and never surender!") |
|--------|----------|------------------------------------------------------------------|
| 0      | 15       | `               B`  ← Muncul dari kanan                          |
| 1      | 14       | `              Be`                                               |
| 8      | 7        | `       Be yourse`                                               |
| 16     | -1       | `urender         ` ← Mulai keluar dari kiri                      |
| ...    | ...      | ...                                                              |

Loop berakhir saat `offset = LCD_COLS + textLen`, artinya seluruh teks sudah keluar dari layar. Kemudian ada jeda `800ms` sebelum scroll dimulai ulang dari awal.

---

## Simulasi

Simulasi dilakukan menggunakan **Tinkercad Circuits** dengan komponen Arduino Uno dan LCD I2C.

> 📁 Lihat folder `Dokumentasi/` untuk rekaman video simulasi.

---

## Cara Menjalankan

1. Buka **Tinkercad** → buat project baru di Circuits.
2. Tambahkan komponen **Arduino Uno** dan **LCD 16x2 (I2C)**.
3. Hubungkan pin sesuai skema wiring di atas (SDA→SDA, SCL→SCL, VCC→5V, GND→GND).
4. Salin kode dari `Source Code/main.ino` ke editor kode Tinkercad.
5. Klik **Start Simulation**.
6. Amati: baris pertama menampilkan `"QUOTE"` statis di tengah, baris kedua menampilkan teks scrolling dari kanan ke kiri.
