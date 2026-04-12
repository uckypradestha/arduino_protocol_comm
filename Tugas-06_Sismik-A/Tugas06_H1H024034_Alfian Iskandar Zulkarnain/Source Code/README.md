# Penjelasan Kode `main.cpp`

Program ini mengontrol **LCD 16x2** melalui komunikasi **I2C** menggunakan library Adafruit LiquidCrystal. LCD menampilkan teks statis di baris pertama dan teks dinamis di baris kedua.

---

## 1. Import Library

```cpp
#include <Adafruit_LiquidCrystal.h>
```

Mengimpor library **Adafruit LiquidCrystal** untuk mengontrol LCD 16x2 melalui protokol komunikasi **I2C**.

---

## 2. Inisialisasi Objek LCD

```cpp
Adafruit_LiquidCrystal lcd(0);
```

Membuat objek `lcd` dengan alamat I2C `0`. Objek ini digunakan untuk memanggil semua fungsi pengendalian LCD seperti `begin()`, `setCursor()`, `print()`, dan lainnya.

---

## 3. Deklarasi Variabel 

```cpp
String teksDiam = "OWO SAID:";
String teksJalan = "                HI AN TECH AN TECH ASHING                ";
```

Variabel `teksDiam` berfungsi sebagai teks statis yang akan ditampilkan di baris pertama LCD. Variabel `teksJalan` berfungsi sebagai teks dinamis yang akan ditampilkan di baris kedua LCD. Spasi di awal dan akhir `teksJalan` berfungsi sebagai *padding* agar teks muncul dan menghilang secara halus dari layar 16 karakter.
---

## 4. Fungsi `setup()` 

```cpp
void setup() {
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setBacklight(HIGH);

  int posisiTengah = (16 - teksDiam.length()) / 2;

  lcd.setCursor(posisiTengah, 0);
  lcd.print(teksDiam);
}
```

### Penjelasan:

1. `lcd.begin(16, 2)` — Menginisialisasi LCD dengan ukuran 16 kolom × 2 baris.
2. `lcd.clear()` — Membersihkan seluruh tampilan layar LCD.
3. `lcd.setBacklight(HIGH)` — Menyalakan *backlight* LCD.
4. Menghitung posisi tengah:
   ```
   posisiTengah = (16 - 9) / 2 = 3
   ```
   Teks `"OWO SAID:"` memiliki 9 karakter, sehingga kursor dimulai di kolom ke-3 agar teks tampil di tengah.
5. `lcd.setCursor(posisiTengah, 0)` — Memindahkan kursor ke kolom ke-3, baris 0 (baris atas).
6. `lcd.print(teksDiam)` — Mencetak `"OWO SAID:"` di posisi tengah baris atas.

---

## 5. Fungsi `loop()`

```cpp
void loop() {
  for (int i = 0; i <= teksJalan.length() - 16; i++) {
    lcd.setCursor(0, 1);
    lcd.print(teksJalan.substring(i, i + 16));
    delay(100);
  }
}
```

### Penjelasan Alur:

1. Loop `for` mengiterasi variabel `i` dari `0` hingga `teksJalan.length() - 16`.
2. `lcd.setCursor(0, 1)` — Setiap iterasi, kursor diatur ke kolom 0, baris 1 (baris bawah).
3. `teksJalan.substring(i, i + 16)` — Mengambil potongan 16 karakter dari `teksJalan` mulai dari indeks ke-`i`.
4. `lcd.print(...)` — Menampilkan potongan 16 karakter tersebut di baris kedua LCD.
5. `delay(100)` — Memberikan jeda 100 milidetik sebelum pergeseran berikutnya.

Setiap iterasi menggeser 16 karakter satu posisi ke kanan pada string `teksJalan`, sehingga menghasilkan efek teks berjalan dari kanan ke kiri pada layar LCD.