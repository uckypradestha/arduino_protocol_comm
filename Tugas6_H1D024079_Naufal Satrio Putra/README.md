# 📟 Running Text Display dengan LCD 16x2 I2C & Arduino Uno

[![Tinkercad Simulation](https://img.shields.io/badge/Tinkercad-Simulasi_Project-blue?style=for-the-badge&logo=autodesk)](https://www.tinkercad.com/things/1SvVMVEpeyI/editel?returnTo=%2Fdashboard)
[![Arduino](https://img.shields.io/badge/-Arduino-00979D?style=for-the-badge&logo=Arduino&logoColor=white)](https://www.tinkercad.com/things/1SvVMVEpeyI/editel?returnTo=%2Fdashboard)

## Deskripsi Proyek
Proyek ini merupakan implementasi antarmuka visual pada sistem tertanam menggunakan layar **LCD 16x2** yang dilengkapi dengan modul komunikasi **I2C (Inter-Integrated Circuit)**. Sistem ini diprogram menggunakan Arduino Uno untuk merender dan menganimasikan pesan teks berjalan (*running text*) secara dinamis.

Penggunaan modul I2C secara signifikan meningkatkan efisiensi penggunaan *General Purpose Input/Output* (GPIO) pada mikrokontroler. Modul ini mereduksi kebutuhan kabel dari 6 jalur komunikasi paralel (standar 4-bit mode) menjadi hanya 2 jalur komunikasi serial (SDA dan SCL).

## Kebutuhan Perangkat Keras (Hardware)
- 1x Arduino Uno R3
- 1x Layar LCD 16x2 dengan Modul I2C *Backpack* terintegrasi
- 4x Kabel Jumper 

## Pin Mapping (Konfigurasi I2C)
Integrasi dari modul LCD I2C ke Arduino Uno dilakukan dengan sangat ringkas mengikuti standar protokol berikut:

| Pin Modul I2C | Pin Arduino Uno | Deskripsi Fungsi |
| :---: | :---: | :--- |
| **GND** | `GND` | Ground (Jalur Negatif) |
| **VCC** | `5V` | Catu Daya 5 Volt (Jalur Positif) |
| **SDA** | `A4` | Serial Data (Jalur transfer data dua arah) |
| **SCL** | `A5` | Serial Clock (Jalur sinkronisasi sinyal waktu) |

## Implementasi Teknis & Library
Pengembangan perangkat lunak memanfaatkan pustaka antarmuka I2C bawaan (`Adafruit_LiquidCrystal.h` pada Tinkercad atau `LiquidCrystal_I2C.h` pada lingkungan fisik).

Logika animasi teks diimplementasikan menggunakan pemanggilan fungsi `scrollDisplayLeft()` di dalam blok `loop()`. Untuk memastikan teks dapat terbaca (*readable*) saat bergerak, sistem menerapkan interval interupsi waktu (`delay(300)`) di setiap iterasi pergeseran piksel karakter.

## Cara Menjalankan Sistem
1. Rangkai perangkat keras sesuai tabel *Pin Mapping* di atas.
2. Jalankan simulasi di Tinkercad atau unggah (*upload*) kode ke *board* fisik.
3. Observasi layar: Teks awal akan dirender, lalu bergeser ke arah kiri layar secara berulang (*looping*).
4. **Troubleshooting Fisik:** Jika *backlight* menyala namun piksel teks tidak terlihat (kosong), putar potensiometer (trimpot biru) di bagian belakang modul I2C menggunakan obeng presisi untuk melakukan kalibrasi tingkat kontras layar.

**Naufal Satrio Putra** *H1D024079 | Informatika, Fakultas Teknik* Universitas Jenderal Soedirman  