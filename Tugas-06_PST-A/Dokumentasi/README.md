# Running Text LCD I2C (Arduino Uno)
Nama: Wildan Munawwar Habib     
NIM: H1D023045
## Deskripsi
Project ini bertujuan untuk menampilkan teks berjalan (running text) pada LCD 16x2 menggunakan modul I2C.

- Baris pertama menampilkan teks statis "QUOTE:"
- Baris kedua menampilkan teks berjalan dari kanan ke kiri

## Komponen
- Arduino Uno
- LCD 16x2 I2C
- Kabel jumper

## Wiring
| LCD I2C | Arduino Uno |
|--------|------------|
| VCC    | 5V         |
| GND    | GND        |
| SDA    | A4         |
| SCL    | A5         |

## Cara Kerja
- Teks berjalan dibuat menggunakan metode substring
- Setiap loop menampilkan 16 karakter sesuai lebar LCD
- Teks dibuat seolah-olah masuk dari kanan ke kiri

## Source Code
Lihat folder `Source Code`

## Hasil
Baris 1: QUOTE:  
Baris 2: (teks berjalan)