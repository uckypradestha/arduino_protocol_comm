# Identitas

- Nama: Adeyunita Rachmadhani
- NIM: H1D023057
- Pemrograman Sistem Tertanam A

# Scrolling Text LCD I2C dengan Arduino

Proyek ini merupakan program Arduino untuk menampilkan **scrolling text** pada LCD 16x2 berbasis I2C. Tampilan LCD dibuat dalam dua baris, di mana baris pertama berisi judul **"QUOTE"** yang bersifat statis, sedangkan baris kedua menampilkan isi kutipan yang bergerak dari kanan ke kiri.

## Tujuan Program

Program ini dibuat untuk mempelajari cara:
- menggunakan LCD 16x2 berbasis I2C
- memanfaatkan library `Wire.h` dan `Adafruit_LiquidCrystal.h`
- menampilkan teks statis dan dinamis pada LCD
- membuat efek scrolling text menggunakan Arduino

## Rangkaian Hardware
![Rangkaian LCD I2C](Dokumentasi/Rangkaian06.png)

## Library yang Digunakan

Program menggunakan dua library utama:
- `Wire.h` untuk komunikasi I2C
- `Adafruit_LiquidCrystal.h` untuk mengontrol LCD

## Cara Kerja

Saat program dijalankan, LCD akan diinisialisasi terlebih dahulu dengan ukuran 16 kolom dan 2 baris. Setelah itu, tulisan **"QUOTE"** ditampilkan secara tetap pada baris pertama. Pada baris kedua, program menampilkan isi kutipan yang bergerak dari kanan ke kiri menggunakan teknik pengambilan substring sepanjang 16 karakter sesuai lebar LCD. Pergeseran teks diatur menggunakan `delay(200)` sehingga menghasilkan animasi running text.

## Struktur Program

Program terdiri dari:
- **Inisialisasi library dan objek LCD**
- **Variabel teks** untuk menyimpan isi quote
- **Fungsi `setup()`** untuk menyiapkan LCD
- **Fungsi `loop()`** untuk menjalankan animasi scrolling text

## Output Program

Output dari program ini adalah:
- tulisan **QUOTE** pada baris pertama LCD
- teks quote berjalan pada baris kedua secara terus-menerus

### Demo
[Klik untuk melihat video demo](Dokumentasi/0412.gif)

## Link Tinkercad
https://www.tinkercad.com/things/cMkk1XvuU49-lcd-quotes



