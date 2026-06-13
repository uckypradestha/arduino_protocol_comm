# 📺 Arduino I2C LCD Running Text - QUOTE PROJECT

Proyek ini mendemonstrasikan cara membuat teks berjalan (*running text*) pada LCD 16x2 menggunakan protokol I2C dan Arduino Uno. Cocok untuk menampilkan kutipan motivasi atau informasi status secara dinamis.

---

## 🛠️ Komponen yang Digunakan
* **Arduino Uno** (atau kompatibel)
* **LCD 16x2** dengan **I2C Backpack**
* **Kabel Jumper**

## 🔌 Skema Koneksi
Berdasarkan rangkaian yang saya buat, berikut adalah pinout yang digunakan:

| Pin LCD I2C | Pin Arduino | Warna Kabel |
| :--- | :--- | :--- |
| **GND** | GND | Hitam |
| **VCC** | 5V | Merah |
| **SDA** | SDA (Pin Khusus I2C) | Kuning |
| **SCL** | SCL (Pin Khusus I2C) | Hijau |

> **Catatan:** Pin SDA dan SCL di Arduino Uno biasanya terletak di dekat pin AREF atau menggunakan pin Analog A4 (SDA) dan A5 (SCL).

---
## Tinkercad
Link : https://www.tinkercad.com/things/1rdNISaYnWg-tugas-6lcdh1d023090

## 💻 Kode Sumber
Proyek ini menggunakan library `Adafruit_LiquidCrystal`. 

### Logika Teks Berjalan:
Teks diberikan *padding* spasi kosong di awal dan akhir agar saat muncul tidak langsung terpotong, melainkan terlihat masuk dari sisi kanan layar:
`"                " + pesanQuote + "                "`

### Pengaturan Kecepatan:
Untuk mengubah kecepatan gerak teks, kamu bisa mengubah nilai pada fungsi `delay()`:
* `delay(100);` -> Lebih Cepat
* `delay(200);` -> Lebih Lambat

---

## 🚀 Cara Penggunaan
1. Instal Library **Adafruit LiquidCrystal** di Arduino IDE.
2. Hubungkan perangkat sesuai skema di atas.
3. *Upload* kode `.ino` yang tersedia di repositori ini.
4. Teks akan otomatis berjalan di baris kedua LCD.

---

## 📝 Lisensi
Proyek ini bersifat open-source. Silakan gunakan dan modifikasi sesuai kebutuhan Anda!