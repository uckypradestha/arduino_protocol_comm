# Tugas 06: Implementasi Protokol I2C pada LCD 16x2

## 1. Deskripsi Proyek
Proyek ini merupakan implementasi dari protokol komunikasi serial I2C (Inter-Integrated Circuit) untuk mengendalikan perangkat output berupa LCD (Liquid Crystal Display) 16x2. Fokus utama tugas ini adalah menyajikan informasi secara hierarkis: baris pertama sebagai judul statis dan baris kedua sebagai media informasi dinamis menggunakan efek teks berjalan (scrolling text).

## 2. Tautan Simulasi
Seluruh rangkaian dan logika program dapat diuji secara virtual melalui tautan Tinkercad berikut: 
https://www.tinkercad.com/things/0uNGQag5a9M-tugas-6pst-a?sharecode=2pppboYPMdt5P3X9ZqWHpwHVy3IuAblQlUrinzWFIIA

## 3. Analisis Kode program
Kode program ini dikembangkan dengan efisiensi memori dan kelancaran visual sebagai prioritas. Berikut adalah bedah teknis tiap bagian:

### A. Integrasi Library
```cpp
#include <Adafruit_LiquidCrystal.h>
```
Penggunaan library Adafruit_LiquidCrystal bertujuan untuk mengabstraksi kompleksitas transmisi data pada bus I2C. Library ini menangani pengalamatan perangkat (addressing) dan pengiriman bit data melalui jalur SDA secara otomatis, sehingga pengembang cukup menggunakan perintah tingkat tinggi untuk menampilkan karakter.

### B. Inisialisasi Sistem (Setup)
```cpp
Adafruit_LiquidCrystal lcd(0);
void setup() {
  lcd.begin(16, 2);
  lcd.setBacklight(1);
}
```
Pada tahap inisialisasi, dilakukan penetapan alamat I2C (dalam simulasi Tinkercad menggunakan indeks 0). Fungsi lcd.begin(16, 2) sangat krusial untuk mendefinisikan batas koordinat layar. Pengaktifan backlight dilakukan di awal untuk menjamin keterbacaan (readability) karakter yang akan diproses pada tahap selanjutnya.

### C. Alur Logika Perulangan (Looping)
Bagian void loop() menangani dua mekanisme tampilan sekaligus:

- Statis (Baris pertama)
Menggunakan lcd.setCursor(5, 0) untuk menempatkan kursor di kolom ke-5. Hal ini dilakukan berdasarkan perhitungan matematis agar kata "QUOTE:" yang berjumlah 6 karakter berada tepat di tengah (Center Aligned) dari total 16 kolom yang tersedia.

- DInamis (Baris kedua)
Logika pergerakan teks dibangun menggunakan struktur kontrol for loop. Variabel pos berfungsi sebagai indeks kolom yang terus berkurang (iterasi mundur).

Mekanisme Transisi: Ketika pos bernilai positif, program menambahkan spasi di depan teks. Namun, ketika pos bernilai negatif (teks mulai keluar layar kiri), fungsi substring(-pos) akan memotong string di sisi depan.

Pembersihan Buffer: Logika while (displayStr.length() < 16) memastikan bahwa setiap frame pergerakan selalu memiliki panjang 16 karakter. Hal ini mencegah terjadinya ghosting effect atau sisa karakter yang tertinggal di layar saat teks bergeser.


Penerapan protokol I2C dalam tugas ini membuktikan efisiensi penggunaan pin pada mikrokontroler. Dengan hanya menggunakan dua jalur komunikasi (SDA dan SCL), kita dapat mengontrol display yang kompleks. Penggunaan logika pemotongan string (substring) dalam kode menjamin tampilan teks berjalan tetap rapi dan sinkron tanpa memerlukan intervensi manual pada perangkat keras.