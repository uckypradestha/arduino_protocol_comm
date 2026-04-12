# Laporan Tugas 06: Scrolling Text Dengan I2C

Dokumentasi ini menjelaskan implementasi program teks berjalan (*scrolling text*) menggunakan mikrokontroler Arduino dan LCD 16x2 I2C. Program ini membagi layar menjadi dua bagian: satu baris statis dan satu baris dinamis yang bergerak secara berkelanjutan.

## Spesifikasi Sistem
Berdasarkan ketentuan tugas, sistem harus memenuhi kriteria berikut:
* **Jumlah Kalimat**: Terdiri dari 2 kalimat berbeda.
* **Baris 0 (Atas)**: Bertulisan "QUOTE" dan bersifat statis (tidak bergerak).
* **Baris 1 (Bawah)**: Berisi kutipan (*quote*) yang bersifat dinamis (bergerak/scrolling).
* **Posisi Judul**: Tulisan "QUOTE" harus berada tepat di tengah tampilan LCD.
* **Animasi Teks**: Tulisan kutipan pada baris [1] harus langsung muncul dari sisi kanan layar atau dimulai dari koordinat Cursor (15, 1).

## Analisis Kode Program

### 1. Inisialisasi Library dan Hardware
Program menggunakan library `Adafruit_LiquidCrystal.h` untuk mempermudah komunikasi I2C dengan modul LCD. Alamat I2C yang digunakan adalah `0` (biasanya digunakan dalam simulasi seperti Tinkercad).

### 2. Logika Penempatan Teks (Setup)
Untuk memposisikan kata "QUOTE" di tengah secara statis:
* LCD memiliki lebar 16 kolom.
* Kata "QUOTE" terdiri dari 5 karakter.
* Rumus posisi tengah: `(16 kolom - 5 karakter) / 2 = 5.5`. 
* Kursor diatur pada kolom **5** baris **0** agar teks terlihat seimbang di tengah layar.

### 3. Logika Teks Berjalan (Loop)
Karena fungsi bawaan `scrollDisplayLeft()` akan menggeser seluruh layar (termasuk baris atas), maka digunakan teknik **Padding dan Substring**:
* **Padding**: Kalimat kutipan ditambahkan 16 karakter spasi di awal dan di akhir. Spasi awal berfungsi agar teks muncul bertahap dari kanan (kolom 15).
* **Substring**: Program mengambil potongan teks sepanjang 16 karakter berdasarkan indeks yang terus bertambah (`scrollIndex`).
* **Reset**: Ketika indeks mencapai akhir panjang string (dikurangi lebar layar), indeks dikembalikan ke `0` agar teks berulang kembali.