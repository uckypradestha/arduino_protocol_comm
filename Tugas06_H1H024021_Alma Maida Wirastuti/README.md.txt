## Author
- Nama  : Alma Maida Wirastuti
- NIM   : H1H024021
- Kelas : A

# Scrolling Text Dengan I2C

## Deskripsi
Program ini menampilkan dua kalimat pada LCD 16x2 yang terhubung 
melalui protokol komunikasi I2C. Kalimat pertama bersifat statis 
dan ditampilkan tepat di tengah baris atas, sedangkan kalimat kedua 
bersifat dinamis (scrolling) yang muncul dari sisi kanan layar.

## Library yang Digunakan
- `Adafruit_LiquidCrystal.h` untuk kontrol LCD 16x2 via modul I2C

## Inisialisasi
LCD diinisialisasi dengan 16 kolom dan 2 baris, backlight dinyalakan,
lalu kalimat statis dihitung posisi tengahnya secara otomatis.

## Looping
Setiap siklus, baris ke-1 dibersihkan lalu teks scroll dicetak 
mulai dari posisi scrollPos yang terus bergeser ke kiri. Ketika 
teks habis keluar layar kiri, posisi direset ke kolom 16 (sisi kanan).

## Hasil Program
| Baris LCD | Isi | Sifat |
|---|---|---|
| Baris [0] | "Sleep is import" | Statis, di tengah |
| Baris [1] | "but assignments said ‘not today’" | Dinamis, scroll dari kanan |

## Konfigurasi Hardware
| Pin LCD I2C | Pin Arduino |
|---|---|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |
