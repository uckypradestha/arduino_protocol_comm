# Source Code - Scrolling Text I2C

## Deskripsi
Folder ini berisi kode sumber (source code) untuk proyek Scrolling Text menggunakan protokol I2C pada Arduino UNO dan LCD 16x2.

## File yang Disertakan

### ScrollingTextl2c.ino
File utama yang berisi program Arduino untuk menampilkan teks scrolling pada LCD.

## Penjelasan Kode

### Library
```cpp
#include <LiquidCrystal_I2C.h>
```
- Library untuk mengontrol LCD melalui protokol I2C
- Mengurangi jumlah pin yang digunakan dari 6 menjadi hanya 2 (SDA dan SCL)

### Inisialisasi LCD
```cpp
LiquidCrystal_I2C lcd(0x27, 16, 2);
```
- Alamat I2C LCD: **0x27**
- Ukuran LCD: **16 kolom × 2 baris**

### Teks yang Ditampilkan
- **Baris Atas (Statis):** "QUOTE:"
- **Baris Bawah (Dinamis/Scrolling):** "Man Jadda Wajada - Barang siapa bersungguh-sungguh, maka ia akan berhasil"

### Fitur Utama

#### Setup (Inisialisasi)
- Menginisialisasi LCD
- Menyalakan backlight (lampu latar)
- Menampilkan teks "QUOTE:" di tengah baris pertama
- Menambahkan spasi di awal dan akhir teks scrolling agar efek smooth

#### Loop (Program Utama)
- Menggeser teks secara horizontal pada baris kedua
- **Kecepatan scroll:** 150 ms per frame
- Perulangan terus menerus membuat teks bergerak ke kiri

## Cara Kerja
1. Teks "QUOTE:" ditampilkan statis di baris pertama
2. Teks panjang di baris kedua bergerak dari kanan ke kiri
3. Efek scrolling menciptakan animasi teks berjalan berkelanjutan

## Kebutuhan Hardware
- Arduino UNO
- LCD 16x2 dengan modul I2C
- Kabel USB untuk koneksi
- Power supply 5V
