# Laporan Praktikum Protokol Komunikasi - Modul 06

**Nama:** Muhammad Faiz Mubarok  
**NIM:** H1H024051  
**Kelas:** B

---

## Penjelasan Kode Program

Program ini bertujuan untuk menampilkan teks berjalan (*running text*) pada layar LCD 16x2 menggunakan protokol komunikasi I2C melalui ESP32/Arduino.

### 1. Library yang Digunakan
* `#include <Wire.h>`: Library standar untuk komunikasi I2C (Inter-Integrated Circuit).
* `#include <LiquidCrystal_I2C.h>`: Library khusus untuk mengontrol layar LCD yang menggunakan modul driver I2C (PCF8574).

### 2. Inisialisasi
Pada bagian awal, dilakukan inisialisasi objek LCD dengan alamat I2C `0x27` dan ukuran `16x2`.
* `lcd.init()`: Perintah untuk memulai konfigurasi hardware LCD.
* `lcd.backlight()`: Mengaktifkan lampu latar agar teks terlihat jelas.
* `lcd.setCursor(5, 0)`: Mengatur posisi awal kursor pada baris pertama untuk mencetak judul "QUOTE".

### 3. Logika Looping (Teks Berjalan)
Logika utama berada di dalam fungsi `loop()` dan sebuah perulangan `for`:
* **Variabel `offset`**: Digunakan untuk mengatur posisi awal karakter pertama dari string `quote`.
* **Perhitungan Posisi**: Dengan menggunakan rumus `15 - offset`, posisi teks akan dimulai dari kolom paling kanan (15) dan perlahan berkurang hingga ke kiri.
* **Kondisi `if (col >= 0 && col < 16)`**: Kondisi ini untuk memastikan karakter hanya dicetak jika posisinya berada dalam rentang layar LCD (kolom 0 sampai 15). Hal ini mencegah error tampilan saat teks mulai masuk atau keluar dari area layar.
* **`delay(DELAY)`**: Mengatur kecepatan pergerakan teks. Nilai 50ms memberikan efek gerakan yang cukup cepat namun tetap terbaca.

---

## Dokumentasi Hardware
Video demonstrasi alat saat menjalankan kode ini dapat dilihat pada folder `Dokumentasi` di repositori ini.