# Scrolling Text dengan I2C LCD

## Identitas
**Nama**: Muhammad Zaim Pahlevi  
**NIM**: H1D023073  
**Kelas**: PST-A  

## Deskripsi Proyek
Proyek ini mengimplementasikan **text scrolling (marquee effect)** pada LCD 16x2 menggunakan protokol **I2C**.  
- Baris pertama: Teks statis **\"QUOTE\"** yang diposisikan di tengah.  
- Baris kedua: Teks quote panjang yang bergerak dari **kanan ke kiri** secara kontinu dan smooth.  
Teks quote dapat dikustomisasi di variabel `quoteText`.  

Proyek ini mensimulasikan papan pengumuman digital sederhana menggunakan Arduino dan LCD I2C.

### Fitur Utama
- ✅ Tampilan statis \"QUOTE\" di baris atas (centered)
- ✅ Efek scrolling text di baris bawah (right-to-left)
- ✅ Animasi smooth dengan delay 200ms per frame
- ✅ Pause 800ms setelah 1x scroll penuh
- ✅ LCD I2C (address 0) - hemat pin
- ✅ Teks kustomisasi mudah

## Alat dan Bahan
| Komponen              | Jumlah | Keterangan |
|-----------------------|--------|------------|
| Arduino Uno           | 1      | Brain |
| LCD 16x2 + I2C Backpack | 1  | Display (address 0x27/0) |
| Jumper Wires          | 4+     | Koneksi |

## Skema Rangkaian
```
LCD I2C    → Arduino Uno
GND    →    GND
VCC    →    5V
SDA    →    A4
SCL    →    A5
```

![Simulasi](Dokumentasi/simulasi.webm)  
*(Video simulasi Tinkercad)*

## Simulasi dengan Tinkercad
1. **Buat Proyek Baru**: Circuits → New Circuit.
2. **Tambahkan Komponen**:
   - Arduino Uno
   - LCD 16x2 → tambah I2C Backpack (address 0)
3. **Koneksi**:
   | LCD I2C | Arduino Uno |
   |---------|-------------|
   | GND     | GND         |
   | VCC     | 5V          |
   | SDA     | A4          |
   | SCL     | A5          |
4. **Upload Kode**: Copy dari `Source Code/main.ino` ke Code editor.
5. **Start Simulation**: Amati scrolling text di LCD.

## Penjelasan Kode

### Library & Setup
```cpp
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);  // I2C address 0
```
Inisialisasi LCD 16x2, backlight ON, print \"QUOTE\" centered di row 0.

### Logika Scrolling (LOOP)
```cpp
for (int offset = 0; offset < LCD_COLS + textLen; offset++) {
  clearRow1();  // Hapus row 1 dengan 16 spasi
  int startCol = (LCD_COLS - 1) - offset;  // Mulai print dari posisi ini
  
  for (int i = 0; i < textLen; i++) {
    int col = startCol + i;
    if (col >= 0 &amp;&amp; col < LCD_COLS) {  // Hanya print di layar LCD
      lcd.setCursor(col, 1);
      lcd.print(quoteText[i]);
    }
  }
  delay(SCROLL_DELAY);  // 200ms
}
```

#### Cara Kerja Per Offset (Contoh: quoteText=\"ABCDE\", LCD_COLS=16):
| offset | startCol | Karakter Terlihat di LCD (row 1, pos 0-15) |
|--------|----------|--------------------------------------------|
| 0      | 15       | ................ABCDE                      |
| 1      | 14       | .................BCDE.                     |
| 2      | 13       | ................CDE..                      |
| 3      | 12       | .................DE...                     |

- `offset` bertambah → `startCol` bergeser kiri → text \"bergerak\" kiri.
- Saat `startCol + i < 0` atau `>15` → skip (hilang dari layar).
- 1 iterasi penuh: offset 0 sampai (16+5=21).

**Variabel Kunci**:
```cpp
const char* quoteText = \"Yang terbaik masih akan datang. - (Anas)\";
const int SCROLL_DELAY = 200;  // ms per frame
```

## Cara Penggunaan
1. Install library **Adafruit_LiquidCrystal** di Arduino IDE.
2. Upload `main.ino` ke Arduino Uno.
3. Power on → LCD menampilkan scrolling quote otomatis.

## Kesimpulan
Proyek berhasil mengimplementasikan **I2C LCD scrolling text** dengan animasi smooth. Konsep berguna untuk display info panjang (notif, pesan, etc.). Perlu diperbaiki: Tambah button untuk pause/ubah quote.

