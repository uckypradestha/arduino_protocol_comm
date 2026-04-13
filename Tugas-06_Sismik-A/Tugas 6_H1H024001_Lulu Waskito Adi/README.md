# LCD I2C Scrolling Quote Text

Menampilkan teks statis pada baris atas dan teks berjalan (*scrolling*) pada baris bawah LCD 16x2 menggunakan komunikasi I2C.Dapat dilihat di simulasi tinkercad : https://www.tinkercad.com/things/1Zo53RlqkZt-tugas6h1h024001lulu-waskito-adi?sharecode=j4kHNdQ_FATlZ2lNMZSZyleO7qY_jWuduIZ4x-ICyN8

---

## Spesifikasi

| Parameter | Nilai |
|---|---|
| LCD | 16x2 karakter |
| Protokol | I2C |
| Alamat I2C | `0x27` |
| Kecepatan scroll | 150 ms/karakter |
| Platform | Arduino |

---

## Cara Kerja

- **Baris 0** menampilkan label `QUOTE` secara statis dan terpusat. Ditulis sekali di `setup()`, tidak pernah di-refresh.
- **Baris 1** menampilkan teks pesan yang bergerak dari kanan ke kiri secara terus-menerus. Setiap iterasi `loop()` menggeser potongan 16 karakter satu posisi ke kiri dengan jeda `TICK_MS`.

Mekanisme scroll:

```
[16 spasi] + [teks pesan] + [16 spasi]
     ↑
  Dipotong 16 karakter, digeser 1 posisi tiap tick
```

Padding kiri memastikan teks masuk dari sisi kanan. Padding kanan memastikan teks keluar bersih ke sisi kiri sebelum scroll diulang.

---

## Kode

```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const char* label    = "QUOTE";
const char* message  = "Pelan Tidak Apa, Yang Penting Maju";
const int   COLS     = 16;
const int   TICK_MS  = 150;

void centerPrint(uint8_t row, const char* text) {
  uint8_t len = strlen(text);
  uint8_t col = (len < COLS) ? (COLS - len) / 2 : 0;
  lcd.setCursor(col, row);
  lcd.print(text);
}

void setup() {
  lcd.init();
  lcd.backlight();
  lcd.clear();
  centerPrint(0, label);
}

void loop() {
  String ticker = String("                ") + message + "                ";
  uint8_t totalLen = ticker.length();

  for (uint8_t pos = 0; pos + COLS <= totalLen; pos++) {
    lcd.setCursor(0, 1);
    lcd.print(ticker.substring(pos, pos + COLS));
    delay(TICK_MS);
  }
}
```

---

## Penjelasan Fungsi

### `centerPrint(row, text)`

Mencetak teks tepat di tengah LCD pada baris yang ditentukan.

- Menghitung kolom awal dengan rumus `(COLS - panjang_teks) / 2`
- Jika teks lebih panjang dari layar, kolom awal diset ke `0`

### `setup()`

Berjalan sekali saat Arduino menyala. Menginisialisasi LCD, menyalakan backlight, membersihkan layar, dan mencetak label statis di baris 0.

### `loop()`

Berjalan terus-menerus. Membangun string `ticker` dengan padding, lalu menggeser jendela 16 karakter satu posisi per iterasi dengan jeda `TICK_MS` milidetik.

---

## Komponen

| Komponen | Jumlah |
|---|---|
| Arduino (Uno/Nano/dll) | 1 |
| LCD 16x2 | 1 |
| Modul I2C (PCF8574) | 1 |

### Wiring

| Pin I2C Modul | Pin Arduino |
|---|---|
| VCC | 5V |
| GND | GND |
| SDA | A4 |
| SCL | A5 |

---

## Library

Install melalui Arduino IDE Library Manager:

- `LiquidCrystal_I2C` oleh Frank de Brabander
- `Wire` (built-in Arduino)

---

## Kustomisasi

| Variabel | Fungsi |
|---|---|
| `label` | Teks statis baris atas |
| `message` | Teks yang discroll di baris bawah |
| `TICK_MS` | Kecepatan scroll — nilai lebih kecil = lebih cepat |
| `COLS` | Sesuaikan jika menggunakan LCD dengan lebar berbeda |

---

## Troubleshooting

**LCD tidak menampilkan apa-apa**
- Periksa alamat I2C. Jalankan I2C Scanner untuk mengetahui alamat yang benar.
- Atur contrast modul I2C melalui potensiometer di bagian belakang modul.

**Karakter acak muncul**
- Pastikan library `LiquidCrystal_I2C` yang digunakan kompatibel dengan modul I2C yang dipakai.

**Scroll tidak mulus**
- Kurangi nilai `TICK_MS` untuk scroll lebih cepat, tambah untuk scroll lebih lambat.
