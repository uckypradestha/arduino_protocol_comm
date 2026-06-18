
# Laporan Praktikum Modul 06 - Scrolling Text dengan I2C

## Deskripsi Tugas
Tugas ini bertujuan untuk mengimplementasikan protokol komunikasi **I2C (Inter-Integrated Circuit)** pada Arduino Uno untuk mengendalikan **LCD 16x2**. Program dirancang untuk menampilkan dua jenis informasi:
1.  **Baris 1 (Statis):** Menampilkan teks "Halo" yang diposisikan di tengah.
2.  **Baris 2 (Dinamis):** Menampilkan teks nama "Ratu Naurah Calista" yang berjalan (scrolling) dari sisi kanan ke kiri.

## Komponen yang Digunakan
* 1x Arduino Uno R3
* 1x LCD 16x2 dengan Modul I2C (PCF8574)
* Kabel Jumper secukupnya

## Penjelasan Source Code

### 1. Inisialisasi dan Library
```cpp
#include <Adafruit_LiquidCrystal.h>
Adafruit_LiquidCrystal lcd(0);
```
Program menggunakan library `Adafruit_LiquidCrystal` untuk mempermudah kontrol LCD melalui I2C. Angka `0` merujuk pada alamat default modul I2C di Tinkercad.

### 2. Fungsi `setup()`
```cpp
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(4, 0); 
  lcd.print("Halo");
}
```
* `lcd.begin(16,2)`: Mengatur dimensi LCD 16 kolom dan 2 baris.
* `lcd.setCursor(4, 0)`: Menempatkan teks "Halo" mulai dari kolom ke-4 agar terlihat berada di tengah baris pertama. Teks ini bersifat statis karena diletakkan di dalam `setup()`.

### 3. Fungsi `loop()` dan Logika Scrolling
Berbeda dengan fungsi `scrollDisplayLeft()` bawaan yang menggerakkan seluruh layar, kode ini menggunakan logika **Buffer** agar hanya baris kedua yang bergerak:

* **Variabel `scrollPos`**: Mengontrol posisi awal teks. Dimulai dari 16 (posisi di luar layar sebelah kanan).
* **Perulangan `for`**: Membuat sebuah "string bayangan" (buffer) sepanjang 16 karakter.
    * Jika indeks karakter berada di dalam jangkauan nama, maka karakter tersebut dimasukkan ke buffer.
    * Jika di luar jangkauan, buffer diisi dengan spasi kosong.
* **Reset Posisi**: Jika teks sudah bergerak ke kiri sampai hilang sepenuhnya (`scrollPos < -panjang teks`), posisi dikembalikan ke 16 untuk memulai kembali dari kanan.
