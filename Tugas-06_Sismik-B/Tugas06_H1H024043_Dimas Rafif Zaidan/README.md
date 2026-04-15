# 📟 Scrolling Text LCD 16x2 dengan I2C (Arduino)

## 📌 Deskripsi Proyek

Proyek ini bertujuan untuk menampilkan **teks statis** dan **teks berjalan (scrolling)** pada LCD 16x2 menggunakan komunikasi **I2C** dengan Arduino.

Sistem terdiri dari:

* Baris pertama: teks **"QUOTE"** (statis, berada di tengah)
* Baris kedua: teks **quote** yang bergerak dari kanan ke kiri

---

## ⚙️ Spesifikasi Sistem

* Mikrokontroler: Arduino Uno
* Display: LCD 16x2
* Modul komunikasi: I2C (berbasis MCP23008)
* Library: `Adafruit_LiquidCrystal`
* Protokol: I2C (SDA & SCL)

---

## 🔌 Wiring

Hubungkan komponen sebagai berikut:

| LCD I2C | Arduino Uno |
| ------- | ----------- |
| VCC     | 5V          |
| GND     | GND         |
| SDA     | A4          |
| SCL     | A5          |

📷 **Dokumentasi Wiring:**

Dokumentasi terlampir di dalam folder

---

## 🧠 Konsep yang Digunakan

### 1. Komunikasi I2C

I2C (Inter-Integrated Circuit) adalah protokol komunikasi serial yang menggunakan:

* **SDA (Serial Data)**
* **SCL (Serial Clock)**

Keunggulan:

* Hemat pin (hanya 2 kabel)
* Mendukung banyak perangkat dalam satu jalur

---

### 2. Scrolling Text

Scrolling dilakukan dengan cara:

* Menggeser posisi teks dari kanan ke kiri
* Menghitung posisi tiap karakter
* Menampilkan hanya karakter yang berada dalam area layar (0–15)

---

## 🔄 Cara Kerja Program

### 1. Inisialisasi

* LCD diaktifkan menggunakan `lcd.begin(16,2)`
* Backlight dinyalakan
* Teks "QUOTE" ditampilkan di tengah baris pertama

---

### 2. Menampilkan Header (Statis)

```cpp
lcd.setCursor(centerColumn(staticText), 0);
lcd.print(staticText);
```

Teks akan selalu berada di tengah layar.

---

### 3. Proses Scrolling

Setiap loop:

1. Baris kedua dibersihkan
2. Setiap karakter dihitung posisinya
3. Jika posisi masuk layar → ditampilkan
4. Posisi geser bertambah (`scrollPos++`)

---

### 4. Reset Scrolling

Jika teks sudah keluar layar:

```cpp
if (scrollPos >= totalScroll) {
  scrollPos = 0;
}
```

---

## 📊 Logika Perhitungan Posisi

Rumus posisi karakter:

```
col = (LCD_COLS - 1 - scrollPos) + i
```

Keterangan:

* `scrollPos` → pergeseran
* `i` → indeks karakter
* `col` → posisi kolom di LCD

---

## ⏱️ Pengaturan Kecepatan

Kecepatan scrolling diatur oleh:

```cpp
delay(SCROLL_DELAY);
```

Rekomendasi:

* 200 ms → cukup smooth
* 100 ms → lebih halus
* 300 ms → lebih lambat

---

## 📌 Catatan Penting

* Library yang digunakan adalah `Adafruit_LiquidCrystal` karena kompatibel dengan MCP23008
* Pastikan wiring benar (terutama SDA & SCL)
* Jika LCD tidak tampil:

  * Periksa koneksi
  * Pastikan simulasi berjalan (jika di Tinkercad)

---

## 🚀 Pengembangan Lanjutan

Beberapa fitur yang bisa ditambahkan:

* Multi-quote (array teks)
* Tombol untuk mengganti quote
* Scrolling non-blocking (menggunakan `millis()`)
* Efek animasi tambahan

---

## 📎 Kesimpulan

Sistem ini berhasil:

* Menampilkan teks statis di baris pertama
* Menampilkan teks berjalan di baris kedua
* Mengimplementasikan komunikasi I2C secara efisien

Proyek ini membantu memahami:

* Protokol I2C
* Pengolahan tampilan LCD
* Logika animasi sederhana pada sistem embedded

---
