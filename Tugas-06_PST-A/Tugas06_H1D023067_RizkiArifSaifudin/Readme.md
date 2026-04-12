
# Tugas PST - Scrolling Text


Nama : Rizki Arif Saifudin

NIM : H1D023067

## Peralatan dan Bahan
- Arduino UNO
- LCD I2C 16 x 2 PCF8574-based pada address 0x20
- Kabel Jumper

## Penugasan
Membuat running text menggunakan LCD I2C 16 x 2. Baris pertama menampilkan teks "QUOTE" ditengah layar secara statis. Baris kedua menampilkan quote pilihan yang bergerak dari kanan ke kiri.

---

### Penjelasan

Program pada `main.ino` dibuat untuk menampilkan teks statis di baris pertama LCD dan efek running text di baris kedua.

1. Pemilihan Library
- `#include <Wire.h>` dipakai untuk komunikasi I2C antara Arduino UNO dan modul LCD (PCF8574).
- `#include <LiquidCrystal_I2C.h>` dipakai untuk mempermudah kontrol LCD I2C seperti inisialisasi, set posisi kursor, dan cetak teks.
- Objek LCD dibuat dengan `LiquidCrystal_I2C layar(0x20, 16, 2);`, artinya alamat LCD adalah `0x20` dengan ukuran `16 kolom x 2 baris`.

2. Inisialisasi (`setup()`)
- `layar.init();` untuk mengaktifkan LCD.
- `layar.backlight();` untuk menyalakan lampu latar LCD.
- Header `QUOTE` ditampilkan di tengah baris pertama dengan menghitung posisi tengah:
	`(16 - header.length()) / 2`, lalu kursor diarahkan menggunakan `layar.setCursor(tengah, 0)` dan dicetak dengan `layar.print(header)`.

3. Proses Looping Running Text (`loop()`)
- Variabel `pesan` berisi quote yang diberi spasi di awal dan akhir agar transisi teks masuk-keluar layar terasa halus.
- Fungsi `tampilkanRunningText()` menampilkan 16 karakter sesuai dengan lebar LCD dari `pesan`, dimulai dari indeks `giliranPrint`.
- Setelah satu tampilan selesai, `giliranPrint++` menggeser titik awal satu karakter, sehingga teks di layar terlihat bergerak dari kanan ke kiri.
- Saat indeks melebihi batas (`giliranPrint > pesan.length() - 16`), nilainya direset ke `0` agar animasi berulang terus.
- `delay(250);` memberi jeda 250 ms antar frame agar kecepatan gerak tetap nyaman dibaca.

4. Cara Efek Running Text Terbentuk
- Program berulang kali mengambil potongan 16 karakter dari string, menampilkannya, lalu menggeser posisi awal potongan tersebut.
- Karena potongan karakter bergeser satu per satu pada setiap loop, mata menangkapnya sebagai animasi teks berjalan.



## Dokumentasi
### Schematics
![skematik](Dokumentasi\schematics.png)  
### Simulasi
Screenshot
![skrinsut](Dokumentasi\simulation.png)
Video
![demo](Dokumentasi\live.gif)

### Link Simulasi
[Tinkercad](https://www.tinkercad.com/things/6JCNUa024u7-mighty-krunk-turing/)