# Tugas 6 – Scrolling Text LCD I2C

* Nama: Difa' Tamaya Maulidina Adz Dzikro
* NIM: H1H024019
* Kelas: A
---
## Deskripsi Program

Program ini dibuat untuk menampilkan teks pada LCD 16x2 menggunakan komunikasi I2C di Tinkercad.
Tampilan terdiri dari:
* Baris pertama menampilkan tulisan **"QUOTE"** secara statis dan berada di tengah.
* Baris kedua menampilkan kalimat (quote) yang bergerak dari kanan ke kiri (scrolling).
---
## Library yang Digunakan
```cpp id="q4f9r0"
#include <Wire.h>
#include <Adafruit_LiquidCrystal.h>
```
---
## Inisialisasi LCD

```cpp id="3t3t1c"
Adafruit_LiquidCrystal lcd(0);
```

Digunakan untuk menginisialisasi LCD dengan alamat default pada Tinkercad.

---

## Variabel

```cpp id="0v8zzg"
String teks = "                life must go on                ";
```

Variabel ini berisi kalimat yang akan ditampilkan.
Spasi di awal dan akhir digunakan agar teks terlihat masuk dari sisi kanan dan keluar ke kiri.

---

## Fungsi setup()

```cpp id="9whn1k"
void setup() {
  lcd.begin(16, 2);

  lcd.setCursor(5, 0);
  lcd.print("QUOTE");
}
```

Penjelasan:

* Menginisialisasi LCD ukuran 16x2
* Menampilkan tulisan "QUOTE" di tengah baris pertama

---

## Fungsi loop()

```cpp id="8qhy0z"
void loop() {
  for (int i = 0; i < teks.length() - 15; i++) {
    lcd.setCursor(0, 1);
    lcd.print(teks.substring(i, i + 16));
    delay(300);
  }
}
```

Penjelasan:

* Menggunakan perulangan untuk membuat efek scrolling
* `substring()` mengambil 16 karakter sesuai lebar LCD
* `delay(300)` memberikan jeda agar pergerakan terlihat

---

## Rangkaian

* VCC → 5V
* GND → GND
* SDA → A4
* SCL → A5

---

## Dokumentasi
(https://www.tinkercad.com/things/cAAmLiA63sG-tugas-6-sismik?sharecode=wM1bwOmBsizrVRQAN7pHhfrlu_0g2zkS7tJM5MpCFE8)

---

## Kesimpulan

Program berhasil menampilkan teks statis pada baris pertama dan teks berjalan (scrolling) pada baris kedua sesuai dengan spesifikasi yang diberikan.

---
